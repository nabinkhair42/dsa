#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

typedef struct SLL SLL;

SLL *first = NULL, *last = NULL;

// Create Node
SLL *createNode(int data)
{
    SLL *newNode = (SLL *)malloc(sizeof(SLL));
    if (newNode == NULL)
    {
        return NULL;
    }
    else
    {
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }
}

// Insert Node at the Beginning
void insertAtBeginning(int data)
{
    printf("Inserting %d at the beginning\n", data);
    SLL *newNode = createNode(data);
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    if (first == NULL)
    { // List is empty
        first = last = newNode;
    }
    else
    { // List Contains Elements
        newNode->next = first;
        first = newNode;
    }
}

// Display Nodes
void display()
{
    SLL *temp = first;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtEnd(int data)
{
    printf("Inserting %d at the end\n", data);
    SLL *newNode = createNode(data);
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    if (first == NULL)
    { // List is empty
        first = last = newNode;
    }
    else
    { // List Contains Elements
        last->next = newNode;
        last = newNode;
    }
}

// Delete Node at the Beginning
void deleteAtBeginning()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Deleting %d from the beginning\n", first->data);
    SLL *temp = first;
    first = first->next;
    free(temp);
}

// Delete Node at the End
void deleteAtEnd()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Deleting %d from the end\n", last->data);
    SLL *temp = first;
    while (temp->next != last)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    free(last);
    last = temp;
}

int main()
{
    printf("Singly Linked List\n");
    insertAtBeginning(10);
    display();
    insertAtBeginning(20);
    display();
    insertAtBeginning(30);
    display();
    insertAtBeginning(40);
    display();

    printf("\n");
    printf("\n");
    printf("\n");
    insertAtEnd(50);
    display();
    insertAtEnd(60);
    display();
    insertAtEnd(70);
    display();
    insertAtEnd(80);
    display();

    printf("\n");
    printf("\n");
    printf("\n");
    deleteAtBeginning();
    display();

    printf("\n");
    printf("\n");
    printf("\n");
    deleteAtEnd();
    display();

    return 0;
}
