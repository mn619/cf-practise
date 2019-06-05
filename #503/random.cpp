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
int dig(int n)
{
	int ans = 0;
	while(n)ans++,n/=10;
	return ans;
}
signed main()
{
 	//start_routine
 	bool prime[100000]={0};
 	
 	int i;
 	int n = 100000;
 	fr(i,2,n)
 	{
 		if(prime[i] == 0)
 		{
 			int j;
 			for(j=i*i;j<n;j+=i) prime[j] = 1;
 		}
 	}
 	vector <int> v,ans;
 	fr(i,2,n) if(prime[i] == 0)v.pb(i);

 	fr(i,0,v.size())
 	{
 		int j;
 		fr(j,i,v.size())
 		{
 			if(dig(v[i])!=dig(v[j]) ) continue;

 			int num = v[i]*v[j];
 			int cnt1[10] = {0};
 			int cnt2[10] = {0};

 			int temp1 = v[i];
 			while(temp1) cnt1[temp1%10]++,temp1/=10;
 			temp1=v[j];
 			while(temp1) cnt1[temp1%10]++,temp1/=10;

 			temp1 = num;
 			while(temp1) cnt2[temp1%10]++,temp1/=10;

 			bool b = 1;
 			int k;
 			fr(k,0,10)if(cnt1[k] != cnt2[k]) {b=0; break;}
 			if(b && (dig(num)== dig(v[i])*2))ans.pb(num);
 		}
 	}
 	sort(ans.begin(), ans.end());
 	fr(i,0,ans.size())cout<<i+1<<" "<<ans[i]<<"\n";


 	//end_routine
}



