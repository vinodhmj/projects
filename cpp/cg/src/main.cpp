#include <iostream>
#include "../include/elements.hpp"
#include "../include/helper.hpp"

int main(int argc, char* argv[]) {
    try {
        std::vector<cg::segment> segments;
        std::string sFileName = "input.txt";
        cg::readFromFile(sFileName, segments);
        bool ans = cg::segmentsIntersect(segments.at(0), segments.at(1));
        std::cout << segments.at(0) << segments.at(1) << ": " << ans << std::endl;
        ans = cg::segmentsIntersect(segments.at(2), segments.at(3));
        std::cout << segments.at(2) << segments.at(3) << ": " << ans << std::endl;
        ans = cg::segmentsIntersect(segments.at(4), segments.at(5));
        std::cout << segments.at(4) << segments.at(5) << ": " << ans << std::endl;
        ans = cg::segmentsIntersect(segments.at(6), segments.at(7));
        std::cout << segments.at(6) << segments.at(7) << ": " << ans << std::endl;

        // find if colinear
        // find if overlapping
        // find intersections
        std::cout << "The End";
    } catch (std::exception& ex) {
        std::cout << ex.what();
    } catch (...) {
        std::cout << "elipsis";
    }
    return 0;
}
