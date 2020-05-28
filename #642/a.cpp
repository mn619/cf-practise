#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, m;

void solv(){
	cin>>n>>m;
	if(n == 1){
		cout<<0<<'\n';
		return;
	}
	else if(n == 2){
		cout<<m<<'\n';
		return;
	}
	else cout<<2*m<<'\n';
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