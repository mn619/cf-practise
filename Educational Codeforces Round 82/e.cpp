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

bool check(string s, string a, string b){
	int l = s.size(), n = a.size(), m = b.size();
	int ptr1 = ptr2 = 0, i = 0;

	for(int i = 0; i < l; i++){
		if(ptr1 == n and ptr2 == m) return true;

		if(ptr1 == n){
			if(s[i] == b[ptr2]) ptr2++;
		}
		else if(ptr2 == m){
			if(s[i] == b[ptr2]) ptr2++;	
		}
	}
}
void solv(){
	string s, t;
	cin>>s>>t;

	int n = s.size(), m = t.size();
	
	for(int i = 0; i < n; i++){
		string t1 = "", t2 = "";
		for(int j = 0; j <= i; j++) t1 += t[j];
		for(int j = i + 1; j < m; j++) t2 += t[j]; 
		if(check(s, t1, t2)){
			cout<<"YES\n";
			return;
		}
	}

	cout<<"NO\n";
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