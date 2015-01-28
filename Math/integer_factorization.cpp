#include <iostream>
#include <math.h>

using namespace std;

void factorization(int n)
{
  while(n%2==0)
  {
    cout<<"2 ";
    n/=2;
  }
  for(int i=3;i<=sqrt(n);i=i+2)
  {
    if(n%i==0)
    {
      cout<<i<<" ";
      n/=i;
    }
  }

  // case when n is prime;
  if(n>2)
    cout<<n<<" "<<endl;
}

int main()
{
  int n;
  cin>>n;
  factorization(n);
  return 0;
}
