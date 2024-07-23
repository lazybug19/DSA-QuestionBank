#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct Node_t
{
    int data;
    struct Node_t *next;
};
typedef struct Node_t Node;
// Creates a new node with given value and returns a pointer to it
Node *createNode(int value)
{
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
// Creates a new node with given value and adds it to
// the back of the given singly linked list,
// returns a pointer to the newly created node
Node *addToList(Node *head, int val)
{
    Node *newNode = createNode(val);
    if (head == NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}
// Creates a singly linked list by reading input and
// returns a pointer the head of the newly created linked list
Node *readList()
{
    int n;
    scanf("%d", &n);
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (head == NULL)
        {
            head = addToList(head, x);
        }
        else
        {
            addToList(head, x);
        }
    }
    return head;
}
// Prints the values stored in the nodes of the given singly linked list
void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}
// Frees the memory dynamically allocated to
// all the nodes of the given singly linked list
void freeList(Node *head)
{
    Node *cur, *nxt;
    cur = head;
    while (cur != NULL)
    {
        nxt = cur->next;
        free(cur);
        cur = nxt;
    }
}
// Function definition goes here
Node *mergeLists(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *merged = NULL;
    if (head1->data < head2->data)
    {
        merged = head1;
        merged->next = mergeLists(head1->next, head2);
    }
    else
    {
        merged = head2;
        merged->next = mergeLists(head1, head2->next);
    }
    return merged;
}

Node *findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *sortList(Node *head)
{
    // If there's only one node, the linked list is already sorted
    if (head->next == NULL)
        return head;

    // More than one node, so we divide the linked list into two halves
    Node *midl = findMiddle(head);
    Node *midr = midl->next;
    midl->next = NULL;

    // Recurively sort the two halves
    Node *head1 = head;
    Node *head2 = midr;
    head1 = sortList(head1);
    head2 = sortList(head2);

    // Merge the two sorted halves
    return mergeLists(head1, head2);
}

int main(void)
{
    // Function calls go here
    Node *head = readList();
    head = sortList(head);
    printList(head);
    freeList(head);
    return 0;
}