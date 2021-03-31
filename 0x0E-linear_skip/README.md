# Linear Skip

## About
Looking for a specific value in a singly linked list always leads to browse every element of the list. A common way to optimize the time complexity of a search in a singly linked list is to modify the list itself by adding an “express lane” to browse it. A linked list with an express lane is called a skip list.

### C Program
C program that searches for a value in a sorted skip list of integers:
- Where list is a pointer to the head of the skip list to search in
- A node of the express lane is placed every index which is a multiple of the square root of the size of the list
- And value is the value to search for
- The Linear SKip function must return a pointer on the first node where value is located
- If value is not present in list or if head is NULL, it will return NULL