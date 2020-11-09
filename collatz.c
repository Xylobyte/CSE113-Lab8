/**
 * @file collatz.c
 * @author Donovan Griego
 * @brief Prints the hailstone sequence for a given number
 * @date 2020-11-08
 */
#include <stdlib.h>
#include <stdio.h>
#define BUFFER 20

struct node_t {
    int data;
    struct node_t *next;
};

void delete_list(struct node_t *head);

int main() {
    int n;
    int i = 0;
    char in[BUFFER];
    printf("\nEnter a value for n\n");
    printf(">> ");
    fgets(in, BUFFER, stdin);
    sscanf(in, "%d", &n);
    struct node_t *head = NULL;
    struct node_t *tail = NULL;
    printf("n = %d\n",n);
    while(1) {
        struct node_t *node = malloc(sizeof(struct node_t));
        node->data = n;
        node->next = NULL;
        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        i++;
        if(n == 1) {
            break;
        } else if(n % 2 == 0) {
            n = n / 2;
        } else {
            n = (n * 3) + 1;
        }
    }
    printf("cycle length = %d\n", i);
    struct node_t *h = head;
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    delete_list(h);
}

/**
 * @brief Frees every element in a list
 * 
 * @param head head of the list to free
 */
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