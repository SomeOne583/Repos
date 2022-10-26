template<class T> class BST;
template <class T>
class NodeT {
        friend class BST<T>;
        private:
                T data;
                NodeT<T> *left, *right;
        public:
                NodeT() { left = right = nullptr; };
                NodeT(T data) { this->data = data; left = right = nullptr; };
};