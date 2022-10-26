#pragma once

template<class T> class PriorityQueue;
template<class T> class Stack;
template<class T>
class Node {
        friend class PriorityQueue<T>;
        friend class Stack<T>;
        public:
                Node(T e) {
                        data = e;
                        next = nullptr;
                }
        private:
                T data;
                Node<T> *next;
};