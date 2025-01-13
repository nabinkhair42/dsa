// Dynamic Stack Vaneko: Stack ko size fixed hudaina, stack ko size lai runtime ma badhauna sakincha.

#include <stdio.h>
#include <stdlib.h>

// Stack ko structure banayeko
struct Stack {
    int data;             // Stack ko data
    struct Stack *next;   // Agadi ko pointer
} *top;                   // Stack ko top pointer define gareko

// Stack ko push operation (element add garaune)
void push(int data) {
    // Naya node ko lagi memory allocation garaune
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->data = data;  // Data store garaune
    newNode->next = top;    // Naya node ko next pointer lai purano top ma set garaune
    top = newNode;          // Top pointer lai naya node ma update garaune
}

// Stack ko pop operation (element remove garaune)
void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");  // Yadi stack khali cha bhane, message dincha
        return;
    }

    struct Stack *temp = top;  // Top node lai temporary variable ma store garaune
    top = top->next;           // Top pointer lai agadi ko node ma update garaune
    free(temp);                // Pahilo node ko memory free garaune
}

// Stack ko display operation (elements dekhaune)
void display() {
    struct Stack *temp = top;
    if (top == NULL) {
        printf("Stack is empty\n");  // Yadi stack khali cha bhane, message dincha
        return;
    }

    // Stack ko sabai elements display garaune
    while (temp != NULL) {
        printf("%d ", temp->data);  // Data print garaune
        temp = temp->next;          // Agadi ko node ma jancha
    }
    printf("\n");
}

int main() {
    top = NULL;  // Stack ko top pointer lai initialize gareko (NULL)

    // Stack ma elements add garaune (push)
    push(10);
    push(20);
    push(30);

    printf("Stack after pushing 10, 20, 30: ");
    display();  // Stack ko current state dekhaune

    // Stack bata element remove garaune (pop)
    pop();

    printf("Stack after popping one element: ");
    display();  // Stack ko updated state dekhaune

    return 0;
}
