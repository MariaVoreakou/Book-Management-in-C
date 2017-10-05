#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "books.h"
#define NOTFOUND -1


//Print the menu for user
void printmenu(){
	printf("Select:\n1.Add a Book\n");
	printf("2.Delete a Book (with id)\n");
	printf("3.Print all Books\n");
	printf("4.Print a Specific Book\n");
	printf("5.Find a Book (with id)\n");
	printf("6.Update a book\n");
	printf("7.Save Books to file\n");
	printf("8.Load Books from file\n");
	printf("9.Quit\n");
}

//Find a Book
book findBook(book b, list bList){ 		
	node currentNode=bList->head;
		while (currentNode!=NULL){
			if (currentNode->b->id==b->id){
				return currentNode->b;
				}
			}
	return NULL;			
 }
 
//Find a Node 
node findNode(book b, list bList){ 		
	node currentNode=bList->head;
		while (currentNode!=NULL){
			if (currentNode->b->id==b->id){
				return currentNode;
				}
			}
	return NULL;			
 }
 
//Create a Book
book createBook(list myList){
	
	char tmp_author[MAXSTRING];
	enum genres tmp_genre;
	int tmp_id=0;
	char tmp_review[MAXLINES][MAXSTRING];
	
	printf("Insert Author\n");
		for(int j=0;j<MAXSTRING;j++){ 
				tmp_author[j]='\0';
			}	
	scanf("%s",tmp_author);
	
	
	int choice=-1;
	printf("Type the category: \n");
	printf("Press '1' for Fiction\n");
	printf("Press '2' for Scientific \n");
	printf("Press '3' for Politics \n");
	while (choice<0){
		scanf("%d",&choice);
		if(choice<1||choice>3){
		choice=-1;
		}
	}
	if(choice==1){
		tmp_genre=Fiction;
	}
	if(choice==2){
		tmp_genre=Scientific;
	}
	if(choice==3){
		tmp_genre=Politics;
	}
	
	
	
	//Check if id already exists
	int chck_id=-1;
		while(chck_id<0){
			printf("Insert id\n");
			scanf("%d",&tmp_id);
			chck_id=tmp_id;
			node currentNode=myList->head;
				while (currentNode!=NULL){
					if (currentNode->b->id==chck_id){
						chck_id=-1;
						printf("ID already exists!\n");
						break;
					}
					currentNode=currentNode->next;
				}
		}	
	
	printf("Insert Review of Book\n");
	for (int i=0;i<MAXLINES;i++){
			for(int j=0;j<MAXSTRING;j++){
				tmp_review[i][j]='\0';
			}
		printf("Enter %d line of review: ",i+1);
		scanf("%s",tmp_review[i]);
		
	}
	
	book aBook=(book)malloc(sizeof(struct bookR)); //Desmeusi mnimis gia to book
	
	strcpy(aBook->author,tmp_author); // copy to tmp_author sto author
	
	aBook->id=tmp_id; // copy to tmp_id sto id
	
	aBook->genre=tmp_genre; // copy to tmp_genre sto genre
	
	memcpy(aBook->review,tmp_review,sizeof(char)*MAXLINES*MAXSTRING);  //Source:http://www.cplusplus.com/reference/cstring/memcpy/
	
	return aBook;
} 

//Add a Book
void addBook(book b, list bList){ 
	if (bList->head==NULL){
		node headnode=(node) malloc(sizeof(struct nodeR)); // Desmeusi gia to node
		headnode->prev=NULL;
		headnode->next=NULL;
		headnode->b=b;	
		bList->head=headnode;
	}
	else{
		node currentnode;
		currentnode=bList->head;
		while (currentnode->next!=NULL){
			currentnode=currentnode->next;		
		}	
		node finalnode=(node) malloc(sizeof(struct nodeR)); //Desmeusi gia to node
		finalnode->next=NULL;
		finalnode->prev=currentnode;
		finalnode->b=b;
		currentnode->next=finalnode;		
	}	
}

//Delete a Book
void deleteBook(book b, list bList){ 
	node currentnode;
	currentnode=findNode(b, bList);
	if (currentnode!=NULL){
		if (currentnode->next!=NULL){				
			if (currentnode->prev!=NULL){
				currentnode->next->prev=currentnode->prev; // metaferoume to prev tou next sto current tou previous
			}
		}
		if (currentnode->prev!=NULL){
			if (currentnode->next!=NULL){
				currentnode->prev->next=currentnode->next; //metaferoume to next tou prev sto current tou next
			}
		}
		if (currentnode->prev==NULL){
			bList->head=currentnode->next;
		}
		free(currentnode->b); // Free to Deleted Book
		free(currentnode);	// Free to node
	}
}


//Print Book
void print(book b){ 
	 printf("Book Author: %s \n",b->author);
	 
	 printf("Book Id: %d \n",b->id);
	 if(b->genre==1){
		printf("Book Genre:Fiction \n");
		}
	 if(b->genre==2){
		printf("Book Genre:Scientific \n");
		}
	 if(b->genre==3){
		printf("Book Genre:Politics \n");
		}
		
	 printf("Book Review:\n");
	 for(int i=0;i<MAXLINES;i++){
	 	printf("%s \n",b->review[i]);
	 }
	 	printf("\n\n\n");
	 	 
}

//Print all Books
void printAllBooks(list bList){ 
	 node currentnode=bList->head; //To current node na vrisketai sti thesi Head
	 
	 while(currentnode!=NULL){
	 	print(currentnode->b);
	 	currentnode=currentnode->next;
	 }

}

//Print a Specific Book'
void printSpecific(list bList){
	node currentnode=bList->head; //To current node na vrisketai sti thesi Head
	int tmp_id;
	printf("Give ID of book\n");
	scanf("%d",&tmp_id);
	if(currentnode!=NULL){
		if(tmp_id==currentnode->b->id){
			print(currentnode->b);
		}
		
	}
}

//update book to list
void updateBook(book b, list bList){
	book bookFound;
	bookFound=findBook(b,bList);
	int choice=-1;
	char tmp_author;
	enum genres tmp_genre;
	char review[MAXLINES][MAXSTRING];
	
	printf("Update:\n");
	printf("1.Author\n");
	printf("2.Genre\n");
	printf("3.Review\n");
	printf("4.Exit\n");
	
	
	
	while(choice<0){
		scanf("%d",&choice);
		if (choice<0 || choice>4){
			choice=-1;
		}
	}
		switch (choice){
			case 1:
				char tmp_author[MAXSTRING];
				for(int j=0;j<MAXSTRING;j++){
					tmp_author[j]='\0';
				}
				printf("Give Author\n");
				scanf("%s",tmp_author);
				strcpy (bookFound->author,tmp_author);
				printf("Done!\n");
				break;
				
			case 2:
				enum genres tmp_genre;
				printf("Give Genre (1 for Fiction, 2 for Scientific, 3 for Politics)\n");
				while (choice<0){
					scanf("%d",&choice);
					if(choice<1||choice>3){
						choice=-1;
						}
				if(choice==1){
					tmp_genre=Fiction;
					}
				if(choice==2){
					tmp_genre=Scientific;
					}
				if(choice==3){
					tmp_genre=Politics;
					}
				bookFound->genre=tmp_genre;
				printf("Done!\n");
				break;
				
			case 3:
				char tmp_review[MAXLINES][MAXSTRING];
				printf("Give the review\n");
				for (int i=0;i<MAXLINES;i++){ //Ginetai for gia na kalipsoume kai tous dio pinakes 
					for(int j=0;j<MAXSTRING;j++){
						tmp_review[i][j]='\0'; //Vazoume \0 se oses kenes theseis exoume wste ekei pou teleiwnei to onoma na ksexwrizei
						}
				printf("Enter %d line of review",i+1);
				scanf("%s",tmp_review[i]);
				}
				memcpy(bookFound->review,tmp_review,sizeof(char)*MAXLINES*MAXSTRING); //copy to review *MAXLINES*MAXSTRING
				break;
				
			case 4:
				return;
			}
	}
}

//save list of books to file	
void save(char *filename, list bList){
	FILE* myfile;
	
	myfile=fopen(filename,"wb+");
	
	node currentnode=bList->head;
	
	while (currentnode!=NULL){

																					/*	fwrite(&currentnode->b->id, sizeof(int),1,myfile);
																						fwrite(currentnode->b->author,sizeof(char),1,myfile);
																						for(int i=0;i<MAXLINES;i++){
																					 		fwrite(currentnode->b->review, sizeof(char)*MAXSTRING,1,myfile);
																					 		}
																						fwrite(&currentnode->b->genre, sizeof(int),1,myfile);*/
		fwrite(currentnode->b, sizeof(struct bookR),1,myfile);
		currentnode=currentnode->next;
	}
	fclose(myfile);

}	

//load list of books
list load(char *filename, list bList){
	 
	FILE* myfile;
	
	myfile=fopen(filename,"rb");
	int booksRead;
	do{
		book loadedBook=(book)malloc(sizeof(struct bookR));	// Desmeusi gia to loadedbook
		booksRead= fread(loadedBook,sizeof(struct bookR),1,myfile); //read to my file
		if(booksRead<1){
			free(loadedBook); // free ti mnimi
			break;
		}		
		addBook(loadedBook,bList);
	}
	while (booksRead>0);
	
	fclose(myfile);
	
	

}
	
void deinitialize(list blist){ //Epanarxikopoisi 
	node currentnode = blist->head;
	
	while(currentnode!=NULL){
		node temp = currentnode->next;
		free(currentnode->b);
		free(currentnode);
		currentnode = temp;
	}
	free(blist); //Free tin mnimi 
}




