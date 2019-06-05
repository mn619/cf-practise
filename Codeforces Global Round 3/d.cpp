#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, dpinc[600002], dpdec[600002];
vector <int> inc[300001], dic[300001];

bool compinc(vector <int> v1, vector <int> v2){
	return (v1[1] > v2[1]);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;	
 	int inccnt = 0, deccnt = 0;

 	fr(i, 1, n + 1){
 		int a, b;
 		cin>>a>>b;
 		if(a < b){
 			inc[++inccnt].pb(-b), inc[inccnt].pb(i);
 		}
 		else{
 			dic[++deccnt].pb(b), dic[deccnt].pb(i);
 		}
 	}

 	if(deccnt > 0) sort(dic + 1, dic + deccnt + 1);
 	if(inccnt > 0) sort(inc + 1, inc + inccnt + 1);

 	if(inccnt > deccnt){
 		cout<<inccnt<<"\n";
 		fr(i, 1, inccnt + 1) cout<<inc[i][1]<<" ";
 	}
 	else{
 		cout<<deccnt<<"\n";
 		fr(i, 1, deccnt + 1){
 			cout<<dic[i][1]<<" ";
 		}
 	}

}