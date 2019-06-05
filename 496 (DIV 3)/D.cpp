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
inline int f(char x)
{
	int n=x-'0';
	return n;
}
signed main()
{
 	//start_routine
 	string s;
 	cin>>s;
 	int n=s.size();
 	
 	int i;

 	int a[n];
 	fr(i,0,n)
 	{
 		a[i]=(f(s[i]))%3;
 		a[i]=(3+a[i])%3;
 	}
 	//fr(i,0,n)cout<<a[i]<<"\n";
 	int ans=0;
 	
 	fr(i,0,n)
 	{
 		if(a[i]%3==0)
 		{
 			
 			ans++;
 			continue;
 		}
 		if(i+1<n)
 		if((a[i]==1 && a[i+1]==2) || (a[i]==2 && a[i+1]==1))
 		{
 			
 			ans++;
 			i+=1;
 			continue;
 		}
 		if(i+2<n)
 		{
 			if((a[i]==1 && a[i+1]==1 && a[i+2]==1)||(a[i]==2 && a[i+1]==2 && a[i+2]==2))
 			{
 				
 				ans++;
 				i+=2;
 				continue;
 			}
 		}
 	}

 	cout<<ans;
 	//end_routine
}



