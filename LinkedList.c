#include <stdio.h>
#include <stdlib.h>

struct List{
	char name[100];//stores node value
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
	int option = 0x1;
	
	while (option != 0x0) {
		menu();
		scanf_s("%x", &option);
		
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
	printf("3 To delete a node in the list by a value\n");
	printf("4 Display list values\n");
}

void addNodeAtBegining(struct List** headPtr,char string[]) {//** is pointer to a pointer

	//allocate dynamic memory for a new node in a linked list
	struct List *newNode = (struct List*)malloc(sizeof(struct List));
	
	//check if memory has been allocated
	if (newNode == NULL) {
		printf("Memory not allocated\n");
	}
	else {
		strcpy(newNode->name, string);//copy string array to struct member array
		newNode->next = (*headPtr);//make new node point to head
		//make this node the new head
		(*headPtr) = newNode;
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
		struct List* lastNode = *headPtr;//make lastNode point to the head pointer
		strcpy(newNode->name, string);//copy string array to struct member array
		newNode->next = NULL;
		
		if (*headPtr == NULL) {//check if there are values in the head
			*headPtr = newNode;//if there isn't any make new node the head
		}
		else {
			//loop through until the next node found is null then we have the pointer of the last node
			while (lastNode->next != NULL) {
				lastNode = lastNode->next;
			}
			lastNode->next = newNode;//make newNode the last node in the list
		}
	}
}
void deleteNode(struct List** headPtr, char string[]) {
	
	struct List* currentNodePtr = *headPtr, *previousNodePtr = NULL;

	if (currentNodePtr != NULL && strcmp(currentNodePtr->name,string) == 0) {//strcmp compares each string character by character
		*headPtr = currentNodePtr->next;//assign next node in the list the head
		free(currentNodePtr);//free up current node
		return;
	}
	else {
		while (currentNodePtr != NULL && strcmp(currentNodePtr->name, string) != 0) {
			previousNodePtr = currentNodePtr;//hold current node for deletion if name found
			currentNodePtr = currentNodePtr->next;//get next node in list to check name value
		}
		if (currentNodePtr == NULL) {
			printf("\nNo value found in linked list\n");
			return;
		}
		
		previousNodePtr->next = currentNodePtr->next;//overwrite previous node address space to point to current node address space
		//free up pointers
		free(currentNodePtr);
	}
}

void printList(struct List *nextNode) {
	
	while (nextNode != NULL) {//break when next node is NULL

		printf("Data in node %s\n", nextNode->name);//display value in node
		nextNode = nextNode->next;//get memory address of next node
	}
}