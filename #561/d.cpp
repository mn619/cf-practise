#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;
	
int a, b, m, pwr[51], hp, k;

int find(){
	fr(i, 0, 50){
		if(pwr[i + 1]*(a + 1) > b){hp = i; k = i + 2; return pwr[i]*(a + 1);}
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	int q;
 	cin>>q;
 	pwr[0] = 1;

 	fr(i, 1, 51){
 		pwr[i] = 2*pwr[i - 1];
 	}

 	while(q--){	
 		cin>>a>>b>>m;
 		int x = find();
 		int y = b - x;

 		int r[51] = {0};
 		fr(i, 0, hp){
 			r[i] = 1;
 		}
 		r[0]++;
 		
 		int cur = 0;
 		cout<<y<<'\n';

 		while(y){
 			if(y&1) r[k - cur + 1]++;
 			y /= 2;
 			cur++;
 		}

 		cout<<k<<" "<<hp<<'\n';
 		int ans[51];
 		ans[1] = a;
 		cout<<ans[1]<<" ";

 		fr(i, 0, hp) cout<<r[i]<<" ";
 		cout<<'\n';

 		fr(i, 2, k + 1){
 			ans[i] = r[i];
 			fr(j, 1, i) ans[i] += ans[j];
 			cout<<ans[i]<<" ";
 		}		
 		cout<<"\n";
 	}



}