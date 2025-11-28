#include <bits/stdc++.h>
using namespace std;
#define C 1000000000
#define F first
#define S second
typedef pair<int,int> pi;

const int MOD = 1e9 + 7;

const int BUF_SZ = 1 << 15;


inline namespace Input {

char buf[BUF_SZ];

int pos;

int len;

char next_char() {

	if (pos == len) {

		pos = 0;

		len = (int)fread(buf, 1, BUF_SZ, stdin);

		if (!len) { return EOF; }

	}

	return buf[pos++];

}


int read_int() {

	int x;

	char ch;

	int sgn = 1;

	while (!isdigit(ch = next_char())) {

		if (ch == '-') { sgn *= -1; }

	}

	x = ch - '0';

	while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }

	return x * sgn;

}

}  // namespace Input

inline namespace Output {

char buf[BUF_SZ];

int pos;


void flush_out() {

	fwrite(buf, 1, pos, stdout);

	pos = 0;

}


void write_char(char c) {

	if (pos == BUF_SZ) { flush_out(); }

	buf[pos++] = c;

}


void write_int(int x) {

	static char num_buf[100];

	if (x < 0) {

		write_char('-');

		x *= -1;

	}

	int len = 0;

	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }

	write_char((char)('0' + x));

	while (len) { write_char(num_buf[--len]); }

	write_char('\n');

}


// auto-flush output when program exits

void init_output() { assert(atexit(flush_out) == 0); }

}  // namespace Output

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int n = read_int();
    int m = read_int();
    int qu = read_int();
    vector<vector<int>> listadj(n);
    for(int i = 0; i<m; i++){
        int a = read_int();
        int b = read_int();
        listadj[a-1].push_back(b-1);
        listadj[b-1].push_back(a-1);
    }
    //vector<vector<vector<int>>> ansd(n, vector<vector<int>>(n, vector<int>(2,C)));
    int*** ansd = (int***)malloc(n*sizeof(int**));
    for(int i = 0; i<n; i++){
        ansd[i] = (int**)(malloc(n*sizeof(int*)));
        for(int j = 0; j<n; j++){
            ansd[i][j] = (int*)(malloc(2*sizeof(int)));
            ansd[i][j][0] = C;
            ansd[i][j][1] = C;
        }
    } 
    queue<int> q;
    for(int i = 0; i<n; i++){
        queue<int> q;
        ansd[i][i][0]=0;
        q.push(i);
        while(!q.empty()){
            int c = q.front(); q.pop();
            //cout << "Visiting " << (c&(~(1<<30)))+1 << " " <<  ((c&(1<<30))!=0) << " " << ansd[i][(c&(~(1<<30)))][((c&(1<<30))!=0)] << "\n";
            for(auto e: listadj[(c&(~(1<<30)))]){
                if(ansd[i][e][((c&(1<<30))==0)] <= 0) continue;
                q.push((e|(1<<30))^(c&(1<<30)));
                ansd[i][e][((c&(1<<30))==0)]= ansd[i][(c&(~(1<<30)))][((c&(1<<30))!=0)]-1;
            }
        }
    }
    for(int i = 0; i<qu; i++){
        int a = read_int();
        int b = read_int();
        int c = read_int();
        a--; b--;
        if((-ansd[a][b][c%2])<=c && (ansd[a][b][c%2]!=C)) cout << "YES\n";
        else cout << "NO\n";
    }
}