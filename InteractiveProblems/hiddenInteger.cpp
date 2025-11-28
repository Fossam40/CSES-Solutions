#include <bits/stdc++.h>
using namespace std;

int main() {
    int bmin = 1;
    int bmax = (int)(1e9);
    map<int, char> m;
    bool f = false;
    for(int i = 0; i<32; i++){
        if(bmin==bmax){
            cout << "! " << bmin << "\n";
            f = true;
            break;
        }
        else{
            int att = (bmin + bmax)/2;
            char a;
            if(!m[att]){
                cout << "? " << att << "\n";
                cout << flush;
                string ans; cin >> ans;
                m[att] = ans[0];
                a = ans[0];
            }
            else a = m[att];
            if(a=='N'){
                bmax = att;
            }
            else{
                att += (bmin==att);
                bmin = att;
            }
        }
    }
    if(bmin==bmax && !f){
            cout << "! " << bmin << "\n";
        }
}