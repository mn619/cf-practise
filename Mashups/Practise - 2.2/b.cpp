#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);

using namespace std;


double sgn(double a){
	if(a > 0) return 1.0;
	return -1.0;
}
signed main()
{
	#ifndef ONLINE_JUDGE
	FILEIO
	#endif
 	FLASH

// 	double Q[5] = {30.0, 60.0, 10.0, 20.0, 20.0};
// 	double r1[5] = {4.0, -2.0, -1.0, 1.0, 2.0};
// 	double r2[5] = {2.0, -4.0, 1.0, 2.0, -1.0};

 	double Q[5] = {90.0, 10.0, 10.0, 60.0, 10.0};
 	double r1[5] = {2.0, -4.0, 3.0, 1.0, 2.0};
 	double r2[5] = {2.0, -4.0, -3.0, 1.0, 2.0};

 	int a[] = {0, 1, 2}, b[] = {2, 3, 4};

 	for(int k = 1; k < 1000; k++){
 		double h = 0, rq = 0;

 		for(auto p: a){
 			h += r1[p]*Q[p]*Q[p];
 			rq += 2*abs(r1[p])*Q[p];
 		}

 		double dQ1 = -h/rq;

 		h = 0, rq = 0;
 		for(auto p: b){
 			h += r2[p]*Q[p]*Q[p];
 			rq += 2*abs(r2[p])*Q[p];
 		}

 		double dQ2 = -h/rq;

 		for(auto p: a){
 			Q[p] += 0.1*dQ1*sgn(r1[p]);
 		}

		for(auto p: b){
 			Q[p] += 0.1*dQ2*sgn(r2[p]);
 		}

 		for(auto f: Q){
 			cout<<f<<" ";
 		}
 		cout<<' '<<dQ1<<" "<<dQ2<<'\n';
 	}

}