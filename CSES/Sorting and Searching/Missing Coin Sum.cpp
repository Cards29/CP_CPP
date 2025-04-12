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

    vi v(n);
    for (auto& i : v) cin >> i;

    sort(v.begin(), v.end());

    ll currSum = 1;
    for (auto& i : v) {
        if (currSum < i) {
            break;
        }
        else {
            currSum += i;
        }
    }

    cout << currSum << endl;
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
