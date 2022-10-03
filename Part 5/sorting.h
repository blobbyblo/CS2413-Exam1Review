#ifndef PART_5_SORTING_ALGOS_H
#define PART_5_SORTING_ALGOS_H

#include <cstdint>
#include <vector>
#include <iostream>

// Sorting algorithms from here are taken from GeeksForGeeks
namespace sorting {
    // Array that we will be using for testing
    int* my_array = new int[10];

    // Helper function for initializing an unsorted array for testing purposes
    void init_array() {
        // Array will be 30, 29, 28, 27, 26, 25, 24, 23, 22, 21
        for (int idx = 0; idx < 10; idx++) {
            my_array[idx] = 30 - idx;
        }
    }

    // Helper function to print the contents of our array to validate sorting
    void print_array() {
        std::cout << "Array: ";
        for (int idx = 0; idx < 10; idx++) {
            std::cout << my_array[idx] << " ";
        }
        std::cout << std::endl;
    }

    // Memory management
    // Not needed because we will be closing our application after testing
    void deinit_array() {
        delete[] my_array;
    }

    void bubble_sort(int* array, int size) {
        // Step = number of each available element in the array
        // Once one index is sorted, we "step" to the next index
        // We do not "step" on the last index, as stepping on the second to last element should sort the last element
        for (int step = 0; step < size - 1; step++) {
            // Our upper limit is the number of elements that have already been checked
            int limit = size - step - 1;
            // Loop through each element to the limit
            for (int idx = 0; idx < limit; idx++) {
                // Compare two adjacent elements to see if they are sorted
                // If they are not sorted (before element is larger than latter element)
                // Then swap these two elements
                if (array[idx] > array[idx + 1]) {
                    int temp = array[idx];
                    array[idx] = array[idx + 1];
                    array[idx + 1] = temp;
                }
            }
        }
    }

    void insertion_sort(int* array, int size) {
        // Loop through each element starting from the second element in the array
        for (int idx = 1; idx < size; idx++) {
            // Loop through every element before the current element
            // If it is larger than the current element, then shift them down
            // Stop when the array hits 0 or the previous element is smaller than the current element
            int current = array[idx];
            int prev_idx = idx - 1;
            while (prev_idx >= 0 && array[prev_idx] > current) {
                array[prev_idx + 1] = array[prev_idx];
                prev_idx -= 1;
            }
            // Once no more elements that meet the criteria are found then
            // set the current sort index to our current element
            array[prev_idx + 1] = current;
        }
    }

    void selection_sort(int* array, int size) {
        // Loop over every element in the array except for the last element
        // This defines the lower limit for the sorting loop below
        for (int idx = 0; idx < size - 1; idx++) {
            // Loop over the elements above the lower limit
            int min_idx = idx;
            for (int jdx = idx + 1; jdx < size; jdx++) {
                // Find the index of the minimum value within the lower limit
                if (array[min_idx] > array[jdx]) {
                    min_idx = jdx;
                }
                // Swap the first element of the array with the minimum element
                if (min_idx != idx) {
                    int temp = array[min_idx];
                    array[min_idx] = array[idx];
                    array[idx] = temp;
                }
            }
        }
    }

    void merge_arrays(int* array, int left_index, int midpoint, int right_index) {
        // Get the number of elements in the left bounds and the right bounds of our array
        int size_left = midpoint - left_index + 1;
        int size_right = right_index - midpoint;

        // Allocate memory for our left and right side arrays
        int* left_array = new int[size_left];
        int* right_array = new int[size_right];

        // Loop through the left and right bounds and copy the elements into our split arrays
        for (int idx = 0; idx < size_left; idx++) {
            left_array[idx] = array[left_index + idx];
        }
        for (int idx = 0; idx < size_right; idx++) {
            right_array[idx] = array[midpoint + 1 + idx];
        }

        // Copy the split arrays back into the main array
        int i = 0;
        int j = 0;
        int k = left_index;
        while (i < size_left && j < size_right) {
            if (left_array[i] <= right_array[j]) {
                array[k] = left_array[i];
                i++;
            }
            else {
                array[k] = right_array[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements from the left bounds
        while (i < size_left) {
            array[k] = left_array[i];
            i++;
            k++;
        }

        // Copy the remaining elements from the right bounds
        while (j < size_right) {
            array[k] = right_array[i];
            j++;
            k++;
        }

        // Delete our temporary split arrays and free the memory
        delete[] left_array;
        delete[] right_array;
    }

    void merge_sort(int* array, int left_index, int right_index) {
        // Overflow check before splitting the arrays
        if (right_index > left_index) {
            // Get the midpoint of the main array
            int midpoint = left_index + (right_index - left_index) / 2;

            // Split the arrays into two parts then sort each half recursively
            merge_sort(array, left_index, midpoint);
            merge_sort(array, midpoint + 1, right_index);

            // Sort and merge the two arrays together
            merge_arrays(array, left_index, midpoint, right_index);
        }
    }

    int partition(int* array, int lower_bound, int upper_bound) {
        // Get the last element for the pivot point
        // It will move the elements around the pivot point and move the pivot element to its correct location
        int pivot = array[upper_bound];

        // Loop through each element within the bounds
        // If the current element is smaller than the pivot element increase the smallest element index
        // then swap the smallest element index with the current element
        int i = (lower_bound - 1);
        for (int j = 0; j <= upper_bound -1; j++) {
            if (array[j] < pivot) {
                i++;

                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // Swap the pivot element to its correct location
        int temp = array[i + 1];
        array[i + 1] = array[upper_bound];
        array[upper_bound] = temp;

        // Return the partition index
        return (i + 1);
    }

    void quick_sort(int* array, int lower_bound, int upper_bound) {
        if (upper_bound > lower_bound) {
            // Get the partition index
            int partition_index = partition(array, lower_bound, upper_bound);

            // Recursively sort around the partition index
            quick_sort(array, lower_bound, partition_index - 1);
            quick_sort(array, partition_index + 1, upper_bound);
        }
    }

    void bucket_sort(float* array, int size) {
        // Create size many buckets
        std::vector<float> bucket[size];

        // Loop through all elements in the array and sort them into buckets using the bucket index (size * num)
        for (int idx = 0; idx < size; idx++) {
            int bucket_index = size * array[idx];
            bucket[bucket_index].push_back(array[idx]);
        }

        // Sort each bucket with std::sort
        for (int idx = 0; idx < size; idx++) {
            std::sort(bucket[idx].begin(), bucket[idx].end());
        }

        // Add each bucket to the array
        int index = 0;
        for (int idx = 0; idx < size; idx++) {
            for (int bdx = 0; bdx < bucket[idx].size(); bdx++) {
                array[index++] = bucket[idx][bdx];
            }
        }
    }

    void counting_sort(char* array, int size, int max_val) {
        char output[size];
        char count[max_val + 1];

        // Set all elements in the count array to 0
        memset(count, 0, sizeof(count));

        // Find the numerical appearances of each element in the original array
        // We can do this because chars (should) have a numerical value that is between 0 and 255 (max_val)
        // This will fit inside the count array, so we can increment the index it is at in the count array
        for (int idx = 0; idx < size; idx++) {
            if (array[idx] > 0 && array[idx] <= max_val) {
                ++count[array[idx]];
            }
        }

        // Shift each element down so it will match the position in the original array
        for (int idx = 1; idx <= max_val; idx++) {
            count[idx] += count[idx - 1];
        }

        // Here we can use array[idx] as the boolean value for the for loop to continue
        // The last should be 0 for a null terminator or nonexistent character
        for (int idx = 0; array[idx]; idx++) {
            output[count[array[idx]] - 1] = array[idx];
            --count[array[idx]];
        }

        // Copy the contents of the temp output array to our main array
        for (int idx = 0; array[idx]; idx++) {
            array[idx] = output[idx];
        }
    }

    void radix_sort(int* array, int size) {
        // We're all failing this one
    }
}

#endif //PART_5_SORTING_ALGOS_H
