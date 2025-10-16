#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int studentID;
    int bookID;
    char title[50];
    char date[15];
    struct Book *next;
};

struct Book *head = NULL;

void issueBook(int studentID, int bookID, char title[], char date[]) {
    struct Book *newnode = (struct Book *)malloc(sizeof(struct Book));
    newnode->studentID = studentID;
    newnode->bookID = bookID;
    strcpy(newnode->title, title);
    strcpy(newnode->date, date);
    newnode->next = head;
    head = newnode;
    printf("\nBook issued successfully!\n");
}

void returnBook(int bookID) {
    struct Book *temp = head, *prev = NULL;
    while (temp != NULL && temp->bookID != bookID) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nBook not found!\n");
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("\nBook returned successfully!\n");
}

void searchByStudent(int studentID) {
    struct Book *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->studentID == studentID) {
            printf("\nBook ID: %d | Title: %s | Date: %s\n", temp->bookID, temp->title, temp->date);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("\nNo books borrowed by this student.\n");
}

void displayAll() {
    struct Book *temp = head;
    if (temp == NULL) {
        printf("\nNo borrowed books.\n");
        return;
    }
    printf("\nBorrowing History:\n");
    while (temp != NULL) {
        printf("StudentID: %d | BookID: %d | Title: %s | Date: %s\n",
               temp->studentID, temp->bookID, temp->title, temp->date);
        temp = temp->next;
    }
}

void countBooks() {
    struct Book *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\nTotal Borrowed Books: %d\n", count);
}

int main() {
    int choice, studentID, bookID;
    char title[50], date[15];

    do {
        printf("\n--- Library Book Borrowing System ---\n");
        printf("1. Issue Book\n");
        printf("2. Return Book\n");
        printf("3. Search by Student ID\n");
        printf("4. Display All Borrowed Books\n");
        printf("5. Count Total Books\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Student ID: ");
            scanf("%d", &studentID);
            printf("Enter Book ID: ");
            scanf("%d", &bookID);
            printf("Enter Book Title: ");
            scanf(" %s", title);
            printf("Enter Date of Issue: ");
            scanf("%s", date);
            issueBook(studentID, bookID, title, date);
            break;

        case 2:
            printf("Enter Book ID to return: ");
            scanf("%d", &bookID);
            returnBook(bookID);
            break;

        case 3:
            printf("Enter Student ID: ");
            scanf("%d", &studentID);
            searchByStudent(studentID);
            break;

        case 4:
            displayAll();
            break;

        case 5:
            countBooks();
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
