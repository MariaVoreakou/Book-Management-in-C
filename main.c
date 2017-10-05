#include <stdio.h>
#include <stdlib.h>
#include "books.h"
/*
Programma to opoio dimiourgei mia vasi me vivlia, prosthetei, afairei, ektipwnei ti lista kai kanei save kai load to file twn saved books.
Author: Maria Voreakou (it214123)
*/

int main(){
	
	int run;
	run=1;
	int x;
	
	list bList=(list)malloc(sizeof(struct listR));
	bList->head=NULL;
	
	while(run){
		printmenu();
		scanf("%d",&x);
		system("cls");
		
		switch (x){
			case 1:{
				addBook(createBook(bList),bList);				
				system("cls");
				break;
			}
			case 2:{
				int tmp_id;
				printf("Give Id you want to delete:\n");
				scanf("%d",&tmp_id);
				book bookToDelete = (book)malloc(sizeof(struct bookR));
				bookToDelete->id=tmp_id;
				deleteBook(bookToDelete,  bList);
				free(bookToDelete);
				system("cls");
				break;
			}
			case 3:{
				printAllBooks(bList);
				system("pause");
				system("cls");
				break;
			}
			case 4:{
				printSpecific(bList);
				system("pause");
				system("cls");
				break;
			}
			case 5:{
				int tmp_id;
				printf("Give Id you want to Find:\n");
				scanf("%d",&tmp_id);
				book bookFound = (book)malloc(sizeof(struct bookR));
				bookFound->id=tmp_id;
				print(findBook(bookFound,  bList));
				free(bookFound);
				system("cls");
				break;
			}
			case 6:{
				int tmp_id;
				printf("Give Id you want to Update:\n");
				scanf("%d",&tmp_id);
				book bookFound = (book)malloc(sizeof(struct bookR));
				bookFound->id=tmp_id;
				updateBook(bookFound, bList);
				free(bookFound);	
				system("cls");			
				break;
			}
			case 7:{
				save("Books.bin",bList);
				system("cls");
				break;
			}
			case 8:{
				load("Books.bin",bList);
				system("cls");
				break;
			}
			case 9:{
				run=0;
				deinitialize(bList);
				break;
			}
			default:{
				system("cls");
				break;
			}	
		}
		
	}
	return 0;
}
