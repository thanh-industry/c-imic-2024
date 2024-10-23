#ifndef _BAI_9_H_
#define _BAI_9_h_

/**
 * @brief struct of book with title, author, numberOfISBN, yearOfPublication
 *
 */

typedef struct book
{
    char title[100];
    char author[100];
    char numberOfISBN[13];
    int yearOfPublication;
} Book;

enum FLAG
{
    FLAG_OFF,
    FLAG_ON,
};

#define ADD_BOOK 1
#define VIEW_BOOK 2
#define SEARCH_BOOK 3
#define EXIT 4

int viewBook(Book *_book);
int addBook(Book *_book);
int searchBook(Book *_book, int _bookCap, char *_search, int _type);
int menuBook(void);

char askForExit(void);

#endif