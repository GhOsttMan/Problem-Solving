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
#define     Pair            pair< int ,ll>
#define     MAX             1000000000000014
#define     MIN             -100000000000014
#define 	endl			'\n'
#define     Fread           freopen("input.txt","r",stdin)
#define     Fwrite          freopen("output.txt","w",stdout)


/************************End Of Template*************************/
Pair dp[33][33];
string a , b;
Pair go(int i , int j){
	if(i >= a.size() and j >= b.size()) return mp(0 , 1);
	if(i >= a.size()) return mp((b.size() - j) , 1);
	if(j >= b.size()) return mp((a.size() - i) , 1);
	if(dp[i][j].f != -1) return dp[i][j];
	Pair ans1 = mp(1e5 , 0);
	Pair ans2 = ans1, ans3 = ans1;
	if(a[i] == b[j]){
		ans1 = go(i + 1 , j + 1);
	}else {
		ans2 = go(i , j + 1);
		ans3 = go(i + 1 , j);
	}
	Pair mn;
	mn.f = min3(ans1.f , ans2.f , ans3.f);
	if(ans1.f == mn.f)  mn.s += ans1.s;
	if(ans2.f == mn.f) mn.s += ans2.s;
	if(ans3.f == mn.f) mn.s += ans3.s;
	mn.f++;
	return dp[i][j] = mn;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d" , &t);
	for(int ii = 1; ii <= t; ii++){
		cin >> a >> b;
		mem(dp , -1);
		printf("Case %d: %d %lld\n", ii , go(0 , 0).f , go(0 , 0).s);
	}
	return 0;
}
