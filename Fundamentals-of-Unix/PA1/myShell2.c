#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);       /* our signal-catching function */

int
main(void)
{
    char    buf[MAXLINE];   /* from apue.h */
    pid_t   pid;
    int     status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");  /* print prompt (printf requires %% to print %) */
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0; /* replace newline with null */

        char **cmd_strs = NULL;  /* var declaration to dynamically store cstrings */
        char *token = strtok(buf, " ");
        int i = 0;

        while(token != NULL) { /* allocate memory, copy cstring to memory, iterate to next cstring */
            cmd_strs = realloc(cmd_strs, (i + 1) * sizeof(char *)); 
            cmd_strs[i] = malloc(strlen(token) + 1);
            strcpy(cmd_strs[i], token);
            token = strtok(NULL, " ");
            i++;
        }
        cmd_strs = realloc(cmd_strs, (i + 1) * sizeof(char *)); /* allocate for NULL termination */
        cmd_strs[i] = NULL;


        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {      /* child */
            execvp(cmd_strs[0], cmd_strs);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }
         /* parent */
        if ((pid = waitpid(pid, &status, 0)) < 0) 
            err_sys("waitpid error");
        

        /* free memory */
        int j;

        for (j = 0; cmd_strs[j] != NULL; j++) {
            free(cmd_strs[j]);
        }

        free(cmd_strs);
        printf("%% ");
        }    
    exit(0);
}  
        
void        
sig_int(int signo)
{
    printf("interrupt\n%% ");
}
