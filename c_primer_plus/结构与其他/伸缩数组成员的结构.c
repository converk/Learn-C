//伸缩数组成员的结构,一般声明不会声明变量,而是会声明指针,然后用malloc分配空间mnjdjbnjhhjj

#include<stdio.h>
#include<stdlib.h>

struct flex{
    size_t count;
    double average;
    double scores[];  //伸缩数组成员
};

void showflex(const struct flex * pf);

int main(int argc, char const *argv[])
{
    struct flex *pf1;
    int n=5;
    int i;
    int totle=0;

    //分配空间
    pf1=malloc(sizeof(struct flex)+n*sizeof(double));  //scores的大小为n
    pf1->count=n;
    for (i=0;i<n;i++){
        pf1->scores[i]=20.0-i;
        totle+=pf1->scores[i];
    }
    pf1->average=totle/n;
    showflex(pf1);
    free(pf1);

    return 0;
}

void showflex(const struct flex *pf){
    int i;
    fputs("Scores: ",stdout);
    for(i=0; i<pf->count; i++)
        printf("%.1f ",pf->scores[i]);
    printf("\nAvange: %.1f\n", pf->average);
}