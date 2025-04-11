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

void solve(ll tc) {
    ll n, x;
    cin >> n >> x;

    vi v(n), v1(n, x);
    for (auto& i : v) cin >> i;

    sort(v.begin(), v.end());
    // for (auto i : v) cout << i << ' ';
    // cout << endl;
    // for (auto i : v1)  cout << i << ' ';
    // cout << endl;



    ll i = 0, j = n - 1, count = 0, childCount = 0, k = 0;
    while (i < n && j >= 0 && i < j) {
        if ((v[i] + v[j]) <= x) {
            // cout << v[i] << ' '  << v[j] << ' ' << count << " yo1\n";
            i++;
            j--;
            count++;
        }
        else {
            // cout << v[i] << ' '  << v[j] << ' ' << count << " yo2\n";
            j--;
            count++;
        }
    }
    if (i == j) {
        count++;
    }

    cout << count << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++)
        solve(i);



    return 0;
}
