//
// Created by fail on 9/27/21.
//

#ifndef LAB01_PART2_SOLID_OF_REVOLUTION_H
#define LAB01_PART2_SOLID_OF_REVOLUTION_H

#include <cmath>
#include <numbers>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <iostream>

class solid_of_revolution {
private:
    std::vector<std::pair<double, double>> data;

public:
    solid_of_revolution() = delete;
    /* Stores an approximation of a body created by rotation of y = fun(x) from y = 0 to y = 5 about x-axis */
    solid_of_revolution(double start, double end, std::size_t sample_count, const std::function<double(double)>& fun);
    explicit solid_of_revolution(std::vector<std::pair<double, double>>  values);

    [[nodiscard]] double get_volume() const noexcept;
    [[nodiscard]] double get_surface() const noexcept;

    [[nodiscard]] bool is_inside(double x, double y, double z) const noexcept;
};

#endif //LAB01_PART2_SOLID_OF_REVOLUTION_H
