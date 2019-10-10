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
#define     MAX             1000000000000000000
#define     MIN             -100000000000014
#define     Fread           freopen("input.txt","r",stdin);
#define     Fwrite          freopen("output.txt","w",stdout);
 
 
/************************End Of Template*************************/
ll dp[33][2][2][33][3];
std::vector<ll> arr;
ll go(int i , int small , int start , ll tot , int yes){
    if(i == arr.size()) return tot;
    if(dp[i][small][start][tot][yes] != -1) return dp[i][small][start][tot][yes];
    ll ans = 0;
    int last = (small ? 1 : arr[i]);
    if(start){
        for(int j = 1; j <= last ; j++){
            ans += go(i + 1 , small | j < arr[i] , 0 , tot + (j == 1 && yes == 1) , j);
        }
        ans += go(i + 1 , 1 , 1, 0 , 0);
    }
    else {
        for(int j = 0; j <= last ; j++){
            ans += go(i + 1 , small | j < arr[i] , 0 , tot + (j == 1 && yes == 1) , j);
        }
    }
    return dp[i][small][start][tot][yes] = ans;
}
ll digit(ll n){
    if(n < 3) return 0;
    mem(dp , -1);
    arr.clear();
    while(n > 0){
        arr.pb(n % 2);
        n /= 2;
    }
    reverse(all(arr));
    return go(0 , 0 , 1 , 0 , 0);
}
int main()
{
    int t;
    scanf("%d" , &t);
    for(int i = 1; i <= t; i ++){
        ll n;
        scanf("%lld" ,&n);
        ll ans = digit(n);
        printf("Case %d: %lld\n", i , ans);
    }  
    return 0;
}
