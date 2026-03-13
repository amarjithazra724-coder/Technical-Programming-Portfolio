#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if(count >= MAX) {
        printf("Database full.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if(count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\nID\tName\tMarks\n");
    printf("-------------------------\n");

    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n",
               students[i].id,
               students[i].name,
               students[i].marks);
    }
}

void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++) {
        if(students[i].id == id) {
            printf("Found: %s, Marks: %.2f\n",
                   students[i].name,
                   students[i].marks);
            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    int choice;

    while(1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}