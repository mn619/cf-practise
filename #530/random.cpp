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

int f(int n)
{
	 int x = sqrt(n);
	 while(x*x < n) x++;
	 while(x*x > n) x--;

	 if(x*x == n) return 2*x;
	 if(x*(x + 1) < n) return  2*x + 2;
	 return 2*x + 1;
}
int my(int n)
{
	int ans = 1000000000;

	for(int i = 1; i*i <=n; i++)
	{
		int temp = i + n/i;
		if(n%i != 0) temp++;
		ans = min(temp, ans);
	}

	return ans;
}
signed main()
{
	FILEIO
 	//start_routine
	
	int tests = 10000;
	while(tests--)
	{
		int n = rand()*rand();
		int a = f(n), b = my(n);
		if(a != b) 
		{
			cout<<n<<" "<<a<<" "<<b<<'\n';
		}
	}
 	//end_routine
}
