#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct rec{
char name[20];
char roll_no[3];
char id[7];
char address[10];
char faculty[10];
int no_of_books;
char  book_name[5][10];
}student;




void home_menu(void);
void information(student *);  //function
void datastore(student *);   //function
void display(void);
void search(void);
void edit(void);

void  main()
{

//char option;
//char nam[10];

//student *std , std1;
//std=&std1;

home_menu();


//system("pause");
//loop:
  // system("cls");
       //stores information in the file "data.txt"






//optionloop:
    //loop for wrong input of the option


/*system("cls");
  printf("\n do you want to enter another data ?");
  printf("\n press y/Y for yes  and n/N for no");
   scanf("%c",&option);


  switch(option)
  {
  case 'y':
    {goto loop;
     break;}
  case'Y':
    {goto loop;
     break;}
  case 'n':
      break;
  case  'N':
       break;
  default:
   {

    goto optionloop; }


  } */
}

//taking information of the student

void information(student *std){

FILE *fp;
 char fname[10];
int i;





  printf("\n\n\n\tenter the name of the student\t");
 scanf("%s",(*std).name);

  printf("\n\n\t enter the roll no. of the students\t");
  scanf("%s",(*std).roll_no);




 loop3:

 printf("\n\n\tenter the id no.\t");
 scanf("%s",(*std).id);

 strcpy(fname,(*std).id);
  strcat(fname,".txt");
   fp=fopen(fname,"r");

   if(fp !=NULL)
   {
       printf("sorry student id error");
       goto loop3;
   }


 printf("\n\tenter the address of the students \t\t");
 scanf("%s",(*std).address);
  printf("\n\tenter the  faculty and level  of the students \t\t");
  scanf("%s",(*std).faculty);
  printf("enter the no of book taken");
  scanf("%d",&(*std).no_of_books);

  printf("enter the name of the book");
  for(i=0;i<((*std).no_of_books);i++)
  {
      scanf("%s",(*std).book_name[i]);
  }


}

//data input to the file
void datastore(student *std)
{
  FILE *fp;
  char fname[10];
int i;

/*******************conversion of integer into string************/
  char snum[10];

   itoa((*std).no_of_books,snum,10);

  strcpy(fname,(*std).id);
  strcat(fname,".txt");

  fp=fopen(fname,"w");

/****************************************************************/



  if(fname==NULL)
  {
      puts("sorry no file found ");
      exit(1);
  }


       fputs("\n\t\t\t\t name:  ",fp);
      fputs((*std).name,fp);


       fputs("\n\t\t\t\t Rollno:  ",fp);
      fputs((*std).roll_no,fp);
         fputs("\n\t\t\t\t ID:  ",fp);
      fputs((*std).id,fp);
       fputs("\n\t\t\t\t Address:  ",fp);
      fputs((*std).address,fp);
       fputs("\n\t\t\t\t Faculty:  ",fp);
      fputs((*std).faculty,fp);
       fputs("\n\t\t\t\t no.of books:  ",fp);
       fputs(snum,fp);
      fputs("\n\t\t\t\t name of books takens: ",fp);

     for(i=0;i<((*std).no_of_books);i++){
        fprintf(fp,"%d",i+1);
         fprintf(fp," %s\t",(*std).book_name[i]);
       }


fclose(fp);


}




void display(void){
     FILE *fp;
   int i ;
    fp=fopen("data.txt","r");
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

void search(void){
    char fname[10];
    FILE *fp;
    printf("enter the id of the student");
    scanf("%s",fname);
    strcat(fname,".txt");
     fp=fopen(fname,"r");
    if(fp==NULL)
    {

        printf("no file found");
        system("pause");
    }
    while(1){
            if(feof(fp)){

                break;

            }
    int c=getc(fp);
    printf("%c",c);
    }


}

home_menu(void)
{
int option,op;
student *std , std1;
std=&std1;

 loop4:
     system("cls");
        printf("\n\n\t\t choose the option given below ");
        printf("\n\n\t1.data_entry");
        printf("\t\t2.search");
        printf("\t\t3.edit");
        printf("\n\n\t4.marksheet");
        printf("\t\t5.about");
        printf("\n\n\t6.exit");
        printf("\n\n\t\t");
   scanf("%d",&option);

   switch(option)
   {
   case 1:
      {

loop5:
        system("cls");
        information(std); //takes information
        datastore(std);
loop7:
        printf("what do you want to do ");
        printf("1.re-entry    2.home_menu");
        printf("3.search      4.exit");
        scanf("%d",&op);

switch(op){
      case 1:
        {
            system("cls");
            goto loop5;
        }
      case 2:
        {
            goto loop4;
        }
      case 3:
          {

              goto loop6;

          }
      case 4:
          {
              exit(1);
          }
      default:
          {
              printf("\n\n\t\tsorry!! you have entered wrong value");
              system("pause");
              system("cls");
              goto loop7;
          }
          }




      }
    case 2:
          {
loop6:
          system("cls");
          search();
          system("pause");
          goto loop4;
          }

    case 3:
        {
            system("cls");
            edit();

            system("pause");
            break;
        }
     case 4:
          {
          system("cls");
          printf("sorry ! system under construction");
          system("pause");
         goto loop4;
          }
     case 5:
          {
          system("cls");
         about();
          goto loop4;
          }
      case 6:
          {
          exit(1);
          }
      default:
          {
        printf("\n\n\n\t\t\t sorry ! you have entered wrong value");
        system("pause");
        system("cls");
        goto loop4;
          }
   } *


}
void about()
{

    printf("\n\n version v1 \n\n\n");
    system("pause");

}
/**************************************************************
void edit(void)
{
    FILE *fp;
    int no,i;
    char id[10];
    char name[5][10];
    printf("enter the id of the student");
    scanf("%s",id);
   printf("no of books return");
    scanf("%d",&no);
    printf("name of book returns");
    for(i=0;i<no;i++)
    {
     scanf("%s",name[i]);
    }
    strcat(id,".txt");
fp=fopen(id,"r");
if(fp==NULL)
{
    printf("sorry no file found");
    system("pause");
}
while(1){
    if(feof(fp))
    {
        break;
    }
int   c=getc(fp);
printf("%c",c);


while((fgets(id,10,fp)) != NULL) {

  fscanf(fp,"%s",&id);

  if(strcmp(id,"name")==0){
    printf("A match has been found");
  }
else{
    printf("no word found");
}


}

}
}
********************************************************************************************////
