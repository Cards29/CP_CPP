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
    vpi v;

    for (int i = 0; i < n; i++) {
        ll k, l;
        cin >> k >> l;
        v.push_back({ k, 1 });
        v.push_back({ l, -1 });
    }

    sort(v.begin(), v.end());

    ll count = 0, mx = 0;

    for (auto& i : v) {
        count += i.second;
        mx = max(mx, count);
    }

    cout << mx << endl;
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
