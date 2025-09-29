#include <iostream>
using namespace std;

// 병합 정렬 알고리즘
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 문제의 입력 입력 받기
    int N;
    cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // 정렬
    merge_sort(arr, 0, N - 1);

    // 답안 도출
    int sum = 0;
    int answer = 0;

    // 답안 조정
    for (int i = 0; i < N; ++i) {
        sum += arr[i];
        answer += sum;
    }

    // 답안 출력
    cout << answer << '\n';


    // 동적할당 해제
    delete[] arr;

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