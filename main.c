#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int main()
{
    int a[20], value, i = 0, total = 0;
    while (scanf("%d", &value) != EOF) {
        a[i++] = value;
        total++;
    }
    
    quicksort(a, 0, total - 1);
    
    int sum = a[0], prev = a[0], count = 1;
    for (i = 1; i < total; ++i) {
        if (a[i] == prev) {
            continue;
        } else {
            sum += a[i];
            count++;
        }
        prev = a[i];
    }
    printf("%.2f", (float)sum/count);
    
    return 0;
}
