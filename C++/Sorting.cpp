/*
Name: Aasiruddin Walajahi
Sorting Algorithm Implementation for CSE 331
 */

#include <iostream>
#include <cassert>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

// short integer random number generator from stdlib
int rand(void);


// Quicksort function
void quickSort(int array[], int left, int right)
{
      // Assigning right and left values
      int i = left, j = right;
      int temp_array;

      // Assignment of the pivot.
      // Pivot is chosen to be in the middle of the array
      int pivot = array[(left + right) / 2];

      // Partitioning the array
      while (i <= j) {
            // If the current element in the array is before the pivot
            while (array[i] < pivot)
                  i++;
            // If the current element in the array is after the pivot
            while (array[j] > pivot)
                  j--;

            /* Making sure that the left index is always less than/equal to the larger index */
            if (i <= j) {
                  temp_array = array[i];
                  array[i] = array[j];
                  array[j] = temp_array;
                  i++; j--;
            }
      }

      // Recursive Calls to the QuickSort Functions
      if (left < j)
            quickSort(array, left, j);
      if (i < right)
            quickSort(array, i, right);
}


// // Implementation of the Insertion Sort
// void insertionSort(int array[])
// {
//  int j;
//   for (int p = 1; p < int(sizeof(array)); ++p)
//   {
//     int temp = array[p];
//     for (j = p; j > 0 && temp < array[j - 1]; j--)
//       array[j] = array[j - 1];
//     array[j] = temp;
//   }
// }

int main()
{
  int size;
  //hrtime_t start, total;  // defined in sys/time.h  long long int
  timeval start, end; // type defined in sys/time.h.
  double start_sec, end_sec, t_sec;

  //double t_sec;

  cout << endl << " ----- insertion/quicksort comparison ----- " << endl;
  cout << endl << "How many elements to sort: - ";  cin >> size;
  int* dataArray = new int [size];   // get array of right size
  int* copyArray = new int [size];   // to hold a copy of random ints
  assert ( (dataArray != NULL) && (copyArray != NULL) );

  //  ============ insertion sort random integers  ===================

  for (int k=0; k< size ; k++)  dataArray[k] = rand();

  // copy the array for later use by quicksort
  for (int k=0; k< size ; k++)  copyArray[k] = dataArray[k];

  cout << "Intial Random Order: ";
  for ( int k=0; k<5; k++)  cout << dataArray[k] << ", " ;
  cout << endl;

  cout << endl << "Insertion sort of Integer data initially in random order" << endl;

  //start = gethrtime();   // hi_resolution time nanoseconds

  gettimeofday(&start, NULL);  // get time at start of function


  // implement your insertionSort here or call it as a function
  //   =====================InsertionSort===============
  //   You can refer Mark Allan Weiss Third Edition Figure 7.2 page 263

  int j;
  for (int p = 1; p < size; ++p)
  {
    int temp = dataArray[p];
    for (j = p; j > 0 && temp < dataArray[j - 1]; j--)
      dataArray[j] = dataArray[j - 1];
    dataArray[j] = temp;
  }


  gettimeofday(&end, NULL);  // get time at end of function
  // convert to seconds and print out
  start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
  end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
  t_sec = end_sec - start_sec;

  //total = gethrtime() - start;
  //t_sec = double(total) * 1.0e-9;  // convert to seconds
  cout << "For N = " << size << " # seconds = " << t_sec << "\n";

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << dataArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << dataArray[size-k] << ", " ;
  cout << endl << endl;

  //  ============ quicksort random integers  ===================
  //

  cout << "Intial First Five:  ";
  for ( int k=0; k<5; k++)  cout << copyArray[k] << ", " ;
  cout << endl;

  cout << endl << "quicksort of Integer data initially in random order" << endl;

  //start = gethrtime();   // hi_resolution time nanoseconds
  gettimeofday(&start, NULL);  // get time at start of function


  // implement your quicksort here or call it as a function
  // =====================Quicksort ======================
  // you can refer Mark Allan Weiss Third Edition Figure 7.16 page 286. Note that this piece
  // of code only use quick sort when the input has size at least 10. Please only implement
  // the quicksort part no matter how large the input is.

  quickSort(copyArray, 0, size - 1);


  gettimeofday(&end, NULL);  // get time at end of function
  // convert to seconds and print out
  start_sec = double(start.tv_sec) + double(start.tv_usec) * 1e-6;
  end_sec = double(end.tv_sec) + double(end.tv_usec) * 1e-6;
  t_sec = end_sec - start_sec;

  //total = gethrtime() - start;
  //t_sec = double(total) * 1.0e-9;  // convert to seconds
  cout << "For N = " << size << " # seconds = " << t_sec << "\n";

  cout << "First five sorted elts:  ";
  for ( int k=0; k<5; k++)  cout << copyArray[k] << ", " ;
  cout << endl;
  cout << "Last five sorted elts:  ";
  for ( int k=5; k>0; k--)  cout << copyArray[size-k] << ", " ;
  cout << endl << endl;

  return 0;
}
