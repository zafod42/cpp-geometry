#include <iostream>
#include "rectangle.h"
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
    Rectangle rect(point_t(0, 0), point_t(1, 2));
    file << rect;
    /*while (file >> input) {
        std::cout << input << std::endl;
    }*/
    return 0;
}