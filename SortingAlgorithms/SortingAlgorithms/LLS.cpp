//
//  LLS.cpp
//  
//
//  Implementing a stack using linked list.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

class LLS{
    Node * top;
    //int count;
    
public:
    class underflow{};
    
    LLS(){
        top = NULL;
        //count = 0;
    }
    
    void push(int n){
        Node * ptr = new Node(n);
        if (ptr!=NULL){
            ptr->next = top;
            top = ptr;
            //count++;
        }
    }
    
    int pop(){
        if (top){
            int temp = top->data;
            Node * ptr = top;
            top = top->next;
            delete ptr;
            ptr = NULL;
            //count--;
            return temp;
        }
        throw underflow();
    }
};

int main(){
    cout << "Please enter a list of integers separated by space:" <<endl;
    LLS ll;
    
    string line;
    getline(cin, line );
    
    istringstream iss(line );
    int num;
    while( iss >> num ) {
        ll.push(num);
    }
    
    cout << "The numbers are pushed to the stack." << endl;
    
    cout << "Poping:";
    while (true){
        try{
            num = ll.pop();
            cout << " " << num ;
        } catch (LLS::underflow){
            cout << endl;
            break;
        }
    }
    return 0;
}
