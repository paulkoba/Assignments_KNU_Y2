//
// Created by fail on 9/27/21.
//

#include "solid_of_revolution.h"

#include <utility>

solid_of_revolution::solid_of_revolution(double start, double end, std::size_t sample_count,
                                         const std::function<double(double)> &fun) {
    if(sample_count < 2) throw std::invalid_argument("Expected sample count >= 2");

    double step = (end - start) / (static_cast<double>(sample_count) - 2.);

    data.reserve(sample_count - 1);

    for(std::size_t i = 0; i < sample_count - 1; ++i) {
        data.emplace_back(start + i * step, fun(start + i * step));
    }
}

solid_of_revolution::solid_of_revolution(std::vector<std::pair<double, double>>  values) : data(std::move(values)) {
    std::sort(data.begin(), data.end());

    if(data.size() < 2) throw std::invalid_argument("Expected sample count >= 2");
};

[[nodiscard]] double solid_of_revolution::get_volume() const noexcept {
    double result = 0.;

    for(std::size_t i = 1; i < data.size(); ++i) {
        double dx = (data[i].first - data[i - 1].first);
        double y = (data[i].second + data[i - 1].second) / 2;
        result += dx * y * y;
    }

    return result * std::numbers::pi;
}


[[nodiscard]] double solid_of_revolution::get_surface() const noexcept {
    double result = 0.;

    for(std::size_t i = 1; i < data.size(); ++i) {
        double dx = (data[i].first - data[i - 1].first);
        double dy = (data[i].second - data[i - 1].second);
        double y = (data[i].second + data[i - 1].second) / 2;
        result += y * std::sqrt(1 + std::pow(dy / dx, 2)) * dx;
    }

    return result * std::numbers::pi * 4;
}

[[nodiscard]] bool solid_of_revolution::is_inside(double x, double y, double z) const noexcept {
    if(x <= data[0].first || x >= data[data.size() - 1].first) return false;
    std::size_t idx = 0;

    while(data[idx].first < x) ++idx;
    --idx;

    double proportion =  (x - data[idx].first) / (data[idx + 1].first - data[idx].first);
    double radius = data[idx].second + proportion * (data[idx + 1].second - data[idx].second);

    return radius * radius > y * y + z * z;
}