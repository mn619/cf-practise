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

vector <int> v;
int n;
int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b,a%b);
}

int f(int x)
{
	int g = gcd(n,x);
	g = n/g;
	if(g%2 == 0)
	{
		return (g/2)*(g - 1)*x + g;
	}
	return (g - 1)*(g/2)*x + g + (x*(g/2))%n;
}
set <int> s;

signed main()
{
	cin>>n;
	int i;
	fr(i,1,sqrt(n) + 1)
	{
		if(n%i ==0) 
		{
			int x = f(i);
			int y = f(n/i);
			if(s.find(x) == s.end())
			{
				v.pb(x);
				s.insert(x);
			}
			if(i*i != n)
			{
				x = y;
				if(s.find(x) == s.end())
				{
					v.pb(x);
					s.insert(x);
				}
			}
		}
	}

	sort(v.begin(), v.end());
	fr(i,0,v.size())
	{
		cout<<v[i]<<" ";
	}
}
