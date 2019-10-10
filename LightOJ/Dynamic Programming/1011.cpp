#include<bits/stdc++.h>
using namespace std;

long long int A[20][20];
long long int dp[20][(1<<17)];
long long int N;

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

long long int BitMask(long long int i,long long int mask)
{
    if(i > N) return 0;

    if(dp[i][mask]!=-1) return dp[i][mask];

    long long int Ans=0,Max=-1;

    for(int j=1;j<=N;j++)
    {
        if(Check(mask,j)==false)
        {
            Ans=A[i][j]+BitMask(i+1,Set(mask,j));
        }
        Max=max(Ans,Max);
    }
    return dp[i][mask]=Max;
}

int main()
{
    long long int T;
    scanf("%lld",&T);

    for(long long int i=1;i<=T;i++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%lld",&N);

        for(long long int j=1;j<=N;j++)
        {
            for(long long int k=1;k<=N;k++)
            {
                scanf("%lld",&A[j][k]);
            }
        }
        long long int Ans=BitMask(1,0);
        printf("Case %lld: %lld\n",i,Ans);
    }
}
