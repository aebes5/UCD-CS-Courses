#include <signal.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* track for ctrlc reset and staggered 3-3-8 alarm */
int count = 0;
int ctrlc_count = 0;

/* get a date in MM/DD/YYYY format and perform calculations */
void daysLeft(const char* input_date) {
    /* track current time */
    time_t current_time;
    struct tm* tmp;
    time(&current_time);
    char str_buf[100];
    /* get local time */
    tmp = localtime(&current_time);

    struct tm input_tmp = {0};
    time_t input_sec;
    /* parse date to struct */
    sscanf(input_date, "%d/%d/%d", &input_tmp.tm_mon, &input_tmp.tm_mday, &input_tmp.tm_year);
    /* account for year since 1900 and month index beginning at 0 */
    input_tmp.tm_year = input_tmp.tm_year - 1900;
    input_tmp.tm_mon = input_tmp.tm_mon - 1;
    
    input_sec = mktime(&input_tmp);
    /* output current date/time*/
    strftime(str_buf, sizeof(str_buf), "Current date and time: %F %A %r, %Z\n", tmp);
    printf("%s", str_buf);
    /* get difference accounting for time zone */
    time_t sec_diff = input_sec - current_time - 3600;

    struct tm* diff_tm = gmtime(&sec_diff);
    /* output, extra hour for christmas because of daylight savings */
    if (strcmp(input_date, "07/04/2024") == 0) {
        printf("Until 2024 Independence Day: %d Days, %d Hours, %d Minutes, %d Seconds\n", diff_tm->tm_yday, diff_tm->tm_hour, diff_tm->tm_min, diff_tm->tm_sec);
    }
    else {
        printf("Until 2024 Christmas Day: %d Days, %d Hours, %d Minutes, %d Seconds\n", diff_tm->tm_yday, diff_tm->tm_hour + 1, diff_tm->tm_min, diff_tm->tm_sec);
    }
    printf("Total number of seconds: %i\n", (int) sec_diff);
}
/* in case of SIGINT( ^C) */
void sigintHandler(int signum) {
    /* pause the alarm execution */
    int prev_alarm = alarm(0);
      
    printf("%i By SIGINT:\n", count);
    daysLeft("07/04/2024");
    count++;
    ctrlc_count++;
    /* restore default ctrl c after 3 times */
    if (ctrlc_count == 3) {
        signal(SIGINT, SIG_DFL);
    }
    /* exit if Y/y, continue otherwise */
    char input;
    printf("Quit (y/n)? ");
    scanf(" %c", &input);
    if (input == 'Y' || input == 'y') {
        exit(signum);
    }
    /* resume previous alarm */
    alarm(prev_alarm);
}
/* SIGALRM */
void sigalrmHandler(int signum) {
    printf("%i By SIGALRM:\n", count);
    daysLeft("12/25/2024");
    count++;
}
/* driver */
int main() {
    /* error handling */
    if (signal(SIGINT, sigintHandler) == SIG_ERR) {
        printf("signal(SIGINT) error\n");
    }

    if (signal(SIGALRM, sigalrmHandler) == SIG_ERR) {
        printf("signal(SIGALRM) error\n");
    }
    /* execute alarm at start of program, pause for alarm execution */
    alarm(1);
    pause();

    while (1) {
        /* 8 second alarm every 3 */
          if (count % 3 == 2) {
              alarm(8);
              pause();
              
          }
        /* default 3 second alarm */
          else {
              alarm(3);
              pause();
          }
    } 
    return 0;
}

