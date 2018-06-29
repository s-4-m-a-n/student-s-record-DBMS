 #include<stdio.h>
 void main(){

  FILE *fp;
     int c,i;

   fp=fopen("data.txt","r");

    if(fp==NULL)
    {
        printf("no file found");
        system("pause");

    }
   for(i=0;i<10;i++) {
    c=fgetc(fp);
    printf("%c",fp);
   }
}
