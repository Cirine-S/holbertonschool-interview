#ifndef SORT
#define SORT

void print_array(const int *array, size_t size);
void heapify(int arr[], int n, int i);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);

#endif