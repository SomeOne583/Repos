template<class T> class LinkedList;
template<class T>
class Node {
        friend class LinkedList<T>;
        public:
                Node(T e) {
                        data = e;
                        next = nullptr;
                }
        private:
                T data;
                Node<T> *next;
};