#include <stdlib.h>

typedef struct {
    int val;
    struct node *next;
} node;

void insert_node(node *head, node *prev, int data) {
    node *now = head;

    while (now != prev)
        now = now->next;

    node *new_node = (node*)malloc(sizeof( node));

    if (new_node == NULL)
        return;

    new_node->next = prev->next;
    new_node->val = data;
    prev->next = new_node;
}

void delete_node(node *head, node *del) {
    node* now = head;

    while (now->next != del)
        now = now->next;

    now->next = del->next;
    del->next = NULL;
    free(del);
}

void print_list(node *head) {
    node *now = head;

    while (now != NULL) {
        printf("%d ", now->val);
        now = now->next;
    }
}

int main() {
    node *head = NULL;

    node node3 = {3, NULL};
    node node2 = {2, &node3};
    node node1 = {1, &node2};
    head = &node1;

    printf("Initial linked list:\n");
    print_list(head);
    printf("\n");

    insert_node(head, &node2, 22);
    printf("Lets insert new node:\n");
    print_list(head);
    printf("\n");

    printf("Lets delete old node:\n");
    delete_node(head, &node3);
    print_list(head);
    return 0;
}
