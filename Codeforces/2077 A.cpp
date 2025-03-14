#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef set<ll> si;

#define rep(n) for (ll i = 0; i < n; i++)
#define _ << ' ' <<
#define all(v) v.begin(), v.end()
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

const ll MOD = 1e9 + 9;
const ll N = 1e5 + 10;
/* ================ actual code starts here ================ */

// this is solved using the tutorial, I couldn't do it
void solve() {
    bool flag = 0;
    ll n, ans;
    cin >> n;
    vi v(2 * n);
    rep(2 * n) cin >> v[i];

    // ll ans = 0;
    // rep(2*n) {
    //     if((i+1)%2) ans += v[i];
    //     else ans -= v[i];
    // }

    // if(ans == 0) {
    //     ll temp = v[0];
    //     v[0] = v[1];
    //     v[1] = temp;

    //     rep(2*n) {
    //         if((i+1)%2) ans += v[i];
    //         else ans -= v[i];
    //     }
    // }

    // if(ans > 0) {
    //     cout << ans << ' ';
    //     rep(2*n) cout << v[i] << ' ';
    //     cout << endl;
    //     return;
    // }
    // if(ans < 0) {
    //     rep(2*n) {
    //         if(v[i] + ans == 0) {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if(!flag) {
    //         ans *= -1;
    //         rep(2*n) cout << v[i] << ' ';
    //         cout << ans << endl;
    //         return;
    //     }
    // }

    sort(v.rbegin(), v.rend());
    ans = 0;
    vi v1, v2;
    rep(2 * n) {
        if (i < n + 1) {
            ans += v[i];
            v1.push_back(v[i]);
        }
        else {
            ans -= v[i];
            v2.push_back(v[i]);
        }
    }
    v2.push_back(ans);
    for (int i = 0, j = 0; i < n && j < n; i++, j++) {
        cout << v1[i] << ' ' << v2[j] << ' ';
    }
    cout << v1[n] << endl;
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