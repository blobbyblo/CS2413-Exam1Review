### Linear Search vs Binary Search

With linear search, the elements in the array are not required to be sorted prior to searching. Each element will be iterated one-by-one until the key is found.

```cpp
// Search each element one-by-one and return the index
// -1 will be returned if the element is not found
int linear_search(int* array, int size, int key) {
	for (int idx = 0; idx < size; idx++) {
		if (array[idx] == key) {
			return idx;
		}
	}
	return -1;
}
```

However, with binary search, the array MUST be sorted prior to searching. This can be done in a recursive approach. The array will usually be split by the midpoint, and depending on the value of the midpoint will either be returned or split again until the element is found.

```cpp
bool binary_search(int* array, int low, int high, int key) {
	if (high < low) { // No more elements left, key not found!
		return false;
	}

	int middle = array[(low + high) / 2];
	if (middle == key) { // Found it!
		return true;
	}
	else if (middle < key) { // The key must be on the right side of the array
		return binary_search(array, ((low + high) / 2) + 1, high);
	}
	else { // The key must be on the left side of the array
		return binary_search(array, low, ((low + high) / 2) - 1);
	}
}
```

### Time Complexity of these Algorithms

The exam review says we must know how to justify the time complexity.

Take the below and do what you must o7

![linearsearch](/images/linearsearch.png)

![binarysearch](/images/binarysearch.png)

![comparison](/images/comparison.png)

![whylog](/images/whylog.png)

### Space Complexity of these Algorithms

Again, much like the Big O Notation for time complexity, space complexity simply takes the number of the space that scales with the size of the elements in the array. So defining, say, 500 integers at the start of an algorithm, while larger than the space it would take to simply define 1, would be 3T1 which equals O(1). 

![linearspace](/images/linearspace.png)

![binaryspace](/images/binaryspace.png)

### Big O Overview

![overview](/images/overview.png)
