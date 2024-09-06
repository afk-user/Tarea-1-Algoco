#include <iostream>
#include <chrono>
#include <list>

#include "sorting/default_sort.hpp"
#include "sorting/merge_sort.hpp"
#include "sorting/quick_sort.hpp"
#include "sorting/select_sort.hpp"

using namespace std;

int main() {
    list<int>lista = {1,3,5,12,4,523,63,634,52,341,7,643,7567,234,6};
    list<int>::iterator first = lista.begin();
    list<int>::iterator last = lista.end();
    cout << "proc chaining..." << endl;
    quick_sort(first,last);

    for (int i : lista) {
        cout << i;
        cout << ' ';
    }
    cout << endl;

    return 0;
}