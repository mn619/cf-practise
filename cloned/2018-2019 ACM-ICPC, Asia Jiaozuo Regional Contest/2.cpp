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
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;

signed main()
{
	FILEIO
 	//start_routine
 	int tests;
 	cin>>tests;
 	while(tests--)
 	{
		int n;
		cin>>n;
		int a[n + 2] = {0};
		int i;
		fr(i,1,n)
		{
			cin>>a[i];
			a[i] += a[i - 1];
		}

		int sum = a[n - 1], temp = a[n - 1];

		int l = 0, r = n - 1;
		cout<<"0 "<<a[n - 1];
		if(n!= 2) cout<<" ";

		fr(i,2,n)
		{
			if(i%2 == 0)
			{
				l++;
				sum += temp;
			}
			else 
			{
				r--;
				temp += a[r] - a[l];
				sum += temp;
			}
			cout<<sum;
			if(i!=n - 1)cout<<" ";
		}
		if(tests!=0)cout<<endl;
	}


 	//end_routine
}
