# Stack

This stack implementation is that of a singly linked list. Stacks are 
characterized by the *LIFO* principle or Last-In-First-Out, where elements are 
removed by order of most recent insertion, in contrast with First-In-First-Out,
or *FIFO*, where elements are removed in the order in which they arrived. Think
of a stack of CDs for the former and a line at a store for the latter.

These rules lend themselves to simplicity in their implementation and operation
and are potent dynamic structures where order of processing is the only 
priority. One such case is the *memory stack* found in this very machine. LIFO
emerges scope based memory management which itself allows for recursion.

## Operations

### Push

Inserts an element at the top.

$$O(1)$$

### Pop

Removes an element from the top, returning its value.

$$O(1)$$

### Peak

Returns a read only reference from the top of the stack. Not required, perhaps 
useful