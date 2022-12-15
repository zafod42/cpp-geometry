#include <iostream>
#include "rectangle.h"
#include "izotrapezium.h"
#include "complex.h"
#include <fstream>


int main() {
    std::string existingShapes[] = { "COMPOSITE", "RECTANGLE", "IZOTRAPEZIUM" };
    std::string filename;
    std::string input;
    std::fstream file;
    /*std::cout << "Enter name of file: ";
    std::cin >> filename;
    try {
        file.open(filename, std::ios_base::out);
        if (file.is_open() == false) {
            throw std::runtime_error("File does not exist");
        }
    }
    catch (std::runtime_error e) {
        std::cerr << e.what() << '\n';
        exit(-1);
    }*/
    Rectangle rect(point_t(0, 0), point_t(4, 5));
    Izotrapezium izot(point_t(0,0), 6, 3, 5);
    std::cout << rect;
    std::cout << izot;
    CompositeShape complex(5);
    complex.add(&rect);
    complex.add(&izot);
    std::cout << complex << std::endl;
    return 0;
}