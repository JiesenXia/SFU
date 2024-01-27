#include <stdio.h>
int binarySearch(int A[], int f, int l, int x){
    if (l >= f){  //to make sure the string is not empty
        int m;
        m = f + (l - f)/2;
      // to identify if the element is present in the middle
        if (A[m] == x) return m;
  
        // to identify if element is smaller than middle element, then search it in the left sub array
        if (A[m] > x) return binarySearch(A, f, m-1, x);
  
        // to identify if element is greater than middle element, then search it in the right sub array
        return binarySearch(A, m+1, l, x);}
  
      // if not found then return -1
    return -1;}
  
int main(void){
  int A[] = {2, 3, 4, 10, 40};
  int n = sizeof(A)/ sizeof(A[0]);
  int x = 10;
  int output = binarySearch(A, 0, n-1, x);
  if (output == -1){
  printf("Element is not found in the given array. Please try with other Element\n");}
    else{
    printf("Element is found at index %d.\n", output);}

  return 0;}
