// Link: https://marisaoj.com/problem/51

// You are given an array integer A of length n. Find the number of pairs (i, j) that A_i = A_j and i != j

// Input
// The first line contains an integer n.
// The second line contains n integers A_i.

// Output
// One integer is the number of pairs you found.

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int n;
	  cin >>n;
	  int* arr=new int[100000];
	  for (int i=0; i<n;i++) cin >> arr[i];
	  mergeSort(arr, 0, n-1);
	  int dem=1;
	  long long sum=0;
	  for (int i=1; i<n;i++){
		  if(arr[i]==arr[i-1]) dem++;
		  if(arr[i]!=arr[i-1]||i==n-1){
			  sum+=(long long)dem*(dem-1)/2;
			  dem=1;
		  }
	  }
	  cout <<sum;
	  delete[] arr;
	  return 0;
}
