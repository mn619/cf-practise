#include<bits/stdc++.h>
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define int long long
#define mp make_pair
#define fr(i,a,b) for(i=a;i<b;i++)
#define inf 1000000007
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;


int Calcl(string s)
{
	int n= s.size();

	int i = 0;
	int l = 0, r = 0;
	fr(i,0,n)
	{
		if(s[i] == '(') l++;
		else r++;
		if(r > l) return inf;
	}
	return (l - r);
}

int Calcr(string s)
{
	int n = s.size();
	int l = 0, r= 0;
	for(int i = n - 1; i>= 0; i--)
	{
		if(s[i] == '(') l++;
		else r++;
		if(r < l) return inf;
	}	
	return r - l;
}

const int N = 500000;
int l[N + 1] ={0}, r[N + 1] = {0};

signed main()
{
	//FILEIO
 	//start_routine
	
	int n;
	cin>>n;
	string s[n + 1];

	int i;
	fr(i,1,n + 1) cin>>s[i];

	vector <int> v[n + 1];
	
	int ans = 0;
	fr(i,1,n + 1)
	{
		int a = Calcl(s[i]);
		int b = Calcr(s[i]);
		if(b != inf)
			r[b]++;
		if(a != inf)
			l[a]++;
	}
	ans = l[0]/2;
	fr(i,1,N + 1) ans+=min(l[i], r[i]);
	cout<<ans;




 	//end_routine
}
