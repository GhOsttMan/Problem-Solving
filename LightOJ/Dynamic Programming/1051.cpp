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
int dp[52][6][4];
string st;
bool vowel(char c){
    string k = "AEIOU";
    for(int i = 0 ; i < k.size() ; i++){
        if(k[i] == c) return true;
    }
    return false;
}
int go(int i , int con , int vwl){
    if(con >= 5 || vwl >= 3) return 2;
    if(i >= st.size()){
        return 1;
    }
    if(dp[i][con][vwl]!= -1) return dp[i][con][vwl];
    int ans ;
    if(vowel(st[i])){
         ans = go(i + 1 , 0 , min(3 , vwl + 1 ) );
    }
    else{
        if(st[i] == '?'){
            int way1 = go(i + 1 , min(5 , con + 1) , 0);
            int way2 = go(i + 1 , 0 , min(3 , vwl + 1));
            if(way2 == way1) ans = way1;
            else ans = 3;
        }
        else {
             ans = go(i + 1 , min(5 , con + 1) , 0);
        }
    }
    return dp[i][con][vwl] = ans;
}
 
int main()
{
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> st;
        mem(dp , -1);
        int ans = go(0 , 0 , 0);
        printf("Case %d: ", tc);
        if(ans == 1) printf("GOOD\n");
        else if(ans == 2) printf("BAD\n");
        else printf("MIXED\n");
    }  
    return 0;
}
