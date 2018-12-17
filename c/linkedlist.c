#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void display(Node *);
Node *reverse(Node *);

int main(void)
{
    Node a;
    Node b;
    Node c;
    Node *d;
    
    a.value = 1;
    a.next = &b;
    
    b.value = 2;
    b.next = &c;
    
    c.value = 3;
    c.next = NULL;
    
    // Display forward
    display(&a);
    
    // Rerverse it and display
    d = reverse(&a);
    display(d);

    return 0;
}

void display(Node *node)
{
    printf("%d%s", node->value, node->next == NULL ? "\n" : "->");
    fflush(stdout);

    if (node->next == NULL)
    {
        return;
    }
    
    display(node->next);
}

Node *reverse(Node *node)
{
    Node *prev = NULL;
    Node *current = node;
    Node *next;
    
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}