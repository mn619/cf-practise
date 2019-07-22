#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000
#define double long double
#define p 100000
using namespace std;

int a[maxn];
int b[maxn];
int n, sum = 0;

signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

 	cin>>n;

 	fr(i, 1, n + 1){
 		double x;
 		cin>>x;
 		x *= p;
 		a[i] = (int) x;
 	}

 	fr(i, 1, n + 1){
 		sum += a[i]/p;
 	}

 	if(sum == 0){
 		fr(i, 1, n + 1) cout<<a[i]/p<<'\n';
 	}
 	else if(sum > 0){
 		fr(i, 1, n + 1){
 			if(sum == 0 || (a[i]%p == 0)) cout<<a[i]/p<<'\n';
 			else{
 				if(a[i] < 0){
 					sum--;
 					cout<<a[i]/p - 1<<'\n';
 				}
 			}
 		}
 	}
 	else{
 		fr(i, 1, n + 1){
 			if(sum == 0 || (a[i]%p == 0)) cout<<a[i]/p<<'\n';
 			else{
 				if(a[i] > 0){
 					sum++;
 					cout<<a[i]/p + 1<<'\n';
 				}
 			}
 		}
 	}
}