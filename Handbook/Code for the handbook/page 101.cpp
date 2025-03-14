#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int n = 2496;  // Grid size (n x n)
const int N = 64;    // Number of columns represented by each block

// Function to count subgrids with black corners
long long countSubgridsWithBlackCorners(const std::vector<std::vector<long long>>& grid) {
    long long totalCount = 0;

    // Iterate over all pairs of rows (a, b) where a < b
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            int count = 0;

            // Count common black columns in blocks using bit operations
            for (int k = 0; k < n / N; k++) {
                count += __builtin_popcountll(grid[a][k] & grid[b][k]);
            }

            // Calculate the number of subgrids from the count of common columns
            totalCount += (long long)count * (count - 1) / 2;
        }
    }

    return totalCount;
}

// Main function to run the program
int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Initialize a 2500x2500 grid with 64-bit blocks (for testing purposes)
    std::vector<std::vector<long long>> grid(n, std::vector<long long>(n / N, 0));

    // Fill the grid with random 0s and 1s, packing bits into blocks of 64 bits
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (std::rand() % 2 == 1) {
                grid[i][j / N] |= (1LL << (j % N));  // Set the appropriate bit in the block
            }
        }
    }

    // Run the optimized counting function
    long long result = countSubgridsWithBlackCorners(grid);

    // Print the result
    std::cout << "Total number of subgrids with black corners: " << result << std::endl;

    return 0;
}
