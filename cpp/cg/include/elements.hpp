#ifndef CG_ELEMENTS_H_
#define CG_ELEMENTS_H_

#include <string>
#include <vector>

namespace cg {
template <typename T = int>
struct point {
    T x;
    T y;
};

class segment {
  public:
    segment(int x1, int y1, int x2, int y2) {
        left.x = x1;
        left.y = y1;
        right.x = x2;
        right.y = y2;
    }

    ~segment() {
    }

    segment(const segment& other) {
        left = other.left;
        right = other.right;
    }

    segment* operator=(const segment& other) = delete;

  public:
    point<int> left;
    point<int> right;
};

typedef segment line;

} // namespace cg

#endif /* CG_ELEMENTS_H_ */
