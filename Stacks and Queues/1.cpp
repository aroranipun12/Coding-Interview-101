#include<bits/stdc++.h>
using namespace std;

class mystack{
public:
    int max_size;
    int top;
    int* stack;

        mystack(int s){
            max_size = s;
            top = -1;
            stack = new int[s];
        }

    void push(int element){
        if(top >= max_size)
            return;
        stack[++top] = element;
    }

    void pop(){
        if(top == -1)
            return;
        top--;
    }

    int top_element(){
        return stack[top];
    }

    bool Empty(){
        if(top == -1)
            return true;
        return false;
    }
    void print(){
        if(top == -1)
            return;
        for(int i=top;i>=0;i--)
            cout<<stack[i]<<endl;
    }
};


int main(){
    mystack* s = new mystack(100);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->print();
    s->pop();
    s->pop();
    s->pop();
    //s->pop();
    cout<<endl;
   cout<< s->Empty();
    //s->print();
    
    return 0;
}