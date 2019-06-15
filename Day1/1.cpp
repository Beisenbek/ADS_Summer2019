#include<iostream>
#include<queue>

using namespace std;

int main(){

	queue<int> q;
	string command;
	int n;

	while(true){
		cin >> command;
		if(command == "push"){
			cin >> n;
			q.push(n);
			cout << "ok" << endl;
		}else if(command == "pop"){
			cout << q.front() << endl;
			q.pop();
		}else if(command == "front"){
			cout << q.front() << endl;
		}else if(command == "size"){
			cout << q.size() << endl;
		}else if(command == "clear"){
			for(int i = 0; i < q.size(); ++i){
				q.pop();
			}
			cout << "ok" << endl;
		}else if(command == "exit"){
			cout << "bye!" << endl;
			break;	
		}
	}

	return 0;
}