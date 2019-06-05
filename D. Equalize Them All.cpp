#include<bits/stdc++.h>
using namespace std;
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define pb push_back

int n, a[200001], cnt[200001] = {0};

int main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin>>n;
	int ans = 0, val = 0;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
		int l = cnt[a[i]];
		if(ans < l) val = a[i];
		ans = max(ans, l);
	}

	vector <pair<pair<int, int>, int>> v;
	
	int ind = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] == val)
			{ind = i; break;}
	
	int i = ind - 1;
	while(i > 0)
	{
		if(a[i] == val) {i--; continue;}
		if(a[i] < val)
			v.pb({{i,i + 1}, 1});
		else v.pb({{i,i + 1}, 2});
		i--;
	}

	i = ind + 1;
	while(i <= n)
	{
		if(a[i] == val) {i++; continue;}
		if(a[i] < val)
			v.pb({{i,i - 1}, 1});
		else v.pb({{i,i - 1}, 2});
		i++;
	}

	cout<<v.size()<<'\n';
	for(auto x: v){
		cout<<x.second<<" "<<x.first.first<<" "<<x.first.second<<'\n';
	}
}