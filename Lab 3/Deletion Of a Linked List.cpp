#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void linkedListTraversal(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
Node *deleteFirst(Node *head)
{
    Node *ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
Node *deleteAtIndex(Node *head, int index)
{
    Node *p = head;
    Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    delete q;
    return head;
}

// Case 3: Deleting the last element
Node *deleteAtLast(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }

    p->next = nullptr;
    delete q;
    return head;
}

// Case 4: Deleting the element with a given value from the linked list
Node *deleteAtIndexx(Node *head, int value)
{
    Node *p = head;
    Node *q = head->next;
    while (q->data != value && q->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        delete q;
    }
    return head;
}

int main()
{
    Node *head = nullptr;
    Node *second = nullptr;
    Node *third = nullptr;
    Node *fourth = nullptr;

    // Allocate memory for nodes in the linked list in Heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = nullptr;

    cout << "Linked list before deletion" << endl;
    linkedListTraversal(head);

     head = deleteFirst(head); // For deleting the first element of the linked list
    head = deleteAtIndex(head, 2);
    head = deleteAtLast(head);
    cout << "Linked list after deletion" << endl;
    linkedListTraversal(head);

    // Don't forget to free the memory allocated for the nodes in C++ with delete
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
