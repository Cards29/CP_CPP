#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vli;

#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define fi(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)

void solve()
{
    ll n,m;
    cin>>n;
    m=2*n-1;
    for( int i=0;i<m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i<n && j>=n-i && j<=n+i)
                cout<<"*";
            else if(i>=n && j>=n-m+i+1 && j<=n+m-i-1)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for( int i=0;i<m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j==1)
                cout<<"*";
            if(i!=n-1 && j==m)
                cout<<"*";
            if(i==n-1 && j==m)
                cout<<" *";
            if(i<n && j>=n-i && j<=n+i)
                cout<<" ";
            else if(i>=n && j>=n-m+i+1 && j<=n+m-i-1)
                cout<<" ";
            else
                cout<<"*";
        }
        cout<<"\n";
    }
}

int main()
{
    //fastio;
    ll t;
    //cin>>t;
    //while(t--)
    solve();

    return 0;
}