#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;
	
string t;

void solv(){
	cin>>t;
	int a = 0, b = 0;
	for(int i = 0; i < (int)t.size(); i++) a += t[i] == '0', b += t[i] == '1';
	
	if(a == 0 or b == 0){
		cout<<t<<'\n';
		return;
	}

	// a = max(a, b);
	char p = '0', q = '1';
	if(t[0] == q) swap(p, q);

	for(int i = 0; i < 2*(a + b); i++) if(i&1) cout<<q; else cout<<p;
		cout<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int T;
    cin>>T;

    while(T--) solv();
}