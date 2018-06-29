#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct old{
char old_user[10];
};
/*******************************structure for student record*****************************************************************************/
typedef struct rec{
char id[7];
char name[20];
char f_name[10];
char roll_no[3];
char address[10];
char faculty[10];
char level[10];
char phone_no[10];
char email[10];

}student;

/********************************structure for marksheet*******************************************************************************/
struct sub{
    int math;
    int sci;
    int com;
    int eng;
    int nep;
    };
 struct std
    {
      char  nam[10];
      int per;
      int total;
      char id[10];
      struct sub marks;
    };

    struct std no[50];
/*********************************************************************************************************************************/
void login();
void home_menu(void);
void information(student *);  //function
void datastore(student *);   //function
void account(void); //to change id and password
void user_verification(struct old *); //user verification to change password
void search(void);
void rewrite(student *);
void del(void);
void marksheet(void);
void about(void);
void  main()
{

login();




}

//taking information of the student

void information(student *std){

FILE *fp;
 char fname[10];
int i;
char o; //option for erasing and  crating new data

 loop3:

 printf("\n\n\tenter the id no.\t");
 scanf("%s",(*std).id);

 strcpy(fname,(*std).id);
  strcat(fname,".txt");
   fp=fopen(fname,"r");

   if(fp !=NULL)
   {
       printf("\n\n\t\tsorry student id error");
      printf("\n\t\t\t e r r o r  : student id already exist");
      loop6:
       printf("\n\n do you want to erase and crate new one \n");
       printf("enter y for yes and n for no\t");
       scanf(" %c",&o);

       switch(o){
     case 'y':
           goto loop7;
           break;
     case 'n':
         goto loop3;
         break;
     default:
       {
        printf("\n\n\t\tsorry!!wrong choice  ");
        printf("\n\n\t\t");
        system("pause");
        system("cls");
        goto loop6;
       }

       }



   }

loop7:
  printf("\n\n\n\tenter the name of the student\t\t");
 scanf("%s",(*std).name);
    printf("\n\n\n\tenter the father's name of the student\t\t");
 scanf("%s",(*std).f_name);
  printf("\n\n\n\t enter the roll no. of the student\t\t");
  scanf("%s",(*std).roll_no);

 printf("\n\n\n\tenter the address of the student \t\t");
 scanf("%s",(*std).address);
  printf("\n\n\n\tenter the  faculty   of the student \t\t");
  scanf("%s",(*std).faculty);
  printf("\n\n\n\tenter the level of the student\t\t");
   scanf("%s",(*std).level);
  printf("\n\n\n\tenter the  mobile no. of the student \t\t");
  scanf("%s",(*std).phone_no);

printf("\n\n\n\tenter the email address of the student\t\t");
 scanf("%s",(*std).email);

}

//data input to the file
void datastore(student *std)
{
  FILE *fp;
  char fname[10];
int i;

/*******************conversion of integer into string************/
  char snum[10];



  strcpy(fname,(*std).id);
  strcat(fname,".txt");

  fp=fopen(fname,"w");

/****************************************************************/



  if(fname==NULL)
  {
      puts("sorry no file found ");
      exit(1);
  }

       fputs("\n\n\t\t ID:  ",fp);
      fputs((*std).id,fp);

       fputs("\n\t\t name:  ",fp);
      fputs((*std).name,fp);

         fputs("\t\t\t father's name:  ",fp);
      fputs((*std).f_name,fp);

       fputs("\n\t\t Rollno:  ",fp);
      fputs((*std).roll_no,fp);

       fputs("\t\t\t Address:  ",fp);
      fputs((*std).address,fp);
       fputs("\n\t\t Faculty:  ",fp);
      fputs((*std).faculty,fp);
         fputs("\t\t\t Level:  ",fp);
      fputs((*std).level,fp);
       fputs("\n\t\t email:  ",fp);
      fputs((*std).email,fp);
         fputs("\t\t\t mobile no:  ",fp);
      fputs((*std).email,fp);



fclose(fp);
printf("\n\n\t\tdata entry successful \n\n\n");
system("pause");


}






void search(void){
    char fname[10];
    char option;
    FILE *fp;
    loop9:
        system("cls");
    printf("\n\n\t\tenter the id of the student:\t");
    scanf("%s",fname);
     printf("\t--------------------------------------------------------------------\n\n\n\t\t\t");
    strcat(fname,".txt");
     fp=fopen(fname,"r");
    if(fp==NULL)
    {

        printf("no file found\n\n\n\n\t\t\t");
        system("pause");
        printf("\n\n enter 'h' to goto home_menu and and single key to re-enter id \n\n\t\t ");
          scanf(" %c",&option);
          switch(option){
      case 'h':
          home_menu();
      default:
         goto loop9;

          }

    }
    while(1){
            if(feof(fp)){

                break;

            }
    int c=getc(fp);
    printf("%c",c);
    }
printf("\n\n\n\t\t\t");

}

void home_menu(void)
{
int option,op;
char opt;//option for delete or edit data file
student *std , std1;
std=&std1;

 loop4:
     system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tCHOOSE THE  OPTION GIVEN BELOW ");
        printf("\n\t\t\t\t\t\t---------------------------------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t(HOME_MENU)");
        printf("\n\n\t\t\t\t\t\t\t1.data_entry");
        printf("\t\t2.search");
        printf("\t\t3.edit");
        printf("\n\n\t\t\t\t\t\t\t4.marksheet");
        printf("\t\t5.change login username and password ");
        printf("\n\n\t\t\t\t\t\t\t6.about");
        printf("\t\t\t7.exit");
        printf("\n\n\t\t\t\t\t\t\t");
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
         system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\twhat do you want to do\n ");
        printf("\t\t\t\t\t\t\t  ------------------------------------------------------------");
        printf("\n\n\t\t\t\t\t\t\t\t\t1.re-entry    2.home_menu");
        printf("\n\n\t\t\t\t\t\t\t\t3.search      4.exit \n\n\t\t\t");
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
              printf("\n\n\t\tsorry!! you have entered wrong value \n\n\n\n");
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
            loop8:
            system("cls");
           printf("\n\n\t\t do you want to rewrite or delete the database");
           printf("\n\n\t\t press 'r' for rewrite and 'd' for delete\t");
           scanf(" %c",&opt);
   switch(opt){
   case 'r':
        rewrite(std);
        break;
   case 'd':
        del();
        break;
   default:
      printf("\nwrong input\n\n\n");
      system("pause");
      goto loop8;
   }
            break;
        }
     case 4:
          {
          system("cls");
          marksheet();
          system("pause");
         goto loop4;
          }
     case 5:
        {

          account();
            printf("user_name and password successfully changed");
            system("pause");
            goto loop4;

        }
     case 6:
          {
          system("cls");
         about();
          goto loop4;
          }
      case 7:
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
   }

}

void about()
{
    printf("\n\n student database management system and marksheet generator software");

    printf("\n\n version v2 \n\n\n");

    printf("\n\n-this application software is developed as the project work of c programming language  ");

    system("pause");

}

void marksheet(void)
{
    int ns,nsb,i,j,div;
    char str_per[10];
    char o;
    char sub[5][10];
    char faculty[10];
    char level[5];
   FILE *fp;
     printf("\n\n\n\t\t\t\t\t\tenter the  faculty:  ");
     scanf("%s",faculty);
     printf("\n\n\t\t\t\t\t\tenter the level :  ");
     scanf("%s",level);
    printf("\n\n\t\t\t\t\t\tenter the no. of students:  ");
    scanf("%d",&ns);

  printf("\n\n\t\t\t\t\t\tenter subject name(4 letters ):\n");
for(i=0;i<5;i++)
{
    printf("\t\t\t\t\t\t\t\t\t\t");
    scanf("%s",sub[i]);

}
system("cls");
    for (i=0;i<ns;i++)
    {

       printf("\n\n\t\t\t\t\t\t\t\t\t enter the id of the student:   ");
         scanf("%s",&no[i].id);
          strcat(no[i].id,".txt");

     printf("\t\t\t\t\t\t\t\t\t enter the name of  student :   ") ;
       scanf("%s",&no[i].nam);

       printf("\t\t\t\t\t\t\t\t\t enter the marks of :\n");
       printf("\t\t\t\t\t\t\t\t----------------------------------------------------------------\n");
       printf("\t\t\t\t\t\t\t\t\t\t %s :    ",sub[0]);
       scanf("%d",&no[i].marks.eng);

       printf("\t\t\t\t\t\t\t\t\t\t %s :   ",sub[1]);
       scanf("%d",&no[i].marks.math);

       printf("\t\t\t\t\t\t\t\t\t\t %s :   ",sub[2]);
       scanf("%d",&no[i].marks.sci);

       printf("\t\t\t\t\t\t\t\t\t\t %s :   ",sub[3]);
       scanf("%d",&no[i].marks.nep);

       printf("\t\t\t\t\t\t\t\t\t\t %s :   ",sub[4]);
       scanf("%d",&no[i].marks.com);
}


system("cls");
printf("\n\n\n\n");
printf("  \t :::::::::::::::::::::::::::::::::::::::::/\\ :::::/\\:::::::::::::::::::::::::::::::::::::::::::\n");
printf("    \t  :::::::::::::::::::::::::::::::::::: //\\\\ :://\\\\ARKSHEET:::::::::::::::::::::::::::\n");
printf("   \t::::::::::::::::::::::::::::::::::::::://: \\\\//::\\\\::::::::::::::::::::::::::::::::::::::::\n\n\n");
printf("\t\tF A C U L T Y   :%s\n",faculty);
printf("\t\t    L E V E L   :%s",level);
printf(" \n\n __________________________________________________________________________________________________________________\n");
printf(" |  NAME OF STUDENTS   |  %s  |  %s  | %s     |     %s  |     %s  | TOTAL marks | PERCENTAGE | DIVISION  |\n",sub[0],sub[1],sub[2],sub[3],sub[4],sub[5]);
printf("  __________________________________________________________________________________________________________________\n");
printf(" |                     |        |        |          |           |           |             |            |           |\n");
for (i=0;i<ns;i++)
{
    no[i].total=no[i].marks.eng+no[i].marks.math+no[i].marks.sci+no[i].marks.nep + no[i].marks.com;
     no[i].per= no[i].total /5;
     div=no[i].per;

     if (div>=80 && no[i].marks.eng>=32 && no[i].marks.sci >=32 && no[i].marks.nep>=32 && no[i].marks.com>=32 && no[i].marks.math >=32)
     {


printf(" |%21.7s|%8d|%8d|%10d|%11d|%11d|%12d |%10d %%|   dist    |  \n",no[i].nam,no[i].marks.eng,no[i].marks.math,no[i].marks.sci,no[i].marks.nep,no[i].marks.com,no[i].total,no[i].per);
}
else if (div<80 && div>=60 && no[i].marks.eng>=32 && no[i].marks.sci >=32 && no[i].marks.nep>=32 && no[i].marks.com>=32 && no[i].marks.math >=32)
     {


printf(" |%21.7s|%8d|%8d|%10d|%11d|%11d|%12d |%10d %%|   first   |  \n",no[i].nam,no[i].marks.eng,no[i].marks.math,no[i].marks.sci,no[i].marks.nep,no[i].marks.com,no[i].total,no[i].per);
}
else if (div <60 && div>=50 && no[i].marks.eng>=32 && no[i].marks.sci >=32 && no[i].marks.nep>=32 && no[i].marks.com>=32 && no[i].marks.math >=32)
     {


printf(" |%21.7s|%8d|%8d|%10d|%11d|%11d|%12d |%10d %%|  second   |  \n",no[i].nam,no[i].marks.eng,no[i].marks.math,no[i].marks.sci,no[i].marks.nep,no[i].marks.com,no[i].total,no[i].per);
}
else if (div<50 && div>=40 && no[i].marks.eng>=32 && no[i].marks.sci >=32 && no[i].marks.nep>=32 && no[i].marks.com>=32 && no[i].marks.math >=32)
     {


printf(" |%21s|%8d|%8d|%10d|%11d|%11d|%12d |%10d %%|   third   |  \n",no[i].nam,no[i].marks.eng,no[i].marks.math,no[i].marks.sci,no[i].marks.nep,no[i].marks.com,no[i].total,no[i].per);
}
else
     {


printf(" |%21.7s|%8d|%8d|%10d|%11d|%11d|%12d |%10d %%|    fail   |  \n",no[i].nam,no[i].marks.eng,no[i].marks.math,no[i].marks.sci,no[i].marks.nep,no[i].marks.com,no[i].total,no[i].per);
}
printf(" ------------------------------------------------------------------------------------------------------------------\n");
}
 loop:

printf("\n\n\n\t\tdo you want to store the record in the data base ?");
printf("\npress y/Y for yes and n/N for no  and 'e' to exit the program \t");

scanf(" %c",&o);
switch(o){

case 'y':
          {
               loop_y:
               for (i=0;i<ns;i++){

                fp=fopen(no[i].id,"r");

                if(fp==NULL)
                {
                    printf("no file with id %s",no[i].id);
                    continue;
                }
                else{
                        fclose(fp);
                fp=fopen(no[i].id,"a");
            fputs("\n\t\t\t\t percentage:  ",fp);
                     itoa(no[i].per,str_per,10);
                     fputs(str_per,fp);
                     fclose(fp);

                }
               }
               break;
          }
case 'Y':
    goto loop_y;
    break;
case'n':
    home_menu();
case'N':
    home_menu();
case 'e':
    exit(1);
    {
        exit(1);
    }
default:
    printf("sorry!! you have entered wrong choice");
    goto loop;




}


}



void rewrite(student *std){

FILE *fp;
 char fname[10];
int i;
char o; //option for erasing and  crating new data

 loop3:

 printf("\n\n\tenter the id no.\t");
 scanf("%s",(*std).id);

 strcpy(fname,(*std).id);
  strcat(fname,".txt");
   fp=fopen(fname,"w");

   if(fp==NULL)
   {
      printf("sorry !! failed to create a new file");
      system("pause");
        exit(1);
       }
  printf("\n\n\n\tenter the name of the student\t\t");
 scanf("%s",(*std).name);
    printf("\n\n\n\tenter the father's name of the student\t\t");
 scanf("%s",(*std).f_name);
  printf("\n\n\n\t enter the roll no. of the student\t\t");
  scanf("%s",(*std).roll_no);

 printf("\n\n\n\tenter the address of the student \t\t");
 scanf("%s",(*std).address);
  printf("\n\n\n\tenter the  faculty   of the student \t\t");
  scanf("%s",(*std).faculty);
  printf("\n\n\n\tenter the level of the student\t\t");
   scanf("%s",(*std).level);
  printf("\n\n\n\tenter the  mobile no. of the student \t\t");
  scanf("%s",(*std).phone_no);

printf("\n\n\n\tenter the email address of the student\t\t");
 scanf("%s",(*std).email);

 datastore(std);
}
void del(void){
FILE *fp;

    char file_name[10];
    char id[10];
 printf("\n\n\tenter the id no.\t");
 scanf("%s",id);
  strcpy(file_name,id);
  strcat(file_name,".txt");
 // fp=fopen(file_name,"r");

  //if(fp==NULL)  /*********************************************************************************/
        {
   //   printf("sorry!! file doesn't exist\n\t\t");
   //   system("pause");
   //   home_menu();
 // }
 // else{
  //    fclose(file_name);

  remove(file_name);

  printf("file successfully removed\n\t\t");
  system("pause");

  home_menu();


}
}
void login()
{
    FILE *fp;
    char user_name[10];
    char password[10];
    char pw[10];
    char option;
    loop:
        system("cls");
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tU S E R   L O G I N    ");
        printf("\n\t\t\t\t\t\t\t-----------------------------------------------\n");
    printf("\n\n\t\t\t\t\t\t\t\tENTER USER NAME :");
    scanf("%s",user_name);

    strcat(user_name,".txt");
     fp=fopen(user_name,"r");
     fgets(pw,10,fp);

 if(fp !=NULL){
loop2:
printf("\n\t\t\t\t\t\t\t\tENTER PASSWORD:");
scanf("%s",password);
	if(strcmp(password,pw) == 0)
	{
	     home_menu();

		system("pause");
	}
	else{
          printf("user name and password doesnt match\n");
          system("pause");
          printf("press 'e' to exit  and any other single character to re-enter password ");
          scanf(" %c",&option);
          switch(option){
      case 'e':
        exit(1);
      default:
        goto loop2;

          }

	}
    }

 else{

     printf("U S E R -- N A M E--NOT FOUND ");
        system("pause");
     goto loop;
 }
 }


void account(void){
    char old_user[10];
    char file_name[10];
char user[10];
char password[10];
FILE *fp;
struct old *u,olduser;
u=&olduser;

user_verification(u);
printf("enter new user_name (less than 10 letters) : \t");
scanf("%s",&user);
printf("enter new password (less than 10 letters : \t");
scanf("%s",&password);

strcat(user,".txt");
printf("%s",(*u).old_user);
system("pause");
strcpy(file_name,(*u).old_user);
printf("file name :%s",file_name);
system("pause");
remove(file_name); //old user removed
remove(file_name);


fp=fopen(user,"w");
if(fp==NULL)
{
    printf("error to create new file");
}
printf("%s",password);
system("pause");
    fputs(password,fp);
    fclose(fp);
system("pause");

}










void user_verification(struct old *name){

 FILE *fp;
    char user_name[10];
    char password[10];
    char pw[10];
    char option;
    char option2;
    loop:
        system("cls");
    printf("ENTER old USER NAME :");
    scanf("%s",(*name).old_user);

    strcat((*name).old_user,".txt");
     fp=fopen((*name).old_user,"r");
     fgets(pw,10,fp);

 if(fp !=NULL){
loop2:
printf("ENTER PASSWORD:");
scanf("%s",password);
	if(strcmp(password,pw) != 0)
	{
          printf("user name and password dont match\n");
          system("pause");
          printf("press 'h' to goto home menu  and any other single character to re-enter password ");
          scanf(" %c",&option);
        switch(option)
          {
              case 'h':
              home_menu();
        default:
            goto loop2;
        }
	}
    }


 else{

     printf("U S E R  name unknown \n\n\n");
        system("pause");
     system("cls");
     loop3:
     printf("enter 'r' to re-entre user name and 'h' to goto home_menu");
     scanf(" %c",&option2);
     switch(option2){
 case 'r':{
       system("cls");
    goto loop;
 }
 case 'h':
    system("cls");
     home_menu();

 default:
    printf("you have entered wrong option");
    system("pause");
    goto loop3;
 }
 }
}





