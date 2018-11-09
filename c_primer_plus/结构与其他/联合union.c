//联合union
// #include<stdio.h>

// union hold{
//     int digit;
//     double bigft;
//     char letter;
// };

// int main(void){
//     union hold valA;
//     valA.letter='A';
//     union hold valB = {.letter='a'};
//     union hold valC = {.digit=88}; //注意要加大括号
//     union hold valD = {.bigft = 50}; //当要赋值的类型不是联合的第一个的时候,要使用初始化器
//     printf("%c \n",valB);
//     printf("%d \n",valC);
//     printf("%f \n",valD);

//     return 0;
// }

//联合的另外一种用法
// struct owner{  //车没有租出去,拥有者的名字
//     char socsecurity[12];
// };

// struct leasecompany{   //车租出去了,租借者和租用公司的名字
//     char name[40];
//     char headquarters[40];
// };

// union data{  //二选一
//     struct owner owncar;
//     struct leasecompany leasecar;
//     /* data */
// };

// struct car_data{
//     char make[15];
//     int status;  //未租借为0,租借为1
//     union data ownerinfo;    //二选一
// };
