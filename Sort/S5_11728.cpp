#include <iostream>
#include <vector>

using namespace std;

// 병합 정렬 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);
// 두 배열을 합쳐서 오름차순 정렬해주는 함수 선언
int* merge(int *arr1, int *arr2, int n, int m);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 두 배열의 크기 입력 받기
    int n, m;
    cin >> n >> m;

    // 배열 동적 할당
    int *arr1 = new int[n];
    int *arr2 = new int[m];

    // 배열 원소 채우기
    for (int i = 0; i < n; ++i) cin >> arr1[i];
    for (int i = 0; i < m; ++i) cin >> arr2[i];

    // 두 배열 각각 정렬
    merge_sort(arr1, 0, n - 1);
    merge_sort(arr2, 0, m - 1);
    
    // 정렬된 배열 저장할 포인터 변수
    int *arr = merge(arr1, arr2, n, m);

    // 답안 출력
    for (int i = 0; i < n + m; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    // 동적 할당 해제
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    
    return 0;
}

// 병합 정렬 함수 구현
void merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;

    int *sorted = new int[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }

    while (i <= mid) sorted[k++] = arr[i++];
    while (j <= end) sorted[k++] = arr[j++];

    for (int i = start, k = 0; i <= end; i++, k++) arr[i] = sorted[k];

    delete[] sorted;
}

// 두 배열을 합쳐서 오름차순으로 정렬해주는 함수
int* merge(int *arr1, int *arr2, int n, int m) {
    
    int start1 = 0, start2 = 0;
    int k = 0;
    int *sorted = new int[n + m];

    while (start1 < n && start2 < m) {
        if (arr1[start1] < arr2[start2]) sorted[k++] = arr1[start1++];
        else sorted[k++] = arr2[start2++];
    }

    while (start1 < n) sorted[k++] = arr1[start1++];
    while (start2 < m) sorted[k++] = arr2[start2++];

    return sorted;
}

void merge_sort(int *arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
