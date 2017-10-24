/**
    Main function for the chan 2d algorithm implementation.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <random>

#include "Point.h"
#include "utility.h"
#include "ChanAlgorithm.h"



int main(int argc, char const *argv[]) {
    int POINT_COUNT = 0, PARALLELISM_IDX = 3;

    FileWriter fileWriter;
    fileWriter.setBaseName("graham_history");
    fileWriter.updateFileName();


    ChanAlgorithm chanAlgo;
    //TODO: Parallel implementation
    /*
    std::cout << "Please enter the parallelism index:" << std::endl;
    std::cin >> PARALLELISM_IDX;
    if(PARALLELISM_IDX < 1) return -1;
    */

    std::cout << "Please enter the total number of points:" << std::endl;
    std::cin >> POINT_COUNT;
    if(POINT_COUNT < PARALLELISM_IDX * 3) {
        std::cout << "Please need more points or less parallelism." << std::endl;
        return -1;
    }

    std::vector<Point> points = createPoints(POINT_COUNT);
    pointsVectorToFile(points, "all_points.dat");

    // std::vector<Point> result = graham_scan(points);
    std::vector<Point> result = chanAlgo.chan(points, PARALLELISM_IDX);
    std::cout << "=========Result=========" << std::endl;
    for(Point point: result) {
        std::cout << point << " ";
    }
    std::cout << std::endl;

    pointsVectorToFile(result, "hull_points.dat");

    return 0;
}
