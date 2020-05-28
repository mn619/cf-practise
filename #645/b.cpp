#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

void solv(){
	int n;
	cin>>n;


	vector <int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}

	int ans = 0;

	sort(a.begin(), a.end());
	for(int i = 1; i <= n; i++){
		if(a[i] <= i){
			ans = i;
		}
	}

	cout<<ans + 1<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t = 1;
    cin>>t;

    while(t--) solv();
}