#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, a[200001];

void solv(){
	cin>>n;
	set <int> s;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		int t = (i + n + (a[i])%n)%n;
		if(t < 0) t %= n;
		s.insert(t);
	}

	if(s.size() == n){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
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