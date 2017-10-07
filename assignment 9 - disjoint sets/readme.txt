Have used linux kernel style coding conventions. Used a bst to implement the disjoint set 
1. question_1.c 

    The code forms a bst of key nodes from user input. Initially, each node is a disjoint set. As we perform an union operation, we
    combine disjoint sets to form a bigger disjoint set. If they belong to the same disjoint set, union performs no operation. The bst
    is used for efficient search operation 0(logn); The actual disjoint sets are the linked lists. get function returns the address of 
    the node with the given input data from the tree.
    find_set returns the representative of the disjoint set to which a given node belongs to.
