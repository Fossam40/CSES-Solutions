#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin >> n;
    cin >> m;
    cin >> k;
    int ppl[n];
    int apps[m];
    int x;
    for(int i = 0; i< n; i++){
        cin >> x;
        ppl[i] = x;
    }
    for(int i = 0; i< m; i++){
        cin >> x;
        apps[i] = x;
    }
    sort(ppl, ppl+n);
    sort(apps, apps + m);
    int counter = 0;
    int person = 0;
    for(int i = 0; i< m; i++){
        if((person < n) && (apps[i] <= (ppl[person] + k)) && (apps[i] >= max(ppl[person] - k, 0))){
            counter ++;
            person ++;
        }
        else if((person < n) && (apps[i] > (ppl[person] + k))){
            while((apps[i] > (ppl[person] + k)) && (person < n)){
                person++;
            }
            if(person != n && (apps[i] >= max(ppl[person] - k, 0))){
                person++;
                counter++;
            }
        }
    }
    cout << counter << "\n";
}