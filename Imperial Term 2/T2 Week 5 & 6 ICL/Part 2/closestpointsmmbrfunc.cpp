//Complete the following program which reads a sequence of points from a text file, stores them in a vector and prints the two which are closest to each other.

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
 
struct Point{
    double x;
    double y;
 
    std::string to_s() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
 
    double distance(Point p) const {
        return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
    }
}; 
 
// idxp1 and idxp2 are output parameters
// after the function call they will contain
// the indices of the two closest points in vp
// if vp contains two points or more
// (otherwise they will just contain uninitialised values)
 
void closest_points(const std::vector<Point>& vp, int& idxp1, int& idxp2){
    // TODO:
    // complete this function
    // (make use of member function distance)
    double tmp, min; 
    min = 99; // we choose 99 as it is a good beginning value
    for(int i = 0; i < vp.size()-1; i++){
        for(int j = i+1; j < vp.size(); j++){
            tmp = vp[i].distance(vp[j]); 
            if(tmp < min){
                idxp1 = i; 
                idxp2 = j; 
                min = tmp; 
            }
        } 
    }
}
 
int main(){
 
    // TODO:
    // read the points from the file
    // and store them in vector points

    std::ifstream infile; 
    infile.open("points.txt"); 

    if(!infile.is_open()){
        std::cout << "error opening input file" << std::endl; 
        return EXIT_FAILURE; 
    }

    std::vector<Point> points; 
    Point tmp; 

    while(infile >> tmp.x >> tmp.y){
        points.push_back(tmp); 
    }

    infile.close();
 
    if(points.size() == 0){
        std::cout << "there are no points in the file" << std::endl;
    }
    else if(points.size() == 1){
        std::cout << "there is only one point in the file" << std::endl;
    }
    else{
        int idxp1, idxp2;
        closest_points(points, idxp1, idxp2);

        std::cout << "The closest points are: " << std::endl; 
        std::cout << points[idxp1].to_s() << std::endl; 
        std::cout << points[idxp2].to_s() << std::endl; 
        // TODO: 
        // print the two points
        // (make use of member function to_s)
    }
}

// removing const causes failure of the code as code will not compile
