#ifndef MAX_VALUE_H
#define MAX_VALUE_H

#include <vector>
#include <stdexcept>
#include <limits>

/**
 * Finds the maximum value in a vector of integers.
 * @param vec The vector to search
 * @return The maximum value in the vector
 * @throws std::invalid_argument if the vector is empty
 */
int findMaxValue(const std::vector<int>& vec) {
    if (vec.empty()) {
        throw std::invalid_argument("Cannot find max value in empty vector");
    }

    int max_val = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] > max_val) {
            max_val = vec[i];
        }
    }

    return max_val;
}

#endif // MAX_VALUE_H
