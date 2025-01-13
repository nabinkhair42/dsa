// Doubly Linked List vaneko, ek data structure ho jasma previous node ra next node ko pointer hunxa plus data pani hunxa

#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List ko node ko structure banayeko
struct Node {
    int data;              // Data ko field
    struct Node *prev;     // Previous node ko pointer
    struct Node *next;     // Next node ko pointer
} *head;                   // Head pointer define gareko

// Doubly Linked List ko insertion operation (insert at end)
void insertEnd(int data) {
    // Naya node ko lagi memory allocation garne
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;  // Data store garne
    newNode->next = NULL;   // Next pointer null garne (last node hune)
    
    if (head == NULL) {
        newNode->prev = NULL;  // Yadi list khali cha bhane, prev pointer null garne
        head = newNode;         // Head pointer lai naya node ma point garne
    } else {
        struct Node *temp = head;
        // Last node ko through agadi jancha
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;     // Last node ko next pointer lai naya node ma set garne
        newNode->prev = temp;     // Naya node ko prev pointer lai last node ma set garne
    }
}

// Doubly Linked List ko deletion operation (delete from beginning)
void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");  // Yadi list khali cha bhane, message dincha
        return;
    }
    
    struct Node *temp = head;  // Head node lai temporary variable ma store garne
    head = head->next;         // Head pointer lai next node ma update garne
    if (head != NULL) {
        head->prev = NULL;      // Naya head node ko prev pointer lai null garne
    }
    
    free(temp);  // Purano head node ko memory free garne
}

// Doubly Linked List ko traversal operation (display the list)
void display() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");  // Yadi list khali cha bhane, message dincha
        return;
    }

    // List ko sabai elements display garne
    while (temp != NULL) {
        printf("%d ", temp->data);  // Data print garne
        temp = temp->next;          // Agadi ko node ma jancha
    }
    printf("\n");
}

// Reverse traversal (display from end to start)
void displayReverse() {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");  // Yadi list khali cha bhane, message dincha
        return;
    }

    // Last node ma jancha
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Reverse direction ma display garne
    while (temp != NULL) {
        printf("%d ", temp->data);  // Data print garne
        temp = temp->prev;          // Agadi ko node ma jancha (reverse)
    }
    printf("\n");
}

int main() {
    head = NULL;  // List ko head pointer lai initialize gareko (NULL)

    // List ma elements add garne (insert at the end)
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    
    printf("List after inserting 10, 20, 30: ");
    display();  // List ko current state dekhaune

    // List bata element remove garne (delete from the beginning)
    deleteBegin();
    
    printf("List after deleting one element from the beginning: ");
    display();  // List ko updated state dekhaune

    // List ko reverse traversal garne
    printf("Reverse traversal of the list: ");
    displayReverse();

    return 0;
}
