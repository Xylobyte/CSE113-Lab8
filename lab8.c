#include <stdio.h>
#include <stdlib.h>
#define BUFFER 20


struct node_t {
    double data;
    struct node_t *next;
};


struct node_t *create_node(double n);
void print_node(struct node_t *node);
void print_list(struct node_t *head);
struct node_t *insert_head(struct node_t *head, struct node_t *node);
struct node_t * insert_tail(struct node_t *head, struct node_t *node);
struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos);
int count_nodes(struct node_t *head);
struct node_t *find_node(struct node_t *head, double n);
struct node_t *delete_node(struct node_t *head, double n);
void delete_list(struct node_t *head);


int main() {
    char in[BUFFER];
    int intIn;
    double doubleIn;
    struct node_t *head = NULL;
    while(1) {
        printf("\n1) Enter a number\n");
        printf("2) Delete a number\n");
        printf("3) Print all numbers\n");
        printf("4) Tell how many items are in the list\n");
        printf("5) Find if a number in the list\n");
        printf("6) Quit\n");
        printf(">> ");
        fgets(in, BUFFER, stdin);
        sscanf(in, "%d", &intIn);
        switch(intIn) {
            case 1:
                printf("\nEnter a number\n");
                printf(">> ");
                fgets(in, BUFFER, stdin);
                sscanf(in, "%lf", &doubleIn);
                printf("\n1) Insert at head\n");
                printf("2) Insert at tail\n");
                printf("3) Insert in middle\n");
                printf(">> ");
                fgets(in, BUFFER, stdin);
                sscanf(in, "%d", &intIn);
                switch(intIn) {
                    case 1:
                        head = insert_head(head, create_node(doubleIn));
                        break;
                    case 2:
                        head = insert_tail(head, create_node(doubleIn));
                        break;
                    case 3:
                        printf("Enter a position for insert\n");
                        printf(">> ");
                        fgets(in, BUFFER, stdin);
                        sscanf(in, "%d", &intIn);
                        break;
                }
                break;
            case 2:
                
                break;
            case 3:
                print_list(head);
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:
                delete_list(head);
                exit(0);
                break;
        }
    }
    return 0;
}

struct node_t *create_node(double n) {
    struct node_t *node = malloc(sizeof(struct node_t));
    node->data = n;
    node->next = NULL;
    return node;
}

void print_node(struct node_t *node) {
    printf("Node: %p   Data: %lf   Next: %p\n", node, node->data, node->next);
}

void print_list(struct node_t *head) {
    while (head != NULL) 
    { 
        print_node(head);
        head = head->next; 
    }
}

struct node_t *insert_head(struct node_t *head, struct node_t *node) {
    node->next = head;
    return node;
}

struct node_t * insert_tail(struct node_t *head, struct node_t *node) {
    if (head == NULL){
        return insert_head(head, node);
    }
    struct node_t *h = head;
    while (head->next != NULL) 
    {
        head = head->next; 
    }
    head->next = node;
    return h;
}

struct node_t *insert_middle(struct node_t *head, struct node_t *node, int pos) {
    return head;
}

int count_nodes(struct node_t *head) {
    return 0;
}

struct node_t *find_node(struct node_t *head, double n) {
    return head;
}

struct node_t *delete_node(struct node_t *head, double n) {
    return head;
}

void delete_list(struct node_t *head) {

}