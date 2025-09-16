#include <iostream>

using namespace std;

// 병합정렬 함수 선언
void merge(long long *arr, int start, int mid, int end);
void merge_sort(long long *arr, int start, int end);

int main(void) {

    // 속도증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    // n 입력 받기
    int n;
    cin >> n;

    // 동적 배열 할당 avi는 절대값이 1,000,000,000 이하
    long long *arr = new long long[n];

    // 원소 입력 받아 배열에 넣기
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 병합정렬
    merge_sort(arr, 0, n - 1);


    // start 는 첫 번째 원소를, end는 마지막 원소를 가리킴
    int start, end;
    int count = 0;
    long long sum;

    // i는 대상이 되는 수
    for (int i = 0; i < n; i++) {

        // 탐색 시 초기 세팅
        start = 0;
        end = n - 1;
        
        // 유효한 범위 내에서만 동작
        while (start < end) {

            if (start == i) {
                start++;
                continue;
            }
            if (end == i) {
                end--;
                continue;
            }

            sum = arr[start] + arr[end];

            // sum과 대상이 되는 수가 같다면,
            if (sum == arr[i]) {
                count++; // count 증가
                break;
            } else if (sum > arr[i])  {
                // sum이 더 크다면, sum을 줄여야하므로 end -- 
                end--;
            } else {
                // sum이 더 작다면, sum을 키워야하므로 start++
                start++;
            }
        }
    }

    // 결과 출력
    cout << count << '\n';

    // 동적 할당 해제
    delete[] arr;
    
    return 0;
}

// 병합정렬
void merge(long long *arr, int start, int mid, int end) {

    int i = start, j = mid + 1, k = 0;
    long long *sorted = new long long[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            sorted[k++] = arr[i++];
        }
        else sorted[k++] = arr[j++];
    }

    if (i <= mid) {
        while(i <= mid) sorted[k++] = arr[i++];
    }
    else while (j <= end) sorted[k++] = arr[j++];


    for (int i = start, k = 0; i <= end; i++, k++) {
        arr[i] = sorted[k];
    }

    delete[] sorted;
}

// 병합정렬
void merge_sort(long long *arr, int start, int end) {
    if (start < end) {
        int mid = (end + start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

}