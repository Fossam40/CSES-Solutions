// I am deeply sorry for the horrible memory management in this program

#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

struct node{
    ll val;
    struct node* right;
    struct node* left;
};

typedef struct node node;

node* scopy(node* r, int pos){
    node* consi = (pos == 0)?r->left:r->right;
    node* succ = new node;
    succ->right = (consi)->right;
    succ->left = (consi)->left;
    succ->val = (consi)->val;
    return succ;
}

void update(node* r, int a,int x, int y, ll diff){
    //cout << ".\n";
    if(x<=a && a <= y){
        r->val += diff;
        if(r->right != NULL){
            int d = (x+y)/2;
            if(a<= d){
                r->left = scopy(r, 0);
                update(r->left, a, x, d, diff);
            }
            else{
                r->right = scopy(r, 1);
                update(r->right, a, d+1, y, diff);
            }
        }
    }
}

ll get_sum(node* r, int a, int b, int x, int y){
    if(a<=x && y<=b) return r->val;
    else if(y>=a && x<=b){
        int d = (x+y)/2;
        return(get_sum(r->left, a, b, x, d) + get_sum(r->right, a, b, d+1, y));
    }
    else return (ll)0;
}

node* build(int x, int y){
    node* succ = new node;
    if(x == y){
        succ->val = 0;
        succ-> right = NULL;
        succ->left = NULL;
    }
    else{
        int d = (x+y)/2;
        succ->val = 0;
        succ->right = build(x, d);
        succ->left = build(d+1, y);
    }
    return succ;
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    int tn = n;
    n = 32 - __builtin_clz(n);
    n += (tn != (1<<(n-1)));
    n = (1<<(n-1));
    vector<node*> arrs(q, NULL);
    arrs[0] = build(0, n-1);
    ll t, a, b, x;
    for(int i = 0; i<tn; i++){
        scanf("%lld", &x);
        update(arrs[0], i, 0, n-1, x);
    }
    int next = 1;
    for(int i = 0; i<q; i++){
        scanf("%lld ", &t);
        if(t == 1){
            scanf("%lld %lld %lld", &a, &b, &x);
            ll current = get_sum(arrs[a-1], b-1, b-1, 0, n-1);
            update(arrs[a-1], b-1, 0, n-1, x-current);
        }
        else if(t==2){
            scanf("%lld %lld %lld", &a, &b, &x);
            cout << get_sum(arrs[a-1], b-1, x-1, 0, n-1) << "\n";
        }
        else{
            scanf("%lld", &x);
            arrs[next] = new node;
            arrs[next]->val = arrs[x-1]->val;
            arrs[next]->right = arrs[x-1]->right;
            arrs[next]->left = arrs[x-1]->left;
            next++;
        }
    }
}