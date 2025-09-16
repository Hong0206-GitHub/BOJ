#include <iostream>
// INT_MIN 사용하기 위함
#include <climits>

using namespace std;

// 병합정렬에 필요한 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int n;
    cin >> n;

    // 원소 넣을 배열 동적 할당 및 넣기
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 배열 내용 정렬
    merge_sort(arr, 0, n - 1);

    // 투 포인터
    int start = 0, end = n - 1;
    // 답안 제출용 투 포인터 변수
    int temp_start = 0, temp_end = 0;

    // 절댓값 비교 변수
    int min = INT_MAX;
    
    // 유효한 범위에 한해서
    while (start < end) {
        // sum 갱신
        int sum = arr[start] + arr[end];

        // 조건 검사용
        int temp_sum = sum;

        // sum의 길이가 음수인 경우 절대값 변환
        if (temp_sum < 0) {
            temp_sum *= -1;
        }

        // 최솟값보다 sum이 더 작은 경우
        if (temp_sum < min) {
            min = temp_sum; // min 갱신
            temp_start = start; // 답안 갱신
            temp_end = end; // 답안 갱신
        }

        // 최적의 경우 while문 break
        if (sum == 0) {
            temp_start = start, temp_end = end;
            break;
        }

        // sum이 0보다 큰 경우
        // 값을 줄여야 하므로 start 포인터 오른쪽 이동
        else if (sum > 0) end--;

        // sum이 0보다 작은 경우
        // 값을 키워야 하므로 end 포인터 왼쪽 이동
        else start++;
    }

    // 답안 출력
    cout << arr[temp_start] << ' ' << arr[temp_end] << '\n';

    // 동적 할당 해제
    delete[] arr;

    return 0;
}

// 병합과정
void merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int *sorted = new int[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }

    while (i <= mid) sorted[k++] = arr[i++];
    while (j <= end) sorted[k++] = arr[j++];

    for (int i = start, k = 0; i <= end; ++i, ++k)
        arr[i] = sorted[k];

    delete[] sorted;

}

// 병합정렬
void merge_sort(int *arr, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}