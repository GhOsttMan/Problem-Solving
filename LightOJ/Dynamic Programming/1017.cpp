#include<bits/stdc++.h>
using namespace std;

long long int N,w,K,a,A[105];
long long int dp[105][105];

long long int Rec(int i,int taken)
{
    if(i >= N || taken >= K) return 0;
    if(dp[i][taken]!=-1) return dp[i][taken];

    long long int Max1=0,Max2=0,j;
    long long int Range=A[i]+w;

    for(j=i; j < N ;j++)
    {
        if(A[j] > Range) break;
        Max1++;
    }
    Max1=Max1+Rec(j,taken+1);
    Max2=Rec(i+1,taken);

    return dp[i][taken]=max(Max1,Max2);
}

int main()
{
    long long int T;
    scanf("%lld",&T);

    for(long long i=1;i<=T;i++)
    {
        scanf("%lld %lld %lld",&N,&w,&K);
        memset(dp,-1,sizeof(dp));

        for(int j=0;j<N;j++) scanf("%lld %lld",&a,&A[j]);
        sort(A,A+N);

        long long int Ans=Rec(0,0);
        printf("Case %lld: %lld\n",i,Ans);
    }
}
