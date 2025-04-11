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
    ll n, count = 0;
    cin >> n;
    set<ll> s;
    for (int i = 0; i < n; i++) {
        ll k;
        cin >> k;
        s.insert(k);
    }
    cout << s.size();


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