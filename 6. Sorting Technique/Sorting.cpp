#include <bits/stdc++.h>
using namespace std;

// operations
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

/*_______________________________________________________________________________________
                                 Index Based Sort                                        */

//  O(n)          faster sorting but space consumption is more
void count_sort(int arr[], int n)
{
    // O(3n)
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    int arr2[max + 1] = {0};    // all elements are given value as 0
    for (int i = 0; i < n; i++) // hashing
    {
        arr2[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i < max + 1;)
    {
        if (arr2[i] > 0)
        {
            arr[index++] = i;
            arr2[i]--;
        }
        else if (arr2[i] == 0)
        {
            i++;
        }
    }
}

void bin_bucket_sort(int arr[], int n)
{
}

void radix_sort(int arr[], int n)
{
}

void alternate_sorting(int arr[], int n)
{
    int answer[n] = {0};
    sort(arr, arr + n);
    int j = n - 1, q = 0, i = 0;

    while (q <= j)
    {
        answer[i++] = arr[q++];
        answer[i++] = arr[j--];
    }
    i = 0;

    cout << "Alternate sorting: ";
    for (; i < n - 1; i++)
    {
        cout << answer[i] << " ";
    }

    /*
    i = 0;
    long long int sum = 0;
    for (; i < n - 1; i++)
    {
        sum += abs(answer[i] - answer[i + 1]);
    }
    sum += abs(answer[0] - answer[n - 1]);
    return sum;
    */
}

/*_______________________________________________________________________________________
                                 Comparision Based Sort

  in comparison based sorting merge sort is the only sorting that requires extra space*/

//  O(n^2)
void bubble_sort(int arr[], int n)
{
    /* Called bubble sort as heavier elements settle down and lighter come up as bubble

    /*
    no. of elements: n

    it is stable

    no. of passes=n-1
    (for j no. of passes we get j no. of largest elements from the back)

    Max no. of comparision:1+2+3+.....n-1 = n(n-1)/2   sum of n-1 terms    O(n^2)      for descended sorted array
    Max no. of swaps: 1+2+3+.....n-1 = n(n-1)/2   sum of n-1 terms    O(n^2)           for descended sorted array
    min no. of comparision: O(n)      for ascended sorted array
    min no. of swaps: O(1)               for ascended sorted array

    we made it adaptive by using flag and breaking the loop

    not suitable for linked list
    */

    int flag;                       // just to check weather swaping takes place or not; if not then the array is already sorted and this code is adaptive
    for (int i = 0; i < n - 1; i++) // this for loop is for passes
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++) // to compare the elements and since each time we get a element so reduce the  comparision by 1 time so subtract i
        {
            if (arr[j] > arr[j + 1]) // comparing jth with j+1th element and swaping
            {
                swap(arr + j, (arr + j + 1));
                flag++;
            }
        }
        if (flag == 0)
        {
            cout << "List is already sorted and bubble sort is already adaptive\n";
            break;
        }
    }
}

void insertion_sort(int arr[], int n)
{
    /*
    insertion of element is a sorted array in a sorted position
    we consider that the first element is already sorted
    /* insertion sort is most useful in linked list as here we need not to move rest elements as we did in an array

    . no. of elements: n

    . it is stable

    . no. of passes=n-1
      (no k passes result is achieved)

    . max no. of comparsion: n(n-1)/2= O(n^2)    for descended sorted array
    . max no. of swaps: n(n-1)/2= O(n^2)         for descended sorted array

    . min no. of comparision: O(n)                for ascended sorted array
    . min no. of swaps: O(1)                      for ascended sorted array

    . adaptive by nature
    */

    int j, x;
    for (int i = 1; i < n; i++)
    {
        x = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

void selection_sort(int arr[], int n)
{
    /*only algorithm of with min no. of swaps
    . no. of elements: n

    . it is not stable

    . no. of passes=n-1
      (k passes gives k no. of smallest elements)

    . max no. of comparsion: n(n-1)/2= O(n^2)    for descended sorted array
    . max no. of swaps: n-1= O(n)                for descended sorted array

    . min no. of comparision: O(n)                for ascended sorted array
    . min no. of swaps: O(1)                      for ascended sorted array

    . not adaptive (can't find an algorithm)
    */
    for (int j = 0; j < n - 1; j++) // taking n-1 passes as the element will ne automatically sorted
    {
        int min = j;                    // considering first index having the smallest element
        for (int i = j + 1; i < n; i++) // this loop is just to get the smallest index
        {
            if (arr[min] > arr[i])
            {
                min = i;
            }
        }
        if (arr[j] != arr[min]) // if we got another smaller number then min the swap the values at that index
        {
            swap(arr + j, arr + min);
        }
    }
}

//    O(n log(n) )
void heap_sort(int arr[], int n)
{
}

int partition(int A[], int l, int h)
{
    /* partitioning position and recursive
     for sorted list(ascending or descending order) O(n^2) worst case
     best case time(partitioning happening in the middle) O(nlogn)
     worst case time(partitioning happening in either end when list is already sorted) O(n^n)
     avg case time O(nlogn)


     pivot position: left most,right most, median value(between left,middle,right)
     if array is sorted then worst time complexity takes place O(n^2) -> in this case median-element is taken as pivot

    */
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

void Merge(int a[], int low, int mid, int high)
{
    // O(n+m)
    // merging m list is called m-way merging. Take two list at a time and merge them

    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            B[k++] = a[i++];
        }
        else
        {
            B[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = a[i++];
    }
    while (j <= high)
    {
        B[k++] = a[j++];
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = B[i];
    }
}

void merge_sort(int arr[], int n)
{
    // in comparison based sorting merge sort is the only sorting that requires extra space
    // space taken is n+n+log(n) =(original_array+extra array to store+stack logn times as height is logn)= 2*n+log(n)=n+log(n)
    // mobest case and worst case
    // average case: O(nlogn)     n elements to merged log(n) times i.e height of tree times
    int p, l, h, mid, i;
    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(arr, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = n - 1;
            mid = (l + h) / 2;
            Merge(arr, l, mid, h);
        }
    }
    if (n > p / 2)
    {
        Merge(arr, 0, p / 2 - 1, n - 1);
    }
}

void RecursiveMergeSort(int A[], int low, int high)
{
    // in comparison based sorting merge sort is the only sorting that requires extra space
    // space taken is n+n+log(n) =(original_array+extra array to store+stack logn times as height is logn)= 2*n+log(n)=n+log(n)
    // best case and worst case
    // average case: O(nlogn)     n elements to merged log(n) times i.e height of tree times
    if (low < high)
    {
        int mid = (low + high) / 2;

        // Sort sub-lists
        RecursiveMergeSort(A, low, mid);      // left list is merge sorted
        RecursiveMergeSort(A, mid + 1, high); // right iist is merge sorted

        // Merge sorted sub-lists
        Merge(A, low, mid, high);
    }
}

void tree_sort(int arr[], int n)
{
}

//    O( n^ (3/2) )   or    O(n logn)    or   O(n^(5/2) )   depends on gap taken
void ShellSort(int A[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;
            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = temp;
        }
    }
}

//_______________________________________________________________________________________
int main()
{
    cout << "\t\t\t\t\t\t\t\t\t*************** SORTING ***************\n\n";
    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the values in the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;
    cout << "Enter: \n\t1. Bubble Sort \n\t2. Insertion Sort \n\t3. Selection Sort \n\t4. Quick Sort \n\t5. Merge Sort \n\t6. Count Sort\n\t7. Tree Sort \n\t8. Heap Sort \n\t9. Bin/Bucket Sort \n\t10. Shell Sort \n\t11. Radix Sort \n\t12. Recursive Merge Sort \n\t13. Aternate Sort\n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        bubble_sort(arr, n);
        display(arr, n);
        break;

    case 2:
        insertion_sort(arr, n);
        display(arr, n);
        break;

    case 3:
        selection_sort(arr, n);
        display(arr, n);
        break;

    case 4:
        QuickSort(arr, 0, n - 1);
        display(arr, n);
        break;

    case 5:
        merge_sort(arr, n - 1);
        display(arr, n);

        break;

    case 6:
        count_sort(arr, n);
        display(arr, n);

        break;

    case 7:

        break;

    case 8:

        break;

    case 9:

        break;

    case 10:
        ShellSort(arr, n);
        display(arr, n);

        break;

    case 11:

        break;

    case 12:
        RecursiveMergeSort(arr, 0, n);
        display(arr, n);
        break;

    case 13:
        alternate_sorting(arr, n);
        display(arr, n);
        break;

    default:
        cout << "INVALID INPUT";
        break;
    }

    return 0;
}

/*Criteria of Analysis
  1. no. of comparision
  2. no. of swaps
  3. adaptive (should take less time)  (only bubble , insertion sort)
  5. stable   (maintaining the order of duplicate elements in sorted list )  (only bubble,insertion,merge sort)
  6. extra memory (out-place) (merge-sort (O(n+logn)), quicksort(logn) (stack) (generally stack space in not considered))
     no-extra memory (in-place) (all except merge_Sort)

 -> merge_sort(arr,0,arr.size())
 -> quick_sort(arr,0,arr.size()-1)
*/
