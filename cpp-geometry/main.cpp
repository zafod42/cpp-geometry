#include <iostream>
#include "rectangle.h"
#include "izotrapezium.h"
#include <fstream>


int main() {
    std::string existingShapes[] = { "COMPOSITE", "RECTANGLE", "IZOTRAPEZIUM" };
    std::string filename;
    std::string input;
    std::fstream file;
    std::cout << "Enter name of file: ";
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
    }
    Rectangle rect(point_t(0, 0), point_t(4, 5));
    Izotrapezium izot(point_t(0,0), 5, 3, 5);
    file << rect;
    file << izot;
    if (rect == izot) {
        file << rect.getName() << " equal to " << izot.getName() << std::endl;
    }
    else if (rect < izot){
        file << izot.getName() << " greater than " << rect.getName() << std::endl;
    }
    else {
        file << rect.getName() << " greater than " << izot.getName() << std::endl;
    }
    /*while (file >> input) {
        std::cout << input << std::endl;
    }*/
    return 0;
}