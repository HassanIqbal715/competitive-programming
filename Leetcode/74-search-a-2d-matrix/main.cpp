#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>> matrix, int target) {
    // find the correct row first
    int left = 0;
    int right = matrix.size() - 1;
    int mid = (right + left) / 2;

    while (left <= right) {
        if (target == matrix[mid][0]) {
            return true;
        }
        else if (target < matrix[mid][0]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        mid = (right + left) / 2;
    }

    std::cout << mid << '\n';
    if (mid >= matrix.size() || mid < 0) {
        std::cout << "insane\n";
        return false;
    }

    // find the correct column
    left = 0;
    right = matrix[mid].size();
    int midCol = (right + left) / 2;

    while (left <= right && midCol < matrix[0].size()) {
        if (target == matrix[mid][midCol]) {
            return true;
        }
        else if (target < matrix[mid][midCol]) {
            right = midCol - 1;
        }
        else {
            left = midCol + 1;
        }
        midCol = (right + left) / 2;
    }

    // not found
    return false;
}

int main() {
    std::cout << searchMatrix({
        {1}
    }, 2);

    std::cout << '\n';
}