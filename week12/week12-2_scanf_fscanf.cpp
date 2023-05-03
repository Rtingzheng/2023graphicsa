#include <stdio.h>
int main()
{
    FILE * fin=fopen("file.txt","r");
    char c[100];
    fscanf(fin,"%s",c);
    printf("±qfileÅª¨ì¤F:%s",c);

    fscanf(fin,"%s",c);
    printf(" %s\n",c);
}
