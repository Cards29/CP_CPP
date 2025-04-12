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

bool compare(pi a, pi b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void solve() {
    ll n;
    cin >> n;
    vpi v;

    for (int i = 0; i < n; i++) {
        ll k, l;
        cin >> k >> l;
        v.push_back({ k, l });
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    sort(v.begin(), v.end(), compare);

    ll count = 0, endOfLAstMovie = -1;

    for (int i = 0; i < n; i++) {
        if (endOfLAstMovie <= v[i].first) {
            count++;
            endOfLAstMovie = v[i].second;
        }

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
