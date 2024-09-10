// O(n^2), extraido de wikibooks.org
#include <algorithm> // for: std::iter_swap, std::min_element

template <typename Iterator>
void selection_sort(Iterator begin, Iterator end)
{
    Iterator min;
    while (begin != end)
    {
        min = std::min_element(begin, end);
        std::iter_swap(begin, min);
        ++begin;
    }
}