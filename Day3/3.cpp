#include<iostream>

using namespace std;


int main(){

    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;
    int m = -1;

    while(l < r){
        m = (l + r) / 2;
        if(a[m] < x) {
            l = m + 1;
        }else{
            r = m;
        }
    }

    if(a[r] == x){
        cout << "found!" << endl;
    }else{
        cout << "not found!" << endl;
    }


    return 0;
}