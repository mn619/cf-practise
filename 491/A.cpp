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
int a,b,c,n;
signed main()
{
 	start_routine
 	cin>>a>>b>>c>>n;
 	if(a+b-c>n-1||a+b-c<0||a<c || b<c)cout<<-1;
 	else
 	{
 		cout<<n-(a+b-c);
	}
	end_routine
}



