#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

void kodZaciemniajacyPrzekaz(struct node*, struct node*);
int nodeCount(struct node*);
void showData(struct node*);
void showHeadTail(struct node*, struct node*);
struct node* createNode(int);
struct node* deleteAll(struct node*);
struct node* addAtBeginning(struct node*, struct node*, int);
struct node* addAtEnd(struct node*, struct node*, int);
struct node* deleteFirst(struct node*);
struct node* deleteLast(struct node*);
struct node* addNodeAtPosition(struct node*, struct node*, int, int);
struct node* deleteNodeAtPosition(struct node*, struct node*, int);

int main(){

	struct node *head, *tail;

	printf("\nTworzenie listy");
	head = createNode(1);
	tail = head;
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Dodawanie elementow od konca");
	tail = addAtEnd(head, tail, 10);
	tail = addAtEnd(head, tail, 20);
	tail = addAtEnd(head, tail, 30);
	tail = addAtEnd(head, tail, 40);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Dodawanie elementów od poczatku");
	head = addAtBeginning(head, tail, -10);
	head = addAtBeginning(head, tail, -20);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Kasowanie elementow od konca");
	tail = deleteLast(tail);
	tail = deleteLast(tail);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Dodawanie elementow od konca");
	tail = addAtEnd(head, tail, 50);
	tail = addAtEnd(head, tail, 60);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Skasowanie pierwszego, dodanie pierwszego");
	head = deleteFirst(head);
	head = addAtBeginning(head, tail, -30);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Skasowanie dwóch pierwszych");
	head = deleteFirst(head);
	head = deleteFirst(head);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Skasowanie elementu na pozycji 3");
	head = deleteNodeAtPosition(head, tail, 3);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Dodanie elementu, ma byc na pozycji 4, ostatniej");
	head = addNodeAtPosition(head, tail, 4, -100);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Dodanie elementu, ma byc na pozycji 4, nieostatniej");
	head = addNodeAtPosition(head, tail, 4, -200);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Skasowanie elementu na pozycji 0, pierwszej");
	head = deleteNodeAtPosition(head, tail, 0);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Skasowanie elementu na pozycji 4, nieostatniej");
	head = deleteNodeAtPosition(head, tail, 4);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Skasowanie elementu na pozycji 3, ostatniej");
	head = deleteNodeAtPosition(head, tail, 3);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Skasowanie elementu na pozycji 1, nieostatniej");
	head = deleteNodeAtPosition(head, tail, 1);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Dodawanie elementów od poczatku");
	head = addAtBeginning(head, tail, 500);
	head = addAtBeginning(head, tail, 1000);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Dodawanie elementu od konca");
	tail = addAtEnd(head, tail, 3000);
	kodZaciemniajacyPrzekaz(head, tail);

	printf("Ok, ok..Juz koncze te testy... = %d\n",head->data-tail->data);
	printf("Uwalnianie pamieci\n");
	head = deleteAll(head);
	if (head == NULL){
		printf("Pamiec uwolniona\n\n");
	}
	return 0;
}

void kodZaciemniajacyPrzekaz(struct node* head, struct node* tail){


	printf("\nIlosc elementow = %d\n", nodeCount(head));
	printf("Oto one: ");
	showData(head);
	printf("\n");
	showHeadTail(head, tail);
	printf("\n");
}

int nodeCount(struct node *head){

	int count = 0;
	struct node *ptr = head;

	if(ptr == NULL){
		printf("Lista pusta");
	}
	while(ptr != NULL){
		ptr = ptr->next;
		count++;
	}
	return count;
}

void showData(struct node *head){

	struct node *ptr = head;

	if(ptr == NULL) {
		printf("Lista pusta");
	}
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
}

void showHeadTail(struct node* head, struct node* tail){
		
	printf("Head dane = %d\n", head->data);
	printf("Tail dane = %d\n", tail->data);
}	

struct node* createNode(int number){

	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = number;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

struct node* deleteAll(struct node *head){

	struct node *ptr = head;
	
	while(ptr != NULL){
		ptr = ptr->next;
		free(head);
		head = ptr;
	}
	return head;
}

struct node* addAtBeginning(struct node *head, struct node *tail, int number){

	struct node *newNode = createNode(number);
	newNode->next = head;
	head->prev = newNode;
	
	if(head->next == NULL){
		tail = head;
	}
	head = newNode;
	return head;
}

struct node* addAtEnd(struct node *head, struct node *tail, int number){

	struct node *newNode = createNode(number);
	newNode->prev = tail;
	tail->next = newNode;

	if(tail->prev == NULL){
		head = tail;
	}
	tail = newNode;
	return tail;
}

struct node* deleteFirst(struct node *head){

	if(head == NULL){
		printf("Lista pusta");
	}
	else{
		struct node *ptr = head;
		head = head->next;
		free(ptr);
		head->prev = NULL;
	}
	return head;
}

struct node* deleteLast(struct node *tail){

	if(tail == NULL ){
		printf("Lista pusta");
	}
	else{
		struct node *ptr = tail;
		tail = tail->prev;
		free(ptr);
		tail->next = NULL;
	}
	return tail;
}

struct node* addNodeAtPosition(struct node *head, struct node* tail, int position, int number){

	struct node *ptr2;
	struct node *ptr = head;
	struct node *newNode = createNode(number);

	if(position == 0){
		head = addAtBeginning(head, tail, number);									}
	else{						
		while(position != 1){
			ptr = ptr->next;
			position--;
		}
		if(ptr->next == NULL){
			ptr->next = newNode;
			newNode->prev = ptr;
			tail = newNode;
		}
		else{
			ptr2 = ptr->next;
			ptr->next = newNode;
			ptr2->prev = newNode;
			newNode->next = ptr2;
			newNode->prev = ptr;
		}
	}
	return head;
}

struct node* deleteNodeAtPosition(struct node *head, struct node* tail, int position){

	struct node *ptr2 = head;
	struct node *ptr;
	
	if(head == NULL){
		printf("Lista jest pusta");
	}
	else if(position == 0){
		head = deleteFirst(head);
	}
	else{
		while(position != 0){
			ptr2 = ptr2->next;
			position--;
		}
		if(ptr2->next == NULL){
			tail = ptr2->prev;
			tail->next = NULL;
			free(ptr2);
		}	
		else{
			ptr = ptr2->prev;
			ptr->next = ptr2->next;
			ptr2->next->prev = ptr;	
			free(ptr2);
			ptr2 = NULL;
		}
	}
	return head;
}
