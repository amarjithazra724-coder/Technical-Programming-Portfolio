#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char site[50], pass[50];
    int choice;

    while(1)
    {
        printf("\n===== Password Manager =====\n");
        printf("1. Save Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:

                fp=fopen("passwords.txt","a");

                printf("Enter website name: ");
                scanf("%s",site);

                printf("Enter password: ");
                scanf("%s",pass);

                fprintf(fp,"%s %s\n",site,pass);

                fclose(fp);

                printf("Password saved successfully!\n");
                break;

            case 2:

                fp=fopen("passwords.txt","r");

                printf("\nSaved Passwords:\n");

                while(fscanf(fp,"%s %s",site,pass)!=EOF)
                {
                    printf("Website: %s | Password: %s\n",site,pass);
                }

                fclose(fp);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}