#include <iostream>
#include <math.h>

using namespace std;

//const int MOD = 1000000009;

long long pow(int a,int b, int MOD)
{
  int x = 1, y = a;
  while(b>0){
      if(b%2==1){
      x=x*y;
      if(x>MOD)
        x=x%MOD;
      }
      y = y*y;
      if(y>MOD) y%=MOD;
      b = b/2;
    }
    return x;
}


// from fermats litle theorem, a^(p-1) mod p = 1 or a^(p-1) congruent to 1 modulo p. p is prime
// modulo inverse of a is ax mod p = 1 or ax congruent to 1 modulo p.
// multiply a^p-2 for above equation to get
// a^(p-1)*x congruent to a^p-2 mod p;
// from fermats theorem reduce this to x congruent to a^(p-2) mod p
// hence we need to find a^p-2 mod p.
long long modInverse(int a,int m)
{
  return pow(a,m-2,m);
}

int main()
{
  int a,m;
  cin>>a>>m;
  cout<<"Mod inverse is:"<<modInverse(a,m)<<endl;
  cout<<endl;
}
