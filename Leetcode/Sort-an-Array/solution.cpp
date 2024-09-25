#include <vector>
#include <functional> // For std::function
using namespace std;


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // A lambda function for recursive quick sort
        std::function<void(int, int)> quickSort = [&](int left, int right) {
            // Base case: If the current segment is empty or a single element, no need to sort
            if (left >= right) {
                return;
            }

            // Initialize pointers for partitioning process
            int pivotIndex = left + (right - left) / 2; // Choose middle element as pivot
            int pivotValue = nums[pivotIndex];
            int i = left;
            int j = right;
          
            // Partition the array into two halves
            while (i < pivotIndex && j > pivotIndex) {
                // Increment i until nums[i] is greater or equal to pivot
                while (nums[i] < pivotValue) i++;

                // Decrement j until nums[j] is less or equal to pivot
                while (nums[j] > pivotValue) j--;

                // If i and j haven't crossed each other, swap the elements
                if (i < j) {
                    std::swap(nums[i], nums[j]);
                }
            }

            // Recursively apply the same logic to the left and right halves of the array
            quickSort(left, pivotIndex);     // Apply quicksort to the left subarray
            quickSort(pivotIndex + 1, right); // Apply quicksort to the right subarray
        };

        // Start the quick sort from the first to the last element
        quickSort(0, nums.size() - 1);

        // Return the sorted array
        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5,1,1,2,0,0};

    vector<int> ans = sol.sortArray(nums);

    return 0;
}