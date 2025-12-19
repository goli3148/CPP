#include <iostream>
using namespace std;

class Node{
    public:
        Node(int d, Node* p=0): data(d), next(p) { }
        ~Node(){cout << "data " << data << " destroyed." << endl;}
        int data;
        Node* next;
};

class List{
    public:
        List();
        void append(int data);
        int get(int index);
        void del(int);
        void show_all();
    private:
        Node* start;
        Node* current;
        Node* end;
        int start_index;
        int last_index;

};

int main(){
    List list;
    list.append(5);
    list.show_all();
    list.append(6);
    list.show_all();
    list.append(7);
    list.show_all();
    list.del(6);
    list.show_all();
    list.append(10);
    list.show_all();
    return 0;
}

List::List(){
    start = new Node(0);
    current = start;
    end = start;
    start_index = 0;
    last_index = 0;
}

void List::append(int data){
    current -> next = new Node(data);
    current = current -> next;
    end = current;
    last_index ++;
}

void List::del(int data){
    Node* b = start;
    for(Node* p=start->next; ; p=p->next){
        if (p->data == data){
            if (p == current) current = b;
            b -> next = p -> next;
            last_index --;
            delete p;
            return;
        }
        b = p;
    }
}

int List::get(int index){
    current = start;
    for (int j=start_index; j <= last_index; j++){
        if (j==index){
            int data = current -> data;
            current = end;
            return data;    
        }
        current = current -> next;
    }
    return -1;
}

void List::show_all(){
    cout << "length of list: " << last_index << endl;
    for (Node* p=start -> next; ; p = p-> next){
        cout << "\t data: " << p -> data <<endl;  
        if (!p->next) break; 
    }
}