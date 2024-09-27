#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

#define cy cout << "YES\n"
#define cn cout << "NO\n"

const int MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const ll N = 1e7 + 20;
ll prime_index = 3000;
vector<bool> is_prime(prime_index + 1, true);
inline void sieve() {
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i * i <= prime_index; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= prime_index; j += i)
                is_prime[j] = false;
        }
    }
}

// Function to compute GCD using Euclidean Algorithm
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM using GCD
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll decimalToBinary(ll n) {
    ll binaryNum = 0;
    ll remainder, i = 1;

    while (n != 0) {
        remainder = n % 2;
        n = n / 2;
        binaryNum += remainder * i;
        i *= 10;
    }

    return binaryNum;
}

ll binaryToDecimal(ll binaryNum) {
    ll decimalNum = 0, power = 0;

    // Iterating through each digit of the binary number
    while (binaryNum != 0) {
        ll digit = binaryNum % 10;          // Extracting the last digit
        decimalNum += digit * pow(2, power); // Adding to the decimal number
        binaryNum /= 10;                     // Removing the last digit
        power++;                             // Incrementing the power of 2
    }

    return decimalNum;
}

//------------------------------------------------Soln-------------------------------------------
void solve() {

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