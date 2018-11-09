#include<stdio.h>

int main(void){
    int zippo[4][2]={{1,2},{3,4},{5,6},{7,8}};

    int (*pz)[2];
    pz=zippo;

    printf("  pz=%p,    pz+1= %p\n", pz,pz+1);
    printf("pz[0]= %p, pz[0]+1=%p\n", pz[0],pz[0]+1);
    printf("*pz= %p, *pz+1=%p\n", *pz, *pz + 1);
    printf("   pz[2][1]= %d", pz[2][1]);
    printf("   *(*(pz+2)+1)= %d", *(*(pz + 2) + 1));

    return 0;
}