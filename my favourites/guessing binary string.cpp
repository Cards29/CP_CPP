/*this is the soln to this https://codeforces.com/contest/2013/problem/C*/

#include <bits/stdc++.h>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define cy cout << "YES\n"
#define cn cout << "NO\n"

const int MOD = 1e9 + 7;

void solve() {
    ll n, flag, count = 0, guess = 0;
    cin >> n;
    string t = "0";

    if (n == 1) {
        cout << "? 0" << endl;
        cout.flush();
        cin >> flag;
        if (flag) {
            cout << "! 0" << endl;
            cout.flush();
        }
        else {
            cout << "! 1" << endl;
            cout.flush();
        }
        return;
    }

    while (count < 2) {
        guess++;

        cout << "? " << t << endl;
        cout.flush();
        cin >> flag;

        if (t.size() == n && flag) {
            cout << "! " << t << endl;
            cout.flush();
            return;
        }

        if (flag) {
            t += "0";
            count = 0;
        }
        else {
            t.pop_back();
            t += "1";
            count++;
        }
    }
    t.pop_back();
    t = "1" + t;
    while (guess <= 2 * n) {
        guess++;

        cout << "? " << t << endl;
        cout.flush();
        cin >> flag;

        if (t.size() == n && flag) {
            cout << "! " << t << endl;
            cout.flush();
            return;
        }

        if (flag)
            t = "0" + t;
        else {
            t[0] = '1';
        }
    }

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}//11010110