#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, a[200001], ans[200001];
stack <int> st;
string s;


void dfs(int l, int r, bool c){
	ans[l] = ans[r] = c;

	l++;

	while(l < r){
		dfs(l, a[l], !c);
		l = a[l] + 1;
	}

}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH


 	cin>>n>>s;
 	int d = 0;

 	fr(i, 1, n + 1){
 		if(s[i - 1] == '(') st.push(i);
 		else{
 			int x = st.top();
 			st.pop();
 			a[x] = i, a[i] = x;
 		}
 		d = max(d, (int) st.size());
 	}

 	d = (d/2 + d&1);

 	int l = 1;
 	while(l < n){
 		dfs(l, a[l], 0);
 		l = a[l] + 1;
 	}

 	fr(i, 1, n + 1){
 		cout<<ans[i];
 	}
}