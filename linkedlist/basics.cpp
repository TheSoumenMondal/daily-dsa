#include<iostream>

class Node{
    public:
    int data;
    Node* next;
    Node(int data , Node* next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void push_front(int val){
        Node* new_node = new Node(val);

        if(head == nullptr){
            head = new_node;
            tail = new_node;
        }else{
            new_node->next = head;
            head = new_node;
        }
    }

    void push_back(int val){
        Node* new_node = new Node(val);
        if(head == nullptr){
            head = tail = new_node;
        }else{
            tail->next = new_node;
            tail = tail->next;
        }
    }

    void pop_front(){
        if(head == nullptr){
            std::cout<<"Linkedlist is empty. ☹️";
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        
        if(head == nullptr){
            tail = nullptr;
        }
    }

    void pop_back(){
        if(tail == nullptr){
            std::cout<<"Linkedlist is empty. ☹️";
            return;
        }
        if(head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    void print_linked_list(){
        std::cout<<"🚀 Printing List:"<<std::endl;
        Node* temp = head;
        while(temp != nullptr){
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }
        std::cout<<std::endl;
    }

    int size(){
        int size = 0;
        Node* temp = head;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        return size;
    }

    bool is_empty(){
        return head == nullptr;
    }

};

int main(){
    LinkedList ll;
    ll.push_back(123);
    ll.push_back(124);
    ll.push_back(125);
    ll.push_back(126);
    ll.print_linked_list();
    ll.pop_front();
    ll.print_linked_list();
    ll.push_front(100);
    ll.push_front(300);
    ll.push_front(900);
    ll.print_linked_list();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.pop_front();
    ll.print_linked_list();
    return 0;
}