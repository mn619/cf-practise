#include<bits/stdc++.h>
#define maxn 100000
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

int n, p[maxn + 1];
void solv(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		int a;
		cin>>a;
		p[a] = i;
	}

	int las = n + 1;
	for(int i = 1; i <= n;){
		int j;
		for(j = i + 1; j <= n; j++)
			if(p[j] != p[j - 1] + 1)
				break;
		if(p[j - 1] != las - 1){
			cout<<"No\n";
			return;
		}
		las = p[i];
		i = j + 1;
	}

	cout<<"Yes\n";
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