#include<stdio.h>
#include<math.h>

int main(){
    const float PI = 3.14159;
    float answer;
    printf(" what is the value of PI?");
    scanf("%f", &answer);

    while(fabs(answer-PI)>0.0001){
        /* code */
        printf("try again\n");
        scanf("%f", &answer);
    }
    return 0;
}