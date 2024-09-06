#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define cy cout << "YES\n"
#define cn cout << "NO\n"

const ll MOD = 1e9 + 7;

vi sega(2 * 100005, 0), seg(4 * 2 * 100005, 0), lazy(4 * 2 * 100005, 0);// the array sega is the main array for segment tree
/*
-> index is actually the nodes of the segment tree, it traverses through the tree
-> low and high is the range of the index of the array in a segment tree node
-> l and r is the index range of query
*/
void build_segment_tree(ll index, ll low, ll high) {
    if (low == high) {
        seg[index] = sega[low];
        return;
    }

    ll mid = (low & high) + ((low ^ high) >> 1);
    build_segment_tree(2 * index + 1, low, mid);
    build_segment_tree(2 * index + 2, mid + 1, high);

    seg[index] = seg[2 * index + 1] + seg[2 * index + 2]; //* can be changed according to query
}

/*
-> lazy propagation
-> val is the value with which we'll update the segment tree
*/
void lazy_range_update(ll index, ll low, ll high, ll l, ll r, ll val) {
    if (lazy[index] != 0) {
        seg[index] += (high - low + 1) * lazy[index]; //* again, can be changed according to query

        if (low != high) {
            lazy[2 * index + 1] = lazy[index];
            lazy[2 * index + 2] = lazy[index];
        }
        lazy[index] = 0;
    }

    if (l <= low && r >= high) {
        seg[index] += (high - low + 1) * val;//* again, can be changed according to query
        if (low != high) {
            lazy[2 * index + 1] += val;//* again, can be changed according to query
            lazy[2 * index + 2] += val;//* again, can be changed according to query
        }
        return;
    }
    if (l > high || r < low) return;

    ll mid = (low & high) + ((low ^ high) >> 1);
    lazy_range_update(2 * index + 1, low, mid, l, r, val);
    lazy_range_update(2 * index + 2, mid + 1, high, l, r, val);

    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];//* again, can be changed according to query
}

ll query_segment_tree(ll index, ll low, ll high, ll l, ll r) {
    if (lazy[index] != 0) {
        seg[index] += (high - low + 1) * lazy[index];
        if (low != high) {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
    }

    if (l <= low && r >= high) return seg[index];
    if (l > high || r < low) return 0; //* again, can be changed according to query

    ll mid = (low & high) + ((low ^ high) >> 1);
    ll left = query_segment_tree(2 * index + 1, low, mid, l, r);
    ll right = query_segment_tree(2 * index + 2, mid + 1, high, l, r);;

    return (left + right); //* again, can be changed according to query
}

//------------------------------------------------Soln-------------------------------------------
void solve() {
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++) cin >> sega[i];

    build_segment_tree(0, 0, n - 1);
    for (ll i = 0;i < n;i++) {
        ll l, r;
        cin >> l >> r;
        cout << query_segment_tree(0, 0, n - 1, l - 1, r - 1) << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
