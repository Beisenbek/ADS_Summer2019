#include<iostream>

using namespace std;


int main(){

    int x;
    cin >> x;

    for(int i = 1; i <= x; ++i){
        if(i * i > x){
            cout << i -1 << endl;
            break;
        }
    }

    return 0;
}