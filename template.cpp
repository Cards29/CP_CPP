#include <bits/stdc++.h>
using namespace std;

typedef long long int;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef set<int> si;

#define pb push_back
#define pob pop_back
#define fir(n) for (ll i = 0; i < n; i++)
#define _ << ' ' <<
#define all(v) v.begin(), v.end()
#define cy cout << "YES\n"
#define cn cout << "NO\n"

const int MOD = 1e9 + 7;

inline int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const int N = 1e7 + 20;
int prime_index = 3000;
vector<bool> is_prime(prime_index + 1, true);
inline void sieve() {
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= prime_index; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= prime_index; j += i)
                is_prime[j] = false;
        }
    }
}

long long int decimalToBinary(int n) {
    long long int binaryNum = 0;
    int remainder, i = 1;

    while (n != 0) {
        remainder = n % 2;
        n = n / 2;
        binaryNum += remainder * i;
        i *= 10;
    }

    return binaryNum;
}

int binaryToDecimal(long long int binaryNum) {
    int decimalNum = 0, power = 0;

    // Iterating through each digit of the binary number
    while (binaryNum != 0) {
        int digit = binaryNum % 10;          // Extracting the last digit
        decimalNum += digit * pow(2, power); // Adding to the decimal number
        binaryNum /= 10;                     // Removing the last digit
        power++;                             // Incrementing the power of 2
    }

    return decimalNum;
}

//------------------------------------------------Soln-------------------------------------------
inline void solve() {


}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}