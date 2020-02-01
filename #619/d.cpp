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
int n, a[maxn];


int solv(int j, vector <int> v){
	int cnt0 = 0, cnt1 = 0;

	if(v.size() == 1){
		return 0;
	}

	fr(i, 0, v.size()){
		if(v[i]&(1<<j)){
			cnt1++;
		}
		else cnt0++;
	}

	if(j == 0){
		if(cnt0 > 0 and cnt1 > 0) return 1;
		else return 0;
	}

	vector <int> v0, v1;

	fr(i, 0, v.size()){
		if(v[i]&(1<<j)){
			v1.pb(((1<<j)-  1)&(v[i]));
		}
		else{
			v0.pb(((1<<j) -  1)&(v[i]));
		}
	}

	if(cnt0 == 0){
		return solv(j - 1, v1);
	}
	else if(cnt1 == 0){
		return solv(j - 1, v0);
	}
	else{
		return (1<<j) + min(solv(j - 1, v1), solv(j - 1, v0));
	}
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    cin>>n;
    int ans = 0;
    vector <int> v;
    fr(i, 1, n + 1){
    	cin>>a[i];
    	v.pb(a[i]);
    }

    cout<<solv(30, v);
}
