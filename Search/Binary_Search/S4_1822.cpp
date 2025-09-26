#include <iostream>
using namespace std;

// 병합 정렬 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);

// 이분 탐색 함수 선언
int binary_search(int *arr, int start, int end, int key);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 배열 크기 입력
    int N, M;
    cin >> N >> M;

    // 동적 배열 선언
    int *arr = new int[N];
    int *temp = new int[M];
    bool *chk = new bool[N]();

    // 원소 입력 받기
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < M; ++i) cin >> temp[i];

    // 배열 정렬
    merge_sort(arr, 0, N - 1);

    // 두 번째 집합에 있는 원소가 있을 경우,
    // 첫 번재 집합에 그 원소를 -1로 수정
    for (int i = 0; i < M; ++i) {
        int search = binary_search(arr, 0, N - 1, temp[i]);
        if (search == -1) continue;
        chk[search] = true; // 삭제되면 true
    }

    int cnt = 0;

    for (int i = 0; i < N; ++i) {
        if (chk[i] == false) cnt++;
    }

    // 답안 출력
    if (cnt == 0) cout << cnt;
    else {
        cout << cnt << '\n';
        for (int i = 0; i < N; ++i) {
            if (chk[i] == false) cout << arr[i] << ' ';
        }
    }

    cout << '\n';

    // 동적 할당 해제
    delete[] arr;
    delete[] temp;
    delete[] chk;
    
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
        if (arr[mid] == key) return mid;
        else if (arr[mid] > key) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}