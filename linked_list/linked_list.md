# Linked List

A data structure consisting of nodes containing data and a pointer to its 
neighboring node. Since it is non-contiguous, it is stored on the heap and 
requiring iteration to access elements rather than directly as found in 
arrays. Linked lists dynamic structure affords constant time prepending and appending, making them a viable option for collections of uncertain size.

## Operations

### Find

#### Front

$O(1)$

#### Arbitrary

$O(n)$

#### End

$O(1)$

### Insertion

Insertion operations are constant time, but index access is $O(n)$ therefore
arbitrary insertions inevitable must iterate to reach given index. Prepending
and appending are constant time due to having direct pointers, however.

#### Front

$O(1)$

#### Arbitrary

$O(n)$

#### End

$O(1)$

### Removal

Like insertion, removal operations are constant time but removals at arbitrary
indices require iteration causing O(n) complexity for elements without direct 
access.

#### Front

$O(1)$

#### Arbitrary

$O(n)$

#### End

$O(1)$

