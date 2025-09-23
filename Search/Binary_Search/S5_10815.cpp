#include <iostream>

using namespace std;

// 이진 탐색을 위한 병합정렬 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);


int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int N;
    cin >> N;

    // 배열 채우기
    int *arr = new int[N];
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // 이진 탐색을 위한 병합 정렬
    merge_sort(arr, 0, N - 1);

    // 테스트 케이스 입력 받기
    int M;
    cin >> M;

    while(M--) {
        // 탐색할 key 입력 받기
        int key;
        cin >> key;

        // 답안 출력을 위한 분기 조건
        bool check = false;

        // 이진 탐색을 위한 투 포인터
        int start = 0, end = N - 1;
        
        // 유효한 범위 동안
        while (start <= end) {
            // mid 값은 항상 갱신
            int mid = (start + end) / 2;
            
            // mid 위치에 key 탐색 성공시
            if (arr[mid] == key) {
                check = true; // 답안 출력 분기 true로 변경
                break;  // 반복분 빠져나옴
            }
            // mid 위치의 값 보다 key 값이 작은경우
            // start ~ mid - 1 부분에 있기 때문에 end포인터 갱신
            else if(arr[mid] > key) end = mid - 1;
            
            // mid 위치의 값 보다 key 값이 큰 경우
            // mid + 1 ~ end 부분에 있기 때문에 end포인터 갱신
            else start = mid + 1;
        }

        // 답안 출력
        if(check) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    // 동적 할당 해제
    delete[] arr;

    return 0;
}

void merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int *sorted = new int [end - start + 1];

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