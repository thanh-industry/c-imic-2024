#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include "error_handling.h"
#include "BAI_1.h"
#include "BAI_2.h"
#include "BAI_4.h"
#include "BAI_5.h"
#include "BAI_6.h"
#include "BAI_7.h"
#include "BAI_8.h"
#include "BAI_9.h"

// #define BAI_TAP_1 // Tao va in bien so
// #define BAI_TAP_2 // Tao va in struct hoc sinh
// #define BAI_TAP_4 // Sap xep mang so nguyen
// #define BAI_TAP_5 // Dao chuoi
// #define BAI_TAP_6 // Tam giac Pascal
// #define BAI_TAP_7 // Tim cau trong doan van, su dung malloc() de input doan van
// #define BAI_TAP_8 // Khai bao va su dung con tro ham
#define BAI_TAP_9 // Library Book Management System

int main(void)
{
#ifdef BAI_TAP_1
	inBienSo();
#endif

#ifdef BAI_TAP_2
	hocSinh();
#endif

#ifdef BAI_TAP_4
	int arr[13] = {21, 321, 91, 31, 5634, 213, 12, 1, 2134, 2314, -912, -18, 312};
	sortArray(arr);
#endif

#ifdef BAI_TAP_5

	char str[1000];
	printf("Please input your string:");
	fgets(str, sizeof(str), stdin);

	int type;
	printf("Please input your type of reverse (0 - reverse whole string, 1 - reverse each word): ");
	scanf("%d", &type);

	daoChuoi(str, type);
#endif

#ifdef BAI_TAP_6

	while (1)
	{
		tamGiacPascal();
		printf("Do you want to input again? [Y/N]: ");
		char type;
		scanf(" %c", &type);
		if (type == 'Y' || type == 'y')
			continue;
		else
			break;
	}

#endif

#ifdef BAI_TAP_7
	while (1)
	{
		char *str = timCauTrongDoanVan();
		printf("The sentence is: %s\n", str);
		free(str);
		printf("Do you want to input again? [Y/N]: ");
		char type;
		scanf(" %c", &type);
		if (type == 'Y' || type == 'y')
			continue;
		else
			break;
	}
#endif

#ifdef BAI_TAP_8

	int a, b;
	int (*tong)(int, int);

	printf("Please input a: ");
	scanf("%d", &a);

	printf("Please input b: ");
	scanf("%d", &b);

	tong = tong1;
	printf("Tong 1: %d\r\n", tong(a, b));

	tong = tong2;
	printf("Tong 2: %d\r\n", tong(a, b));

	tong = tong3;
	printf("Tong 3: %d\r\n", tong(a, b));

#endif

#ifdef BAI_TAP_9

	int g_choice,
		g_bookCap = 1;								// First init capacity of book is 1
	Book *g_book = (Book *)calloc(1, sizeof(Book)); // First allocate memory for 1 book

	if (g_book == NULL) // Print out error and terminate the program in case of memory allocation failed
	{
		printf("Memory allocation failed\r\n");
		exit(EXIT_FAILURE);
	}

	while (1) // Main loop for book management system
	{
		g_choice = menuBook();
		switch (g_choice)
		{
		case ADD_BOOK: // Add book function
			int result;
			if (g_bookCap > 100) // check if book capacity is reach (100 books)
			{
				printf("Book capacity is full\r\n");
			}
			else if (g_bookCap == 1 && g_book[0].title[0] == '\0') // check if the first book is still empty for adding book to it
			{
				result = addBook(&g_book[0]);
				if (result == STATE_OK)
				{
					printf("Book is added successfully.");
				}
				else
				{
					printf("Book is not added successfully.");
				}
			}
			else
			{
				g_book = realloc(g_book, (g_bookCap + 1) * sizeof(Book)); // Reallocate memory for new book
				if (g_book == NULL)										  // Print out error and terminate the program in case of memory allocation failed
				{
					printf("Book system memory allocation failed\r\n");
					exit(EXIT_FAILURE);
				}
				g_bookCap++; // Increase book capacity
				result = addBook(&g_book[g_bookCap - 1]);
				if (result == STATE_OK)
				{
					printf("Book is added successfully.");
				}
				else
				{
					printf("Book is not added successfully.");
				}
			}
			printf(" Press ENTER to continue...");
			while (getchar() != '\n')
				; // Wait for ENTER
			getchar();
			break;

		case VIEW_BOOK: // View book function
		{
			int index,
				i,
				result,
				noBookFlag = FLAG_ON;
			char exitResult;
			printf("List of books:\r\n");

			for (i = 0; i < g_bookCap; i++)
			{
				if (g_book[i].title[0] == '\0')
				{
					// Skip empty book
				}
				else
				{
					noBookFlag = FLAG_OFF;
					printf("%d. %s\r\n", i, g_book[i].title);
				}
			}
			if (noBookFlag == FLAG_ON)
			{
				printf("No book is available\r\n");
			}
			else
			{
				printf("Please input book index: ");
				scanf("%d", &index);
				result = viewBook(&g_book[index]);
				if (result == STATE_OK)
				{
					printf("Book information is shown successfully\r\n");
				}
				else
				{
					printf("Book information is not shown successfully\r\n. Error code: %d", result);
				}
			}

			exitResult = askForExit();

			if (exitResult != 'Y' && exitResult != 'y')
			{
				free(g_book); // Free book memory
				exit(EXIT_SUCCESS);
			}
		} // End of case VIEW_BOOK
		break;

		case SEARCH_BOOK: // Search book function
		{
			int result,
				type;
			char *search = (char *)malloc(100 * sizeof(char)); // Allocate memory for search string
			char exitResult;

			printf("Search by:\r\n[1] Title\r\n[2] Author\r\nType your search: ");
			scanf("%d", &type);
			printf("Please input your search: ");
			scanf(" %[^\n]", search);
			search = realloc(search, strlen(search) + 1); // Reallocate memory for better memory management
			if (search == NULL)
			{
				printf("Search string memory allocation failed\r\n");
				free(g_book); // Free book memory
				exit(EXIT_FAILURE);
			}

			result = searchBook(g_book, g_bookCap, search, type);
			if (result == STATE_OK)
			{
				printf("Book information is shown successfully\r\n");
			}
			else
			{
				printf("Book information is not shown successfully\r\n. Error code: %d", result);
			}

			free(search); // Free search string memory after using

			exitResult = askForExit();

			if (exitResult != 'Y' && exitResult != 'y')
			{
				free(g_book);
				exit(EXIT_SUCCESS);
			}
		}
		break;

		case EXIT:		  // Exit the program
			free(g_book); // Free book memory
			exit(EXIT_SUCCESS);
			break;

		default:
			printf("Invalid choice\r\n");
			break;
		} // End of switch
	} // End of while

#endif

	return 1;
}
