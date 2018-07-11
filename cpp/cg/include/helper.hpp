#ifndef CG_HELPER_H
#define CG_HELPER_H

#include "elements.hpp"
#include <fstream>

namespace cg
{
  void readFromFile(const std::string& sfileName, std::vector<segment>& segments)
  {
    std::ifstream fin(sfileName.c_str());
    if (!fin)
      throw std::runtime_error("Cannot find input file");

    unsigned int nSize = 0;
    int x1(0), y1(0), x2(0), y2(0);

    fin >>  nSize;
    segments.reserve(nSize);
    
    for (unsigned int i=0; i < nSize; ++i) {
      fin >> x1 >> y1 >> x2 >> y2;
      segments.push_back(segment(x1,y1,x2,y2));
    }//do for all segments in input file
    
  }//end of function readFromFile
}// namespace cg

#endif /* CG_HELPER_H */
