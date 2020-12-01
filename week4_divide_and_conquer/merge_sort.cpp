#include<iostream>
using namespace std;
void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
    
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int arr1[n1], arr2[n2];

    for(int i = 0; i < n1; i++){
        arr1[i] = array[l + i];
    }
    for(int j = 0; j < n2; j++){
        arr2[j] = array[m + j + 1];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            array[k] = arr1[i];
            i++;
        } else{
            array[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < n1) {       //extra element in left array
      array[k] = arr1[i];
      i++; k++;
   }
   while(j < n2) {     //extra element in right array
      array[k] = arr2[j];
      j++; k++;
   }


}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l + (r - l) / 2;

      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   mergeSort(arr, 0, n-1);     //(n-1) for last index
   cout << "Array after Sorting: ";
   display(arr, n);
}
