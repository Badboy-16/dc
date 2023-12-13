#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YEAR_STR_LEN 4
#define MONTH_STR_LEN 2
#define DAY_STR_LEN 2
#define FORMAT_ERROR_CODE -1
#define MAX_MONTH 12
#define LEAP_FEB_DAYS 29
#define NORMAL_FEB_DAYS 28
#define SHORT_MONTH_DAYS 30
#define LONG_MONTH_DAYS 31

#define WELCOME_MSG "Count number of days between two dates.\n"
#define FIRST_DATE_INPUT "Enter the first date (earlier) in format yyyymmdd: "
#define SECOND_DATE_INPUT "Enter the second date (later) in format yyyymmdd: "
#define WRONG_FORMAT_MSG "Wrong format. Usage: yyyymmdd\n"
#define RESULT_MSG "Number of days between them: %d.\n"

struct date_struct {
    short int year;
    short int month;
    short int day;
};

typedef struct date_struct date;

short int is_num_only(char*);
short int is_leap_year(int);
short int is_eight_digits(char*);
int get_year(char*);
short int get_month(char*);
short int get_day(char*);
date construct_date(char*);
short int date_struct_is_valid(date);
short int get_max_day(int, short int);
int calc_days_between(date, date);
