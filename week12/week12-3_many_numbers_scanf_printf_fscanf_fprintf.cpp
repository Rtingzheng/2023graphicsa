#include<stdio.h>
int main()
{
    int a[10]={0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int b[10]={90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    FILE*fout=fopen("file3.txt","w");
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
        fprintf(fout,"%d ",a[i]);
    }
    printf("\n");
    fprintf(fout,"\n");
    fclose(fout);
    FILE*fin=fopen("file3.txt","r");
    for(int i=0;i<10;i++)
    {
        fscanf(fin,"%d ",&b[i]);
        printf("b%d:%d ",i,b[i]);
    }
    fclose(fin);
}
