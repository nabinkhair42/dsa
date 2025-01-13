// implementation of dynamic queue:
//  Yesma Chai, dynamically allocated array use garera queue implement garna parne.
#include <stdio.h>
#include <stdlib.h>

// Queue ko structure banayeko
struct Queue {
    int data;            // Queue ko data
    struct Queue *next;  // Agadi ko pointer
} *front, *rear;        // front ra rear pointer define gareko

// Queue ko enqueue operation
void enqueue(int data) {
    // Naya node ko lagi memory allocation gareko
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->data = data;  // Data store garna
    newNode->next = NULL;   // Next pointer null gareko 

    // Yadi queue khali cha bhane
    if (front == NULL && rear == NULL) {
        front = rear = newNode;  // Front ra rear duitai lai naya node ma point garauna
    } else {
        rear->next = newNode;    // Rear ko next ma naya node connect garauna
        rear = newNode;          // Rear pointer lai naya node ma update garauna
    }
}

// Queue ko dequeue operation
void dequeue() {
    // Front pointer ma node cha bhane, dequeue garauna
    struct Queue *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");  // Yadi queue khali cha bhane, message dincha
        return;
    }
    
    // Yadi queue ma ek matra node cha bhane
    if (front == rear) {
        front = rear = NULL;  // Front ra rear dono null garauna
    } else {
        front = front->next;  // Front pointer agadi ko node ma point garauna
    }

    free(temp);  // Pahilo node ko memory free garauna
}

// Queue ko display operation
void display() {
    struct Queue *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");  // Yadi queue khali cha bhane, message dincha
        return;
    }

    // Queue ko sabai elements display garauna
    while (temp != NULL) {
        printf("%d ", temp->data);  // Data print garauna
        temp = temp->next;          // Agadi ko node ma jancha
    }
    printf("\n");
}

int main() {
    front = rear = NULL;  // Initializing front ra rear pointer lai NULL

    // Queue ma elements add garauna (enqueue)
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    printf("Queue after enqueuing 10, 20, 30: ");
    display();  // Queue ko current state dekhaune

    // Queue bata element remove garauna (dequeue)
    dequeue();
    
    printf("Queue after dequeuing one element: ");
    display();  // Queue ko updated state dekhaune

    return 0;
}
