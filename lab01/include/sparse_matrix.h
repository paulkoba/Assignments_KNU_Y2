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
    /* Used internally to be able to hash std::pair<std::size_t, std::size_t> */
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
    /* Use sparse_matrix(std::size_t, std::size_t) with specified matrix dimensions instead. */
    sparse_matrix() = delete;

    /* Creates a sparse matrix with specified dimensions */
    sparse_matrix(std::size_t height, std::size_t width) : n(height), m(width) {}
    

    /* Returns number of rows in matrix. */
    [[nodiscard]] constexpr std::size_t get_height() const noexcept { return n; }

    /* Returns number of columns in matrix. */
    [[nodiscard]] constexpr std::size_t get_width() const noexcept { return m; }

    /* Returns an element at position (i, j). Throws if invalid index is provided. */
    [[nodiscard]] constexpr T get_element(std::size_t i, std::size_t j) {
        if(i >= n || j >= m) throw std::out_of_range("sparse_matrix::get_element(): element doesn't fit into the matrix");
        auto it = data.find({i, j});
        return it == data.end() ? 0 : it->second;
    }

    /* Sets an element at position (i, j) to a specified value. Throws if invalid index is provided. */
    constexpr void set_element(std::size_t i, std::size_t j, T value) {
        if(i >= n || j >= m) throw std::out_of_range("sparse_matrix::set_element(): element doesn't fit into the matrix");
        if(value == 0) return;
        data[{i, j}] = value;
    }

    /* Returns reference to an element at position (i, j). Throws if invalid index is provided. */
    [[nodiscard]] constexpr T& operator[](std::pair<std::size_t, std::size_t> pos) {
        if(pos.first >= n || pos.second >= m)
            throw std::out_of_range("sparse_matrix::operator[](): element doesn't fit into the matrix");
        return data[pos];
    }

    /* Perform matrix addition on two matrices. Throws if matrices have incompatible dimensions. */
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

    /* Perform matrix subtraction on two matrices. Throws if matrices have incompatible dimensions. */
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

    /* Returns a matrix after transposition. */
    [[nodiscard]] constexpr sparse_matrix transposed() const noexcept {
        sparse_matrix output(m, n);
        for(const auto& p : data) output.data[{p.first.second, p.first.first}] = p.second;
        return output;
    }

    /* Transpose current matrix. */
    void transpose() noexcept {
        *this = transposed();
    }

    /* Perform matrix multiplication on two matrices. Throws if matrices have incompatible dimensions.
     * O(width * data.size()) complexity */
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

    /* Finds an element by its value. O(data.size()) complexity */
    std::pair<std::size_t, std::size_t> find_by_value(T val) {
        for(const auto& p : data) if(p.second == val) return p.first;

        throw std::logic_error("sparse_matrix::find_by_value(): no element with value T found");
    }
};


#endif //LAB01_SPARSE_MATRIX_H
