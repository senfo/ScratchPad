#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int hasCycle(Node *head);

int main(void)
{
    Node a;
    Node b;
    Node c;
    
    a.value = 1;
    a.next = &b;
    
    b.value = 2;
    b.next = &c;
    
    c.value = 3;
    c.next = &a;

    printf("Is circular? %s\n", hasCycle(&a) ? "Yes" : "No");
    
    return 0;
}

int hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
	{
            return 1; // There's a cycle
        }
    }

    return 0; // No cycle found
}

