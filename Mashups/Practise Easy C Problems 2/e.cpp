#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n;

int s[200011], p[200011];

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

	cin>>n;
	
	cout<<setprecision(20);

	int sum = 0, len = 1;

	while(n--) 	{
		int t;
		cin>>t;
		if(t == 1){
			int a, x;
			cin>>a>>x;
			p[a] += x;
			sum += a*x;
		}
		else if(t == 2){
			int x;
			cin>>x;
			s[++len] = x;
			sum += x;
		}
		else{
			s[len] += p[len];
			p[len - 1] += p[len];
			p[len] = 0;
			
			int x = s[len];
			s[len] = 0;

			len--;
			sum -= x;
		}

		long double ans = 1.0*sum/len;
		cout<<ans<<'\n';
	}
}