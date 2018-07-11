#include <iostream>
#include "../include/elements.hpp"
#include "../include/helper.hpp"

int main(int argc, char *argv[])
{
  try
  {
  std::vector<cg::segment> segments;
  std::string sFileName = "input.txt";
  cg::readFromFile(sFileName, segments);
  
  // test case
  // read from file
  // find intersections
  }
  catch (std::exception& ex)
  {
    std::cout<<ex.what();
  }
  catch(...)
  {
    std::cout<<"elipsis";
  }
  return 0;
}

