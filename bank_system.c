#include <stdio.h>

int main()
{
    int balance = 0, choice, amount;

    while(1)
    {
        printf("\nBank System\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter amount: ");
                scanf("%d",&amount);
                balance += amount;
                break;

            case 2:
                printf("Enter amount: ");
                scanf("%d",&amount);
                balance -= amount;
                break;

            case 3:
                printf("Balance: %d\n",balance);
                break;

            case 4:
                return 0;
        }
    }
}