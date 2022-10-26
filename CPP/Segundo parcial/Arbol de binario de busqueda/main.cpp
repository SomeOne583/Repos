#include "BST.h"
#include <iostream>
using namespace std;

int main() {
        BST<float> bst;
        bst.insert(5);
        bst.insert(3);
        bst.insert(1);
        bst.insert(7);
        bst.insert(6);
        bst.insert(8);
        bst.print();

        return 0;
}