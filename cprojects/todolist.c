#include<stdio.h>
#include<string.h>
void add_task(char [][100],int*);
void view_task(char [][100],int);
void del_task(char [][100],int*);
int main()
{
    char task[50][100];
    int choice,count=0;
    while(1)
    {
    printf("\n___To Do List__\n");
    printf("1. Add Task\n2. View Tasks\n3. Delete Task\n4. Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    if(choice==4)
    break;
    switch (choice)
    {
        case 1:
        add_task(task,&count);
        break;
        case 2:
        view_task(task,count);
        break;
        case 3:
        del_task(task,&count);
        break;
        default :
        printf("Please enter a valid choice\n");
        break;
    }
    }
    return 0;
}
void add_task(char task[][100],int *l)
{
  printf("\nEnter The Task Here:");
  scanf("%s",&task[*l]);
  printf("\nTask Added\n");
(*l)++;
}
void view_task(char task[][100],int l)
{   
    printf("\nAvailable Tasks :\n");
    for(int i=0;i<l;i++)
    {
        printf("%d. %s\n",i+1,task[i]);
    }
    printf("Total number of task= %d",l);
}
void del_task(char task[][100],int *l)
{
  if(*l==0){
  printf("No tasks to delete");
  return;
  }
  int del;
  printf("Enter the Task number to delete:");
  scanf("%d",&del);
  if(del<1||del>*l){
    printf("Not a valid Task index");
    return;
  }
  
for(int i=del-1;i<*l-1;i++)
{
    strcpy(task[i],task[i+1]);
}
 (*l)--;
 printf("Task %d Deleted successfully",del);
}