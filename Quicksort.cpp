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
bool testQuickSort(Iter begin, Iter end) {
	if (begin == end)
		return false;

	while (begin != end)
	{
		int a = *begin;
		++begin;
		if (a>*begin && begin != end)
		{
			std::cout << *begin << " is not greater than " << a;
			return false;
		}
	}

	return true;
}


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

    Iter middle1 = std::stable_partition(begin, end, [pivot](const auto& em) { return em < pivot; });
    
    quickSort(begin, middle1, pivotType);
    quickSort(middle1 + 1, end, pivotType);
}

int main() {
    std::ifstream inputFile("Path to input array");
    if (!inputFile.is_open())
    {
    	std::cout << "Nu s-a deschis fisierul!!!";
    	return 0;
    }
    
    std::istream_iterator<int> start(inputFile);
    std::istream_iterator<int> end;
    std::vector<int> array(start, end);
    
    quickSort(array.begin(), array.end(), PivotType::FIRST_ELEMENT);

    std::ofstream outputFile("Path to output file");

    if (testQuickSort(array.begin(), array.end()))
    	std::cout<<"The array is sorted!";
    else
    	std::cout<<"The array is not sorted!";

    std::copy(array.begin(), array.end(), std::ostream_iterator<int>(outputFile, " "));

    return 0;
}