#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int get_parent(vi & t, int a){
    if(t[a] != a){
        int parent = get_parent(t, t[a]);
        t[a] = parent;
        return parent;
    }
    else return a;
}

int unite(vi&t, int a, int b){
    int parent1 = get_parent(t,a);
    int parent2 = get_parent(t,b);
    t[parent1] = parent2;
    return -(parent1 != parent2);
}

int main(){
    int n, m;
    cin >> n >> m;
    vi t(n);
    for(int i = 0; i<n; i++){
        t[i] = i;
    }
    int a, b;
    int parts = n;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        parts += unite(t, a-1, b-1);
    }
    cout << parts - 1 << "\n";
    int cons = 0;
    for(int i = 0; i<n; i++){
        if(t[i]== i && cons != 0){
            cout << i +1 << "\n";
        }
        if(t[i]==i && cons < parts-1){
            cout << i +1 << " ";
            cons++;
        }
    }
}