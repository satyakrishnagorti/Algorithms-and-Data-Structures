#include <iostream>
#include <algorithm>
using namespace std;

int lcs(string x,string y)
{
  string lcs_str="";
  int DP[x.size()+1][y.size()+1];
  for(int i=0;i<=x.size();i++) 
    for(int j=0;j<=y.size();j++) 
      DP[i][j]=0;

  for(int i=1;i<=x.size();i++)
  {
    for(int j=1;j<=y.size();j++)
    {
      if(x[i]==y[j]){
        DP[i][j]=DP[i-1][j-1]+1;
        lcs_str+=x[i];
      }
      else
        DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
    }
  } 

  for(int i=0;i<=x.size();i++){
    for(int j=0;j<=y.size();j++)
      cout<<DP[i][j]<<" ";
    cout<<endl;
  }
  cout<<lcs_str<<endl;
}

int main()
{
  string a,b;
  //cin>>a>>b;
  lcs("abcbdab","bdcabc");
}