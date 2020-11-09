#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
        printf("5) Find a number in the list\n");
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
                        head = insert_middle(head, create_node(doubleIn), intIn);
                        break;
                }
                break;
            case 2:
                printf("Enter a value to delete from the list\n");
                printf(">> ");
                fgets(in, BUFFER, stdin);
                sscanf(in, "%lf", &doubleIn);
                head = delete_node(head, doubleIn);
                break;
            case 3:
                print_list(head);
                break;
            case 4:
                printf("\nThere are %d items in the list.\n", count_nodes(head));
                break;
            case 5:
                printf("Enter a value to find in the list\n");
                printf(">> ");
                fgets(in, BUFFER, stdin);
                sscanf(in, "%lf", &doubleIn);
                struct node_t *n = find_node(head, doubleIn);
                if(n != NULL) {
                    printf("\nThe value was found in the list\n");
                    printf("%-15s %-15s %-15s\n", "Node", "Data", "Next");
                    print_node(n);
                } else {
                    printf("\nThe value was not found in the list\n");
                }
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
    printf("%-15p %-15lf %-15p\n", node, node->data, node->next);
}

void print_list(struct node_t *head) {
    printf("\n%-15s %-15s %-15s\n", "Node", "Data", "Next");
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
    if ((head == NULL || pos == 1) && pos > 0){
        return insert_head(head, node);
    }else if (pos > 1) {
        struct node_t *h = head;
        int i = 2;
        while (head->next != NULL && i != pos) 
        {
            head = head->next; 
            i++;
        }
        node->next = head->next;
        head->next = node;
        return h;
    } else {
        free(node);
        printf("\nThat is not a valid position; Number was not recorded.\n");
        return head;
    }
}

int count_nodes(struct node_t *head) {
    if(head == NULL){
        return 0;
    }
    int i = 1;
    while (head->next != NULL) 
        {
            head = head->next; 
            i++;
        }
    return i;
}

struct node_t *find_node(struct node_t *head, double n) {
    if(head == NULL){
        printf("\nThere are no numbers in the list\n");
        return NULL;
    }
    int found = 0;
    while (head != NULL) 
    {
        if(isgreaterequal(head->data, n) && islessequal(head->data, n)){
            found = 1;
            break;
        }
        head = head->next;
    }
    if(found) {
        return head;
    } else {
        return NULL;
    }
}

struct node_t *delete_node(struct node_t *head, double n) {
    if(head == NULL){
        printf("\nThere are no numbers in the list\n");
        return head;
    }
    struct node_t *h = head;
    struct node_t *prev;
    int i = 1;
    int found = 0;
    while (head != NULL) 
    {
        if(isgreaterequal(head->data, n) && islessequal(head->data, n)){
            found = 1;
            break;
        }
        prev = head;
        head = head->next; 
        i++;
    }
    if(found) {
        if(i == 1){
            h = head->next;
            free(head);
        } else if(head->next == NULL) {
            prev->next = NULL;
            free(head);
        } else {
            prev->next = head->next;
            free(head);
        }
    } else {
        printf("\nThe number was not found in the list; nothing was deleted\n");
    }
    return h;
}

void delete_list(struct node_t *head) {
    if(head == NULL){
        return;
    }
    struct node_t *next = head;
    while (head != NULL) 
    {
        next = head->next;
        free(head);
        head = next;
    }
}