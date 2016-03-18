#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <iterator>
#include <iostream>

enum PivotType {
    FIRST_ELEMENT,
    LAST_ELEMENT,
    MEDIAN_ELEMENT,
    RANDOM_ELEMENT
};

template<typename Iter>
void quickSort(Iter begin, Iter end, PivotType pivotType) {
    
    if (begin == end)
        return;

    int pivot = 0;
    switch (pivotType) {
        default:
        case FIRST_ELEMENT:
        case RANDOM_ELEMENT: /// TODO: implement random pivot
            pivot = *begin;
            break;
        case LAST_ELEMENT:
            pivot = *(end - 1);
            break;
        case MEDIAN_ELEMENT:
            pivot = *std::next(begin, std::distance(begin, end) / 2);
            break;
    }

    std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    Iter middle1 = std::stable_partition(begin, end, [pivot](const auto& em) { return em < pivot; });
    std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
    std::cout<< std::endl << *middle1 << std::endl << std::endl;
    
    quickSort(begin, middle1, pivotType);
    quickSort(middle1 + 1, end, pivotType);
}

int main() {
    //std::ifstream inputFile("C:/QuickSort.txt");
    //std::istream_iterator<int> start(inputFile);
    //std::istream_iterator<int> end;
    //std::vector<int> externalData(start, end);

    std::vector<int> array = {2,3,7,8,9,2,5,1,4,0,5,6,5,8,0,4,2,7,4,1,7,9,9,3};

    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl << std::endl;
    
    quickSort(array.begin(), array.end(), PivotType::FIRST_ELEMENT);

    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<< std::endl << std::endl;

    return 0;
}