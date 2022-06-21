#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int data;
    struct Element * next;
} node;

void addOnStart(node **head, int num);
void addOnEnd(node **head, int num);
void removeOnStart(node **head);
void removeOnEnd(node **head);
void displayList(node *head);
int sizeOfList(node *head);

int main() {
    node *head;
    head = (node *)malloc(sizeof(node));
    head = NULL;

    addOnStart(&head, 1);
    addOnStart(&head, 2);
    addOnEnd(&head, 3);
    removeOnStart(&head);
    addOnStart(&head, 4);
    removeOnEnd(&head);
    displayList(head);
    sizeOfList(head);
    free(head);

    return 0;
}

void addOnStart(node **head, int num) {
    node * present;
    present = (node *)malloc(sizeof(node));

    present->data = num;
    present->next = (*head);
    *head = present;
}

void addOnEnd(node **head, int num) {
    if(*head == NULL) {
        *head = (node *)malloc(sizeof(node));
        (*head)->data = num;
        (*head)->next = NULL;
    } else {
        node * present = *head;

        while (present->next != NULL) {
            present = present->next;
        }

        present->next = (node *)malloc(sizeof(node));
        present->next->data = num;
        present->next->next = NULL;
    }
}

void removeOnStart(node **head) {
    node * temp = NULL;

    if (*head != NULL) {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}

void removeOnEnd(node **head) {
    if ((*head)->next == NULL) {
        *head = NULL;
    } else {
        node *present = *head;
        while (present->next->next != NULL) {
            present = present->next;
        }

        free(present->next);
        present->next = NULL;
    }
}

void displayList(node *head) {
    if (head == NULL) {
        printf("Lista jest pusta");
    } else {
        node *present = head;
        do {
            printf("%i \n", present->data);
            present = present->next;
        } while (present != NULL);
    }
}

int sizeOfList(node *head) {
    int i = 0;

    if (head == NULL) return 0;
    else {
        node *present=head;
        do {
            i++;
            present = present->next;
        } while (present != NULL);
    }

    return i;
}
