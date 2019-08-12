#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define pb push_back
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define maxn 200000

using namespace std;


struct date{
	string d, m, y;
	int day, month, year;
};


bool comp(date date1, date date2){
	if(date1.year != date2.year) return date1.year < date2.year;
	if(date1.month != date2.month) return date1.month < date2.month;	
	return date1.day < date2.day;
}

bool valid(date d){
	if(d.year < 2000 or d.month < 1 or d.month > 12) return 0;
	bool leap = 0;
	if(d.year%400 == 0) leap = 1;
	else if(d.year%100 == 0) leap = 0;
	else if(d.year%4 == 0) leap = 1;

	int days[] = {-1, 31, 28 + leap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(d.day < 1 or d.day > days[d.month]) return 0;
	return 1;
}

void solv(){
	date d1, ans;

	char p[8];
	for(int i = 0; i < 8; i++){
		cin>>p[i];
	}

	sort(p, p + 8);
	
	ans.d = "99", ans.m = "99", ans.y = "99";
	ans.day = 99, ans.month = 99, ans.year = 9999;

	int cnt = 0, temp = 0;

	do{
		string x = "";
		x  += p[0];
		x += p[1];
		d1.d = x;

		x = "";
		x += p[2];
		x += p[3];
		d1.m = x;

		x = "";
		x += p[4];
		x += p[5];
		x += p[6];
		x += p[7];
		d1.y = x;

		d1.day = stoi(d1.d);
		d1.month = stoi(d1.m);
		d1.year = stoi(d1.y);		
		
		if(valid(d1) ){
			cnt++;
			if(comp(d1, ans)){
				ans = d1;
			}
		}
		temp++;
	}while(next_permutation(p, p + 8));

	if(cnt != 0){
		cout<<cnt<<" ";
		cout<<ans.d<<" "<<ans.m<<" "<<ans.y<<'\n';
	}
	else cout<<0<<"\n";

}
signed main()
{
	FLASH

 	int t;
 	cin>>t;
 	while(t--) solv();
}