#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second 

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i< n; i++){
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a.begin(), a.end());
    int counter = 1;
    int parcours = a[0].S;
    for(auto i: a){
        if (i.S < parcours){
            counter ++;
        }
        parcours = i.S;
    }
    cout << counter << "\n";
} 

/* A O(n) version, but in practice less efficient
int main() {
    int n;
    cin >> n;
    int counter = 0;
    int x = 0;
    unordered_set<int> s;
    for(int i = 0; i< n; i++){
        cin >> x;
        if(!(s.count(x-1))){
            counter++;
        }
        s.insert(x);
    }
    cout << counter << "\n";
} */