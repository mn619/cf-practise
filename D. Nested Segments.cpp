#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

vector <int> v[200001];
int l[400001], r[400001];
int k = 450, n;

bool comp(vector <int> &v1, vector <int> &v2)
{
	if(v1[0]/k != v2[0]/k) return (v1[0] < v2[0]);
	return (v1[1] < v2[1]);
}

void compress()
{
	vector <int> compress;
	map <int, int> m;

	fr(i,1,n + 1)
	{
		compress.pb(v[i][0]);
		compress.pb(v[i][1]);
	}

	sort(compress.begin(),compress.end());

	int t = 0;
	for(auto x: compress)
	{
		m[x] = ++t;
	}

	fr(i,1,n + 1)
	{
		v[i][0] = m[v[i][0]];
		v[i][1] = m[v[i][1]];
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i,1,n + 1)
 	{
 		int l, r;
 		cin>>l>>r;
 		v[i].pb(l);
 		v[i].pb(r);
 		v[i].pb(i);
 	}


 	compress();

 	sort(v + 1, v + n + 1, comp);

 	int l1 = 1, r1 = 2*n, cnt = n;
 	
 	memset(l, mod, sizeof l);

 	fr(i,1,n + 1)
 	{
 		l[v[i][0]] = v[i][1];
 		r[v[i][1]] = v[i][0];
 	}

 	int ans[n + 1];
 	fr(i,1,n + 1)
 	{
 		while(l1 > v[i][0])
 		{
 			l1--;
 			if(l[l1] <= r1) cnt++;
 		}
 		while(r1 < v[i][1])
 		{
 			r1++;
 			if(r[r1] >= l1) cnt++;
 		}
 		while(l1 < v[i][0])
 		{
 			if(l[l1] <= r1) cnt--;
 			l1++;
 		}
 		while(r1 > v[i][1])
 		{
 			if(r[r1] >= l1) cnt--;
 			r1--;
 		}
 		//cout<<l1<<" "<<r1<<" "<<cnt<<'\n';
 		ans[v[i][2]] = cnt - 1;
 	}

 	fr(i,1,n + 1)
 	{
 		cout<<ans[i]<<"\n";
 	}

}	