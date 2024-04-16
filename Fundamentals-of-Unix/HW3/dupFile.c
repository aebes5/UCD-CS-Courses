#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int my_dup2_with_fcntl(int fd, int fd2) {

    close(fd2);  /* ensure fd2 is closed */    
    
    if (fd == fd2) {   /* return if fd2 is fd */
        return fd2;
    }
    
   return fcntl(fd, F_DUPFD, fd2); /* fcntl function to duplicate */


}

int main(int argc, char *argv[]) {

    if (argc != 3) {                                    /* ensure we get ./program dup_num file_name */
        printf("Error with number of arguments.\n");
        exit(EXIT_FAILURE);
    }

    int newfd = atoi(argv[1]); /* vars stored in argv */
    char *file = argv[2];

    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644); /* open file */
    if (fd == -1) {
        perror("open"); 
        exit(EXIT_FAILURE);
    }

    printf("old fd: %d\n", fd);

    int dupResult = my_dup2_with_fcntl(fd, newfd);   /* execute my_dup2 */

    if (dupResult == -1) {
        printf("Error with dup2.");
        exit(EXIT_FAILURE);
    }

    char fd_path[256];
    snprintf(fd_path, sizeof(fd_path), "/proc/self/fd/%d", newfd); /* formats string /proc/self/fd/newfd to fd_path var */

    printf("%s\n", fd_path);

    char buf[256];
    ssize_t length = readlink(fd_path, buf, sizeof(buf) - 1); /* reads contents of symbolic link in fd_path and stores in buf */


    if (length == -1) {        /* didn't properly read contents bc sizeof(buf) == 0 */
        printf("Error with readlink.");
        exit(EXIT_FAILURE);
    }
    else {
        buf[length] = '\0';        /* terminate cstring */
        printf("new duped fd as requested: %d\n", newfd);
        printf("new fd file path:%s\n", buf);
    }
    close(fd); /* close */

    return 0;

}

