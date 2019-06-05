#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

string s, t;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>s>>t;

 	auto k = prefix_function(t);
 	int l = t.size() - k[t.size() - 1];

 	int a = 0, b = 0;
 	fr(i, 0, s.size()){
 		if(s[i] == '0') a++;
 		else b++;
 	}

 	int pos = -1;
 	fr(i, 0, s.size()){
 		pos = (pos + 1)%l;
 		if(a == 0){
 			cout<<1;
 			continue;
 		}
 		if(b == 0){
 			cout<<0;
 			continue;
 		}

 		if(t[pos] == '0'){
 			cout<<0;
 			a--;
 		}
 		if(t[pos] == '1'){
 			cout<<1;
 			b--;
 		}
 	}

}