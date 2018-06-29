#include <stdio.h>
#include <string.h>
typedef struct name{
char name[10];
int roll;

}student;

void display(student *);

void main()
{
  student *rec,rec1;
  rec=&rec1;

  printf("enter your name ");
gets((*rec).name);
  printf("enter your roll no ");
  scanf("%d",&(*rec).roll);
  display(rec);


}
void display(student *rec)
{

    printf("%s",(*rec).name);
    printf("%d",(*rec).roll);
}





