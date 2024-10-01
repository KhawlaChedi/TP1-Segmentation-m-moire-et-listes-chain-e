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
    for (Node* current = head; current != NULL; current = current->next) {
        length++;
    }
    return length;
}

void displayList(Node* head) {
    for (Node* current = head; current != NULL; current = current->next) {
        printf("%p %d\n", current, current->value);
    }
}

Node* removeFirst(Node* head) {
    if (!head) return NULL;  
   
    if (!head->next) {      
        free(head);
        return NULL ;              
    }

    Node* temp = head;    
    head = head->next;    
    free(temp);      
    return head;      

}

Node* removeLast(Node* head) {
    if (!head) return NULL;  

    if (!head->next) {      
        free(head);        
        return NULL;        
    }

    Node* current;
    for (current = head; current->next->next != NULL; current = current->next) {
    }
    free(current->next);      
    current->next = NULL;
    return head;    
}

Node* addToEnd(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
        return head;
    }

    Node* temp;
    for (temp = head; temp->next != NULL; temp = temp->next) {

    }
    temp->next = newNode;
    return head;
}

Node* addToBeginning(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  
    newNode->value = value;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
        return head;
    }

    newNode->next = head;  
    head = newNode;                    
    return head;                              
}

Node* concatLists(Node* list1, Node* list2) {
    if (!list1) return list2;  
    if (!list2) return list1;  

    Node* temp = list1;
    for (; temp->next != NULL; temp = temp->next) {

    }
    temp->next = list2;
    return list1; 
}

Node* mapList(Node* head, int (*func)(int)) {
    if (!head) return NULL;  

    Node* newHead = NULL;
    Node* newTail = NULL;

    for (Node* current = head; current != NULL; current = current->next) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = func(current->value); 
        newNode->next = NULL;

        if (!newHead) {
            newHead = newNode; 
            newTail = newNode; 
        } else {
            newTail->next = newNode; 
            newTail = newNode; 
        }
    }
    return newHead;
}


int square(int x) {
    return x * x;
}

int main() {
	printf("********************* Linked_list ***********************\n");
    Node* list1 = createList(5);
    Node* list2 = createList(3);
    displayList(list1);
    
	printf("********************* Lenght ***********************\n");
    printf("Length of list: %d\n", listLength(list1));
    
	printf("********************* Add to the begin ***********************\n");
    list1 = addToBeginning(list1, 0);
    displayList(list1);
    
	printf("********************* Add to the end ***********************\n");
    list1 = addToEnd(list1, 6);
    displayList(list1);
    
	printf("*********************remove First***********************\n");
    list1=removeFirst(list1);
    displayList(list1);
    
	printf("*********************remove Last***********************\n");
    list1 = removeLast(list1);
    displayList(list1);
    
	printf("*********************concat list***********************\n");
    Node* concatenatedList = concatLists(list1, list2);
    printf("Concatenated list:\n");
    displayList(concatenatedList);
	
	
	Node* squaredList = mapList(concatenatedList, square);
    printf("*********************Linked list after square :*********************\n");
    displayList(squaredList);
    
    
    free(list1);
    free(list2);
    free(concatenatedList);
    frees(squaredList);
    return 0;
}
