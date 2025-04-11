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

    vi v(n);
    for (auto& i : v) cin >> i;

    sort(v.begin(), v.end());

    ll i = 0, j = n - 1, count = 0;

    while (i <= j) {
        if (i == j) {
            count++;
            break;
        }
        else if (v[i] + v[j] <= x) {
            i++;
            j--;
            count++;
        }
        else {
            j--;
            count++;
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
    for (ll i = 1; i <= t; i++)
        solve(i);



    return 0;
}
