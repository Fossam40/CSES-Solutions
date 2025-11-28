#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t llb;

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    ll sumx = 0;
    ll sumy = 0;
    llb tot = 0;
    vector<ll> arrx(n);
    vector<ll> arry(n);
    for(int i = 0; i<n; i++){
        cin >> arrx[i] >> arry[i];
    }
    sort(arrx.rbegin(), arrx.rend());
    sort(arry.rbegin(), arry.rend());
    for(ll i = 0; i<n; i++){
        ll decal = (sumx - arrx[i]*i) + (sumy - arry[i]*i);
        tot += decal;
        sumx += arrx[i];
        sumy += arry[i];
    }
    cout << tot << "\n";
}