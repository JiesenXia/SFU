// Swaps array elements at index i and j
void swap(int arr[], int i, int j) {
	// Complete your code for question 1a) here
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

/*  Partitions an array into three parts, arr[first...mid-1],
    arr[mid], and arr[mid+1...last], such that all elements in
	arr[first...mid-1] <= arr[mid], and all elements in
	arr[mid+1...last] >= add[mid]. Returns mid */
int partition(int arr[], int first, int last) {
	// Complete your code for question 1d) here

	
	int pivotIndex = first + 3;
	if (pivotIndex > last) {  // if the index is larger than the last element
		pivotIndex = last;  // use the last element as pivot
	}
	int pivot = arr[pivotIndex]; // pivot
	int i = first - 1; 

	for (int j = first; j <= last; ++j) {
		if (j == pivotIndex) {  // skip if j is same as the pivotIndex
			continue;
		}
		if (arr[j] < pivot) { 
			i++;     // increment index of smaller element
			swap(arr, i, j);  // swap the element of j and j
		}
	}
	swap(arr, i+1, pivotIndex);  // swap value of i+1 with pivotIndex
	return i+1;
}


void QuickSort(int arr[], int first, int last) {
	// Complete your code for question 1e) here
	
	// Base case
	if (last <= first) return;

	// do partition to split array
	int mid = partition(arr, first, last);

	// Recursively doing sort
	QuickSort(arr, first, mid - 1);
	QUickSort(arr, mid+1, last);

}
