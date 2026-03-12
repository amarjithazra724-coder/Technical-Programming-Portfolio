#include <stdio.h>

int main()
{
    char task[100][100];
    int i=0, choice;

    while(1)
    {
        printf("\n1 Add Task\n2 Show Tasks\n3 Exit\n");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter task: ");
            scanf(" %[^\n]",task[i]);
            i++;
        }

        else if(choice==2)
        {
            for(int j=0;j<i;j++)
                printf("%d. %s\n",j+1,task[j]);
        }

        else
            break;
    }
}