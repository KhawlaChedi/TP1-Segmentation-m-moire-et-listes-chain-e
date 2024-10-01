#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createCircularList(int n) {
    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 1; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = i;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head) {
            head = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;  
    }

    if (temp) {
        temp->next = head; 
        head->prev = temp; 
    }

    return head;
}


void displayList(Node* head) {
    if (!head) return;
    Node* current = head;
    do {
        printf("%p %d (prev: %p)\n", current, current->value, current->prev);
        current = current->next;
    } while (current != head);
}


Node* removeFirst(Node* head) {
    if (!head) return NULL;

    Node* tail = head->prev; 
    if (head == tail) { 
        free(head);
        return NULL;
    }

    Node* newHead = head->next;
    tail->next = newHead;
    newHead->prev = tail;

    free(head);
    return newHead;
}


Node* addToEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;

    if (!head) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    Node* tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;

    return head;
}


int main() {
    printf("********************* Circular Doubly Linked List ***********************\n");
    Node* list = createCircularList(5);
    displayList(list);

    printf("********************* Add to the End ***********************\n");
    list = addToEnd(list, 6);
    displayList(list);

    printf("********************* Remove First ***********************\n");
    list = removeFirst(list);
    displayList(list);
    
    free(list);

    return 0;
}

