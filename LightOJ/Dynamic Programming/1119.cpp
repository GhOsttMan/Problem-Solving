#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll A[16][16];
ll dp[1<<16];
ll N;
int Set(int n,int P)
{
    return n=(n | (1<<P));
}
int Reset(int n,int P)
{
    return n=(n & ~(1<<P));
}
bool Check(int n,int P)
{
    return (bool)( n & (1<<P));
}


ll BitMask(int mask)
{
   // cout<<mask<<" "<<(1 << N)-1<<endl;
    if(mask==(1<<N)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];

    ll Ans,Max=1000000009;

    for(int i=0;i<N;i++)
    {
        ll Sum;
        if(Check(mask,i)==false)
        {
            Sum=A[i][i]+BitMask(Set(mask,i));
            for(int j=0;j<N;j++)
            {
                if(Check(mask,j)==true && i!=j)
                {
                    Sum+=A[i][j];
                }
            }
           // cout<<Sum<<endl;
            Max=min(Max,Sum);
        }
    }
    return dp[mask]=Max;
}

int main()
{
    ll T;
    scanf("%lld",&T);

    for(ll i=1 ; i<=T ; i++)
    {
        scanf("%lld",&N);
        memset(dp,-1,sizeof(dp));
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                scanf("%lld",&A[j][k]);
            }
        }
        ll Ans=BitMask(0);

        printf("Case %lld: %lld\n",i,Ans);
    }
}
