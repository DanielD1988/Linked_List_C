#include <stdio.h>
#include <stdlib.h>
#include "LinkedListFunctions.h"

void menu();

int main() {
	//Set struct member head to null
	struct List *head = NULL;
	char string[100];
	int option = 0x1;//Set option equal to 1
	
	while (option != 0x0) {//While 0 isn't entered
		menu();
		scanf_s("%x", &option);//Take in hex value for number
		
		switch (option) {
			case 0x1:
				getchar();//Removes new line 
				puts("Enter a name to add to the begining of thelinked list max 99 characters");
				fgets(string,99, stdin);
				addNodeAtBegining(&head, string);//Memory address of the head pointer and an array of chars
				break;
			case 0x2:
				getchar();
				puts("Enter a name to add to the end of the linked list max 99 characters");
				fgets(string, 99, stdin);
				addNodeAtEnd(&head, string);
				break;
			case 0x3:
				getchar();
				puts("Enter a name to search for and delete in the linked list max 99 characters");
				fgets(string, 99, stdin);
				deleteNode(&head, string);
				break;
			case 0x4:
				printList(head);
				break;
		}
		if (option < 0x0 || option > 0x4) {
			printf("You didn't enter a valid menu option quiting menu");
			option = 0;
		}
		else if (option == 0x0) {
			printf("Exiting menu");
		}
	}
	free(head);
	return 0;
}

void menu() {
	printf("Choose an option\n");
	printf("0 To quit menu\n");
	printf("1 To add a node at the begining of the list\n");
	printf("2 To add a node at the end of the list\n");
	printf("3 To delete a node in the list by a name\n");
	printf("4 Display names in list\n");
}
