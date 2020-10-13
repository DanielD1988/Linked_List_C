#include "Node.h"

void addNodeAtBeginning(struct List** headPtr, char string[]) {//** Is memory address to a pointer

	//Allocate dynamic memory for a new node in a linked list
	struct List* newNode = (struct List*)malloc(sizeof(struct List));

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
	struct List* newNode = (struct List*)malloc(sizeof(struct List));

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

	struct List* currentNodePtr = *headPtr, * previousNodePtr = NULL;

	if (currentNodePtr != NULL && strcmp(currentNodePtr->name, string) == 0) {//strcmp compares each string character by character
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

void printList(struct List* nextNode) {
	int i = 0;
	while (nextNode != NULL) {//break when next node is NULL

		printf("Name in node %d is %s\n", i, nextNode->name);//display name value in node
		i++;
		nextNode = nextNode->next;//get memory address of next node
	}
}
