// O(n^3), basado en multiplicacion de learn.microsoft.com
#include <iostream>
#include <vector>

using namespace std;

void MatrixMultiply(vector<vector<int>> mA,vector<vector<int>> mB,vector<vector<int>> &mC) {
    int m = mC.size(), n = mB.size(), p = mC[0].size();

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < p; col++) {
            for (int inner = 0; inner < n; inner++) {
                mC[row][col] += mA[row][inner] * mB[inner][col];
            }
        }
    }
}