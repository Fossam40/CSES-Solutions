#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pi;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int x;
    stack<pi> prec;
    for(int i = 0; i< n; i++){
        cin >> x;
        while(prec.size() > 0 && (prec.top()).F >= x){
            prec.pop();
        }
        if(prec.size()>0){
            cout << (prec.top()).S << " ";
        }
        else{
            cout << 0 << " ";
        }
        pi a = {x,i + 1};
        prec.push(a);
    }
}