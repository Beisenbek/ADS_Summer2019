#include <iostream>

using namespace std;

class node{
    public:
        node * next;
        node * prev;
        int val;
        node(int v){
            val = v;
            next = prev = NULL;
        }
};

class queue{
    private:
        node * last;
        node * first;
        int cnt;

    public:
        queue(){
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

        int front(){
            if(first == NULL) return 0;
            return first->val;
        }

        void pop(){
            if(first != NULL){
                cnt--;
                node * x = first;
                first = first->next;
                delete x;
            }
        }

        bool isEmpty(){
            return cnt == 0;
        }
};



int main(){
    queue q;

    for(int i = 0; i < 10; ++i){
        q.push(i + 1);
    }

    for(int i = 0; i < 11; ++i){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}