#include <iostream>
#include <vector>

using namespace std;

// funcion transponedora
void transpose(vector<vector<int>> matrix, vector<vector<int>> &transposed) {
    int row = matrix.size(), col = matrix[0].size();
    for (int i=0;i<col;i++) {
        for (int j=0;j<row;j++) {
            transposed[i][j] = matrix[j][i];
        }
    }
}

void MMoptimized(vector<vector<int>> mA,vector<vector<int>> mB,vector<vector<int>> &mC) {
    int m = mC.size(), n = mB.size(), p = mC[0].size();
    vector<vector<int>> tB (mB[0].size(),vector<int> (n));
    transpose(mB, tB);
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            for (int row2 = 0; row2 < p; row2++) {
                // se multiplican dos filas distintas
                mC[row][row2] += mA[row][col] * tB[row2][col];
            }
        }
    }
}