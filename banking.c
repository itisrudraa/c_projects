#include<stdio.h>
struct bank{
    int acc_no;
    char name[50];
    char address[100];
    int dob;
    int phone;
    int pin;
    float balance;
};
int main()
{
    struct bank account[100];
    int i=0,mode=1,acno,open,pass,acmode=0,pc;
    float credit,debit;
    do{
    printf("Wlecome to the bank\n");
    printf("Please select the options from the menu below:\n");
    printf("\t\tMenu\n\t\t1. Create Account\n\t\t2.Login to account\n\t\t3. Quit");
    printf("\nPlease enter your choice:");
    scanf("%d",&mode);
    if(mode==1)
    {
        printf("welcome to the account creation page\nyou have to provide some of your details for creating the account\n");
        printf("Please enter your Name:");
        scanf("%s",&account[i].name);
        printf("Please enter your address:");
        scanf("%s",&account[i].address);
        printf("Enter your date of birth in DDMMYY format:");
        scanf("%d",&account[i].dob);
        printf("Please provide your contact number:");
        scanf("%d",&account[i].phone);
        account[i].acc_no=25000+i+1;
        printf("\n\tCongratulations Mr %s your account has been created successfully\n",account[i].name);
        printf("Account Number: %d\n",account[i].acc_no);
        printf("Now you need to create a strong pin for your account\n");
        printf("Create pin: ");
        scanf("%d",&account[i].pin);
        printf("Account creation process fully compelete\nNow you can login and use your account\n\n");
        i++;
    }
    else if(mode==2)
    {
      printf("enter your account number:");
      scanf("%d",&acno);
      open=acno-25000-1;
      if(account[open].name!=NULL){
      printf("Account fetched successfully\n");
      printf("Welcome Mr. %s\n",account[open].name);
      printf("Please enter your pin to continue: ");
      scanf("%d",&pass);
      if(pass==account[open].pin)
      {
      printf("Correct PIN\n");
      printf("Current balance: %f INR",account[open].balance);
      acmode=0;
      while(acmode!=3)
      {
        printf("\naccount operations\n\t1)Deposit money\n\t2)Withdraw money\n\t3)Log Out\nEnter your choice:");
        scanf("%d",&acmode);
        switch (acmode)
        {
            case 1:
            printf("Enter the amount:");
            scanf("%f",&credit);
            account[open].balance+=credit;
            printf("\nMoney deposited successfully");
            printf("\nCurrent balance: %f",account[open].balance);
            break;
            case 2:
            printf("\nEnter the amount to withdraw:");
            scanf("%f",&debit);
            account[open].balance-=debit;
            printf("\nAmount withdrawl complete");
            printf("\nRemaining Balance %f INR",account[open].balance);
            break;
            case 3:
            acmode=3;
            break;
            default :
            printf("Enter a valid choice");
        }

      }

      }
      else
      printf("Incorrect PIN\n");
      
     }
    }
    else if(mode==3)
    mode=0;}while(mode!=0);
    return 0;
}