#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef set<ll> si;

#define pb push_back
#define pob pop_back
#define fir(n) for (ll i = 0; i < n; i++)
#define _ << ' ' <<
#define all(v) v.begin(), v.end()
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

const int MOD = 1e9 + 7;
//------------------------------------------------Soln-------------------------------------------

char pa[1001][1001];
char adj_matrix[1001][1001];
bool visited[1001][1001];
vector<char> path;
bool something;
ll n, m;

bool isValid(ll a, ll b) {
    if (a < 0 || a >= n || b < 0 || b >= m) return false;
    if (adj_matrix[a][b] == '#' || visited[a][b]) return false;
    return true;
}

void bfs(ll& x, ll& y) {
    queue<pair<ll, ll>> q;
    q.push({ x,y });
    visited[x][y] = true;
    while (!q.empty()) {
        ll a = q.front().first, b = q.front().second;
        q.pop();
        // visited[a][b] = true;
        // If B is found
        if (adj_matrix[a][b] == 'B') {
            something = true;
            while (1) {
                path.push_back(pa[a][b]);
                // going to the opposite direction or u can say, going from B to A
                if (path.back() == 'L') b++;
                else if (path.back() == 'R') b--;
                else if (path.back() == 'U') a++;
                else if (path.back() == 'D') a--;
                // break if we reach A
                if (a == x && b == y) break;
            }
            return;
        }
        // left
        if (isValid(a, b - 1)) q.push({ a,b - 1 }), pa[a][b - 1] = 'L', visited[a][b - 1] = true;
        // right
        if (isValid(a, b + 1)) q.push({ a,b + 1 }), pa[a][b + 1] = 'R', visited[a][b + 1] = true;
        // up
        if (isValid(a - 1, b)) q.push({ a - 1,b }), pa[a - 1][b] = 'U', visited[a - 1][b] = true;
        // down
        if (isValid(a + 1, b)) q.push({ a + 1,b }), pa[a + 1][b] = 'D', visited[a + 1][b] = true;
    }
}

void solve() {
    ll x, y;
    cin >> n >> m;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> adj_matrix[i][j];
            if (adj_matrix[i][j] == 'A') x = i, y = j;
        }
    }

    bfs(x, y);
    if (something) {
        cy;
        ll sz = path.size();
        cout << sz << endl;
        for (int i = sz - 1;i >= 0;i--) cout << path[i];
    }
    else cn;

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
