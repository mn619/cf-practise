#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 300000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

string s;
int n, bit[26][maxn + 1];

void update(int c, int x){
	while(x <= n){
		bit[c][x]++;
		x += x&-x;
	}
}

int queri(int c, int x){
	int ans = 0;
	while(x){
		ans += bit[c][x];
		x -= x&-x;
	}
	return ans;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    s = '%';

    string temp;
    cin>>temp;
    
    n = temp.size();
    s += temp;

    fr(i, 1, n + 1){
    	update(s[i] - 'a', i);
    }
    int q;
    cin>>q;

    fr(i, 1, q + 1){
    	int l, r;
    	cin>>l>>r;

    	if(l == r){
    		cout<<"Yes\n";
    		continue;
    	}

    	vector <int> cnt;
    	fr(j, 0, 26){
    		int t = (queri(j, r) != queri(j, l - 1));
    		if(t)
    			cnt.pb(t);
    	}

    	if(cnt.size() > 2){
    		cout<<"Yes\n";
    	}
    	else if(cnt.size() == 2){
    		if(s[l] == s[r]){
    			cout<<"No\n";
    		}
    		else cout<<"Yes\n";
    	}
    	else{
    		cout<<"No\n";
    	}
    }
}