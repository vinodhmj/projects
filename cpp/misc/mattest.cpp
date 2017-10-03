//! \file
//! \brief Math Library use
//! \author Vinodh MJ
//! \bugs No known bugs

#include <iostream>
#include "mipmathlib/MIPMathLib.h"

using namespace std;
using namespace MIPMATRIX;

int main(int argc, char *argv[])
{
  try  {
    CMatrix<double> mFull(3,3,FULL,EYE);
    CMatrix<double> mSparse(3, 3, SPARSE);
    mSparse.ReadFromFile("input.txt");

    // uses move semantics
    // mSum matrix will be of type 'FULL'
    auto mSum = mFull + mSparse; 

    // Prints matrix to the console
    std::cout << "Sum Matrix \n"  << mSum;
  }
  catch(std::exception& myex)  {
    cout << myex.what();
  }
  return 0;
}// end of the function main
