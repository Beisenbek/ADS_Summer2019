#include <iostream>
using namespace std;

struct QueueItem{
	int val;
	QueueItem * next;
	QueueItem * prev;
	QueueItem(){
		next = NULL;
		prev = NULL;
	}
};

struct MQueue{
	QueueItem * first;
	QueueItem * last;
	int cnt;

	MQueue(){
		first = NULL;
		last = NULL;
		cnt = 0;
	}
	void push(int x){
		QueueItem * item = new QueueItem();
		item->val = x;
		if(last == NULL){
			first = item;
			last = item;
		} else{
			item->prev = last;
			last->next = item;
			last = item;
		}
		cnt ++;
	}
	int front(){
		return first->val;
	}
	/*void pop(){
		QueueItem * y = last;
		last->prev->next = NULL;
		last = last->prev;
		delete y;
		cnt --;
	}*/
};
int main(){
	MQueue mq;
	string command;
	while(cin >> command){
		if(command == "push"){
			int n;
			cin >>n;
			mq.push(n);
			cout<<"ok"<<endl;
		}else if(command == "pop"){
			//mq.pop();
		}else if(command == "front"){
			cout<<mq.front()<<endl;
		}else if(command == "exit"){
			cout<<"bye"<<endl;
			break;
		}
		}
	return 0;
}



	