#include <iostream>
#include <string>
#include <math.h>
#include <limits>
#include <complex>
#include <vector>
#include <list>
#include <memory>
#include <functional>

using namespace std;

//----------------------------------------------------
//!
void merge_sort(std::vector<int>& vNum, std::function<bool(int,int)> sort_func)
{
	//recursive algorithm
	vNum.size();
	
} // end of the function merge_sort
//----------------------------------------------------

//----------------------------------------------------
//! \fn void insertion_sort(std::vector& vNum)
//! \brief method that performs insertion on a vector of integers
void insertion_sort(std::vector<int>& vNum, std::function<bool(int,int)> sort_func)
{
  if(vNum.size()<=1) {return;}
  int i(0), j(0), iKey(0);//key to compare
  for (i = 1; i < vNum.size(); i++) {
    iKey=vNum.at(i); // initialize key
    j = i-1;
    while (j >= 0 && sort_func(vNum.at(j),iKey)) {
      vNum.at(j+1) = vNum.at(j);
      --j;
    }
    vNum.at(j+1) = iKey;
  }//loop from second element in the vector to size()
}// end of the function insertion_sort
//----------------------------------------------------
//! \fn void fill_args_to_vector(int argc, char *argv[])
//! \brief function to fill command line arguments into vectore
std::vector<int> fill_args_to_vector(int argc, char *argv[])
{
  std::vector<int> vNum;
  vNum.resize(argc-1);
  for (int i = 1; i < argc; i++) 
  {
    vNum.at(i-1) = std::atoi(argv[i]);
  }
  return std::move(vNum);
}// end of the function fill_args

int main(int argc, char *argv[])
{
  try
  {
    // cout << argc << '\t' << argv[0] << '\t'<< argv[1]  << '\t' << argv[2] << endl;
    if (argc <= 1) return 0;
    auto vNum = fill_args_to_vector(argc, argv); 
    insertion_sort(vNum, std::greater<int>());
    for(auto& var : vNum)
    {
      cout << var << endl;
    }
    
  }
  catch(std::exception& myex)
  {
    std::cout <<  myex.what()  << "\n";
  }
  return 0;
}
  








