#ifndef BOOKS_H 
#define BOOKS_H
#include <stdio.h>
#include <stdlib.h>

#define MAXSTRING 1000
#define MAXLINES 5

enum genres{
	Fiction=1, Scientific, Politics
};

struct bookR{
	char author[MAXSTRING];
	enum genres genre;
	int id;
	char review[MAXLINES][MAXSTRING];

};

typedef struct bookR* book;


struct nodeR{
	struct nodeR* prev;
	struct nodeR* next;
	book b;
};

typedef struct nodeR* node;

struct listR{
	node head;
};

typedef struct listR* list;

//Print menu
void printmenu();

//Find a Book
book findBook(book b, list bList);

//Find a Node 
node findNode(book b, list bList);

//Create a Book
book createBook(list myList);

//Add a Book
void addBook(book b, list bList);

//Delete a Book
void deleteBook(book b, list bList);

//Print Book
void print(book b);

//Print all Books
void printAllBooks(list bList);

//Print a Specific Book'
void printSpecific(list bList);

//update book to list
void updateBook(book b, list bList);

//save list of books to file	
void save(char *filename, list bList);

//load list of books
list load(char *filename, list bList);

void deinitialize(list blist);


#endif
