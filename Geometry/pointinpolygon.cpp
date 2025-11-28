#include <bits/stdc++.h>
using namespace std;
typedef long long C;
typedef complex<C> P;
#define F first
#define S second
#define X real()
#define Y imag()

int pointlocate(P p1, P p2, P p3) { // 0 if in, 1 if out, 2 if left, 3 if right
    P vector1 = p3 - p1;
    P vector2 = p3 - p2;
    C cross = (conj(vector1)*vector2).Y;
    if(cross > 0) return 2;
    else if(cross < 0) return 3;
    else{
        if(p1.X > p2.X) swap(p1,p2);
        if(p1.X == p2.X && p1.Y > p2.Y) swap(p1,p2);
        if((p3.X>= p1.X && p3.X <= p2.X && p1.X != p2.X) || (p1.X==p2.X && p2.X == p1.X && p3.Y>= p1.Y&& p3.Y <= p2.Y )) return 0;
        else return 1;
    }
}

int lineintersection(P p1, P p2, P p3, P p4) { // 0 if none, 1 if  one, 2 if inf
    if(p1.X > p2.X || (p1.X == p2.X && p1.Y > p2.Y)) swap(p1,p2);
    if(p3.X > p4.X || (p3.X == p4.X && p3.Y > p4.Y)) swap(p3,p4);
    if(pointlocate(p1,p2, p3) <=1 && pointlocate(p1,p2,p4)<=1){
        if(p3 == p2 || p1 == p4) return 1;
        if(p2.X < p3.X || p4.X < p1.X ) return 0;
        if(p2.X == p3.X && p4.X == p1.X && (p2.Y < p3.Y || p4.Y < p1.Y)) return 0;
        else return 2;
    }
    else if(p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4) return 1;
    else {
        if(pointlocate(p1,p2,p3) != pointlocate(p1,p2,p4)){
            return (pointlocate(p3,p4,p1) != pointlocate(p3,p4,p2));
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; cin >> n >> q;
    vector<pair<P,P>> polygon(n);
    P p1,p2;
    C x1,y1, x2, y2;
    cin >> x1 >> y1; p1 = {x1,y1};
    for(int i = 1; i<n; i++){
        cin >> x2 >> y2;
        p2 = {x2,y2};
        polygon[i-1] = {p1, p2};
        p1 = p2;
    }
    polygon[n-1] = {p1, polygon[0].F};
    for(int i = 0; i<q; i++){
        cin >> x1 >> y1;
        bool repeat = true;
        int intersect;
        bool boundary;
        while(repeat){
            repeat = false;
            boundary = false;
            p1 = {x1,y1};
            p2 = {(C)1e9 + (rand() % (C)(1e7)),(C)1e9 + (rand() % (C)(1e7))};
            intersect = 0;
            for(int i = 0; i<n; i++){
                int res = lineintersection(p1, p2, polygon[i].F, polygon[i].S);
                if(res == 2){
                    repeat = true;
                    break;
               }
               else intersect += res;
               if(pointlocate(polygon[i].F, polygon[i].S, p1)==0){
                    boundary = true;
                    break;
               }
            }
        }
        if(boundary){
            cout << "BOUNDARY\n";
        }
        else if(intersect%2) cout << "INSIDE\n";
        else cout << "OUTSIDE\n";
    }
}