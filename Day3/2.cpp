#include<iostream>
#include<map>

using namespace std;

int main(){

    int n;
    cin >> n;

    map<int,int> m;
    int k;

    for(int i = 0; i < n; ++i){
        cin >> k;
        m[k]++;
    }

    int x;
    cin >> x;

    cout << m[x] << endl;

    return 0;
}