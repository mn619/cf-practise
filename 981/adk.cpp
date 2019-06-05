#include<bits/stdc++.h>
#define int long long int
#define fr(i,x,y) for(int i=x;i<y;i++)
#define f(n) for(int i=0;i<n;i++)
#define ff(m) for(int j=0;j<m;j++)
#define fff(l) for(int k=0;k<l;k++)
#define in insert
#define pb push_back
#define c(x) cout<<x<<endl;
#define d(x) cout<<x<<" ";
#define m(x) x%1000000007
#define inc int x=0,y=0,n=0,t=0,count=0,counter=0,q=0,p=0,g=0,h=0,l=0,u=0,sum=0,sum1=0,sum2=0,count1=0,count2=0;
#define inc1(n) int a[n],b[n];
using namespace std;
void ins(int a[],int n,int i=0){f(n) a[i]=i;} template<typename t>void ins(t a[],int n,t i=0){ f(n) a[i]=i;}
void print(int a[],int n){ f(n) d(a[i]); cout<<endl;} template <typename t>void print(t a[],int n){f(n) d(a[i]); cout<<endl;}
void po(int a[],int n){f(n){   cin>>a[i]; } } template <typename t>void po(t a[],int n){f(n){cin>>a[i];}}
//strlen(s.c_str());  set <int, greater<int>> s; numeric_limits<double>::max()
//---------------------------------------------------------------------------------------------------------------------------------------------



#define int int
int main(){
	#define int long long int
	int n;
	cin>>n;
	vector <int> a[n+1];
	int x,y;
	
	f(n-1){
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
		
		
		
	}
	int counter=0;
	int ind=0;
	
	for(int i=1;i<=n;i++){
		if(a[i].size()>2){
			counter++;
			ind=i;
		}
	}
	
	if(counter==0){
		cout<<"Yes"<<endl;
		cout<<1<<endl;
		cout<<1<<" "<<n<<endl;
	}
	else if(counter>=2){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
		vector <int>:: iterator it;
		vector <int>:: iterator it1;
		vector <int>:: iterator it2;
		vector <int>:: iterator it3;
		cout<<a[ind].size()<<endl;
		int index;
		
		for(it=a[ind].begin();it!=a[ind].end();it++){
			cout<<ind<<" ";
			it1=it;
			index=ind;
			it3=it;
			while(a[*it1].size()>=2){
				for(it2=a[*it1].begin();it2!=a[*it1].end();it2++){
					if(*it2!=index){
						index=*it1;
						it1=it2;
						it3=it2;
						
						break;
						
						
					}
				}
			}
			cout<<*it1<<endl;
			
		}
		
	}
	
	
	





	return 0;
}

