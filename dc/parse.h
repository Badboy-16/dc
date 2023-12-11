#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORMAT_ERROR_MSG "Wrong date format."
#define YEAR_STR_LEN 4
#define MONTH_STR_LEN 2
#define DAY_STR_LEN 2
#define FORMAT_ERROR_CODE -1

struct date_struct {
    short int year;
    short int month;
    short int day;
};

typedef struct date_struct date;

short int is_num_only(char*);
short int is_leap_year(int);
short int is_eight_digits(char*);
short int get_year(char*);
short int get_month(char*);
short int get_day(char*);
date construct_date(char*);
int date_is_valid(date);
short int get_max_day(short int, short int);
int calc_days_between(date, date);
