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

ll bellmanFord(int V, vvi& edges, vi& dist, ll start) {
    dist[start] = 0;
    ll u, v, w;
    for (int i = 0; i < V; i++) {
        for (auto edge : edges) {
            u = edge[0];
            v = edge[1];
            w = edge[2];

            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                if (i == V - 1) return -1;
                dist[v] = w + dist[u];
            }
        }
    }
    return 0;
}

void solve(ll tc) {
    ll n, e;
    cin >> n >> e;

    vvi edges;

    ll u, v, w;
    while (e-- > 0) {
        cin >> u >> v >> w;
        edges.push_back({ u, v, w });
    }

    ll start = 1;
    vi dist(n, LLONG_MAX);

    ll f = bellmanFord(n, edges, dist, 0);

    if (f != -1) {
        for (auto i : dist) cout << i << ' ';
    }
    else cout << -1 << endl;
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