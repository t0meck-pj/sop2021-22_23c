#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
}node_t;

void print_list(node_t * head);
void push(node_t * head, int val);
int pop(node_t ** head);
int remove_last(node_t * head);

int main()
{
    int option, number;

    /* tworzymy testowa liste */
    node_t * head = (node_t *) malloc(sizeof(node_t));
    head->val = 3;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 4;
    head->next->next = (node_t *) malloc(sizeof(node_t));
    head->next->next->val = 5;

    while(1)
    {
        printf("\n\nMENU\n");
        printf("(1) Wyswietl liste.\n");
        printf("(2) Dodaj do listy.\n");
        printf("(3) Usun z poczatku listy.\n");
        printf("(4) Usun z konca listy.\n");
        printf("(0) Wyjdz\n");
        scanf("%i", &option);
        switch (option)
        {
            case 0:
                return 0;
            case 1:
                print_list(head);
                break;
            case 2:
                printf("Wpisz liczbe jaka chcesz dodac: ");
                scanf("%i", &number);
                push(head, number);
                break;
            case 3:
                pop(&head);
                break;
            case 4:
                remove_last(head);
                break;
            default:
                printf("Podaj wlasciwa opcje.");
                break;
        }
    }
}

void print_list(node_t * head)
{
    node_t * current = head;

    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push(node_t * head, int val)
{
    node_t * current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    /* dodajemy nowa wartosc do listy */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

int pop(node_t ** head) {
    int retval = -1;

    node_t * next_node = NULL;

    if (*head == NULL)
    {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int remove_last(node_t * head)
{
    int retval = 0;

    /* jesli jest tylko jeden elemet to go usunie */
    if (head->next == NULL)
    {
        retval = head->val;
        free(head);
        return retval;
    }

    /* przejscie do przedostatniego elementu */
    node_t * current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    /* teraz gdy wskazuje na przedostatni element, mozna usunac ostatni */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}
