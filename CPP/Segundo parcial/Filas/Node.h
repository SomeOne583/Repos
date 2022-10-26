template<class T> class Queue;
template<class T>
class Node {
        friend class Queue<T>;
        public:
                Node(T e) {
                        data = e;
                        next = nullptr;
                }
        private:
                T data;
                Node<T> *next;
};