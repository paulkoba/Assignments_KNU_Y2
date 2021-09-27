#include <iostream>

#include "solid_of_revolution.h"
#include "tests/solid_of_revolution_tests.h"

int main() {
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

    return 0;
}
