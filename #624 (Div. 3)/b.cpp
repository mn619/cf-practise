#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)

using namespace std;

void solv(){
	int n, m;
	cin>>n>>m;

	int a[n];
	vector <int> p(m);
	fr(i, 0, n) cin>>a[i];
	fr(i, 0, m) cin>>p[i];

	vector <bool> in(n);
	for(int i = 0; i < m; i++){
		in[p[i] - 1] = 1;
	}

	int las = -1;

	for(int i = 0; i < n; i++){
		if(las == -1 and in[i]) las = i;
		if(in[i] == 0 and las != -1){
			sort(a + las, a + i + 1);
			las = -1;
		}
	}

	bool ok = 1;
	for(int i = 0; i < n - 1; i++){
		if(a[i] > a[i + 1]) ok = 0;
	}
	if(ok) cout<<"YES\n";
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