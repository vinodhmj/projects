#ifndef CG_HELPER_H
#define CG_HELPER_H

#include "elements.hpp"
#include <fstream>

namespace cg {
void readFromFile(const std::string& sfileName, std::vector<segment>& segments) {
    std::ifstream fin(sfileName.c_str());
    if (!fin) {
        throw std::runtime_error("Cannot find input file");
    }

    unsigned int nSize = 0;
    int x1(0), y1(0), x2(0), y2(0);

    fin >> nSize;
    segments.reserve(nSize);

    for (unsigned int i = 0; i < nSize; ++i) {
        fin >> x1 >> y1 >> x2 >> y2;
        segments.push_back(segment(x1, y1, x2, y2));
    } // do for all segments in input file

} // end of function readFromFile

int direction(const point<int>& i, const point<int>& j, const point<int>& k) {
    return (i.x - k.x) * (j.y - k.y) - (j.x - k.x) * (i.y - k.y);
} // end of function direction

template <typename T>
bool isInBounds(const T& value, const T& low, const T& high) {
    return (value >= low) && (value <= high);
} // end of function isInBounds

bool onSegment(const point<int>& i, const point<int>& j, const point<int>& k) {
    bool xBound = isInBounds(k.x, std::min(i.x, j.x), std::max(i.x, j.x));
    bool yBound = isInBounds(k.y, std::min(i.y, j.y), std::max(i.y, j.y));
    if (xBound && yBound) {
        return true;
    } else {
        return false;
    }
} // end of function onSegment

bool segmentsIntersect(const segment& a, const segment& b) {
    int d1 = direction(b.left, b.right, a.left);
    int d2 = direction(b.left, b.right, a.right);
    int d3 = direction(a.left, a.right, b.left);
    int d4 = direction(a.left, a.right, b.right);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    } else if (d1 == 0 && onSegment(b.left, b.right, a.left)) {
        return true;
    } else if (d2 == 0 && onSegment(b.left, b.right, a.right)) {
        return true;
    } else if (d3 == 0 && onSegment(a.left, a.right, b.left)) {
        return true;
    } else if (d4 == 0 && onSegment(a.left, a.right, b.right)) {
        return true;
    } else {
        return false;
    }
} // end of function segmentIntersect

} // namespace cg

std::ostream &  operator<<(std::ostream &output, const cg::point<int>& pt) {
    output << "(" << pt.x << "," << pt.y << ")";
    return output;
}

std::ostream &  operator<<(std::ostream &output, const cg::segment& seg) {
    output << seg.left << "\t" << seg.right << "\n";
    return output;
}



#endif /* CG_HELPER_H */
