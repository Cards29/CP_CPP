#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define cy cout << "YES"<< endl
#define cn cout << "NO"<< endl

//* cout << fixed << setprecision(0) << count << endl;

void solve()
{
    ll b, c, d;
    cin >> b >> c >> d;
    ll a = c ^ d;
    if ((a | b) - (a & c) == d)
        cout << a << endl;
    else
        cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
/**
    * *this is the editorial btw
void solve() {
    ll a = 0, b, c, d, pos = 1, bit_b, bit_c, bit_d, mask = 1;
    cin >> b >> c >> d;
    for (ll i = 0; i < 62; i++) {
        if (b&mask) bit_b = 1;
        else bit_b = 0;
        if (c&mask) bit_c = 1;
        else bit_c = 0;
        if (d&mask) bit_d = 1;
        else bit_d = 0;
        if ((bit_b && (!bit_c) && (!bit_d)) || ((!bit_b) && bit_c && bit_d)) {
            pos = 0;
            break;
        }
        if (bit_b && bit_c) {
            a += (1ll-bit_d)*mask;
        } else {
            a += bit_d*mask;
        }
        mask<<=1;
    }
    if (pos) {
        cout << a << "\n";
    } else {
        cout << -1 << "\n";
    }
}

    * *the guy who solved it(above, uporer ta) is a math genius, his codeforces handle : Expert XiaoTieLa 
    * *tor ta aro boro chilo
*/