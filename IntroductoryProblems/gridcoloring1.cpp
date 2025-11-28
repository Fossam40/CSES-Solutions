#include <bits/stdc++.h>
using namespace std;

int main(){
    int l, c; cin >> l >> c;
    string s,p;
    for(int i = 0; i<l; i++){
        cin >> s;
        for(int j = 0; j<c; j++){
            bool arr[4] = {false, false, false, false};
            arr[s[j]-'A'] = true;
            if(j>0) arr[s[j-1]-'A'] = true;
            if(i>0) arr[p[j]-'A'] = true;
            for(int k = 0; k<4; k++){
                if(!arr[k]){
                    cout << (char)(k + 'A');
                    s[j] = (char)(k + 'A');
                    break;
                }
            }
        }
        cout << "\n";
        p = s;
    }
}