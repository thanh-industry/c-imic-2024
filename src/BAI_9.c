#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BAI_9.h"
#include "error_handling.h"

void clearMenu(void)
{
#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#endif

#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#endif
}

/**
 * @brief add book information by input title, author, numberOfISBN, yearOfPublication
 *
 * @return int for error handling
 */

int addBook(Book *_book)
{
    printf("Enter title: ");
    scanf(" %[^\n]", _book->title);
    printf("Enter author: ");
    scanf(" %[^\n]", _book->author);
    printf("Enter ISBN No: ");
    scanf("%s", _book->numberOfISBN);
    printf("Enter year of publication: ");
    scanf("%d", &_book->yearOfPublication);

    return STATE_OK;
}

/**
 * @brief view book information by print out title, author, numberOfISBN, yearOfPublication
 *
 * @param _book the book array
 * @return int for error handling
 */

int viewBook(Book *_book)
{
    printf("Title: %s\r\n", _book->title);
    printf("Author: %s\r\n", _book->author);
    printf("ISBN No: %s\r\n", _book->numberOfISBN);
    printf("Year of Publication: %d\r\n", _book->yearOfPublication);

    return STATE_OK;
}

/**
 * @brief search book information based on title or author
 *
 * @param _book the book array
 * @param _bookCap the book capacity
 * @param _search the search string
 * @param _type the search type
 *
 * @return int
 */
int searchBook(Book *_book, int _bookCap, char *_search, int _type)
{
    int i,
        BookFlag = FLAG_OFF,
        textLength,
        searchLength;

    searchLength = strlen(_search);

    if (_type == 1)
    {
        printf("Search result for title: %s\r\n", _search);

        for (i = 0; i < _bookCap; i++)
        {
            textLength = strlen(_book[i].title);
            if (textLength < searchLength)
            {
                // Do nothing
            }
            else
            {
                int j;
                for (j = 0; j < textLength; j++)
                {
                    if (_book[i].title[j] == _search[0]) // Start to check if the first character is matched
                    {
                        if (strncmp(&_book[i].title[j], _search, searchLength) == 0) // Check if the rest of the string is matched
                        {
                            BookFlag = FLAG_ON;
                            viewBook(&_book[i]);
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (_type == 2)
    {
        printf("Search result for author: %s\r\n", _search);
        for (i = 0; i < _bookCap; i++)
        {
            textLength = strlen(_book[i].author);
            if (textLength < searchLength)
            {
                // Do nothing
            }
            else
            {
                int j;
                for (j = 0; j < textLength; j++)
                {
                    if (_book[i].author[j] == _search[0]) // Start to check if the first character is matched
                    {
                        if (strncmp(&_book[i].author[j], _search, searchLength) == 0) // Check if the rest of the string is matched
                        {
                            BookFlag = FLAG_ON;
                            viewBook(&_book[i]);
                            break;
                        }
                    }
                }
            }
        }
    }

    if (BookFlag == FLAG_OFF)
    {
        printf("No book is available\r\n");
    }
    return STATE_OK;
}

/**
 * @brief choose menu for book
 *
 * @return int for choice
 */
int menuBook(void)
{
    int choice;
    clearMenu();
    printf("Book Management System Menu:\r\n");
    printf("[1] Add book\r\n");
    printf("[2] View book\r\n");
    printf("[3] Search book\r\n");
    printf("[4] Exit\r\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice != 4)
    {
        clearMenu();
    }
    return choice;
}

/**
 * @brief return to the menu
 *
 */
char askForExit(void)
{
    char type;
    printf("Do you want to go back the menu? [Y/N]: ");
    scanf(" %c", &type);

    return type;
}