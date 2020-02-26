 
#include <bits/stdc++.h> 
using namespace std; 
void merge(int arr[], int start, int mid, int end, int max) 
{ 
	int i = start; 
	int j = mid + 1; 
	int k = start; 
	while (i <= mid && j <= end) { 
		if (arr[i] % max <= arr[j] % max) { 
			arr[k] = arr[k] + (arr[i] % max) * max; 
			k++; 
			i++; 
		} 
		else { 
			arr[k] = arr[k] + (arr[j] % max) * max; 
			k++; 
			j++; 
		} 
	} 
	while (i <= mid) { 
		arr[k] = arr[k] + (arr[i] % max) * max; 
		k++; 
		i++; 
	} 
	while (j <= end) { 
		arr[k] = arr[k] + (arr[j] % max) * max; 
		k++; 
		j++; 
	} 
 
	for (int i = start; i <= end; i++) 
		arr[i] = arr[i] / max; 
} 

 
void mergeSortRec(int arr[], int start, int end, int max) 
{ 
	if (start< end) { 
		int mid = (start + end) / 2; 
		mergeSortRec(arr, start, mid, max); 
		mergeSortRec(arr, mid + 1, end, max); 
		merge(arr, start, mid, end, max); 
	} 
} 

 
void mergeSort(int arr[], int n) 
{ 
int max = *max_element(arr, arr+n) + 1; 
mergeSortRec(arr, 0, n-1, max); 
} 

int main() 
{ 
	int arr[] = { 999, 612, 589, 856, 56, 945, 243 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	
	mergeSort(arr, n); 

	cout << "Sorted array \n"; 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	return 0; 
} 

// compilation time is 4.97s
// process exited 0.3652s with return value 0.

