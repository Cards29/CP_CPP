#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef deque<int> di;
typedef set<int> si;
typedef map<int, int> mii;
typedef map<ll, string> mls;

#define fastio                            \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
    }
#define rof(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define rep(i, a) for (ll i = 0; i < (ll)a; i++)
#define per(i, a) for (ll i = (ll)a - 1; i >= 0; i--)
#define cy cout << "Yes\n"
#define cn cout << "No\n"
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()

ll gcd(ll a, ll b)
{
    while (b)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//--------------------------------yohohohohohoho--------------------------------//


bool isBalancedParenthesis(string str)
{
    int n=str.size();
    stack<char>openingBrackets;

    for(int i=0;i<n;i++)
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            openingBrackets.push(str[i]);
        else
        {
            if(openingBrackets.empty())
                return false;
            if(str[i]==')')
            {
                char last=openingBrackets.top();
                    openingBrackets.pop();

                if(last!='(')
                    return false;
            }
            if(str[i]=='}')
            {
                char last=openingBrackets.top();
                    openingBrackets.pop();
                if(last!='{')
                    return false;
            }
            if(str[i]==']')
            {
                char last=openingBrackets.top();
                    openingBrackets.pop();
                if(last!='[')
                    return false;
            }
        }
    }

    return openingBrackets.empty();
    
}

int main()
{
    fastio;
    ll t=1;
    cin>>t;
    
    string str;

    while(t--)
    {
        cin>>str;
        if(isBalancedParenthesis(str)) cy;
        else cn;
    }

    return 0;
}
