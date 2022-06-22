#include <stdio.h>
#include <stdlib.h>
  
struct Node {
    int data;
    struct Node* next;
};
  
void print_linked_list_forward(struct Node* n){
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}
  
int main(){

    struct Node*first_node=NULL;
    struct Node*second_node=NULL;
    struct Node*third_node=NULL;
    struct Node*fourth_node=NULL;
  
    first_node=malloc(sizeof(struct Node));
    second_node=malloc(sizeof(struct Node));
    third_node=malloc(sizeof(struct Node));
    fourth_node=malloc(sizeof(struct Node));

    first_node->data=1; 
    second_node->data=2;
    third_node->data=3;
    fourth_node->data=4;

    first_node->next=second_node;
    second_node->next=third_node;
    third_node->next=fourth_node;
    fourth_node->next=NULL;

    print_linked_list_forward(first_node);

    free(first_node);
    free(second_node);
    free(third_node);
    free(fourth_node);
  
    return 0;
}
