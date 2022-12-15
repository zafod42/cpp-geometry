#include <iostream>
#include "rectangle.h"
#include "izotrapezium.h"
#include "complex.h"
#include <fstream>


int main() {
    size_t N = 0, size = 0;
    std::string existingShapes[] = { "COMPLEX", "RECTANGLE", "IZOTRAPEZIUM" };
    std::string filename;
    std::string input;
    std::fstream file;
    std::cout << "Enter name of file: ";
    std::cin >> filename;
    try {
        file.open(filename, std::ios_base::in);
        if (file.is_open() == false) {
            throw std::runtime_error("File does not exist");
        }
    }
    catch (std::runtime_error e) {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
    while (file >> input) {
        for (std::string str : existingShapes) {
            if (str == input) {
                N += 1;
            }
        }
    }
    file.close();
    Shape** shArray = new Shape * [N];
    try {
        file.open(filename, std::ios_base::in);
        if (file.is_open() == false) {
            throw std::runtime_error("File does not exist");
        }
    }
    catch (std::runtime_error e) {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
    bool flag = true;
    while (file >> input) {
        if (input == existingShapes[0]) {
            flag == true;
            size_t maxNum;
            file >> maxNum;
            CompositeShape * complex = new CompositeShape(maxNum);
            do {
                file >> input;
                if (input == "ENDCOMPLEX") {
                    break;
                }
                if (input == existingShapes[1]) {
                    flag = true;
                    point_t leftBot, rightTop;
                    file >> leftBot.x >> leftBot.y;
                    file >> rightTop.x >> rightTop.y;
                    complex->add(new Rectangle(leftBot, rightTop));
                }
                else if (input == existingShapes[2]) {
                    flag = true;
                    point_t leftBot;
                    double lenBot = 0, lenTop = 0, height = 0;
                    file >> leftBot.x >> leftBot.y;
                    file >> lenBot >> lenTop;
                    file >> height;
                    complex->add(new Izotrapezium(leftBot, lenBot, lenTop, height));
                }
                else {
                    if (flag == true) {
                        std::cerr << "Warning: No such shape - " << input << '\n';
                    }
                    flag = false;
                }
            } while (input != "ENDCOMPLEX");
            shArray[size] = complex;
            ++size;
        }
        else if (input == existingShapes[1]) {
            flag == true;
            point_t leftBot, rightTop;
            file >> leftBot.x >> leftBot.y;
            file >> rightTop.x >> rightTop.y;
            shArray[size] = new Rectangle(leftBot, rightTop);
            ++size;
        }
        else if (input == existingShapes[2]) {
            flag == true;
            point_t leftBot;
            double lenBot = 0, lenTop = 0, height = 0;
            file >> leftBot.x >> leftBot.y;
            file >> lenBot >> lenTop;
            file >> height;
            shArray[size] = new Izotrapezium(leftBot, lenBot, lenTop, height);
            ++size;
        }
        else {
            if (flag == true) {
                std::cerr << "Warning: No such shape - " << input << '\n';
            }
            flag = false;
        }
    }
    for (size_t i = 0; i < size; ++i) {
        std::cout<<'\n' << *shArray[i];
    }
    sortByArea(shArray, size);
    for (size_t i = 0; i < size; ++i) {
        std::cout << "\n#" << i << '\n' << *shArray[i];
    }
    for (size_t i = 0; i < size; ++i) {
        delete shArray[i];
    }
    delete shArray;
    return 0;
}