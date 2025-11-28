#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_ok(ll a){
    int prev = -1;
    while(a!=0){
        if((a%10)==prev){
            return false;
        }
        prev = a%10;
        a/=10;
    }
    return true;
}

ll f(ll a,ll b){
    if(b <= 9){
        return (b-a)+1;
    }
    else{
        ll u = 0;
        if(a<=9){
            u += 10-a;
            a = 10; 
        }
        u += f(a/10, b/10)*9;
        if((a%10)<=((a/10)%10)){u -= (a%10)*is_ok(a/10);}
        else{ u -= ((a%10)-1)*is_ok(a/10);}   
        if(((b%10)!=9)){
            if((b%10)>=((b/10)%10)){u -= (9 - (b%10))*is_ok(b/10);}
            else{u -= (8 - (b%10))*is_ok(b/10);}
        }
        return u;
    }
}
int main(){
    ll a,b;
    cin >> a >> b;
    cout << f(a,b) << "\n";
}