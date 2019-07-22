#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

map <string, int> cnt;
string s[70001];
int n;


int count_(string x, string y){
	int l = x.size();
	int l2 = y.size();
	int ans = 0;
	fr(i, 0, l){
		bool ok = 1;
		fr(j, 0, l2){
			if(x[i + j] != y[j]){
				ok = 0;
				break;
			}
		}
		ans += ok;
	}
	return ans;
}


signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;
 	fr(i, 1, n + 1){
 		cin>>s[i];
 		fr(l, 0, 9){
 			string x = "";
 			fr(r, l, 9){
 				x += s[i][r];
 				cnt[x]++;
 			}
 		}
 	}

 	fr(i, 1, n + 1){
 		int ans = 9, ansl = 0, ansr = 8;
 		fr(l, 0, 9){
 			string x = "";
 			fr(r, l, 9){
 				x += s[i][r];
 				if(cnt[x] == count_(s[i], x)){
 					if(r - l + 1 < ans){
 						ans = r - l + 1;
 						ansl = l;
 						ansr = r;
 					}
 				}
 			}
 		}

 		fr(j, ansl, ansr + 1) cout<<s[i][j];
 		cout<<'\n';
 	}

 	
}