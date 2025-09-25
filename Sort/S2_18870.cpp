#include <iostream>
using namespace std;

// 병합 정렬 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);

// 이진 탐색 알고리즘 함수
int binary_search(int *arr, int start, int end, int key);

// 중복 제거 함수
int *unique_array(int *arr, int start, int end, int& new_size);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;
    
    // 원본과 정렬할 배열 선언
    int *arr = new int[N];
    int *sorted = new int[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < N; ++i) sorted[i] = arr[i];

    // 배열 정렬
    merge_sort(sorted, 0, N - 1);

    // 정렬 배열 중복 제거
    int size;
    int *unique = unique_array(sorted, 0, N - 1, size);

    // 답안 출력
    for (int i = 0; i < N; ++i) cout << (binary_search(unique, 0, size - 1, arr[i])) << ' ';

    cout << '\n';

    // 동적 할당 해제
    delete[] arr;
    delete[] sorted;
    delete[] unique;

    return 0;
}

void merge(int *arr, int start, int mid, int end) {

    int i = start, j = mid + 1, k = 0;
    int *sorted = new int[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) sorted[k++] = arr[i++];
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

int binary_search(int *arr, int start, int end, int key) {

    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) end = mid - 1; 
        else start = mid + 1;
    }

    return -1;
}

// 중복 제거 함수
int* unique_array(int *arr, int start, int end, int &new_size) {
    // 원본 배열 사이즈
    int size = end - start + 1;

    // 중간 결과를 담을 배열 임시 생성
    int *temp = new int[size];
    int idx = 0; // 해당 배열이 찰 경우의 사이즈
    
    // 첫 번째 원소는 무조건 삽입
    temp[idx++] = arr[start];

    // 이후 두 번째 원소부터 탐색하면서
    // 중복 원소는 건너뛰고 중복이 아니면 배열에 삽입
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] != arr[i - 1]) temp[idx++] = arr[i];
    }

    // 중복 제거된 배열의 사이즈를 알려줄 변수
    new_size = idx;

    // 최적화를 위해 최소 사이즈로 중복 제거 배열 재생성
    int *result = new int[new_size];
    // 배열에 원소 채우기
    for (int i = 0; i < new_size; ++i) result[i] = temp[i];

    // 임시배열 동적할당 해제
    delete[] temp;

    return result;
}