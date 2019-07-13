#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

	int n;
	cin >> n;

	int a[n][n];

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}

	int s,t;
	cin >> s >> t;
	s--;
	t--;

	int d[n];
	bool u[n];
	queue<int> q;
	int p[n];

	for(int i = 0; i < n; ++i){
		d[i] = 10000;
		u[i] = false;
	}

	d[s] = 0;
	u[s] = true;
	q.push(s);
	p[s] = -1;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(int i = 0; i < n; ++i){
			if(a[cur][i] == 1 && u[i] == false){
				d[i] = d[cur] + 1;
				u[i] = true;
				q.push(i);
				p[i] = cur;
			}
		}
	}

	if(d[t] == 0){
		cout << 0 << endl;
	}
	else if(d[t] >= 10000){
		cout << -1 << endl;
	}
	else{
		cout << d[t] << endl;

		int k = t;
		vector<int> v;

		while(k != -1){
			v.push_back(k+1);
			k = p[k];
		}

		for(int i = v.size() - 1; i >= 0; --i){
			cout << v[i] << " ";
		}
	}

	return 0;
}