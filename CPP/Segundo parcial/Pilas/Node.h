template<class T> class Stack;
template<class T>
class Node {
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