#include <iostream>

#include "expression_parser.h"
#include "solid_of_revolution.h"

#include "tests/solid_of_revolution_tests.h"
#include "tests/expression_parser_tests.h"

int main() {

    std::cout << "Enter 0 if you want to enter function symbolically or 1 if you want to enter a function as a table: ";
    char ch;
    std::cin >> ch;

    if(ch == '1') {
        std::cout << "Please enter number of points to interpolate function from: ";
        std::size_t n = 0;
        std::cin >> n;

        std::vector<std::pair<double, double>> data(n);
        for(std::size_t i = 0; i < n; ++i) {
            std::cout << "Please enter " << i + 1 << "-th x: \n";
            std::cin >> data[i].first;
            std::cout << "Please enter " << i + 1 << "-th y: \n";
            std::cin >> data[i].second;
        }

        solid_of_revolution solid(data);
        std::cout << "Volume of solid obtained by rotating given function about x axis: "
                  << solid.get_volume() << "\n";

        std::cout << "Surface area of solid obtained by rotating given function about x axis: "
                  << solid.get_surface() << "\n";

    } else if(ch == '0') {
        std::cout << "Enter lower bound: ";
        double lower;
        std::cin >> lower;

        std::cout << "Enter upper bound: ";
        double upper;
        std::cin >> upper;

        std::cout << "Enter step count: ";
        std::size_t steps;
        std::cin >> steps;

        std::cout << "Please enter function: ";
        std::string str;
        std::cin >> str;
        auto r = expression_parser::infix_to_rpn(str);

        auto f = std::bind(expression_parser::calculate, std::placeholders::_1, r);
        solid_of_revolution solid(lower, upper, steps, f);

        std::cout << "Volume of solid obtained by rotating given function about x axis: "
                  << solid.get_volume() << "\n";

        std::cout << "Surface area of solid obtained by rotating given function about x axis: "
                  << solid.get_surface() << "\n";
    } else {
        std::cout << "Invalid number. Halting...\n";
    }

    return 0;
}
