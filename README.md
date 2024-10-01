#TP1 - Memory Segmentation and Linked Lists

#Exercise 1 :
This C program displays the addresses of the different memory segments used in a process. 
It begins by defining an initialized global variable and an uninitialized one, then uses printf with the %p format to show their respective addresses. 
It also displays the address of a string literal and allocates memory on the heap using malloc, printing the address of this allocation. Next, it creates a local variable on the stack and displays its address. 
The program uses mmap to allocate an anonymous memory segment, showing the address if the allocation is successful. After retrieving the parent process's PID, it creates a child process using fork. In this child process, execlp is used to execute the command pmap -X, which displays the memory map of the parent process. The parent process waits for the child process to finish, and then the program frees the allocated memory and terminates.


#Exercise 2
This C program demonstrates file memory mapping using the mmap function to efficiently manipulate the contents of a file named test.txt. It starts by opening the file and retrieving its size using fstat. The program then maps the entire file into memory, allowing it to access and modify the content directly as a character array. It reverses the bytes in the file by swapping characters from the beginning and end of the mapped memory region. 
The mechanism for reversing the file's bytes involves iterating through half of the file, symmetrically swapping the bytes from the beginning with those at the end. In each loop iteration, the byte at the start is temporarily stored, then replaced by the byte from the end. The byte at the end is subsequently replaced with the stored value. This process continues until all the bytes from the start and end have been swapped, fully reversing the file's content.
 After making the changes, it unmaps the memory with munmap and closes the file descriptor.
 Finally, it prompts the user to verify the modifications by checking the file content with the cat command. This approach leverages memory mapping to enhance performance when working with large files. 

#Exercise 3
1. Linked list
This C program implements a singly linked list and provides various operations to manipulate it. Below is a brief explanation of each function:

* Node Structure : Defines the basic building block of the linked list, containing an integer value and a pointer to the next node, allowing the list to be traversed.

* createList:Uses a loop to create n nodes. For each iteration, it allocates memory for a new node, sets its value, and links it to the previous node. The head pointer is updated to point to the first node.

* listLength:Initializes a length counter to zero and iterates through the list using a pointer. For each node encountered, it increments the counter until it reaches the end (where the pointer is NULL).

* displayList:Iterates through the list, printing the memory address and value of each node. It continues until it reaches the end of the list (where the pointer is NULL).

* removeFirst:Checks if the list is empty. If not, it updates the head pointer to the next node, freeing the memory of the first node. If the list only has one node, it returns NULL.

* removeLast:First checks if the list is empty. If there’s only one node, it frees it and returns NULL. Otherwise, it traverses the list to find the second-to-last node, frees the last node, and sets the next pointer of the second-to-last node to NULL.

* addToEnd:Allocates memory for a new node, sets its value, and initializes its next pointer to NULL. If the list is empty, it sets the new node as the head. Otherwise, it traverses the list to find the last node and links the new node to it.

* addToBeginning:Allocates memory for a new node, sets its value, and points its next to the current head. It then updates the head pointer to point to the new node, effectively adding it to the front of the list.

* concatLists:Checks if either list is empty and returns the other list if so. Otherwise, it traverses the first list to find its last node and links it to the head of the second list, merging them into a single list.

* mapList:Initializes a new list head and tail. It iterates through the original list, applying a provided function to each value, creates new nodes with the transformed values, and links them together to form a new list.

* square: A simple utility function that takes an integer and returns its square by multiplying it by itself.

2. Doubly linked list :
This C program implements a Doubly linked list and provides various operations to manipulate it. Below is a brief explanation of each function:

* Node Structure: Defines a doubly linked list node with an integer value and two pointers: next (to the next node) and prev (to the previous node), allowing bidirectional traversal.

* createList: Allocates memory for n nodes. Each node's value is set in a loop from 1 to n. The new node is linked to the previous one using the next pointer, and the prev pointer of the new node is set to the last node, establishing a doubly linked structure.

* listLength: Initializes a counter and iterates through the list, incrementing the counter for each node encountered until reaching the end of the list (NULL).

* displayList: Iterates through the list, printing each node's address, value, and the address of its previous node, allowing visualization of the list's structure.

* removeFirst:Checks if the list is empty. If not, it updates the head to the next node, freeing the memory of the first node. If there was only one node, it returns NULL and cleans up properly by setting the prev of the new head to NULL.

* removeLast: Handles cases for empty and single-node lists similarly to removeFirst. For longer lists, it traverses to the second-to-last node, frees the last node, and sets the next pointer of the second-to-last node to NULL.

* addToEnd: Allocates a new node with the specified value and links it at the end of the list. If the list is empty, the new node becomes the head. Otherwise, it traverses to the last node and updates pointers accordingly.

* addToBeginning: Allocates a new node, links it as the new head, and updates the prev pointer of the current head to point to this new node. If the list is empty, it directly sets the new node as the head.

* concatLists: Concatenates two linked lists. If one list is empty, it returns the other. It finds the last node of the first list, links it to the head of the second list, and sets the prev pointer of the second list’s head to the last node of the first list.

* mapList: Transforms the original list by applying a given function (e.g., squaring values) to each node's value. It creates a new list by allocating new nodes and linking them appropriately, preserving the doubly linked structure.

* square: A utility function that returns the square of an integer, used in mapping operations to transform values in the list.

3. Doubly circular linked list

* Node Structure: Defines a node for a circular doubly linked list, which contains an integer value, a pointer to the next node, and a pointer to the prev node. This allows traversal in both directions.

* createCircularList: - Initializes an empty circular doubly linked list with n nodes.
 - Allocates memory for each node and sets its value from 1 to n.
 - If the list is empty, the new node becomes the head. Otherwise, the new node is linked to the last node using the next pointer, and the previous node's prev pointer is updated.
 - After creating all nodes, it links the last node's next pointer to the head and the head's prev pointer to the last node, forming a circular structure.

* displayList: - Displays the contents of the circular doubly linked list.
 - Uses a do-while loop to print each node's address, value, and address of the previous node, starting from the head and continuing until it loops back to the head.

* removeFirst: - Removes the first node from the circular list.
  - Checks if the list is empty. If there’s only one node, it frees it and returns NULL.
  - Otherwise, it updates the next pointer of the tail (last node) to point to the second node and updates the prev pointer of the new head to point to the tail.
  - Finally, it frees the old head and returns the new head.

* addToEnd: - Adds a new node with a specified value at the end of the circular list.
 - Allocates memory for the new node and sets its value.
 - If the list is empty, it initializes the new node to point to itself for both next and prev.
 - Otherwise, it links the new node to the current tail (last node) and updates pointers to maintain the circular structure.
