#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;

int n, mn[300002], mn2[300002];
vector <int> v[300001];


int bs(int h){
	int ans = -1;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l + r)/2;
		if(v[mid][0] >= h){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
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
 		int a, b;
 		cin>>a>>b;
 		v[i].pb(a);
 		v[i].pb(b);
 		v[i].pb(i);
 	}	

 	sort(v + 1, v + n + 1);
 	mn[n] = n, mn2[n] = n;
 	for(int i = n - 1; i >= 1; i--){
 		mn[i] = mn[i + 1];
 		mn2[i] = mn2[i + 1];
 		if(v[i][1] < v[mn[i]][1]){
 			mn2[i] = mn[i];
 			mn[i] = i;
 		}
 		else if(v[i][1] < v[mn2[i]][1]){
 			mn2[i] = i;
 		}
 	}

 	int ans = 0, a = 1, b = 2;
 	
 	fr(i, 1, n + 1){
 		int ind = bs(v[i][1]);
 		if(ind == -1) continue;
 		ind = mn[ind];
 		if(ind == i){
 			ind = mn2[i];
 			if(mn2[i] == i) continue;
 		}

 		int temp = v[i][0];
 		if(v[ind][1] <= v[i][0]) temp += v[ind][0];
 		if(ans < temp){
 			ans = temp;
 			a = v[i][2], b = v[ind][2];
 		}
 	}

 	int h = v[n][1];

 	fr(i, 1, n){
 		if(v[i][0] >= h){
 			if(ans < v[n][0]){
 				ans = v[n][0];
 				a = v[n][2];
 				b = v[i][2];
 			}
 			if(v[n][0] >= v[i][1]){
 				if(ans < v[i][0] + v[n][0]){
 					ans = v[n][0] + v[i][0];
 					a = v[n][2];
 					b = v[i][2];
 				}
 			}
 		}
 	}

 	cout<<ans<<"\n"<<a<<" "<<b;
 	return 0;
}