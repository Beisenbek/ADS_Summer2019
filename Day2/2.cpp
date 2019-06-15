#include <iostream>

using namespace std;

struct node{
    node * next;
    node * prev;
    int val;
    node(int v){
        val = v;
        next = prev = NULL;
    }
};

struct stack{
    node * last;
    node * first;
    int cnt;

    stack(){
        cnt = 0;
        last = first = NULL;
    }

    void push(int x){
        node * el = new node(x);
        cnt++;
        if(last != NULL){
            last->next = el;
            el->prev = last;
            last = el;
        }else{
            first = el;
            last = el;
        }
    }

    int top(){
        if(last == NULL) return 0;
        return last->val;
    }

    void pop(){
        if(cnt != 0){
            cnt--;
            node * x = last;
            last = last->prev;
            delete x;
        }
    }

    bool isEmpty(){
        return cnt == 0;
    }
};



int main(){
    stack s;

    for(int i = 0; i < 10; ++i){
        s.push(i + 1);
    }

    while(!s.isEmpty()){
        cout << s.top() << endl;
        s.pop();
    }

    

    return 0;
}