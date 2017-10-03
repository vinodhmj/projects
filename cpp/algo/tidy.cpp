#include<iostream>
#include <bitset>
#include <limits>
#include <math.h>

using namespace std;


int main(int argc, char *argv[])
{
  int output(0), d1(0), d2(0), i(0),n = 132;
  int D = log10(floor(n)) +1;
  if(D == 1)
    output = n;
  
  for (i = 0; i < D-1; ++i) {
    dl = n/pow(10,i);
    dr = n/pow(10,i+1);
    if(dl < dr)
    {
      output+= 9*pow(10,
      if(i == D-2)
      {
      }
    }
      
      
  }
  return 0;
}
