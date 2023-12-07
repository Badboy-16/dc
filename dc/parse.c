#include "parse.h"

/* Check if a string only has numeric char */
short int is_num_only(char* string) {
    while (*string != '\0') {
        if (isdigit(*string) == 0) {
            return 0;
        }
        string++;
    }
    return 1;
}

/* Check if a year is leap year */
short int is_leap_year(int year) {
    if (year % 4 != 0) {
        return 0;
    }
    else if (year % 100 != 0) {
        return 1;
    }
    else if (year % 400 != 0) {
        return 0;
    }
    else {
        return 1;
    }
}

/* Parse and return the year from user input of yyyymmdd */
short int get_year(char* input_date) {
    if (strlen(input_date) != 8 || is_num_only(input_date) == 0) {
        return FORMAT_ERROR_CODE;
    }
    char year_str[YEAR_STR_LEN];
    short int year;
    for (int i = 0; i < 4; i++) {
        year_str[i] = input_date[i];
    }
    year = atoi(year_str);
    return year;
}

/* Parse and return the month from user input of yyyymmdd */
short int get_month(char* input_date) {
    if (strlen(input_date) != 8 || is_num_only(input_date) == 0) {
        return FORMAT_ERROR_CODE;
    }
    char month_str[MONTH_STR_LEN];
    short int month;
    for (int i = 0; i < 2; i++) {
        month_str[i] = input_date[i + 4];
    }
    month = atoi(month_str);
    if (month < 1 || month > 12) {
        return FORMAT_ERROR_CODE;
    }
    return month;
}

/* Parse and return the day from user input of yyyymmdd */
short int get_day(char* input_date) {
    if (strlen(input_date) != 8 || is_num_only(input_date) == 0) {
        return FORMAT_ERROR_CODE;
    }
    char day_str[DAY_STR_LEN];
    short int day;
    for (int i = 0; i < 2; i++) {
        day_str[i] = input_date[i + 6];
    }
    day = atoi(day_str);
    short int year = get_year(input_date);
    short int month = get_month(input_date);
    if (year == FORMAT_ERROR_CODE || month == FORMAT_ERROR_CODE) {
        return FORMAT_ERROR_CODE;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) {
            return FORMAT_ERROR_CODE;
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day < 1 || day > 31) {
            return FORMAT_ERROR_CODE;
        }
    }
    else if (month == 2) {
        if (is_leap_year(year) == 1) {
            if (day < 1 || day > 29) {
                return FORMAT_ERROR_CODE;
            }
        }
        else {
            if (day < 1 || day > 28) {
                return FORMAT_ERROR_CODE;
            }
        }
    }

    return day;
}

/* Construct a date struct from user input of yyyymmdd */
date construct_date(char* input_date) {
    short int year = get_year(input_date);
    short int month = get_month(input_date);
    short int day = get_day(input_date);
    date date_struct;
    date_struct.year = year;
    date_struct.month = month;
    date_struct.day = day;
    return date_struct;
}

/* Check if date struct is valid */
int date_is_valid(date date_struct) {
    if (date_struct.year != FORMAT_ERROR_CODE && date_struct.month != FORMAT_ERROR_CODE && date_struct.day != FORMAT_ERROR_CODE) {
        return 1;
    }
    return 0;
}
