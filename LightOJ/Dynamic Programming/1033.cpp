#include<bits/stdc++.h>
using namespace std;
string A,B;
int dp[102][102];

int LCS(int i,int j)
{
    if(i >= A.size() || j >= B.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int Ans=0;
    if(A[i]==B[j]) Ans=1+LCS(i+1,j+1);

    else
    {
        Ans=max(LCS(i,j+1),LCS(i+1,j));
    }
    return dp[i][j]=Ans;
}
int main()
{
    int T;
    scanf("%d",&T);

    for(int i=1;i<=T;i++)
    {
        cin>>A;
        B=A;
        reverse(A.begin(),A.end());
        memset(dp,-1,sizeof(dp));
        int Ans=LCS(0,0);

        printf("Case %d: %d\n",i,A.size()-Ans);
    }
}
