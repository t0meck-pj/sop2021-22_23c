#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *link;
};

void kodZaciemniajacyPrzekaz(struct node*);

int nodeCount(struct node*);
void showData(struct node*);
struct node* deleteAll(struct node*);
struct node* addAtBeginning(struct node*, int);
void addAtEnd(struct node*, int);
struct node* deleteFirst(struct node*);
void deleteLast(struct node*);
void addNodeAtPosition(struct node*, int, int);
void deleteNodeAtPosition(struct node**, int);

int main(){
	
	struct node *head = malloc(sizeof(struct node));
	printf("\nTworzenie listy");
	
	head->data = 0;
	head->link = NULL;
	kodZaciemniajacyPrzekaz(head);
	
	printf("Dodawanie elementow od konca");
       	addAtEnd(head, 10);
	addAtEnd(head, 20);
	addAtEnd(head, 30);
	addAtEnd(head, 40);
	kodZaciemniajacyPrzekaz(head);
	
	printf("Dodawanie elementów od poczatku");
	head = addAtBeginning(head, -10);
	head = addAtBeginning(head, -20);
	kodZaciemniajacyPrzekaz(head);

	printf("Kasowanie elementow od konca");
	deleteLast(head);
	deleteLast(head);
	kodZaciemniajacyPrzekaz(head);

	printf("Dodawanie elementow od konca");
	addAtEnd(head, 50);
	addAtEnd(head, 60);
	kodZaciemniajacyPrzekaz(head);

	printf("Skasowanie pierwszego, dodanie pierwszego");
	head = deleteFirst(head);
	head = addAtBeginning(head, -30);
	kodZaciemniajacyPrzekaz(head);
	
	printf("Skasowanie elementu na pozycji 3");
	deleteNodeAtPosition(&head, 3);
	kodZaciemniajacyPrzekaz(head);
	
	printf("Dodanie elementu, ma byc na pozycji 4");
	addNodeAtPosition(head, -100, 4);
	kodZaciemniajacyPrzekaz(head);
	
	printf("Uwalnianie pamieci\n");
	head = deleteAll(head);
	if (head == NULL){
		printf("Pamiec uwolniona\n\n");
	}
	return 0;
}

void kodZaciemniajacyPrzekaz(struct node* head){
	
	printf("\nIlosc elementow = %d\n", nodeCount(head));
	printf("Oto one: ");
	showData(head);
	printf("\n\n");
}
int nodeCount(struct node *head){
	
	int count = 0;
	struct node *temp = head;
	
	if(temp == NULL){
		printf("Lista pusta");
	}
	while(temp != NULL){
		temp = temp->link;
		count++;
	}
	return count;
}

void showData(struct node *head){
	
	struct node *temp = head;
	
	if(temp == NULL) {
		printf("Lista pusta");
	}
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->link;
	}
}

struct node* deleteAll(struct node *head){
	
	struct node *temp = head;
	while(temp != NULL){
		temp = temp->link;
		free(head);
		head = temp;
	}
	return head;
}

struct node* addAtBeginning(struct node *head, int number){
	
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = number;
	ptr->link = head;
	head = ptr;
	return head;
}

void addAtEnd(struct node *head, int number){
	
	struct node *ptr = head;
	
	struct node *temp = malloc(sizeof(struct node));
	temp->data = number;
	temp->link = NULL;
	
	while(ptr->link != NULL) {
		ptr = ptr->link;
	}
	ptr->link = temp;
}

struct node* deleteFirst(struct node *head){
	
	if(head == NULL ){
		printf("Lista pusta");
	}
	else{
		struct node *ptr = head;
		head = head->link;
		free(ptr);
		ptr = NULL;
	}
	return head;
}

void deleteLast(struct node *head){
	
	if(head == NULL ){
		printf("Lista pusta");
	}
	else if(head->link == NULL){
		free(head);
		head = NULL;
	}
	else {
		struct node *temp = head;
		struct node *temp2 = head;
	       	
		while (temp->link != NULL) {
			temp2 = temp;
			temp = temp->link;
		}
		temp2->link = NULL;
		free(temp);
		temp = NULL;
	}
}

void addNodeAtPosition(struct node *head, int number, int position){
	
	struct node *ptr = head;
	
	struct node *ptr2 = malloc(sizeof(struct node));
	ptr2->data = number;
	ptr2->link = NULL;
	
	while(position != 2){
		ptr = ptr->link;
		position--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;
}

void deleteNodeAtPosition(struct node **head, int position){
	
	struct node *current = *head;
	struct node *previous = *head;
	
	if(*head == NULL){
		printf("Lista jest pusta");
	}
	else if(position == 0){
		*head = current->link;
		free(current);
		current = NULL;
	}
	else{
		while(position != 1){
			previous = current;
			current = current->link;
			position--;
		}
		previous->link = current->link;
		free(current);
		current = NULL;
	}
}
