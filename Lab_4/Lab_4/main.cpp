#include "BST.h"

int main()
{
    BST bst;

    bst.insert(22, "Jane");
    bst.insert(22, "Mary");
    bst.insert(0, "Harold");
    bst.insert(9, "Edward");
    bst.insert(37, "Victoria");
    bst.insert(4, "Matilda");
    bst.insert(26, "Oliver");
    bst.insert(42, "Elizabeth");
    bst.insert(19, "Henry");
    bst.insert(4, "Stephen");
    bst.insert(24, "James");
    bst.insert(-1, "Edward");
    bst.insert(31, "Anne");
    bst.insert(23, "Elizabeth");
    bst.insert(1, "William");
    bst.insert(26, "Charles");

    bst.displayTree();
}
