#include <stdio.h>
#include <string.h>

typedef struct book
{
	char title[50];
	char author[50];
	int yearOfPublication;
	char ISBNNumber[10];
}Book;

void MenuSystem(Book *bookList);
void AddNewBook(Book *bookList);
void ViewAllBook(Book *bookList);
void ResearchBook(Book *bookList);

int addIndex;
int close = 0;
int main(void)
{
	Book bookList[100];	
	
	while(close == 0)
	{
		MenuSystem(bookList);
	}
	return 0;
}

void MenuSystem(Book *bookList)
{
	int userInput;
	
	printf("\n");
	printf("--------------------- Menu ------------------\n");
	printf("Choose one of following options\n");
	printf("1. Add a new book\n");
	printf("2. View all books\n");
	printf("3. Research for a book by title or author\n");
	printf("4. Exit the program\n");
	printf("User input: ");
	scanf("%d",&userInput);
	
	switch (userInput)
	{
		case 1:
			AddNewBook(bookList);
			break;
		case 2:
			ViewAllBook(bookList);
			break;
		case 3:
			ResearchBook(bookList);
			break;
		case 4:
			close = 1;
			break;
		default:
			printf("Invalid input !!!!!!!\n");		
	}

	
}

void AddNewBook(Book *bookList)
{	
	printf("\n");
	printf("--------------------- Import following data ------------------\n");
	
	printf("Title: ");
	getchar();
	fgets(bookList[addIndex].title, sizeof(bookList[addIndex].title), stdin);
	bookList[addIndex].title[strcspn(bookList[addIndex].title, "\n")] = '\0';
	
	printf("Author: ");
	fgets(bookList[addIndex].author, sizeof(bookList[0].author), stdin);
	bookList[addIndex].author[strcspn(bookList[addIndex].author, "\n")] = '\0';
	
	printf("Year Of Publication: ");
	scanf("%d", &bookList[addIndex].yearOfPublication);
	
	printf("ISB Number: ");
	scanf("%s", bookList[addIndex].ISBNNumber);
	
	addIndex++;
	printf("\n");
}

void ViewAllBook(Book *bookList)
{
	printf("\n");
	printf("--------------------- Books infomation ------------------------\n");
	for(int i=0; i<addIndex;i++)
	{
		printf("%d.\n",i+1);
		printf("Title: %s\n", bookList[i].title);
		printf("Author: %s\n", bookList[i].author);
		printf("Year Of Publication: %d\n", bookList[i].yearOfPublication);
		printf("ISB Number: %s\n\n", bookList[i].ISBNNumber);
	}
}

void ResearchBook(Book *bookList)
{
	char title[50];
	char author[50];
	int userInput;
	printf("--------------------- Find book ------------------------\n");
	printf("Search by title or author?\n");
	printf("1. Title\n");
	printf("2. Author\n");
	printf("User input: ");
	scanf("%d",&userInput);
	
	if(userInput == 1)
	{
		printf("Title: ");
		getchar();
		fgets(title, sizeof(title), stdin);
		title[strcspn(title, "\n")] = '\0';
		printf("\nYour result\n");
		for(int i=0; i<addIndex;i++)
		{
			for(int j =0; j<sizeof(title);j++)
			{
				if(title[j] != bookList[i].title[j])
				{
					break;
				}
				else if(title[j] == '\0')
				{
					printf("Title: %s\n", bookList[i].title);
					printf("Author: %s\n", bookList[i].author);
					printf("Year Of Publication: %d\n", bookList[i].yearOfPublication);
					printf("ISB Number: %s\n\n", bookList[i].ISBNNumber);
					break;
				}
			}
		}
	}
	else if(userInput == 2)
	{
		printf("Author: ");
		getchar();
		fgets(author, sizeof(author), stdin);
		author[strcspn(author, "\n")] = '\0';
		
		for(int i=0; i<addIndex;i++)
		{
			for(int j =0; j<sizeof(author);j++)
			{
				if(author[j] != bookList[i].author[j])
				{
					break;
				}
				else if(author[j] == '\0')
				{
					printf("\nYour result\n");
					printf("Title: %s\n", bookList[i].title);
					printf("Author: %s\n", bookList[i].author);
					printf("Year Of Publication: %d\n", bookList[i].yearOfPublication);
					printf("ISB Number: %s\n\n", bookList[i].ISBNNumber);
					break;
				}
			}
		}
	}
	else
	{
		printf("Invalid input !!!!!!!\n");
	}
	
}

