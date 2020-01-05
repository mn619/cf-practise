#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 400000

using namespace std;

int n, p[maxn + 1];
void solv(){
	cin>>n;
	vector <int> v;
	fr(i, 1, n + 1) {
		cin>>p[i];
	}
	int las = 1;
	fr(i, 1, n/2 + 1){
		if(p[las] != p[i + 1]){
			v.pb(i - las + 1);
			las = i + 1;
		}
	}

	int len = v.size();
	if(len == 0){
		cout<<"0 0 0\n";
		return;
	}


	vector <int>  p(len);
	p[0] = v[0];
	
	fr(i, 1, len) p[i] = p[i - 1] + v[i];

	int g = 0, s = 0, b = 0;
		
	fr(i, 1, len - 1){
		if(p[i] - p[0] > p[0] and p[len - 1] - p[i] >  p[0]){
			g = p[0];
			s = p[i] - p[0];
			b = p[len - 1] - p[i];
			break;
		}
	}
	

	cout<<g<<" "<<s<<" "<<b<<'\n';
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int t;
 	cin>>t;
 	while(t--) solv();	
}