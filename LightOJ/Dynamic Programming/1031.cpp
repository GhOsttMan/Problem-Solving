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
Pair dp[102][102][2];
ll arr[102];
Pair go(int i , int j , int ok){
	if(j < i) return mp(0 , 0);
	if(dp[i][j][ok].f != MIN) return dp[i][j][ok];
	ll sum = 0;
	Pair ans = mp(MIN , MIN);
	for(int l = i; l <= j; l++){
		sum += arr[l];
		Pair tot = go(l + 1 , j , ok ^ 1);
		if(ok == 0){
			if(tot.f + sum > ans.f){
				tot.f += sum;
				ans = tot;
			}
		}else {
			if(tot.s + sum > ans.s){
				tot.s += sum;
				ans = tot;
			}
		}
	}
	sum = 0;
	for(int r = j ; r >= i; r--){
		sum += arr[r];
		Pair tot = go(i , r - 1 , ok ^ 1);
		if(ok == 0){
			if(tot.f + sum > ans.f){
				tot.f += sum;
				ans = tot;
			}
		}else {
			if(tot.s + sum > ans.s){
				tot.s += sum;
				ans = tot;
			}
		}
	}
	return dp[i][j][ok] = ans;
}
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d" , &t);
	for(int ii = 1; ii <= t; ii++){
		int n;
		scanf("%d" , &n);
		for(int i = 1; i <= n; i++){
			scanf("%lld" , &arr[i]);
			for(int j = 1; j <= n; j++){
				for(int k = 0; k <= 1; k++) dp[i][j][k].f = MIN;
			}
		}
		Pair ans = go(1 , n , 0);
		printf("Case %d: %lld\n", ii , ans.f - ans.s);
	}
	return 0;
}
