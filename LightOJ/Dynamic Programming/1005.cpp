/*****************Bismillahir Rahmanir Rahim***********************/

#include<bits/stdc++.h>
using namespace std;

/************************Start Of Template*************************/

/******** Mahin Shefat - GhOstMan *************/


#define     pb              push_back
#define     popb            pop_back
#define     ll              long long int
#define     ull             unsigned long long int
#define     max3(a,b,c)     max(a,max(b,c))
#define     max4(a,b,c,d)   max(max3(a,b,c),d)
#define     min3(a,b,c)     min(a,min(b,c))
#define     min4(a,b,c,d)   min(a,min3(b,c,d))
#define     MOD             1000000007
#define     f               first
#define     s               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     mp              make_pair
#define     check           printf("check")
#define     sqr(x)          (x)*(x)
#define     all(v)          v.begin(),v.end()
#define     fast            ios_base::sync_with_stdio(0);cin.tie(0)
#define     pii             pair<int,int>
#define     Pair            pair<ll,ll>
#define     MAX             1000000000000014
#define     MIN             -100000000000014
#define     Fread           freopen("input.txt","r",stdin);
#define     Fwrite          freopen("output.txt","w",stdout);


/************************End Of Template*************************/
int n;
ll dp[33][902][33];
ll go(int i , int k , int way){
	if(k == 0) return 1;
	if(i > n) return 0;
	if(dp[i][k][way] != -1) return dp[i][k][way];
	dp[i][k][way] =  way * go(i + 1 , k - 1 , way - 1) + go(i + 1 , k , way);
	return dp[i][k][way];
}
int main()
{	
	int t;
	scanf("%d" , &t);
	for(int tc = 1; tc <= t; tc++){
		int k ;
		scanf("%d %d" ,&n , &k);
		mem(dp , -1);
		ll ans = go(1 , k , n);
		printf("Case %d: %lld\n", tc , ans);
	}	
	return 0;
}
