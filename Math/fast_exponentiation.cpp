#include <iostream>
using namespace std;

const int MOD = 1000000009;
/**
 * fast exponentiation function.
 * @param  a   integer variable
 * @param  b   exponent
 * @param  MOD
 * @return     a^b
 */
long long pow(int a,int b,int MOD)
{
  int x=1,y=a;                            // idea if we want 5^117; 117 = 1110101 => 2^6+2^5+2^4+2^2+2^0
  while(b)                                // whenever left most bit is 1, => perform 5^(placevalue)
  {
    if(b%2==1)
    {
      x=x*y;
      if(x>MOD)
        x%=MOD;
    }
    y=y*y;
    if(y>MOD)
      y%=MOD;
    b/=2;
  }
  return x;
}

int main()
{
  int a,b;
  cin>>a>>b;
  cout<<"a^b : "<<pow(a,b,MOD)<<endl;
}
