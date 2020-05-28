#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;

long double f(int h, int c, int d){
	int a = (d + 1)/2, b = d/2;
	long double ans = 1.0*(h*a + c*b)/d;
	return ans; 
}

int h, c, t;

void solv(){
	cin>>h>>c>>t;

	// for(int i = 1; i <= 100; i += 1){
	// 	cout<<f(h, c, i)<<" ";
	// }
	// cout<<"\n\n";
	// return;

	long double avg = 1.0*(h + c)/2;
	if(t <= avg){
		cout<<"2\n";
		return;
	}

	int l = 0, r = (int)10000000000000;

	int d = -1;
	while(l <= r){
		int mid = (l + r)>>1;
		int x = 2*mid + 1;

		long double t0 = f(h, c, x);
		if(t0 >= t){
			d = x;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	long double diff = abs(f(h, c, d) - 1.0*t);
	for(int i = d; i <= d + 100; i++){
		long double temp = f(h, c, i);
		// cout<<i<<" "<<temp<<" "<<abs(temp - 1.0*t)<<'\n';
		if(abs(temp - 1.0*t) < diff){
			diff = abs(temp - 1.0*t);
			d = i;
		}
	}

	assert(d != -1);
	cout<<d<<'\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    FILEIO
    #endif
    FLASH

    int t = 1;
    cin>>t;

    while(t--) solv();
}