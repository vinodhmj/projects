/*!
  \file
  \author Vinodh MJ Human
  \brief google code jam Oversized pancake flipper problem
  
 */

#include <iostream>
#include <string>
#include <math.h>
#include <limits>
#include <complex>
#include <vector>
#include <list>
#include <memory>
#include <functional>
#include <fstream>

using namespace std;

//count
int nflip_count, k;
std::vector<bool> vbCakes;

std::vector get_bool_cakes(string& sCakes)
{
  vbCakes.resize(sCakes.size(), false);
  int i(0);
  for (i=0; i < vbCakes.size(); i++) {
    if(sCakes.at(i) == '+')
      vbCakes.at(i) = true;
  }// loop for number of pancakes

  return std::move(vbCakes);
}
void flip_and_merge()
{
  vbCakes.
}
void flip_cakes(int p, int r)
{
  if(p <= k)
  {
    
    flip_cakes(p/2);
    
  }
}

int main(int argc, char *argv[])
{
  try
  {
    ifstream fin("input.txt");
    if(!fin){throw std::runtime_error("failed to load input file\n");}
    ofstream fout("output.txt");
    int i(0), TestCases(0);
    std::string sCakes;
    fin >> nTestCases; 
    for (i = 0; i < nTestCases; ++i) {
      fin>>sCakes;
      fin>>k;
      get_bool_cakes(sCakes);
      flip_cakes(0, vbCakes.size());
      fout<< "Case #" << i << ": " << nflip_count <<endl;
    }
    fin.close();
    fout.close();
  }
  catch(std::exception& myex)
  {
    cout<< "Exception occured \t" << myex.what() << endl;
  }
  catch(...)
  {
    cout<< "Exception occured \t" << "unhandled exception" << endl;
  }
  return 0;
}

