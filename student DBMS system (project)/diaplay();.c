#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void main()
{

   FILE *fp;
   int i ;


    fp=fopen("wb.sum","wb+");
    if(fp==NULL)
    {

        printf("no file created");
        system("pause");
    }
   fprintf(fp,"this is the text file");
   fclose(fp);
    fp=fopen("data.sum","r");
    if(fp==NULL)
    {

        printf("no file found");
        system("pause");
    }
    for(i=0;i<50;i++){
    int c=getc(fp);
    printf("%c",c);
    }

}
