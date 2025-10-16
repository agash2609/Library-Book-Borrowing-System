
# Library Book Borrowing System

Description:
This C program manages library book borrowing using a singly linked list. It allows issuing books, returning books, searching by student ID, displaying all borrowed books, and counting total borrowed books. Each record contains Student ID, Book ID, Title, and Date of Issue.

Features:
1. Issue Book – Add a book to a student's borrowing record.
2. Return Book – Remove a book from the borrowed list using Book ID.
3. Search by Student ID – View all books borrowed by a specific student.
4. Display All Borrowed Books – Show all borrowing history.
5. Count Total Books – Display the total number of borrowed books.
6. Exit – Close the program.

How it Works:
- Uses a struct Book with fields: Student ID, Book ID, Title, Date, and a pointer to the next node.
- Linked list dynamically stores borrowed book records.
- New books are added to the head of the list.
- Provides menu-driven interface for easy operation.

Compilation and Execution:
gcc studentsrecord_library.c -o studentsrecord_library
./studentsrecord_library

Sample Input/Output:
Enter your choice: 1
Enter Student ID: 101
Enter Book ID: 201
Enter Book Title: Data Structures
Enter Date of Issue: 2025-09-29
Book issued successfully!

Enter your choice: 4
Borrowing History:
StudentID: 101 | BookID: 201 | Title: Data Structures | Date: 2025-09-29
