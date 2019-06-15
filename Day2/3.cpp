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

class doubleLinkedList{
    private:
        node * last;
        node * first;
        int cnt;

    public:
        
        doubleLinkedList(){
            cnt = 0;
            last = first = NULL;
        }

        node * begin(){
            return first;
        }

        node * end(){
            return NULL;
        }

        void add(int x){
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

        void remove(int x){
            node * res = find(x);
            if(res != NULL){
                remove(res);
            }
        }

        void remove(node * el){
            node * nextX = el->next; 
            node * prevX = el->prev;
            prevX->next = nextX;
            nextX->prev = prevX;
            delete el; 
        }

        node * find(int x){
            node * res = NULL;
            node * it = first;
            while(it != NULL){
                if(it->val == x){
                    res = it;
                    break;
                }
                it = it -> next;
            }
            return res;
        }

        bool isEmpty(){
            return cnt == 0;
        }
};



int main(){
    doubleLinkedList dll;

    for(int i = 0; i < 10; ++i){
        dll.add(i + 1);
    }

    for(node * it = dll.begin(); it != dll.end(); it = it->next){
        cout << it->val << endl;
    }

    dll.remove(5);

    for(node * it = dll.begin(); it != dll.end(); it = it->next){
        cout << it->val << endl;
    }

    return 0;
}