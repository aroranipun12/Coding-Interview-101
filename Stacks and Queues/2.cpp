#include<bits/stdc++.h>
using namespace std;

class myQueue{
public:
    int max_size;
    int* queue;
    int front;
    int back;
        myQueue(int s){
            max_size = s;
            queue = new int[s];
            front = -1;
            back = -1;
        }

    bool Empty(){
        if(front == -1)
            return true;
        else if(front == back)
    }
    int size(){
        return back - front + 1;
    }
    void push(int e){
        queue[++back] = e;
        if(front == -1)
            front++;
    }
    //pops from front
    void pop(){
        if(front == -1)
            return;
        if(front == back)//only 1 element or empty
            {
                front = -1;
                front = -1;
            }
        front++;
    }
    int front_el(){
        return queue[front];
    }
    int back_el(){
        return queue[back];
    }   
    void print(){
        for(int i=front;i<=back;i++)
            cout<<queue[i]<<" ";
        cout<<endl;
        return;
    }
};

int main(){
    myQueue* q = new myQueue(100);
    q->push(10);
    q->push(20);
    q->push(30);
    q->pop();
    q->print();
    cout<<q->Empty();
    return 0;
}