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
#define     MOD             1000000009
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
ll dp[1 << 16] , pwr[16];
char arr[18][18];
int n;
bool chk(int mask , int i){
    return (bool)(mask & (1 << i));
}
int st(int mask , int i){
    return mask = mask | (1 << i);
}
ll go(int mask){
    if(__builtin_popcount(mask) == n) return 0;
    if(dp[mask] != -1) return dp[mask];
    ll ans = MAX;
    for(int i = 0 ; i < n; i++){
        if(chk(mask , i) == true){
            for(int j = 0 ; j < n; j++){
                if(chk(mask , j)) continue;
                ll c = arr[i][j] - 48;
                if(c == 0) continue;
                ll cost = (pwr[j] / c) + (pwr[j] % c != 0);
                ans = min(ans , cost + go(st(mask , j)));
            }
        }
    }
    for(int i = 0 ; i < n; i++){
        if(chk(mask , i ) == false) ans = min(ans , pwr[i] + go(st(mask , i)));
    }
    return dp[mask] = ans;
}
int main()
{
    int t;
    scanf("%d" ,&t);
    for(int i = 1; i <= t; i++){
        scanf("%d" , &n);
        for(int j = 0 ; j < n; j++){
            scanf("%lld" , &pwr[j]);
        }
        string str;
        for(int j = 0 ; j < n; j++){
            cin >> str;
            for(int k = 0 ; k < str.size(); k++){
                arr[j][k] = str[k];
            }
        }
        mem(dp , -1);
        ll ans = go(0);
        printf("Case %d: %lld\n", i , ans);
    }  
    return 0;
}
