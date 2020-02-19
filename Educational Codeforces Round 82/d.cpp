#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;
	
int p[62];

void solv(){
	int n, m;
	cin>>n>>m;
	vector <int> a(m + 1);
	vector <int> cnt(61, 0);

	fr(i, 1, m + 1){
		cin>>a[i];
		for(int j = 0; j < 40; j++) if(a[i] == p[j]) cnt[j]++;
	}
	
	vector <bool> on(64);
	vector <bool> req(64, 0);
	for(int i = 0; i < 61; i++){
		if(n&p[i]) on[i] = 1;
	}
	// *** *** *** ***
	int ans = 0;
	for(int i = 0; i <= 60; i++){
		if(!on[i]) continue;
		if(cnt[i] != 0){
			cnt[i]--;
		}
		else{
			int rem = 0;
			for(int j = 0; j < i; j++){
				rem /= 2;
				rem += cnt[j];
			}
			rem /= 2;

			if(rem != 0){
				for(int j = 0; j < i; j++){
					cnt[j + 1] += cnt[j]/2;
					cnt[j] = (cnt[j]&1);
				}
				cnt[i]--;
			}
			else{
				int temp = 0;
				bool found = 0;
				int ind = 61;
				for(int j = i + 1; j < 61; j++){
					temp++;
					if(cnt[j] > 0){
						cnt[j]--;
						found = 1;
						ind = j;
						break;
					}
				}
				if(!found) {
					cout<<"-1\n";
					return;
				}
				else{
					for(int j = ind - 1; j > i; j--){
						cnt[j]++;
					}
					ans += temp;
				}
			}

		}
	}
	
	cout<<ans<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    p[0] = 1;
    for(int i = 1; i < 61; i++) p[i] = (int)(p[i - 1]*2);

    int t;
    cin>>t;

    while(t--) solv();
}