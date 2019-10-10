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
bool Check(int Mask,int Pos){
    return (bool)(Mask&(1<<Pos));
}
int Set(int Mask,int Pos){
    return Mask=Mask|(1<<Pos);
}
int n;
pair < int , int > arr[18];
ll dp[(1 << 16) + 5];
bool ok(int i , int j , int k){
	if(arr[i].f * (arr[j].s - arr[k].s) + arr[j].f * (arr[k].s - arr[i].s) + arr[k].f * (arr[i].s - arr[j].s) == 0){
		return true;	
	}
	return false;
}
ll go(int mask){
	if(__builtin_popcount(mask) == n) return 0;
	if(__builtin_popcount(mask) == n - 1) return 1;
	if(dp[mask] != -1) return dp[mask]; 
	ll ans = MAX;
	for(int i = 0; i < n; i++){
		if(Check(mask , i) == false){
			for(int j = 0; j < n;j++){
				if(i != j and Check(mask , j) == false){
					int tmp = mask;
					for(int k = 0; k < n; k++){
						if(ok(i , j , k)){
							tmp = Set(tmp , k);
						}
					}
					ans = min(ans , 1 + go(tmp));
				}
			}
			break;
		}
	}
	return dp[mask] = ans;
}
int main()
{
	int t;
	scanf("%d" , &t);
	for(int ii = 1; ii <= t; ii++){
		scanf("%d" , &n);
		for(int i = 0; i < n; i++){
			scanf("%d %d" , &arr[i].f , &arr[i].s);
		}
		mem(dp , -1);
		printf("Case %d: %lld\n", ii , go(0));
	}
	return 0;
}
