#include <bits/stdc++.h>

using namespace std;

void CoinChangingWaysDP(int denominations[],int denom_length,int value)
{

  int DP[denom_length+1][value+1];

  for(int i=0;i<value+1;i++)
    DP[0][i]=0;
  for(int i=0;i<denom_length+1;i++)
    DP[i][0]=1;

  for(int i=1;i<denom_length+1;i++)
  {
    for(int j=1;j<value+1;j++)
    {
      if(denominations[i-1]>j)
        DP[i][j]=DP[i-1][j];
      else
        DP[i][j]=DP[i-1][j]+DP[i][j-denominations[i-1 ]];
    }
  }
  for(int i=0;i<denom_length+1;i++)
  {
    for(int j=0;j<value+1;j++)
      cout<<DP[i][j]<<"  ";
    cout<<endl;
  }
}

int main()
{
  int denominations[]={1,2,3};
  int denom_length = 3;
  int value = 5;
  CoinChangingWaysDP(denominations,denom_length,value);
  return 0;
}