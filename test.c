#include<stdio.h>
#include<string.h>

void selectsort(char (*)[20],int);
void insert_pust(char (*)[20],int, char *,char *);

int main(){
    char str[6][20]={
        "strcpy",
        "atoi",
        "srand",
        "sqrt",
        "power",
        "librart"
    };
    char pushed[20];
    char move_out[20];
    selectsort(str,6);
    puts("please input a strings");
    for (int i = 0; i < 6; i++)
        printf("%s\n", str[i]);
    fgets(pushed,20,stdin);
    insert_pust(str,6,pushed,move_out);
    printf("%s", move_out);
    return 0;
}

void selectsort(char str[6][20], int num){
    char temp[20];
    int i;
    int j;
    for (i=0;i<5;i++){
        for(j=0;j<5-i;j++){
            if(strcmp(str[j],str[j+1])>0){
                strcpy(temp, str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j + 1],temp);
            }
        }
    }
}

void insert_pust(char str[6][20], int num, char *push, char *move_out){
    int i;
    for (i=0;i<6;i++){
        if (strcmp(push, str[i])<0)
            break;
    }
    if(i==5){
        if(strcmp(push,str[5])<0){
            strcpy(move_out , str[5]);
            strcpy(str[5],push);
        }
        else
            strcpy(move_out,push);
    }else{
        strcpy(move_out, str[5]);
        for(int j=4;j<=i;j++){
            strcpy(str[j+1],str[j]);
            strcpy(str[i],push);
        }
    }

}