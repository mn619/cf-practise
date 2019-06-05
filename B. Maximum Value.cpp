/* input
5
1 1 1 2 5
*/
#include <bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b,s) for(i=a;i<b;i+=s)
#define mod 1000000007
#define all(x) x.begin(),x.end()
using namespace std;
int n,mx=0;
vector <int> a;
signed main()
{
 	start_routine
 	cin>>n;
 	int i;
 	fr(i,0,n,1)
 	{
 		int x;
 		cin>>x;
 		a.pb(x);
 	}
 	sort(all(a));
 	bool in[1000001]={0};
 	fr(i,0,n,1)
 	{
 		int temp=2*a[i];
 		if(!in[a[i]])
 		{
 		in[a[i]]=1;
 		fr(temp,temp,2*a[n-1]+2,a[i])
 		{
 			vector <int>:: iterator it=lower_bound(all(a),temp);
 			if(it!=a.end())it--;
 			//cerr<<i<<"\t"<<temp<<"\t"<<*it<<"\n";
 			if(*it%a[i] > mx && it!=a.end())mx=*it%a[i];
 			if(it==a.end())if(a[n-1]%a[i]>mx)mx=a[n-1]%a[i];
 			if(*it%a[i]==a[i]-1 )break;
 		}
 		}
 	}
 	cout<<mx;
	end_routine
}

