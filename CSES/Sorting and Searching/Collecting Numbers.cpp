#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const ll MOD = 1e9 + 9;
const ll N = 1e5 + 10;
/* ================ actual code starts here ================ */

void solve() {
    ll n;
    cin >> n;

    vi v(n + 1);
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        v[k] = i;
    }

    ll count = 1;
    for (int i = 2; i <= n; i++) {
        if (v[i - 1] > v[i]) count++;
    }

    cout << count << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--)
        solve();



    return 0;
}
