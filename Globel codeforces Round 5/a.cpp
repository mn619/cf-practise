#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;

int n, a[maxn];
int odd = 0;
int sgn(int x){
	if(x > 0) return 1;
	if(x < 0) return -1;
	return 0;
}

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		cin>>a[i];
 		odd += (a[i]%2 != 0);
 	}

 	int sum = 0;
 	odd /= 2;
 	fr(i, 1, n + 1){
 		if(a[i]%2 == 0){
 			cout<<a[i]/2<<"\n";
 			sum += a[i]/2;
 			continue;
 		}
 		if( odd > 0){
 			if(a[i] < 0){
 				cout<<(a[i] - 1)/2<<'\n';
 				sum += (a[i] - 1)/2;
 			}
 			else {cout<<a[i]/2<<'\n'; sum += a[i]/2;}
 			odd--;
 		}
 		else {
 			if(a[i]<0){
 				cout<<a[i]/2<<'\n';
 				sum += a[i]/2;
 			}
 			else{
 				cout<<(a[i] + 1)/2<<'\n';
 				sum += (a[i] + 1)/2;
 			}
 		}
 	}

 	assert(sum == 0);
}