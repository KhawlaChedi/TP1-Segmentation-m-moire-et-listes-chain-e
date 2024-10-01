#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createList(int n) {
    Node* head = NULL;
    Node* temp = NULL;

    for (int i = 1; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = i;
        newNode->next = NULL;

        if (!head) {
            head = newNode; 
        } else {
            temp->next = newNode; 
            }
        temp = newNode;  
        }

    return head;
}


int listLength(Node* head) {
    int length = 0;
    Node* current = head;  
    while (current) {
        length++;
        current = current->next; 
    }
    return length;
}


void displayList(Node* head) {
    Node* current = head;  
    while (current) {
        printf("%p %d\n", current, current->value);
        current = current->next; 
    }
}


void removeFirst(Node* head) {
    if (!head) return NULL;  
    
    if (!head->next) {       
        free(head);         
        return NULL;        
    }

    Node* temp = head;     
    head = head->next;       
    free(temp);            

}


void removeLast(Node* head) {
    if (!head) return NULL;  

    if (!head->next) {       
        free(head);         
        return NULL;        
    }

    Node* current = head;    
    while (current->next->next) {
        current = current->next;  
    }

    free(current->next);       
    current->next = NULL;     
}

Node* addToEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (!head) {
        return newNode;
      }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
