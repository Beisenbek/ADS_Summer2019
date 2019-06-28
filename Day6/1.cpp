#include <iostream>

using namespace std;

struct heap{
    private:
        int * val;
        int hs;
        int n;

    public:
        heap(int _n){
            val = new int[_n];
            n = _n;
            hs = 0;
        }

        void add(int v){
            val[hs] = v; 

            int cpos = hs;
            int ppos = (hs - 1) / 2;

            hs++;

            while(ppos >=0 && val[ppos] < val[cpos] ){
                swap(val[cpos],val[ppos]);
                cpos = ppos;
                ppos = (cpos - 1) / 2;
            }    

        }

        int get_max(){
            return val[0];
        }
        
        void del(){
            val[0] = val[hs - 1];
            hs--;
            int rootp = 0, maxp, lcpos, rcpos;

            while(2 * rootp + 1 < hs){
                lcpos = 2 * rootp + 1;
                rcpos = 2 * rootp + 2;
                
                if(rcpos < hs && val[lcpos] < val[rcpos]){
                    maxp = rcpos;
                }else{
                    maxp = lcpos;
                }

                if(val[rootp] < val[maxp]){
                    swap(val[rootp], val[maxp]);
                    rootp = maxp;
                }else{
                    break;
                }
            }
        }

};

int main(){

    int a[] = { 1, 6, 8, 7, 12, 9, 10};
    int n = sizeof(a) / sizeof(int);

    heap h(n);

    for(int i = 0; i < n; ++i){
       h.add(a[i]);
    }

    cout << h.get_max() << endl;

    h.del();
    h.del();

    cout << h.get_max() << endl;

    return 0;
}