#include <iostream>

using namespace std;

template<class T> class Node {
    public:
        Node* next;
        T data;
        Node(): next(NULL) {};
        Node(T d): data(d), next(NULL) {};
        Node(T d, Node* next): data(d), node(next) {};
        ~Node();
}


template<class T> class Stack {
    public:
    Node<T>* top;

    Node<T>*  pop() {
        if (top != NULL){
            Node<T>* temp = this->top;
            this->top = this->top->next;
            return temp;
        }
        return;
    }

    void push (T n){
        Node<T>* node = new Node<T> (n);
        node->next = this->top;
        this->top = node;
    }

    T peek {
        if (top != NULL){
            return this->top->data;
        }
        return;
    }

    Stack(): top(NULL) {;}
    ~Stack();
};


template<class T> class Queue {
     Node<T>* first, last;

     void enqueue (T item){
         Node<T>* n = new Node<T> (item);
         if (last == NULL){
            first = last = n;
         }
         else{
             n->next = this->first;
             this->first = n;
         }
     }

     T deque(){
        if (last != NULL){
            T data =  this->last->data;
            this->last = this->last->next;
            return data;
        }
        return NULL;
}
