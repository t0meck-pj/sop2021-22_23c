/*
Napisz program implementujący listę jednostronnie wiązaną.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} LinkedList;

LinkedList *create();
int length(LinkedList *list);
void printLinkedList(LinkedList *first);

void unshift(LinkedList *list, int data);
void push(LinkedList *list, int data);

int shift(LinkedList *list);
void pop(LinkedList *list);

int get(LinkedList *list, int index);
void delete (LinkedList *list, int index);
void add(LinkedList *list, int index, int data);
void destroy(LinkedList *list);

LinkedList *find(LinkedList *list, int data);

int main(int argc, char *argv[])
{
    LinkedList *list = create();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    push(list, 4);
    push(list, 5);
    printf("%i\n", length(list));
    printf("---\n");
    delete (list, 1);
    printLinkedList(list);
    printf("---\n");
    add(list, 2, 88);
    printLinkedList(list);
    printf("---\n");
    pop(list);
    printLinkedList(list);
    printf("---\n");
    shift(list);
    printLinkedList(list);
    printf("---\n");
    unshift(list, 50);
    printLinkedList(list);
    printf("---\n");
    printf("%i\n", get(list, 0));
    printf("--dd-\n");
    destroy(list);
    printLinkedList(list);
    printf("--dd-\n");
    return 0;
}

void destroy(LinkedList *list)
{
    if (list->next)
    {
        destroy(list->next);
    }
    free(list);
}

void add(LinkedList *list, int index, int data)
{
    int i = index;
    LinkedList *currentP = list;
    while (currentP != NULL && i--)
    {
        currentP = currentP->next;
    }
    LinkedList *afterP = currentP->next;
    currentP->next = (LinkedList *)malloc(sizeof(LinkedList));
    currentP->next->data = data;
    currentP->next->next = afterP;
}

void delete (LinkedList *list, int index)
{
    int i = index;
    LinkedList *currentP = list;
    while (currentP != NULL && i--)
    {
        currentP = currentP->next;
    }
    LinkedList *toDeleteP = currentP->next;
    currentP->next = toDeleteP->next;
    free(toDeleteP);
}

int length(LinkedList *list)
{
    LinkedList *current = list->next;
    int i = 0;

    while (current != NULL)
    {
        i++;
        current = current->next;
    }
    return i;
}

void printLinkedList(LinkedList *list)
{
    LinkedList *current = list->next;

    while (current != NULL)
    {
        printf("%i\n", current->data);
        current = current->next;
    }
}

void pop(LinkedList *list)
{
    LinkedList *currentP = list;

    while (currentP->next->next != NULL)
    {
        currentP = currentP->next;
    }
    LinkedList *lastElementP = currentP->next->next;
    free(lastElementP);
    currentP->next = NULL;
}

void unshift(LinkedList *list, int data)
{
    LinkedList *firstElement = list->next;
    LinkedList *newElement = (LinkedList *)malloc(sizeof(LinkedList));
    newElement->data = data;
    newElement->next = firstElement;
    list->next = newElement;
}

void push(LinkedList *list, int data)
{
    LinkedList *currentP = list;

    while (currentP->next != NULL)
    {
        currentP = currentP->next;
    }
    currentP->next = (LinkedList *)malloc(sizeof(LinkedList));
    currentP->next->data = data;
    currentP->next->next = NULL;
}

int get(LinkedList *list, int index)
{
    int i = index + 1; // omijamy element początkowy listy, numeracja od 0
    LinkedList *currentP = list;
    while (currentP != NULL && i--)
    {
        currentP = currentP->next;
    }
    return currentP->data;
}

int shift(LinkedList *list)
{
    LinkedList *firstElement = list->next;

    int returned = firstElement->data;
    list->next = firstElement->next;
    free(firstElement);
    return returned;
}

LinkedList *find(LinkedList *list, int data)
{
    LinkedList *current = list->next;

    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }
    return list;
}

LinkedList *create()
{
    LinkedList *first = NULL;
    first = (LinkedList *)malloc(sizeof(LinkedList));
    first->data = 0;
    first->next = NULL;
    return first;
}