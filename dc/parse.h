struct date_struct {
    short int year;
    short int month;
    short int day;
};

typedef struct date_struct date;

short int is_num_only(char*);
short int is_leap_year(int);
short int get_year(char*);
short int get_month(char*);
short int get_day(char*);
date construct_date(char*);
