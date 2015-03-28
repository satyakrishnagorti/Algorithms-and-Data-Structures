/*
given a value and a set of denominations, find the way in which minimum
denominations sum up  to the value given that infinite no of coins of a 
particular denomination are available.
example: 
denominations = [1,5,7,8] value: 11; answer:2 i.e 5+6
 */

#include <bits/stdc++.h>
using namespace std;

void CoinChangingMinDP(int denominations[],int denom_length,int value)
{
  int DP[denom_length+1][value+1];
  for(int i=0;i<value+1;i++)
    DP[0][i]=i;
  for(int i=0;i<denom_length+1;i++)
    DP[i][0]=0;

  for(int i=1;i<denom_length+1;i++)
  {
    for(int j=1;j<value+1;j++)
    {
      if(denominations[i-1]>j)
        DP[i][j]=DP[i-1][j];
      else
        DP[i][j]=min(DP[i-1][j],1+DP[i][j-denominations[i-1]]);
    }
  }

  for(int i=0;i<denom_length+1;i++)
  {
    for(int j=0;j<value+1;j++)
      cout<<DP[i][j]<<"  ";
    cout<<endl;
  }

  cout<<"Min value is:"<<DP[denom_length][value]<<endl;
}

int main()
{
  int denominations[]={1,5,6,8};
  int denom_length = sizeof(denominations)/sizeof(denominations[0]);
  int value = 11;

  CoinChangingMinDP(denominations,denom_length,value);
}
