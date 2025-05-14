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
const ll N = 3e5 + 10;
/* ================ actual code starts here ================ */

void radix_sort(vector <ll>& v) {
    ll n = v.size();
    vector<ll> output(n), counter(10, 0);

    ll maxNum = *max_element(v.begin(), v.end()), digitCnt = 0;

    while (maxNum > 0) {
        maxNum /= 10;
        digitCnt++;
    }

    ll mod = 10, div = 1;
    while (digitCnt --> 0) {
        for (int i = 0; i < n; i++) {
            counter[(v[i] % mod) / div]++;
        }

        for (int i = 1; i < 10; i++) {
            counter[i] += counter[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            output[--counter[(v[i] % mod) / div]] = v[i];
        }

        swap(v, output);
        mod *= 10;
        div *= 10;

        for (auto& i : counter) i = 0;
        for (auto& i : output) i = 0;
    }
}

void solve(ll tc) {
    vi v = { 1,5,8,9,15,24,43,20,10,231,567,890,765 };
    radix_sort(v);

    for (auto i : v) cout << i << ' ';
    cout << endl;
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