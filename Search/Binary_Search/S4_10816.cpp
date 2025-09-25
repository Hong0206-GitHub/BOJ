#include <iostream>

using namespace std;

// 이분탐색을 위한 병합정렬 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);

// 이분탐색을 이용한 첫 번째 중복 원소 등장 위치와,
// 마지막 원소 등장 위치 반환 함수
// 탐색 실패시 -1
int last_occurrence(int *arr, int start, int end, int key);
int first_occurrence(int *arr, int start, int end, int key);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;
    
    // 배열 동적 할당 및 채우기
    int *arr = new int[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // 이분 탐색을 위한 정렬
    merge_sort(arr, 0, N - 1);

    // 테스트 케이스 입력 받기
    int M;
    cin >> M;

    while (M--) {
        int key;
        cin >> key;
        int start = first_occurrence(arr, 0, N - 1, key);
        int end = last_occurrence(arr, 0, N - 1, key);

        if (start == -1) cout << 0 << ' ';
        else cout << end - start + 1 << ' ';
    }

    cout << '\n';

    // 동적 할당 해제
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

// 중복 원소중 가장 오른쪽에 있는 인덱스 반환 함수
int last_occurrence(int *arr, int start, int end, int key) {
    // 기본값 -1 (탐색 실패시)
    int temp = -1;
    // 이분탐색 알고리즘
    while (start <= end) {
        int mid = (start + end) / 2;
        // 변형된 알고리즘
        // arr[key] 값이 key보다 작거나 같다면
        if (arr[mid] <= key) {
            // 같은 경우 temp 갱신
            if (arr[mid] == key) temp = mid;
            // 가장 오른쪽에 있는 원소를 찾아야 하므로
            // 왼쪽 인덱스 조정
            start = mid + 1;
        } else end = mid - 1;
    }
    return temp;
}

// 중복 원소 중 가장 왼쪽에 있는 인덱스 반환 함수
int first_occurrence(int *arr, int start, int end, int key) {

    // 기본값 -1 (key가 없는 경우 그대로 반환됨)
    int temp = -1;

    // 이분탐색 알고리즘
    while (start <= end) {
        int mid = (start + end) / 2;
        // 변형된 알고리즘
        // arr[mid] 값이 key보다 크거나 같은 경우로 탐색
        if (arr[mid] >= key) {
            // key가 있으면 temp 갱신
            if (arr[mid] == key) temp = mid;
            // 가장 왼쪽에 있는 인덱스를 찾기 때문에 
            // 오른쪽 인덱스 조정
            end = mid - 1;   
        } else start = mid + 1;
    }

    return temp;
}
