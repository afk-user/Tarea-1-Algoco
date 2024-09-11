// O(n^2), extraido de wikibooks.org
#include <algorithm> // para std::iter_swap, std::min_element

template <typename Iterator>
void selection_sort(Iterator begin, Iterator end) {
    Iterator min;
    while (begin != end) {
        // busca el menor elemento de los dos iteradores
        // luego intercambia el menor con el inicial
        min = std::min_element(begin, end);
        std::iter_swap(begin, min);
        ++begin;
    }
}