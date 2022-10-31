// Algorithm of Randomized quick sort
/*In Randomized quick sort , we select the pivot randomly 
* Pick a pivot element uniformly at random from the array
* Split array into 3 subarrays: those smaller than pivot, those larger than pivot,
  and the pivot itself.
* Recursively sort the subarrays, and concatenate them.
* 
*/

// Time complexity
/* Best case : O(n*logn)
*  Average case : O(n*logn)
*  Worst case : O(n^2) ---> when array is sorted already
*/

// Control movement of program
// main --> RandomPivotPartition --> partition --> main

// Randomized Quick sort implementation
#include <iostream>
using namespace std;

//user-defined functions
int QuickSort(int arr[], int low, int high);
void ShowPass(int arr[], int n);
int partition(int arr[], int low, int high);
int RandomPivotPartition(int arr[], int low, int high);
void Swap(int* x, int* y);

// global variable
int comp = 0; // for reporting comparisons

// main - function
int main()
{
    cout << "Randomized Quick Sort" << endl;
    int n;
    cout << "Enter the size of array :";
    cin >> n;
    int* arr = new int[n];
    // taking input of elements
    for (int i = 0; i < n; i++) {
        cout << "Enter the element " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "Unsorted array: ";
    ShowPass(arr, n);
    cout << endl << "-------------------------------" << endl;
    QuickSort(arr, 0, n - 1); // 0 is the starting index and n-1 is end index
    cout << "-------------------------------" << endl;
    cout << "Sorted array : ";
    ShowPass(arr, n);
    cout << "\nNumber of comparisons : " << comp;
    return 0;
}

// function for swapping 
void Swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// function for printing the array elements
void ShowPass(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// Implementing QuickSort algorithm.
int QuickSort(int arr[], int low, int high)
{
    int pindex;
    if (low < high)
    {
        // Partitioning array using randomized pivot.
        pindex = RandomPivotPartition(arr, low, high);
        // Recursively implementing QuickSort.
        QuickSort(arr, low, pindex - 1);
        QuickSort(arr, pindex + 1, high);
    }
    return 0;
}

// Partitioning the array on the basis of values at high as pivot value.
int partition(int arr[], int low, int high)
{
    int pivot, index, i;
    index = low; // initially set at 0 th index
    pivot = high; // from RandomPivotPartition , the (n-1) th index of array as pivot

    // Getting index of pivot.
    for (i = low; i < high; i++)
    {
        if (arr[i] < arr[pivot])
        {
            Swap(&arr[i], &arr[index]);
            index++;
            comp++;
        }
    }
    // Swapping value at high and at the index obtained.
    Swap(&arr[pivot], &arr[index]);

    return index;
}

// Random selection of pivot. 
// swap the pivot element with element at (n-1) th index
int RandomPivotPartition(int arr[], int low, int high)
{
    int pvt, n, temp;
    n = rand();
    // Randomizing the pivot value in the given subpart of array.
    pvt = low + n % (high - low + 1);

    // Swapping pvt value from high, so pvt value will be taken as pivot while partitioning.
    Swap(&arr[high], &arr[pvt]);

    return partition(arr, low, high);
}
