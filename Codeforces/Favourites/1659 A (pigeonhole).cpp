#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll, ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
typedef vector <vi> vvi;

#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll MOD = 1e9 + 9;
const ll N = 1e5 + 10;
/* ================ actual code starts here ================ */

void solve(ll tc) {
    ll n, r, b;
    cin >> n >> r >> b;

    string s;

    if (b == 1) {
        ll mid = (r + 1) / 2;
        for (int i = 0; i < mid; i++) {
            s += 'R';
            r--;
        }

        s += 'B';

        while (r--) s += 'R';
        cout << s << endl;
        return;
    }

    ll a = r / (b + 1);
    ll rem = r % (b + 1);

    while (b > -1) {
        for (int i = 0; i < a; i++) {
            s += 'R';
            r--;
        }
        if (rem > 0) {
            s += 'R';
            rem--;
            r--;
        }
        s += 'B';
        b--;
    }
    s.pop_back();

    cout << s << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t = 1;
    cin >> t;
    for (ll i = 1; i <= t; i++)
        solve(i);

    return 0;
}