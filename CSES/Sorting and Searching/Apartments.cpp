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
    ll n, m, k, count = 0;
    cin >> n >> m >> k;
    vi v1(n), v2(m);

    for (auto& i : v1) cin >> i;
    for (auto& i : v2) cin >> i;




    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // for(int i=0; i<n; i++) cout << v1[i] << ' ';
    // cout << endl;
    // for(int i=0; i<m; i++) cout << v2[i] << ' ';
    // cout << endl;

    ll i = 0, j = 0;
    for (; i < n; i++) {
        for (; j < m; j++) {
            if (v2[j] < v1[i] - k) continue;
            else if (v2[j] > v1[i] + k) break;
            else {
                // cout << "Hey there " << v1[i] << ' ' << v2[j] << endl;
                count++;
                j++;
                break;
            }
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
