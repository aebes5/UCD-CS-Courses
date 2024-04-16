#include <time.h>
#include <stdio.h>

void timeLeft() {
        
    time_t current_time; /* initialize vars */
    struct tm* tmp;
    time(&current_time);
    char str_buf[100];

    tmp = localtime(&current_time); /* get local time */

    strftime(str_buf, sizeof(str_buf), "Current date and time: %F %A %r, %Z\n", tmp); /* format and output */
    printf("%s", str_buf);

    char input_date[12]; /* initialize for input date */
    time_t input_sec;
    struct tm input_tmp = {0};
    
    printf("Please enter a target date in the future(mm/dd/yyyy): "); /* store input in input_date, note this */ 
    fgets(input_date, sizeof(input_date), stdin);                     /* assumes a perfect input */

    /* parse month, day, year */
    sscanf(input_date, "%d/%d/%d", &input_tmp.tm_mon, &input_tmp.tm_mday, &input_tmp.tm_year);

    input_tmp.tm_year = input_tmp.tm_year - 1900; /* year difference */
    input_tmp.tm_mon = input_tmp.tm_mon - 1; /* indexing begins at 0 */

    input_sec = mktime(&input_tmp); /* total sec */
   

    time_t sec_diff = input_sec - current_time - 3600; /* get diff taking into account extra hour */
    
    struct tm* diff_tm = gmtime(&sec_diff); /* format as struct */

    /* worth noting this is supposed to go years, months, etc. but we just wanted days so I created a shortcut for the days */
    if (input_sec > current_time) {
        printf("%i Days, %i Hours, %i Minutes, %i Seconds\n", (int) sec_diff / 86400, diff_tm->tm_hour, diff_tm->tm_min, diff_tm->tm_sec);
    }
    else { /* account for past datetime, just for fun.. */
        printf("%i Days, %i Hours, %i Minutes, %i Seconds\n", (int) sec_diff / 86400, diff_tm->tm_hour - 23, diff_tm->tm_min - 59, diff_tm->tm_sec - 60);
    }

    int dup_diff = sec_diff; /* EC: substract floor from total remaining seconds for days...hours...minutes...seconds */
    int days = (int)(sec_diff / 86400);
    sec_diff = sec_diff - (((int)(sec_diff / 86400)) * 86400);
    int hours = (int)(sec_diff / 3600);
    sec_diff = sec_diff - (((int)(sec_diff / 3600)) * 3600);
    int minutes = (int)(sec_diff / 60);
    sec_diff = sec_diff - (((int)(sec_diff / 60)) * 60);
    int seconds = (int)(sec_diff);

    printf("%i Days, %i Hours, %i Minutes, %i Seconds(Extra Credit Check)\n", days, hours, minutes, seconds); /* print outputs */
    printf("Total number of seconds of the target date: %i\n", dup_diff);
    
}

int main() {

    timeLeft(); /* execute timeLeft */

    return 0;
}


