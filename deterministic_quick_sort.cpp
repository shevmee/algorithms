#include <iostream>
#include <vector>

template<typename T>
class DeterministicQuickSelect {
private:
    template<typename T>
    int partition(std::vector<T>& array, int begin, int end) {
        T pivotIndex = medianOfFive(array, begin, end);
        std::swap(array[pivotIndex], array[end]);
        T pivot = array[end];
        int l = begin - 1;

        for (int i = begin; i < end; ++i) {
            if (array[i] < pivot) {
                ++l;
                std::swap(array[l], array[i]);
            }
        }
        std::swap(array[l + 1], array[end]);
        return l + 1;
    }

    template<typename T>
    T medianOfFive(std::vector<T>& arr, int begin, int end) {
        int mid = begin + (end - begin) / 2;
        int quarter1 = begin + (mid - begin) / 2;
        int quarter3 = mid + (end - mid) / 2;

        if (arr[begin] > arr[quarter1]) {
            std::swap(arr[begin], arr[quarter1]);
        }

        if (arr[begin] > arr[mid]) {
            std::swap(arr[begin], arr[mid]);
        }

        if (arr[begin] > arr[quarter3]) {
            std::swap(arr[begin], arr[quarter3]);
        }

        if (arr[quarter1] > arr[mid]) {
            std::swap(arr[quarter1], arr[mid]);
        }

        if (arr[quarter1] > arr[quarter3]) {
            std::swap(arr[quarter1], arr[quarter3]);
        }

        if (arr[mid] > arr[quarter3]) {
            std::swap(arr[mid], arr[quarter3]);
        }
        return quarter3;
    }

    template<typename T>
    void deterministic_quick_sort(std::vector<T>& array, int begin, int end) {
        if (begin >= end) return;
        int pivotIndex = partition(array, begin, end);
        deterministic_quick_sort(array, begin, pivotIndex);
        deterministic_quick_sort(array, pivotIndex + 1, end);
    }

    template<typename T>
    void printArray(const std::vector<T>& nums) {
        for (auto num : nums) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
public:
    void deterministic_quick_sortArray(std::vector<int>& nums) {
        deterministic_quick_sort(nums, 0, nums.size() - 1);
        printArray(nums);
    }
};

//int main() {
//    std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
//    deterministic_quick_sortArray(v);
//}
