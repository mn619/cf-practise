#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n;

void solv(){
	cin>>n;
	int s = 1, w = 1;
	vector <int> d;
	
	while(w < n){
		int di;
		if(n - w - s >= 0 and n - w - s <= s){
			di = n - w - s;
		}
		else{
			di = min(s, max((int)0, (n - w)/2 - s));
		}
		assert(di >= 0);
		w += di + s;
		s += di;
		d.push_back(di);
	}

	assert(w == n);
	cout<<d.size()<<'\n';
	for(auto x: d) cout<<x<<" ";
	cout<<'\n';
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