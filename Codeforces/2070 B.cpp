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

void solve() {
    ll x, count = 0, k1 = 0;
    ull n, k;
    bool x_did_become_zero1 = 0, x_did_become_zero2 = 0;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    // how many seconds does it take to find the first zero
    for (int i = 0; i < n && k--;) {

        if (s[i] == 'L') x--;
        else x++;
        i++;
        if (x == 0) {
            count++;
            x_did_become_zero1 = 1; // to see if we hit zero even once
            break;
        }
    }

    // calculate how many times we will hit zero after the first hit, i.e, k1
    if (x_did_become_zero1) {
        int i = 0;
        do {
            if (s[i] == 'L') x--;
            else x++;
            i++;
            k1++;
            if (x == 0) x_did_become_zero2 = 1;
        } while (i < n && x != 0);
    }

    // if k1 is zero or x never became zero 2nd time, we dont do this
    if (x_did_become_zero2 && k1 != 0) count += k / k1;
    cout << count << endl;
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