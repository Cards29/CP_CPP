#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;
typedef vector<vector<ll>> vvli;
typedef vector<pair<int,int>> vpi;
typedef deque<int> di;

#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define rep(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define cy cout<<"Yes"
#define cn cout<<"No"

// -----------------------Soln-----------------------
void addLargeNumbers(const string &num1,const string &num2)
{
    int i,j,k,x,y,num,carry=0;
    i=num1.size()-1;
    j=num2.size()-1;
    k=max(num1.size(),num2.size());
    di result;
    //vi result(k+1,0);
    
    while(i>=0||j>=0||carry>0)
    {
        if(i>=0) x=num1[i]-'0';
        else x=0;
        if(j>=0) y=num2[j]-'0';
        else y=0;

        num=x+y+carry;
        result.push_front(num%10);
        //result[k]=num%10;
        carry=num/10;

        i--;
        j--;
        //k--;
    }

    for(int digit:result)
    {
        cout<<digit;
    }

}

void solve()
{
    string num1,num2;
    cin>>num1>>num2;
    addLargeNumbers(num1,num2);
}

int main()
{
    fastio
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    
    return 0;
}
