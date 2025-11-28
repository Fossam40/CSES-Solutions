#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int, char> pic;

int main(){
    string s; cin >> s;
    int n = s.size();
    sort(s.begin(), s.end());
    map<char, int> chCount;
    priority_queue<pic> sat;
    int i= 0;
    char prev = s[0];
    int ccount = 0;
    while(i<n){
        if(s[i]!=prev){
            chCount[prev] = ccount;
            sat.push({ccount, prev});
            prev = s[i];
            ccount = 1;
            
        }
        else {ccount++;}
        i++;
    }
    chCount[prev] = ccount;
    sat.push({ccount, prev});
    vector<char> ans(s.size());
    i = 0;
    bool pos = true;
    char cand;
    if(((((n-i)%2) && sat.top().F>((n-i+1)/2)) || (((n-i)%2)==0 && sat.top().F>((n-i)/2)))) pos = false;
    while(pos && i<n){
        if(!sat.empty() && ((((n-i)%2) && sat.top().F>((n-i+1)/2)) || (((n-i)%2)==0 && sat.top().F>((n-i)/2)))){
            pos = false;
            break;
        }
        else if(!sat.empty() && sat.top().F>=((n-i+1)/2) && ((n-i)%2)){
            cand = sat.top().S;
        }
        else{
            if(i>0 && (*(chCount.begin())).F == ans[i-1]){
                cand = (*(++chCount.begin())).F;
            }
            else {
                cand = (*(chCount.begin())).F;
            }
        }
        ans[i] = cand;
        cout << cand;
        chCount[cand]--;

        if(chCount[cand] == 0){
            chCount.erase(cand);
        }
        else sat.push({chCount[cand], cand});
        while(!sat.empty() && chCount[sat.top().S]!=sat.top().F){
            if(chCount[sat.top().S]==0) chCount.erase(sat.top().S);
            sat.pop();
        }     
        i++;
    }
    if(!pos){
        cout << "-1";}
    cout << endl;
}