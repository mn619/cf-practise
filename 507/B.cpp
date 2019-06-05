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
signed main()
{
 	//start_routine
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n,k;
	cin>>n>>k;

	if(n<=k+1) return cout<<1<<"\n"<<1,0;
	else if(n<=2*k+1) cout<<1<<"\n"<<k+1,0;
	else 
	{
		int x = n%(2*k+1);
		cout<<n/(2*k+1) + (n%(2*k+1)!=0)<<"\n";

		if(x>k)
		{
			int y;
			y = x ;
			int ind  = y - k;
			cout<<ind<<" ";
			ind +=k;
			ind += k+1;
			while(ind<=n)
			{
				cout<<ind<<" ";
				ind += 2*k +1;
			}
		}
		else // x<=k
		{
			if(x == 0) 
				{
					x = k + 1;
					cout<<x<<" ";
					int ind = x+2*k+1;
					while(ind<=n)
					{
						cout<<ind<<" ";
						ind +=2*k +1;

					}
					return 0;
				}
			cout<<x<<" ";
			int ind = x;
			ind += k;	
			ind += k+1;
			while(ind <= n-k-1)
			{
				cout<<ind<<" ";
				ind+=2*k+1;
			}
			cout<<n<<"\n";


		}
	}
 
 	//end_routine
}



