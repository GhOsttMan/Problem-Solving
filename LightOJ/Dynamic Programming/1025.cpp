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
#define 	endl			'\n'
#define     Fread           freopen("input.txt","r",stdin)
#define     Fwrite          freopen("output.txt","w",stdout)


/************************End Of Template*************************/
string st;
ll dp[65][65];
ll go(int i , int j){
	if(i > j) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	ll ans = 0;
	if(st[i] == st[j]){
		ans = 1 + go(i + 1 , j - 1);
	}
	ans += go(i + 1 , j);
	ans += go(i , j - 1);
	ans -= go(i + 1 , j - 1);
	return dp[i][j] = ans;
}
int main()
{
	int t;
	scanf("%d" , &t);
	for(int ii = 1; ii <= t; ii++){
		cin >> st;
		int n = st.size() - 1;
		mem(dp , -1);
		printf("Case %d: %lld\n", ii , go(0 , n));
	}
	return 0;
}
