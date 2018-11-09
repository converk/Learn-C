//指针与多维数组

#include<stdio.h>

int main(void){
    int zippo[4][2]={{1,2},{3,4},{5,6},{6,7}};

    printf("  zippo =%p,   zippo+1 = %p\n",zippo, zippo+1);
    printf("  zippo[0]= %p, zippo[1]+1= %p\n", zippo[0],zippo[0]+1);
    printf("  *zippo= %p, *zippo+1= %p\n", *zippo,*zippo+1 );
    printf(" *zippo[0]=%d\n", *zippo[0]);
    printf("  **zippo=%d\n", **zippo);
    return 0;

}