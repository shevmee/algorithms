#include <iostream>
#include <vector>
#include <chrono>
#include <random>

class MersenneTwister {
public:
	MersenneTwister() {
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		generator.seed(static_cast<unsigned>(seed));
	}

	int generateRandomIndex(int size) {
		std::uniform_int_distribution<int> distribution(0, size - 1);
		return distribution(generator);
	}

private:
	std::mt19937 generator;
};

class MergeSort {
private:
	MersenneTwister mt;

	template<typename T>
	int partition(std::vector<T>& array, int begin, int end) {
		int pivotIndex = mt.generateRandomIndex(end - begin + 1) + begin;
		std::swap(array[pivotIndex], array[end]);
		int pivot = array[end];
		int l = begin - 1;

		for (size_t i = begin; i < end; ++i) {
			if (array[i] >= array[pivot]) continue;
			if (array[i] < array[pivot]) {
				++l;
				std::swap(array[l], array[i]);
			}
		}
		std::swap(array[l + 1], array[end]);
		return l + 1;
	}

	template<typename T>
	void quick_sort(std::vector<T>& array, int begin, int end) {
		if (begin >= end) return;
		int pivotIndex = partition(array, begin, end - 1);
		quick_sort(array, begin, pivotIndex);
		quick_sort(array, pivotIndex + 1, end);
	}


	template<typename T>
	void printArray(const std::vector<T>& nums) const {
		for (const T& num : nums)
			std::cout << num << ' ';
		std::cout << '\n';
	}
public:
	void quick_sortArray(std::vector<int>& nums) {
		quick_sort(nums, 0, nums.size() - 1);
		printArray(nums);
	}
};

//int main() {
//	std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
//	QuickSort quick;
//	quick.quick_sortArray(v);
//}