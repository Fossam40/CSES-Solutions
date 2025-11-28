#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
    set<int> seen;
    queue<int> qseen;
    int m = 0;
    int n;
    cin >> n;
    int x;
    for(int i = 0; i< n; i++){
        cin >> x;
        if(seen.count(x) != 0){
            while(qseen.front() != x){
                seen.erase(qseen.front());
                qseen.pop();
            }
            qseen.pop();
            qseen.push(x);
        }
        else{
            qseen.push(x);
            seen.insert(x);
        }
        m = max(m,(int)qseen.size());
    }
    cout << m << "\n";
}