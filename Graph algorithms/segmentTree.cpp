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

class segmentTree {
private:
    ll size;
    vi vec;
    vi seg;
    vi lazy;

    void validateIndex(ll index) const {
        if (index < 0 || index >= size) {
            cerr << "Error: Index out of bounds\n";
            exit(1);
        }
    }

    void validateRange(ll l, ll r) const {
        if (l < 0 || r >= size || l > r) {
            cerr << "Error: Invalid range\n";
            exit(1);
        }
    }

    void validLowtoHigh(ll low, ll high) const {
        if (low > high) {
            cerr << "Error: Low index cannot be greater than high index\n";
            exit(1);
        }
    }

public:
    segmentTree(const vector<ll>& v) : vec(v) {
        size = v.size();
        seg.resize(4 * size, 0);
        lazy.resize(4 * size, 0);
    }

    void display() const {
        for (int i = 0; i < 4 * size; i++) cout << seg[i] << ' ';

        cout << endl;
        cout << endl;

        for (int i = 0; i < 4 * size; i++) cout << lazy[i] << ' ';
    }

    ll merge(ll a, ll b) const {
        return (a + b); // for range sum
        // return min(a, b); // for range minimum
        // return max(a, b); // for range maximum
        // return __gcd(a, b); // for range gcd
    }

    void build(ll index, ll low, ll high) {
        if (low == high) {
            seg[index] = vec[low];
            return;
        }

        ll mid = low + (high - low) / 2;
        build(2 * index + 1, low, mid);
        build(2 * index + 2, mid + 1, high);

        seg[index] = merge(seg[2 * index + 1], seg[2 * index + 2]);
    }

    ll query(ll index, ll low, ll high, ll l, ll r) {
        // check if we have any lazy update
        if (lazy[index] != 0) {
            seg[index] += (high - low + 1) * lazy[index];
            if (low != high) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
            lazy[index] = 0;
        }

        // if completely lies
        if (low >= l && high <= r) return seg[index];

        // if completely outside of range
        if (high < l || low > r) {
            return 0; // for range sum and range GCD
            // return INT_MAX; // for range minimum
            // return INT_MIN; // for range maximum
        }

        // if neither of the above
        ll mid = low + (high - low) / 2;
        ll left = query(2 * index + 1, low, mid, l, r);
        ll right = query(2 * index + 2, mid + 1, high, l, r);

        return merge(left, right);
    }

    // lazy propagation
    void rangeUpdate(ll index, ll low, ll high, ll l, ll r, ll value) {
        if (lazy[index] != 0) {
            seg[index] += (high - low + 1) * lazy[index];
            if (low != high) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];

            }
            lazy[index] = 0;
        }

        // if completely lies
        if (low >= l && high <= r) {
            seg[index] += (high - low + 1) * value; // might be changed according to query
            if (low != high) {
                lazy[2 * index + 1] += value;
                lazy[2 * index + 2] += value;
            }
            return;
        }

        // if completely outside of range
        if (high < l || low > r || low > high) return;

        // if neither of the above
        ll mid = low + (high - low) / 2;
        rangeUpdate(2 * index + 1, low, mid, l, r, value);
        rangeUpdate(2 * index + 2, mid + 1, high, l, r, value);
        seg[index] = merge(seg[2 * index + 1], seg[2 * index + 2]);
    }


    // I want to call the method without any parameters
    void build() {
        // for 0 indexed range query
        ll index = 0, low = 0, high = vec.size() - 1;
        build(index, low, high);
    }

    ll query(ll l, ll r) {
        // for 0 indexed range query
        ll index = 0, low = 0, high = vec.size() - 1;
        return query(index, low, high, l, r);
    }

    void rangeUpdate(ll l, ll r, ll value) {
        // for 0 indexed range query
        ll index = 0, low = 0, high = vec.size() - 1;
        rangeUpdate(index, low, high, l, r, value);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;

    vi v(n);
    rep(n) cin >> v[i];

    segmentTree segT(v);
    segT.build();

    while (q--) {
        ll l, r;
        cin >> l >> r;

        cout << segT.query(l, r) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
