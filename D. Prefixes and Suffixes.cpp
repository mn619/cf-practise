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
string s,r;

void lps(string s, int lpsarr[])
{
	int i = 1,j=0,n=s.size();
	lpsarr[0] = 0;
	while(i<n)
	{
		if(s[i] == s[j])
		{
			lpsarr[i] = j+1;
			i++,j++;
		}

		else
		{
			if(j!=0)
			{
				j=lpsarr[j-1];
			}
			else
			{
				lpsarr[i] = 0;
				i++;
			}
		}
	}
}
signed main()
{
 	//start_routine
	cin>>s;
	r=s;
	int n = s.size(),i;
	reverse(r.begin(),r.end()); 	
	int sarr[n],rarr[n];
 	
 	lps(s,sarr);
 	lps(r,rarr);
 	int ans[n-1] =  {0};

 	fr(i,0,n)
 	{
 		if(sarr[i] !=0)
 		{
 			if(rarr[n-2-i+sarr[i]] == sarr[i]) ans[sarr[i]]++;
 		}
 	}

 	fr(i,0,n)cout<<sarr[i]<<" ";
 	cout<<'\n';
 	fr(i,0,n)cout<<rarr[i]<<" ";
 	int k = 0;
 	fr(i,1,n) if(ans[i]) k++;
 	cout<<k<<"\n";
 	fr(i,0,n)
 	cout<<ans[i]<<" ";
  	//end_routine

}



