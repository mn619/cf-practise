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
int p[100001];
signed main()
{
 	start_routine
 	cin>>n;
 	int i;
 	fr(i,1,n+1)
 	{
 		int temp;
 		cin>>temp;
 		p[temp] = i;
 	}

 	bool in[n+1] = {0}, oddlen = 0;
 	int fix = 0, cyc = 0;

 	fr(i,1,n+1)
 	{
 		if(p[i] == i){fix = i ; break;}

 		if(in[i] == 0)
 		{
 			int ind = i;
 			in[ind] = 1;
 			int len = 1;
 			while(p[ind]!= i)
 			{
 				ind = p[ind];
 				in[ind]=1;
 				len++;
 			}
 			if(len %2) oddlen = 1;

 			if(len < 3) { cyc = i; }
 		}
 	}
 	fr(i,0,n + 1)in[i] = 0;
 	
 	if(fix)
 	{
 		cout<<"YES\n";
 		fr(i,1,n+1)
 		{
 			if(i==fix)continue;
 			else cout<<fix<<" "<<i<<'\n';
 		}
 		return 0;
 	}


 	if(oddlen) return cout<<"NO\n",0;

 	if(cyc)
 	{
 		cout<<"YES\n";
 		int u[2] = { cyc, p[cyc]}, cnt = 1;
 		cout << cyc <<" "<< p[cyc]<<"\n";
 		in[cyc] = 1, in[p[cyc]] = 1;
 		
  		fr(i,1,n+1)
 		{
 			if (in[i] == 0)
 			{
 				int ind= i;
		 		cout<<i<<" "<<u[cnt%2]<<"\n";
		 		ind = p[i];

		 		while(i != ind)
		 		{
		 			in[ind]=1;
		 			cnt += 1 ;
		 			cout << ind << " " << u[cnt%2] <<"\n";
		 			ind = p[ind];
		 			if(cnt >= n-1)break;
		 		}
 			}
 			if(cnt>=n-1) break;
 		}
 		return 0;	
 	}
 	cout<<"NO\n";
 	end_routine
}



