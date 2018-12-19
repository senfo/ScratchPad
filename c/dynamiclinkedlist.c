#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void display(Node *);
void freeList(Node *);
void push(Node **, int);
Node *reverse(Node *);

int main(void)
{
    int x;
    Node *node = NULL;
    Node *reversed;
    
    // Initialize the timer
    srand(time(NULL));

    // Generate some random data for our linked list
    for (x = 0; x < 10; x++)
    {
        push(&node, rand() % 100);
    }
    
    // List should be displayed forward or we're borked
    display(node);
    
    // Reverse the list
    reversed = reverse(node);
    display(reversed);
    
    // We don't need to clean the original list because they all point to the same thing
    freeList(reversed);

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

void freeList(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    freeList(head->next);
    free(head);
}

void push(Node **head, int value)
{
    Node *newNode = malloc(sizeof (Node));
    Node *node = (*head);
    Node *prev;
    Node *current;

    newNode->value = value;
    newNode->next = NULL;

    if (node == NULL)
    {
        node = newNode;
        (*head) = node;
    }
    else
    {
        prev = node;
        current = node->next;

        while (current != NULL)
        {
            prev = current;
            current = prev->next;
        }

        prev->next = newNode;
    }
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