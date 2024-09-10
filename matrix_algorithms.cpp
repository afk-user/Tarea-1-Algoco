#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>

#include "matrix/cubic_optimized.hpp"
#include "matrix/cubic_standard.hpp"
#include "matrix/strassen.hpp"

using namespace std;

// print a matrix to the console
void printMatrix(vector< vector<int> > &matrix, unsigned int row, unsigned int column) {
    ofstream mOutput ("resultingMatrix.txt");
    if (mOutput.is_open()) {
        for (unsigned int i = 0; i < row; i++) {
            for (unsigned int j = 0; j < column; j++) {
                mOutput << matrix[i][j] << " ";
            }
            mOutput << endl;
        }
        mOutput << endl;
    }
    mOutput.close();
}

int main() {
    int rowA, columnA, rowB, columnB, input;
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed_seconds;

    ifstream mfile ("datasets/for_matrix/dataset.txt");

    if (mfile.is_open()) {
        mfile >> rowA >> columnA >> rowB >> columnB;
        if (columnA != rowB) {
            cout << "Matrixes are not multipliable" << endl;
            return 0;
        }
    } else {
        cout << "File is not open or does not exist" << endl;
        return 0;
    }

    cout << "1. Standard\n2. Optimized\n3. Strassen" << endl;
    cin >> input;

    cout << "Reading file..." << endl;

    vector<vector<int>> matrixA (rowA,vector<int> (columnA));
    vector<vector<int>> matrixB (rowB,vector<int> (columnB));
    vector<vector<int>> matrixC (rowA,vector<int> (columnB));

    if (mfile.is_open()) {
        for (int i = 0;i<rowA;i++) {
            for (int j = 0;j<columnA;j++) {
                mfile >> matrixA[i][j];
            }
        }

        for (int i = 0;i<rowB;i++) {
            for (int j = 0;j<columnB;j++) {
                mfile >> matrixB[i][j];
            }
        }
    }
    mfile.close();
    
    if (input == 1 || input == 2 || input == 3 ) cout << "Multiplying..." << endl;

    switch (input) {
    case 1: /* - Cubic Standard - */
        start = chrono::system_clock::now();
        MatrixMultiply(matrixA,matrixB,matrixC);
        end = chrono::system_clock::now();
        break;
    case 2: /* - Cubic Optimized - */
        start = chrono::system_clock::now();
        MMoptimized(matrixA,matrixB,matrixC);
        end = chrono::system_clock::now();
        break;
    case 3: /* - Strassen - */
        start = chrono::system_clock::now();
        strassen(matrixA,matrixB,matrixC);
        end = chrono::system_clock::now();
        break;
    default:
        cout << "No algorithm selected" << endl;
        break;
    }

    elapsed_seconds = end - start;
    if (input == 1 || input == 2 || input == 3 ) {
        cout << "Multiplication Elapsed Time: " << elapsed_seconds.count() << " seconds" << endl;
        printMatrix(matrixC,matrixC.size(),matrixC[0].size());
    }

    return 0;
}