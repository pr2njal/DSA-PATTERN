// Given an unsorted array of integers, sort it into a wave-like array.
// Arrange elements such that:
//     arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] ...
//
// Do this in-place without sorting the array beforehand.
// Multiple valid answers may exist.
#include <iostream>
#include <vector>
using namespace std;

void waveSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i += 2) {
        // If previous element is greater, swap
        if (i > 0 && arr[i] < arr[i - 1]) {
            swap(arr[i], arr[i - 1]);
        }

        // If next element is greater, swap
        if (i < n - 1 && arr[i] < arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main() {
    vector<int> arr = {10, 5, 6, 3, 2, 20, 100, 80};
    waveSort(arr);

    cout << "Wave Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
