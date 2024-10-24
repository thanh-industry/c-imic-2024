#include <stdio.h>
#include <string.h>
#include "BaiTap5.h"
// Book information storage structure
struct Book {
    char title[100];
    char author[100];
    int  year;
    char isbn[20];
};
// Declare an array of books and the number of books available.
struct Book library[MAX_BOOKS];
int bookCount = 0;
// Add new book function
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("The library is full, and no new books can be added..\n");
        return;
    }
    struct Book newBook;
    printf("Enter the book title: ");
    getchar(); // Read the newline character first
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove line breaks.
    printf("Enter the author: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove line breaks.
    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);
    printf("Enter ISBN: ");
    getchar(); // Read the newline character first
    fgets(newBook.isbn, sizeof(newBook.isbn), stdin);
    newBook.isbn[strcspn(newBook.isbn, "\n")] = '\0'; // Remove line breaks.
    library[bookCount] = newBook; // Save the book to the library.
    bookCount++;
    printf("Book added successfully!\n");
}
// Function to view all books
void viewBooks() {
    if (bookCount == 0) {
        printf("The library currently does not have this book.\n");
        return;
    }
    printf("List of books in the library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d: \n", i + 1);
        printf("  Title: %s\n", library[i].title);
        printf("  Author: %s\n", library[i].author);
        printf("  Year of publication: %d\n", library[i].year);
        printf("  ISBN: %s\n", library[i].isbn);
        printf("-------------------------------\n");
    }
}
// Function to search for books by title or author.
void searchBook() {
    if (bookCount == 0) {
        printf("The library currently has no books to search for\n");
        return;
    }
    char searchQuery[100];
    int found = 0;
    printf("Enter the title or author to search: ");
    getchar(); // Read the newline character first.
    fgets(searchQuery, sizeof(searchQuery), stdin);
    searchQuery[strcspn(searchQuery, "\n")] = '\0'; // Remove line breaks.

    printf("Search results for \"%s\":\n", searchQuery);
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, searchQuery) || strstr(library[i].author, searchQuery)) {
            printf(" Book %d: \n", i + 1);
            printf("  Title: %s\n", library[i].title);
            printf("  Author: %s\n", library[i].author);
            printf("  Year of publication: %d\n", library[i].year);
            printf("  ISBN: %s\n", library[i].isbn);
            printf("-------------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found matching the search \"%s\".\n", searchQuery);
    }
}
// Function to display the menu and handle user selection.
int KetQuaBaiTap5() {
    int choice;
    do {
        printf("\n--- Library book management ---\n");
        printf("1. Add new books\n");
        printf("2. View all books\n");
        printf("3. TSearch for books by title or author\n");
        printf("4. Escape\n");
        printf("Choose an option.: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addBook();
            break;
        case 2:
            viewBooks();
            break;
        case 3:
            searchBook();
            break;
        case 4:
            printf("Exit the program....\n");
            break;
        default:
            printf("Invalid selection. Please try again.\n");
        }
    } 
    while (choice != 4);
    return 0;
}