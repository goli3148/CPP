#include <iostream>
using namespace std;

typedef int gen;

class Node{
    public:
        Node(gen data, Node* next=0): data(data), next(next) { }
        gen data;
        Node* next;
};

class Stack{
    public:
        Stack(int maxsize=5);
        bool push(gen data);
        gen pop();
        bool isFull();
        bool isEmpty();
        void show_all();

    private:
        Node* start;
        Node* current;
        int maxsize;
        int counter;
};

int main(){
    Stack stack(3);
    stack.push(1);
    stack.show_all();
    stack.push(2);
    stack.show_all();
    stack.push(3);
    stack.show_all();
    stack.push(4);
    stack.show_all();

    stack.pop();
    stack.show_all();
    stack.pop();
    stack.show_all();
    stack.pop();
    stack.show_all();
    stack.pop();
    stack.show_all();
    stack.pop();
    stack.show_all();

    stack.push(10);
    stack.show_all();
    return 0;
}

Stack::Stack(int maxsize){
    this->maxsize = maxsize;
    this->counter = 0;
    start = new Node(0);
    current = start;
}

bool Stack::push(gen data){
    if (isFull()){
        cout << "\033[1;31m Error: Stack if full\033[0m" << endl;
        return false;
    }
    current->next = new Node(data);
    current = current->next;
    counter ++;
    return true;
}

gen Stack::pop(){
    if (isEmpty()){
        cout << "\033[1;31m Error: Stack if empty\033[0m" << endl;
        return -1;
    }
    gen data = current->data;
    Node* b = start;
    for(Node* p=start->next; ; b=p, p=p->next){
        if(p==current){
            current = b;
            // current->next = 0;
            counter --;
            delete p;
            break;
        }
    }
    return data;
}

bool Stack::isEmpty(){
    return current==start;
}

bool Stack::isFull(){
    return counter==maxsize;
}

void Stack::show_all(){
    cout << "Show All Data: " << endl;
    for(Node* p=start->next; ;p=p->next){
        cout << "\t " << p->data;
        if(!p->next) break;
    }
    cout << endl;
}