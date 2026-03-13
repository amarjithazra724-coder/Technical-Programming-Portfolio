#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int id;
    char name[100];
    char author[100];
};

void addBook()
{
    FILE *fp = fopen("library.dat","ab");
    struct Book b;

    printf("Enter Book ID: ");
    scanf("%d",&b.id);

    printf("Enter Book Name: ");
    scanf(" %[^\n]",b.name);

    printf("Enter Author Name: ");
    scanf(" %[^\n]",b.author);

    fwrite(&b,sizeof(b),1,fp);
    fclose(fp);

    printf("Book added successfully!\n");
}

void displayBooks()
{
    FILE *fp = fopen("library.dat","rb");
    struct Book b;

    printf("\n----- Library Books -----\n");

    while(fread(&b,sizeof(b),1,fp))
    {
        printf("ID: %d\n",b.id);
        printf("Name: %s\n",b.name);
        printf("Author: %s\n",b.author);
        printf("------------------------\n");
    }

    fclose(fp);
}

void searchBook()
{
    FILE *fp = fopen("library.dat","rb");
    struct Book b;
    int id,found=0;

    printf("Enter Book ID to search: ");
    scanf("%d",&id);

    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.id==id)
        {
            printf("\nBook Found\n");
            printf("Name: %s\n",b.name);
            printf("Author: %s\n",b.author);
            found=1;
        }
    }

    if(!found)
    printf("Book not found\n");

    fclose(fp);
}

void deleteBook()
{
    FILE *fp,*temp;
    struct Book b;
    int id,found=0;

    fp=fopen("library.dat","rb");
    temp=fopen("temp.dat","wb");

    printf("Enter Book ID to delete: ");
    scanf("%d",&id);

    while(fread(&b,sizeof(b),1,fp))
    {
        if(b.id==id)
        {
            found=1;
        }
        else
        {
            fwrite(&b,sizeof(b),1,temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("library.dat");
    rename("temp.dat","library.dat");

    if(found)
        printf("Book deleted successfully\n");
    else
        printf("Book not found\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}