#include "pointers.h"
template <typename T>
struct Point 
{
  T x=T(1), y=T(2);
};
void smartpointers(std::unique_ptr<double> udoub)
{
  //unique pointer
  // unique_ptr<Point<double>> Pointstr(new Point<double>());
  //cout << Pointstr->x;
}

int main()
{
  //std::unique_ptr<double> udoub(new double);
  //  smartpointers(udoub);
  return 0;
}
