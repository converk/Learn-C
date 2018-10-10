#include<stdio.h>
#include"hotel.h"

int main(int argc, char const *argv[]){
    double rate;
    int code;
    int night;

    
    while((code=menu())!=QUIT){
        
        switch (code)
        {
            case 1:
                rate = HOTEL1;
                break;
            case 2:
                rate = HOTEL2;
                break;
            case 3:
                rate = HOTEL3;
                break;
            case 4:
                rate = HOTEL4;
                break;
            default:
                break;
        }
        night=getnights();
        showprice(rate,code);
    }
    printf("Thank you for using");
    
    return 0;
}
