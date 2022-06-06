#include <iostream>
#include <cstdlib>

using namespace std;
class Node {
public:
    int data;
    Node* next;
};

void print(Node* node);
void push_top(Node** head_node, int new_element);
void push_end(Node** head_node, int new_element);
void pop_top(Node** head_node);
void pop_end(Node** head_node);

int main()
{

    // tworzymy element head i przypisujemy mu wartosc NULL - czyli jest pusty
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

 //   push_top(&head,2);
    push_end(&head,9);

    pop_top(&head);
    pop_end(&head);
    print(head);

    return 0;
}

void push_top(Node** head_node, int new_element) {

    Node* new_node = new Node(); // tworzymy nowe miejsce na nowy element

    new_node->data = new_element; // dodajemy liczbe
    new_node->next = (*head_node); // nastepnym node'em w kolejce, jest aktualny head

    (*head_node) = new_node; //ustawiamy head jako nasz nowy element

}

void push_end(Node** head_node, int new_element) {

    Node* new_node = new Node();

    new_node->data = new_element;
    new_node->next = NULL; // w tym przypadku, kolejny node jest pusty

    Node* last_node = *head_node; // definiujemy nasz aktualny head, jako ostatni

    if(*head_node == NULL) {

        *head_node = new_node; // jesli lista jest pusta, head = nowy node

    }

    while(last_node->next != NULL) {

        last_node = last_node->next; //szukamy ostatniego node'a

    }
    last_node->next = new_node;
}

void pop_top(Node** head_node) {

    Node* temp = NULL;

    temp = (*head_node)->next;
    delete(*head_node);
    *head_node = temp;
}

void pop_end(Node** head_node) {

    Node* temp = *head_node;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void print(Node* node) {

    while (node != NULL) {

        cout << node->data << " ";
        node = node->next;
    }

}
