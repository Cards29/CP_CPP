#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef set<ll> si;

#define cy cout<<"YES\n"
#define cn cout<<"NO\n"

vector<ll> prime(1001, 1);

void sieve_of_eratosthenes() {
	prime[0] = 0;
	prime[1] = 0;
	for (ll i = 2; i < 1001; i++) {
		if (prime[i] == 1) {
			for (ll j = i * i; j < 1001; j += i) {
				prime[j] = 0;
			}
		}
	}
}

void solve() {
	sieve_of_eratosthenes();
	for (ll i = 0; i < 1001; i++) {
		if (prime[i])
			cout << i << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t = 1;
	// cin >> t;
	while (t--)
		solve();

	return 0;
}
