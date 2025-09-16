#include <iostream>
using namespace std;

// 병합 정렬 알고리즘
void merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;

    int *sorted = new int[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }

    if (i <= mid) {
        while(i <= mid) sorted[k++] = arr[i++];
    }

    else {
        while(j <= end) sorted[k++] = arr[j++];
    }

    for (int i = start, k = 0; i <= end; i++, k++) {
        arr[i] = sorted[k];
    }

    delete[] sorted;
}


void merge_sort(int *arr, int start, int end) {

    if (start < end) {
        int mid = (end + start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);

    }
}


int main(void) {

    // // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n 입력받기
    int n;
    cin >> n;

    // 고유번호 m 입력받기
    int m;
    cin >> m;

    // 동적 배열 생성
    int *arr = new int[n];

    // 고유 값 입력받기
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 병합 정렬 (merge sort)
    merge_sort(arr, 0, n - 1);

    // 투 포인터
    // start 맨 앞 원소를 가리키고, end는 맨 뒤 원소를 가리킴
    int start = 0, end = n - 1;
    int count = 0, sum = arr[start] + arr[end];

    // 유효한 범위 내에서만 동작
    while (start < end) {
        // sum 의 값이 m과 같으면 count 1증가 후
        // sum을 키우기 위해 포인터 이동, sum 갱신
        if (sum == m) {
            count++;
            sum -= arr[start++];
            sum += arr[start];
        }
        // sum 의 값이 m 보다 크면
        // sum 값을 줄여야하므로, end포인터를 -1 만큼 이동,
        // sum 값 갱신
        else if (sum > m) {
            sum -= arr[end--];
            sum += arr[end];
        }

        // sum 의 값이 m 보다 작으면
        // sum 값을 키워야하므로, start포인터를 1 증가 후,
        // sum 값 갱신
        else {
            sum -= arr[start++];
            sum += arr[start];
        }
    }

    // 답안 출력
    cout << count << '\n';


    // 동적 할당 해제
    delete[] arr;

    return 0;
}