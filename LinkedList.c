#include <stdio.h>
#include <stdlib.h>

struct List{
	char name[100];
	struct List *next;//stores next nodes memory address
};

void menu();
//Functions for linked list
void addNodeAtBegining(struct List **headPtr, char string[]);
void addNodeAtEnd(struct List **headPtr, char string[]);
void deleteNode(struct List **headPtr, char string[]);
void printList(struct List* nextNode);

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
				getchar();
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

void addNodeAtBegining(struct List** headPtr,char string[]) {//** Is memory address to a pointer

	//Allocate dynamic memory for a new node in a linked list
	struct List *newNode = (struct List*)malloc(sizeof(struct List));
	
	//Check if memory has been allocated
	if (newNode == NULL) {
		printf("Memory not allocated\n");
	}
	else {
		strcpy(newNode->name, string);//copy string array to struct member array
		newNode->next = (*headPtr);//Make newNode point to what head is currently pointing to
		(*headPtr) = newNode;//Make the head pointer point to the newNode
	}

}
void addNodeAtEnd(struct List** headPtr, char string[]) {
	
	//allocate dynamic memory for a new node in a linked list
	struct List *newNode = (struct List*)malloc(sizeof(struct List));

	//check if memory has been allocated
	if (newNode == NULL) {
		printf("Memory not allocated\n");
	}
	else {
		struct List* lastNode = *headPtr;//Make a pointer to what headPtr is pointing to
		strcpy(newNode->name, string);//copy string array to struct member array
		newNode->next = NULL;
		
		if (*headPtr == NULL) {//Check if there are nodes in the list
			*headPtr = newNode;//if there isn't make head point to new node
		}
		else {
			//loop through until the next node found is null then we have the pointer of the last node
			while (lastNode->next != NULL) {
				lastNode = lastNode->next;
			}
			lastNode->next = newNode;//Make lastNode in list point to NewNode
		}
	}
}
void deleteNode(struct List** headPtr, char string[]) {
	
	struct List* currentNodePtr = *headPtr, *previousNodePtr = NULL;

	if (currentNodePtr != NULL && strcmp(currentNodePtr->name,string) == 0) {//strcmp compares each string character by character
		*headPtr = currentNodePtr->next;//Make headPtr point to what the currentNodePtr points to so we can remove the currentNodePtr
		free(currentNodePtr);//free up currentNodePtr
		return;
	}
	else {
		while (currentNodePtr != NULL && strcmp(currentNodePtr->name, string) != 0) {
			previousNodePtr = currentNodePtr;//hold currentNodePtr so next node can be deleted if name found in node
			currentNodePtr = currentNodePtr->next;//get next node in list to check name value
		}
		if (currentNodePtr == NULL) {
			printf("\nNo value found in linked list\n");
			return;
		}
		//Make previousNodePtr point to what the currentNodePtr points to so we can remove the currentNodePtr
		previousNodePtr->next = currentNodePtr->next;
		//free up pointers
		free(currentNodePtr);
	}
}

void printList(struct List *nextNode) {
	int i = 0;
	while (nextNode != NULL) {//break when next node is NULL

		printf("Name in node %d is %s\n",i, nextNode->name);//display name value in node
		i++;
		nextNode = nextNode->next;//get memory address of next node
	}
}