#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define C 1000031

bool isprime(ll n, vector<ll> & primes){
    for(int i = 0; (primes[i]*primes[i])<=n; i++){
        if((n%primes[i])==0) return false;
    }
    return true;
}

int main(){
    int t; cin >> t;
    vector<ll> sieve(C, 0);
    vector<ll> primes;
    for(int i = 2; i<= C; i++){
        if(sieve[i] == 0){
            primes.push_back(i);
            for(int j = 2*i; j<=C; j+=i){
                sieve[j]++;
            }
        }
    }
    ll n;
    for(int i = 0; i<t; i++){
        cin >> n; n++;
        while(!isprime(n, primes)) n++;
        cout << n << "\n";
    }
}