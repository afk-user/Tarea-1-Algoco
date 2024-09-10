// O(nlogn), extraido de wikibooks.org
#include <iterator>
#include <algorithm> // for std::inplace_merge
#include <functional> // for std::less

template <typename BidirectionalIterator, typename Compare = std::less<>>
void merge_sort(BidirectionalIterator first, BidirectionalIterator last, Compare cmp = Compare {})
{
    const auto n = std::distance(first, last);
    
    if (n > 1) {
        const auto middle = std::next(first, n / 2);
        
        merge_sort(first, middle, cmp);
        merge_sort(middle, last, cmp);
        
        std::inplace_merge(first, middle, last, cmp);
    }
}