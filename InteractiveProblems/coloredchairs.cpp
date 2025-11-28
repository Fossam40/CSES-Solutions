#include <bits/stdc++.h>
using namespace std;
 
vector<int> ans;
 
int adj = -1;
int n;
 
int ask_red(int c){
    if(ans[c]!=-1 && ans[(c%n) + 1]== ans[c]) adj = c;
    if(ans[c]!=-1 && ans[((c-2 + n)%n) + 1]== ans[c]) adj = ((c-2 + n)%n) + 1;
    if(ans[c]!=-1) return (ans[c]==1);
    cout << "? " << c << endl;
    char a; cin >> a;
    ans[c] = (a=='R');
    if(ans[c]!=-1 && ans[(c%n) + 1]== ans[c]) adj = c;
    if(ans[c]!=-1 && ans[((c-2 + n)%n) + 1]== ans[c]) adj = ((c-2 + n)%n) + 1;
    return (a=='R');
}
 
int main(){
    cin >> n;
    ans = vector<int>(n+1,-1);
    int range_beg = 1;
    int range_end = n;
    while(adj==-1){
        int m = (range_beg+range_end)/2;
        if(((range_end-m+1)%2)==0 && ((range_end-range_beg + 1) != 3)) m++;
        int d = m - range_beg;
        int ans1 = ask_red(range_beg);
        if(adj!=-1) break;
        if(((ask_red(range_beg) != ask_red(m)) && !(d%2)) || ((ask_red(range_beg) == ask_red(m)) && (d%2))){
            range_end = m;
            if(((range_end-range_beg+1) % 2) == 0) range_end = ((range_end-2+n)%n) + 1;
        }
        else{
            range_beg = m;
            if(((range_end-range_beg+1) % 2) == 0) range_beg++;
        }
        
    }
    cout << "! " << adj << endl;
}