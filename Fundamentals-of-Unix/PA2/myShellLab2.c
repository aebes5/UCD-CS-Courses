#include "apue.h"
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void sig_int(int);       /* our signal-catching function */

int main(void) {
    char buf[MAXLINE];   /* from apue.h */
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");  /* print prompt (printf requires %% to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */

        char **cmd_strs = NULL;  /* var declaration to dynamically store cstrings */
        char *token = strtok(buf, " ");
        int i = 0;

        while (token != NULL) { /* allocate memory, copy cstring to memory, iterate to next cstring */
            cmd_strs = realloc(cmd_strs, (i + 1) * sizeof(char *));
            cmd_strs[i] = malloc(strlen(token) + 1);
            strcpy(cmd_strs[i], token);
            token = strtok(NULL, " ");
            i++;
        }
        cmd_strs = realloc(cmd_strs, (i + 1) * sizeof(char *)); /* allocate for NULL termination */
        cmd_strs[i] = NULL;

        char* output_file = NULL; /* vars */
        char* input_file = NULL;
        char* error_file = NULL;
        int j;

        for (j = 0; j < i; j++) {
            if (strcmp(cmd_strs[j], ">") == 0) { /* checks for > in args */
                if (j + 1 < i ) {
                    output_file = cmd_strs[j + 1]; /* outfile is arg after > */
                    cmd_strs[j] = NULL;
                }
                else {
                    fprintf(stderr, "Error: Missing output file name.\n");
                    exit(EXIT_FAILURE);
                }
            }
            else if(strcmp(cmd_strs[j], "<") == 0) { /* same thing but input < */
                if (j + 1 < i ) {
                    input_file = cmd_strs[j + 1];
                    cmd_strs[j] = NULL;
                }
                else {
                    fprintf(stderr, "Error: Missing input file name.\n");
                    exit(EXIT_FAILURE);
                }
            }
            /* similar thing as for > and <; assumes input is either >& or &>;
             * error_file set to same as output_file redirection if output_file isn't
             * NULL(in the case of > outfile 2 >& 1) which doesn't check the actual 1 or 2
             * but instead expects a perfect situation where we are wanting output and error the same, 
             * else the next argument is output_file and error_file */ 
            
            else if(strcmp(cmd_strs[j], ">&") == 0 || strcmp(cmd_strs[j], "&>") == 0) {
                if (j + 1 < i) {
                    if (output_file != NULL) {
                        error_file = output_file;
                    }
                    else {
                        output_file = cmd_strs[j + 1];
                        error_file = output_file;
                        cmd_strs[j] = NULL;
                    }
                }
                else {
                    fprintf(stderr, "Error: Issues with >& or &>\n");
                    exit(EXIT_FAILURE);
                }
            }
        }
        
        int stdout_dup = -1; /* used for error testing */
        int stderr_dup = -1;

        if (output_file) {
            stdout_dup = dup(STDOUT_FILENO); /* dup STDOUT so we can reset */
            int fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            if (dup2(fd, STDOUT_FILENO) == -1) { /* redirect output and error */
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            if (error_file != NULL) {
                stderr_dup = dup(STDERR_FILENO); /* dup STDERR so we can reset */
                if (dup2(fd, STDERR_FILENO) == -1) {
                    perror("dup2");
                    exit(EXIT_FAILURE);
                }
            }
            close(fd); /* close */
        }

        int stdin_dup = -1; /* input error testing */

        if (input_file) {
            stdin_dup = dup(STDIN_FILENO); /* dup STDIN so we can reset */
            int fd = open(input_file, O_RDONLY);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            if (dup2(fd, STDIN_FILENO) == -1) { /* redirect input */
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(fd);
        }

        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {      /* child */
            execvp(cmd_strs[0], cmd_strs);
            err_ret("couldn't execute: %s", buf);
            exit(EXIT_FAILURE);
        }
 
       /* redirect input, output, error to original state */
        if (stdout_dup != -1) {
            if (dup2(stdout_dup, STDOUT_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(stdout_dup);
        }
        if (stdin_dup != -1) {
            if (dup2(stdin_dup, STDIN_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(stdin_dup);
        }
        if (stderr_dup != -1) {
            if (dup2(stderr_dup, STDERR_FILENO) == -1) {
                perror("dup2");
                exit(EXIT_FAILURE);
            }
            close(stderr_dup);
        }

        /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        
        int k;
        /* free memory */
        for (k = 0; cmd_strs[k] != NULL; k++) {
            free(cmd_strs[k]);
        }
        free(cmd_strs);
        printf("%% ");
    }
    exit(0);
}

void sig_int(int signo) {
    printf("interrupt\n%% ");
}
