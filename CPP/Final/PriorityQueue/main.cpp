#include "PriorityQueue.h"
#include <iostream>

int main() {
        PriorityQueue<int> pQueue;
        for (int i = 0; i < 10; i++) {
                pQueue.enqueue(i);
                pQueue.print();
        }
        pQueue.heapSort(1);
        pQueue.print();

        return 0;
}