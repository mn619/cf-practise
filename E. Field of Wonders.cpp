#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

using namespace std;
int n,m,p=101,powers[51]={1};
string s,a[1001];
set <char> in;
void compute()
{
    int i;
    fr(i,1,51)powers[i]=(powers[i-1]*p)%mod;
}
int f(string x)
{
    int ans=0;
    int i;
    fr(i,0,n)
    {
        if(s[i]=='*' && in.count(x[i])) return -1;
        if(s[i]!='*')
        {
            ans+=(powers[i]*(x[i]-'a'+1))%mod;
            ans%=mod;
        }
    }
    return ans;
}

signed main()
{
 	//start_routine
    compute();
    int i;
    cin>>n;
    cin>>s;
    int hash=0;
    fr(i,0,n)
    {
        if(s[i]!='*')
        {
            in.insert(s[i]);
            hash+=(powers[i]*(s[i]-'a'+1))%mod;
            hash%=mod;
        }
    }
    cin>>m;
    fr(i,0,m)cin>>a[i];
    vector <int> v;
    fr(i,0,m)
    {
        int temp=f(a[i]);
        if(temp==hash)v.pb(i);
    }
    int cnt[m][26]={{0}};
    fr(i,0,m)
    {
        int j;
        fr(j,0,n)
        {
            cnt[i][a[i][j]-'a']=1;
        }

    }
    int ans=0;
    fr(i,0,26)
    {
        int j;
        bool b=1;
        fr(j,0,v.size())
        {
            if(cnt[v[j]][i]==0)
            {
                b=0;
                break;
            }
        }
        if(b)ans++;
    }
    set <char> st;
    fr(i,0,n)
    {
        if(s[i]!='*')st.insert(s[i]);
    }
    ans-=st.size();
    cout<<ans;

	//end_routine
}



