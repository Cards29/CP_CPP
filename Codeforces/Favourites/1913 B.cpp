#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll, ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
typedef vector <vi> vvi;

const ll MOD = 1e9 + 9;
const ll N = 1e5 + 10;
/* ================ actual code starts here ================ */

void solve() {
    string s;
    cin >> s;

    ll cnt[2] = { 0, 0 };
    for (auto& i : s) {
        cnt[i - '0']++;
    }

    if (cnt[0] == cnt[1]) {
        cout << 0 << endl;
        return;
    }

    // this one is from CF tutorial, was hard to understand
    // for (int i = 0; i <= s.size(); i++) {
    //     if (i == s.size() || cnt['1' - s[i]] == 0) {
    //         cout << s.size() - i << endl;
    //         break;
    //     }
    //     cnt['1' - s[i]]--;
    // }

    // in a more simple way
    ll cnt0 = cnt[0], cnt1 = cnt[1], nn = s.size(), length_of_t = 0;
    for (int i = 0; i < nn; i++) {
        if (s[i] == '0' && cnt1 > 0) {
            cnt1--;
            length_of_t++;
        }
        else if (s[i] == '1' && cnt0 > 0) {
            cnt0--;
            length_of_t++;
        }
        else
            break;
    }
    cout << nn - length_of_t << endl;

    /*
        explanation from RAHINUR
        we need to check if cnt0 is 0 only when
        we check for s[i] == '1', not when
        s[i] == '0', this was the edge case that
        I was missing
    */

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