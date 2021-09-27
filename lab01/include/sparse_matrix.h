//
// Created by fail on 9/27/21.
//

#ifndef LAB01_SPARSE_MATRIX_H
#define LAB01_SPARSE_MATRIX_H

#include <unordered_map>
#include <vector>

template <typename T>
class sparse_matrix {
private:
    struct pair_hash {
        template <class T1, class T2>
        [[nodiscard]] constexpr std::size_t operator() (const std::pair<T1, T2> &pair) const noexcept {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    std::size_t n = 0;
    std::size_t m = 0;
    std::unordered_map<std::pair<std::size_t, std::size_t>, T, pair_hash> data;
public:
    sparse_matrix() = delete;
    sparse_matrix(std::size_t height, std::size_t width) : n(height), m(width) {}

    [[nodiscard]] constexpr std::size_t get_height() const noexcept { return n; }
    [[nodiscard]] constexpr std::size_t get_width() const noexcept { return m; }

    [[nodiscard]] constexpr T get_element(std::size_t i, std::size_t j) noexcept {
        auto it = data.find({i, j});
        return it == data.end() ? 0 : it->second;
    }

    constexpr void set_element(std::size_t i, std::size_t j, T value) {
        if(i >= n || j >= m) throw std::out_of_range("sparse_matrix::set_element(): element doesn't fit into the matrix");
        if(value == 0) return;
        data[{i, j}] = value;
    }

    [[nodiscard]] constexpr T& operator[](std::pair<std::size_t, std::size_t> pos) noexcept {
        if(pos.first >= n || pos.second >= m) throw std::out_of_range("sparse_matrix::operator[](): element doesn't fit into the matrix");
        return data[pos];
    }

    [[nodiscard]] sparse_matrix operator+(const sparse_matrix& other) const {
        if(other.m != m || other.n != n) throw std::invalid_argument("sparse_matrix::operator+(): Matrices have incompatible dimensions.");

        sparse_matrix output(n, m);
        for(const auto& p : data) output.data[{p.first.first, p.first.second}] += p.second;
        for(const auto& p : other.data) output.data[{p.first.first, p.first.second}] += p.second;

        //Remove elements that might have ended up 0 after addition.
        std::vector<std::pair<std::size_t, std::size_t>> zeros;
        for(auto& p : output.data) if(!p.second) zeros.push_back(p.first);
        for(auto& el : zeros) output.data.erase(output.data.find(el));

        return output;
    }

    [[nodiscard]] sparse_matrix operator+() const noexcept {
        return *this;
    }

    [[nodiscard]] sparse_matrix operator-() const noexcept {
        sparse_matrix output = *this;
        for(auto& p : output.data) p.second = -p.second;
        return output;
    }

    [[nodiscard]] sparse_matrix operator-(const sparse_matrix& other) const {
        return *this + (-other);
    }

    sparse_matrix& operator+=(const sparse_matrix& other) {
        *this = *this + other;
        return *this;
    }

    sparse_matrix& operator-=(const sparse_matrix& other) {
        *this = *this - other;
        return *this;
    }

    [[nodiscard]] constexpr sparse_matrix transposed() const noexcept {
        sparse_matrix output(m, n);
        for(const auto& p : data) output.data[{p.first.second, p.first.first}] = p.second;
        return output;
    }

    void transpose() noexcept {
        *this = transposed();
    }

    sparse_matrix operator*(const sparse_matrix& other) {
        if(m != other.n) throw std::invalid_argument("sparse_matrix::operator*(): Matrices have incompatible dimensions.");

        sparse_matrix output(n, other.m);

        for(const auto& p : data) {
            for(std::size_t i = 0; i < m; ++i) {
                auto it = other.data.find({p.first.second, i});
                if(it != other.data.end()) {
                    output.data[{p.first.first, i}] += p.second * it->second;
                }
            }
        }

        return output;
    }

    std::pair<std::size_t, std::size_t> find_by_value(T val) {
        for(const auto& p : data) if(p.second == val) return p.first;

        throw std::logic_error("sparse_matrix::find_by_value(): no element with value T found");
    }
};


#endif //LAB01_SPARSE_MATRIX_H
