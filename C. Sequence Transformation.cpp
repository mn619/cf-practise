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
int n;
void solve (int k)
{
    int t = n/k;

    if(t == 3)
    {
        cout<<k<<" "<<k<<" "<<3*k<<"\n";
        return;
    }
    if(t == 2)
    {
    	cout<<k<<" "<<2*k<<'\n';
    	return;
    }
    if(t == 1)
    {
        cout<<k<<" "<<"\n";
        return ;
    }

    for(int i = 1; (2*i-1)*k  <= n; i++)
    {
        cout<<k<<" ";
    }
    solve(2*k);
}
signed main()
{
 	start_routine
	

    cin>>n;
	int i;
	solve(1);
 
 	end_routine
}
