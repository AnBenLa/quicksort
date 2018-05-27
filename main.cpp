#include <iostream>
#include <list>
#include <algorithm>

std::list<int> quicksort(std::list<int> unsorted_part) {
	if (unsorted_part.size() == 1 || unsorted_part.size() == 0) {
		return unsorted_part;
	}
	auto piv_it = unsorted_part.begin();
	std::advance(piv_it, rand() % unsorted_part.size());
	int pivot = *piv_it;

	std::list<int> smaller_or_equal_than_pivot;
	std::list<int> bigger_than_pivot;

	for (auto it = unsorted_part.begin(); it != unsorted_part.end(); ++it) {
		if (*it <= pivot) {
			smaller_or_equal_than_pivot.push_back(*it);
		}
		else {
			bigger_than_pivot.push_back(*it);
		}
	}

	std::list<int> sorted_smaller = quicksort(smaller_or_equal_than_pivot);
	std::list<int> sorted_bigger = quicksort(bigger_than_pivot);
	std::list<int> sorted_complete(sorted_smaller.size());
	std::copy(sorted_smaller.begin(), sorted_smaller.end(), sorted_complete.begin());

	for (auto it = sorted_bigger.begin(); it != sorted_bigger.end(); ++it) {
		sorted_complete.push_back(*it);
	}

	return sorted_complete;
}

int main() {
	std::list<int> unsorted_list(100);
	std::generate(unsorted_list.begin(), unsorted_list.end(), rand);
	for (auto it = unsorted_list.begin(); it != unsorted_list.end(); ++it) {
		std::cout << *it << "\n";
	}
	std::list<int> sorted_list = quicksort(unsorted_list);
	std::cout << "--------------------------------------------\n";

	for (auto it = sorted_list.begin(); it != sorted_list.end(); ++it) {
		std::cout << *it << "\n";
	}
	std::cin.get();
	return 0;
}

