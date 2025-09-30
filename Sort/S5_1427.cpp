#include <iostream>
#include <string>

using namespace std;

void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int size = str.size();
    int *arr = new int[size];

    for (size_t i = 0; i < str.size(); ++i) arr[i] = str[i] - '0';
    
    merge_sort(arr, 0, size - 1);

    for (int i = 0; i < size; ++i) cout << arr[i];
    cout << '\n';

    delete[] arr;

    return 0;
}


void merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int *sorted = new int[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] > arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }

    while (i <= mid) sorted[k++] = arr[i++];
    while (j <= end) sorted[k++] = arr[j++];

    for (int i = start, k = 0; i <= end; ++i, ++k) arr[i] = sorted[k];
    delete[] sorted;
}

void merge_sort(int *arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}