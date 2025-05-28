#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector <ll> vi;
typedef pair <ll, ll> pi;
typedef vector <pi> vpi;

/* ================ actual code starts here ================ */

void dijkstra(ll start, vector <vpi>& adjList, vector <ll>& d) {
    priority_queue <pi, vpi, greater<pi>> pq;
    d[start] = 0;
    pq.push({ 0, start});

    while (!pq.empty()) {
        ll u = pq.top().second;
        ll weight = pq.top().first;

        pq.pop();
        if (d[u] < weight) continue;

        for (auto& [w, v] : adjList[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({ d[v], v });
            }
        }
    }

}

void solve(ll tc) {
    ll n, e;
    cin >> n >> e;

    vector <vpi> adjList(n + 1);
    ll u, v, w;
    while(e--) {
        cin >> u >> v >> w;
        adjList[u].push_back({ w, v });
        adjList[v].push_back({ w, u });
    }
    vector <ll> d(n + 1, LLONG_MAX);

    dijkstra(1, adjList, d);
    
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}


int main() {
    ll t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}