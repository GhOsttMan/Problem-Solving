#include<bits/stdc++.h>
using namespace std;

#define MAX 5000006

unsigned long long int phi[5000006];
//unsigned long long int Sum[5000006];

/*long long int Euler(int N)
{
    int Ans=N;
    for(int i=2;i*i<=N;i++)
    {
        if(N%i==0)
        {
            while(N%i==0) N/=i;
            Ans-=Ans/i;
        }
    }
    if(N > 1) Ans-=Ans/N;
    return Ans*Ans;
}
*/
void calculatePhi() {
  for (int i = 1; i <= MAX; i++) {
    phi[i] = i;
  }
  for (int p = 2; p <= MAX; p++) {
    if (phi[p] == p) { // p is a prime
      for (int k = p; k <= MAX; k += p) {
        phi[k] -= phi[k] / p;
      }
    }
  }
}
void PreCal()
{
    phi[1]=1;

    for(int i=2;i<=MAX;i++)
    {

        phi[i]=phi[i-1]+(phi[i]*phi[i]);
      //  cout<<i<<" "<<A[i]<<endl;
    }
  //  for(int i=2;i<=MAX;i++) Sum[i]=Sum[i-1]+A[i];
}

int main()
{
    int T;
    scanf("%d",&T);
    calculatePhi();
    PreCal();
    for(int i=1;i<=T;i++)
    {
       // cout<<i<<endl;
        int a,b;
        scanf("%d %d",&a,&b);
        int x=max(a,b);
        int y=min(a,b);
        printf("Case %d: %llu\n",i,phi[x]-phi[y-1]);
    }
}
