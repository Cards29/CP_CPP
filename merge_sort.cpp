#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

void merge(ll arr[], ll p, ll q, ll r) {
	// Creating two subarrays of A[p...r] as L[p...q] and M[q+1...r] though the index of L/M is from 0 to n1/n2
	ll n1 = q - p + 1, n2 = r - q;
	ll L[n1], M[n2];

	for (ll i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (ll i = 0; i < n2; i++)
		M[i] = arr[q + 1 + i];

	// Current index of the subarrays and main array
	ll i = 0, j = 0, k = p;

	// Copying sortedly to the main array
	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = M[j];
			j++;
		}
		k++;
	}

	// If one subarray is finished we copy rest of the element of the other one
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}
}

void merge_sort(ll arr[], ll l, ll r) {
	if (l == r)
		return;
	ll m = (l + r) / 2;
	merge_sort(arr, l, m);
	merge_sort(arr, m + 1, r);
	merge(arr, l, m, r);
}

void solve() {
	ll n;
	cin >> n;
	// ll arr[n];
	vi arr(n);
	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	// merge_sort(arr,0,n-1);
	sort(arr.begin(), arr.end());

	for (ll i = 0; i < n; i++)
		cout << arr[i] << ' ';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t = 1;
	// cin >> t;
	while (t--)
		solve();

	return 0;
}
