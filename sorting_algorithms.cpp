#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>

#include "sorting/merge_sort.hpp"
#include "sorting/quick_sort.hpp"
#include "sorting/select_sort.hpp"

using namespace std;

int main() {
    int input, myint;
    vector<int>dataset;
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed_seconds;

    cout << "1. quicksort\n2. selsort\n3. mergesort\n4. defsort" << endl;
    cin >> input;

    ifstream dsfile ("datasets/for_sorting/dataset.txt");

    cout << "Reading file..." << endl;

    if (dsfile.is_open()) {
        while (dsfile >> myint) {
            dataset.push_back(myint);
        }
    } else {
        cout << "File is not open or does not exist" << endl;
        return 0;
    }

    dsfile.close();

    if (input == 1 || input == 2 || input == 3 || input == 4) cout << "Sorting..." << endl;
    
    switch (input) {
    case 1: /* - quicksort - */
        start = chrono::system_clock::now();
        quickSort(dataset,0,dataset.size()-1);
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;

        cout << "Quicksort Elapsed time: " << elapsed_seconds.count() << " seconds" << endl;
        cout << endl;
        break;
    
    case 2: /* - selsort - */
        start = chrono::system_clock::now();
        selection_sort(dataset.begin(),dataset.end());
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;

        cout << "Select Sort Elapsed time: " << elapsed_seconds.count() << " seconds" << endl;
        cout << endl;
        break;

    case 3: /* - mergesort - */
        start = chrono::system_clock::now();
        merge_sort(dataset.begin(),dataset.end());
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;

        cout << "Merge Sort Elapsed time: " << elapsed_seconds.count() << " seconds" << endl;
        cout << endl;
        break;

    case 4: /* - defsort - */
        start = chrono::system_clock::now();
        sort(dataset.begin(),dataset.end());
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;

        cout << "Default Sort Elapsed time: " << elapsed_seconds.count() << " seconds" << endl;
        break;

    default:
        cout << "No algorithm selected" << endl;
        break;
    }

    if (input == 1 || input == 2 || input == 3 || input == 4) {
        ofstream output ("sortedData.txt");

        if (output.is_open()) {
            for (int &n : dataset) {
                output << n << ' ';
            }
        }
        output.close();
    }

    return 0;
}