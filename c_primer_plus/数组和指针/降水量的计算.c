#include<stdio.h>
#define YEARS 5
#define MONTHS 12

int main(void){
    const int RAIN[YEARS][MONTHS] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
        {1, 2, 3, 4, 5, 4, 7, 8, 1, 10, 1, 12},
        {1, 2, 9, 4, 5, 6, 7, 2, 9, 10, 11, 1},
        {10, 2, 3, 14, 5, 6, 7, 8, 9, 10, 11, 18},
        {11, 21, 31, 4, 5, 6, 7, 8, 0, 10, 11, 12}
    };

    int year,month,i;
    double total,each_year,each_month;
    printf("YEAR  RAINFALL\n");

    for (year=0,total=0.0;year<YEARS;year++){
        for (month=0, each_year=0.0; month<MONTHS; month++){
            each_year+=RAIN[year][month];
        }
        printf("%5d %12.1f\n", 2000+year, each_year);
        total+=each_year;
    }
    printf("\nthe yearly average is %.1f\n", total/YEARS);

    for (i=1; i<=MONTHS; i++)
        printf("%-6d", i);
    printf("\n");
    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0, each_month = 0.0; year < YEARS; year++)
        {
            each_month += RAIN[year][month];
        }
        printf("%-6.1f",each_month);
    }
    printf("\n");
    return 0;
}