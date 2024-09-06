#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;

#define cy cout<<"YES\n"
#define cn cout<<"NO\n"

vector<int> prime(1001, 1);

void sieve_of_eratosthenes() {
	prime[0] = 0;
	prime[1] = 0;
	for (int i = 2; i < 1001; i++) {
		if (prime[i] == 1) {
			for (int j = i * i; j < 1001; j += i) {
				prime[j] = 0;
			}
		}
	}

}

void solve() {
	sieve_of_eratosthenes();
	for (int i = 0; i < 1001; i++) {
		if (prime[i])
			cout << i << ' ';
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--)
		solve();

	return 0;
}
