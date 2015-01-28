#include <iostream>
#include <math.h>
using namespace std;

int gcd(int a,int b)
{
  while(b!=0)
  {
    int r = a%b;
    a=b;
    b=r;
  }
  return a;
}

/**
 * tests if ax+by=c has integer solutions
 * @param  a integer
 * @param  b integer
 * @return   1 if solution exists, 0 otherwise
 */
int diophantine_test(int a,int b,int c)
{
  //  Let d be gcd(a,b)
  //  since d | a and d | b, then d | c if there exists integer solutions
  int d = gcd(a,b);
  if(c%d==0){

    return 1;
  }
  else
    return 0;
}

int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  if(diophantine_test(a,b,c))
    cout<<"Yes there are integer solutions"<<endl;
  else
    cout<<"no there aren't integer solutions"<<endl;
  return 0;
}
