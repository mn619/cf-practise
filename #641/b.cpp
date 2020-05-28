#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;
#define maxn 300000
int n, k, a[maxn + 1];

void solv(){
	cin>>n>>k;
	vector <int> pos;
    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    	if(a[i] == k) pos.push_back(i);
 	}
 	if(pos.size() == 0){
 		cout<<"no\n";
 		return;
 	}

	if(n == 1){
		if(a[1] == k) cout<<"yes\n";
		else cout<<"no\n";
		return;
	}
	
	bool ok = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == k){
			if(i > 1 and a[i - 1] >= k){
				ok = 1;
			}
			if(i < n and a[i + 1] >= k){
				ok = 1;
			}
		}
		if(i > 1 and i < n and a[i - 1] == k and a[i + 1] == k){
			ok = 1;
		}
	}
 
	if(ok){
		cout<<"yes\n";
		return;
	}

	int len = pos.size();

	for(int i = 0; i < len; i++){
		int l = (i == 0)?  1: pos[i - 1];
		int r = (i == len - 1)?  n: pos[i + 1];

		int x = 0, y = 0;
		for(int j = pos[i] - 1; j >= l; j--){
			if(a[j] >= k) y++;
			else x++;
			if((pos[i] - j + 1)/2 > x){
				cout<<"yes\n";
				return;
			}
			if((pos[i] - j + 2)/2 == x + 1){
				cout<<"yes\n";
				return;
			}
		}
		x = 0, y = 0;
		for(int j = pos[i] + 1; j <= r; j++){
			if(a[j] >= k) y++;
			else x++;

			if((j - pos[i] + 1)/2 > x){
				cout<<"yes\n";
				return;
			}
			if((j - pos[i] + 2)/2 == x + 1){
				cout<<"yes\n";
				return;
			}
		}
	}

	//hahahahaha
	ok = 0;
	for(int i = 1; i <= n; i++){
		if(i > 1 and a[i] >= k and a[i - 1] >= k ) ok = 1;
		if(i > 1 and i < n and a[i - 1] >= k and a[i + 1] >= k) ok = 1;
	}

	if(ok) cout<<"yes\n";
	else 
	cout<<"no\n";
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