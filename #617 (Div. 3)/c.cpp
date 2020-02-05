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


void solv(){
	int n;
	cin>>n;
	string s = "%";
	string temp;
	cin>>temp;
	s += temp;

	map <pair<int, int>, int> m;

	int h = 0, v = 0;
	int l = -1, r = inf;

	m[{0, 0}] = 0;

	fr(i, 1, n + 1){
		if(s[i] == 'R') h++;
		else if(s[i] == 'L') h--;
		else if(s[i] == 'D') v--;
		else v++;

		if(m.count({h, v})){
			if(r - l > i - m[{h, v}]){
				r = i;
				l = m[{h, v}] + 1;
			}
		}

		m[{h, v}] = i;
	}

	if(l == -1) cout<<"-1\n";
	else cout<<l<<" "<<r<<'\n';
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