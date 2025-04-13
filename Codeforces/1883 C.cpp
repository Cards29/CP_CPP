#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll, ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
typedef vector <vi> vvi;

const ll MOD = 1e9 + 9;
const ll N = 1e5 + 10;
/* ================ actual code starts here ================ */

void solve() {
    ll n, k, count = 0;
    cin >> n >> k;

    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool div = 0;
    ll diff = INT_MAX, even = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] % k == 0) {
            div = 1;
            break;
        }
        if (v[i] % 2 == 0) even++;
        ll _diff = (v[i] + k) / k;
        diff = min((_diff * k) - v[i], diff);
    }

    if (div) {
        cout << 0 << endl;
    }
    else if (k == 4) {
        if (even >= 2) cout << 0 << endl;
        else if (even == 1 || diff == 1) cout << 1 << endl;
        else cout << 2 << endl;
    }
    else {
        cout << diff << endl;
    }



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--)
        solve();



    return 0;
}