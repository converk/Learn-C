/*判断温度*/
#include<stdio.h>

int main(void){
    const int FREEZING=0;
    float temp;
    int cold_days=0,all_days=0;

    while(scanf("%f",&temp) == 1){
        all_days++;
        if (temp<FREEZING){
            cold_days++;
        }
    }

    if (all_days){
        printf("%d days total: %.1f%% were below", all_days,100.0*cold_days/all_days);
    }
    return 0;
}