#include <iostream>

using namespace std;

// 병합 정렬 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N 입력 받기
    int N; 
    cin >> N;

    // 동적 할당 및 배열에 원소 채우기
    int *arr = new int[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // 테스트 케이스 입력 받기
    int M;
    cin >> M;

    // 병합 정렬 함수 호출로 정렬
    merge_sort(arr, 0, N - 1);
        
    // 테스트 케이스만큼 반복
    while (M--) {

        // key 입력 받기
        int key;
        cin >> key;

        // 원소 인덱스 포인터 선언
        int start = 0, end = N - 1;        

        // 답안 출력 분기용 변수 선언
        bool check = false;

        // 이분 탐색 알고리즘
        while (start <= end) {
            int mid = (start + end) / 2;

            // key를 찾았으면, 답안 분기 true로 변환 후 break
            if (arr[mid] == key) {
                check = true;
                break;
            }
            // key보다 중앙값이 큰 경우, 중앙값 왼쪽에 있으므로 end포인터 이동
            else if (arr[mid] > key) end = mid - 1;
            // key보다 중앙값이 작은 경우, 중앙값 오른쪽에 있으므로 start 포인터 이동
            else start = mid + 1;
        }

        // 답안 출력
        if (check) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    // 동적 할당 해제
    delete[] arr;

    return 0;
}

// 병합 함수
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

// 병합 정렬
void merge_sort(int *arr, int start, int end) {

    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
