#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

#define DIR_PERM 0777 /* permission and directory macros */
#define DIR_NAME "/export/homes/eberta/tmp/hw3"

int main() {

    if (mkdir(DIR_NAME, DIR_PERM) < 0)  /* ensure mkdir, chdir, rmdir exectue */
        err_sys("mkdir failed");
    if (chdir(DIR_NAME) < 0)
        err_sys("chdir failed");
    if (rmdir(DIR_NAME) < 0)
        err_sys("rmdir failed");


    DIR *direct = opendir("."); /* test . */
    if (direct == NULL) {
        printf("Failed to open .\n");
    }
    else {
        printf("Opened .\n");
    }

    direct = opendir("../hw3"); /* test ../hw3 */
    if (direct == NULL) {
        printf("Failed to open ../hw3\n");
    }
    else {
        printf("Opened ../hw3\n");
    }
    
    direct = opendir(DIR_NAME); /* test DIR_NAME */
    if (direct == NULL) {
        printf("Failed to open %s\n", DIR_NAME);
    }
    else {
        printf("Opened %s\n", DIR_NAME);
    }

    return 0;
}
