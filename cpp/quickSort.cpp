/// QuickSort implementation in C++

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(vector<int> &arr, int low, int high) {

	// pivot element to be placed at right position
	int pivot = arr[high];

	// index of smaller element and indicates the right position of the pivot found so far
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		
		// if current element is smaller than pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(vector<int> &arr, int low, int high) {
	if (low < high) {

		int partitionIndex = partition(arr, low, high);

		print(arr);
		quickSort(arr, low, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, high);
	}
}

int main() {

	vector<int> sortMe = { 3, 2, 78, 3, 1, 43, 69, 52, 87, 5, 93, 23, 12, 33 };

	quickSort(sortMe, 0, sortMe.size() - 1);

	print(sortMe);

	cin.ignore();
	return 0;
}