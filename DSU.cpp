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

const ll MOD = 1e9 + 7;
/* ================ actual code starts here ================ */

const ll N = 1e5 + 10;
ll parent[N];
// ll _rank[N];
ll _size[N];
multiset<ll> sizes;

void make(ll v) {
    parent[v] = v;
    _size[v] = 1;
    sizes.insert(1);
}

ll find(ll v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(ll a, ll b) {
    sizes.erase(sizes.find(_size[a]));
    sizes.erase(sizes.find(_size[b]));
    sizes.insert(_size[a] + _size[b]);
}

void Union(ll a, ll b) {
    ll ra = find(a);
    ll rb = find(b);
    if (ra != rb) {
        if (_size[ra] < _size[rb]) swap(ra, rb);
        parent[rb] = ra;
        merge(ra, rb);
        _size[ra] += _size[rb];
    }
}

void solve() {



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
