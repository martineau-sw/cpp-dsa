# Doubly Linked List

A data structure consisting of nodes containing data and pointers to its 
neighboring nodes. Since it is non-contiguous, it is stored on the heap and 
requires iteration to access elements rather than directly as found in 
arrays. Linked lists dynamic structure affords constant time prepending and
appending, making them a viable option for collections of uncertain size. This
being the case, distinctions are made on time complexity analysis for 
front/back and arbirtary cases. 

## Operations

### Element access

Element access by either index or value requires iteration unless 
given index or index of value is at 0 or length-1; this unfortunately affects
any other operation that depends on arbitrary element access in the
worst case.

Since linkages are bidirectional, iteratable operations can be cut in half by
starting the operation on whichever end is closer to the desired index, for 
time complexity analysis however, this is irrelevant.

This does afford one constant time operation in removal of the tail, since that
the node can be regressed back by one instead of having to iterate through the
entirety of the list.

#### Front

$O(1)$$

#### Arbitrary

$O(n)$$

#### End

$$O(1)$$

### Insertion

Insertion operations are constant time, but index access is $O(n)$ therefore
arbitrary insertions inevitable must iterate to reach given index. Prepending
and appending are constant time due to having direct pointers, however.

#### Front (Prepend)

$$O(1)$$

#### Arbitrary

$$O(n)$$

#### End (Append)

$$O(1)$$

### Removal

Like insertion, removal operations are constant time but removals at arbitrary
indices require iteration causing O(n) complexity for elements without direct 
access.

#### Front

$$O(1)$$

#### Arbitrary

$$O(n)$$

#### End

$$O(1)$$

