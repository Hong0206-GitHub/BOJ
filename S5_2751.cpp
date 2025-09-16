#include <iostream>
using namespace std;

// 병합과정
void merge(int *arr, int start, int mid, int end) {

    // 정렬된 원소를 저장할 배열 동적 할당
    int *sorted = new int[end - start + 1];
    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        // 1번 배열의 원소가 더 작은 경우 1번 배열 원소를 정렬된 배열에 삽입
        if (arr[i] <= arr[j]) sorted[k++] = arr[i++];
        // 그렇지 않은 경우는 반대
        else sorted[k++] = arr[j++];
    }

    // 위 과정이 모두 실행되면, 2개의 배열 중 한 배열의 모든 원소는 정렬된 배열에 삽입되어있음
    // 즉 원소가 남은 배열의 모든 원소를 그대로 정렬된 배열에 삽입하면 됨.
    
    // 첫 번째 배열의 원소가 남아있는 경우
    while (i <= mid) sorted[k++] = arr[i++];
    // 그렇지 않은 경우는 반대
    while (j <= end) sorted[k++] = arr[j++];

    // 정렬된 배열을 그대로 원본 배열에 복사
    for (int i = start, k = 0; i <= end; i++, k++) {
        arr[i] = sorted[k];
    }

    // 동적 할당 해제
    delete[] sorted;

}

void merge_sort(int *arr, int start, int last) {

    // 유효한 범위에 한해서 작동
    if (start < last) {
        int mid = (start + last) / 2;   // 나눌 기준 점
        merge_sort(arr, start, mid);    // 기준점 포함 왼쪽 부분
        merge_sort(arr, mid + 1, last); // 기준점 포함 오른쪽 부분
        merge(arr, start, mid, last);   // 정렬된 두 배열 병합
    }
}

// 배열의 모든 원소 출력 함수
void print_arr(int *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << '\n';
    }
}

int main(void) {


    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n 입력 받기
    int n;
    cin >> n;    

    // 배열 동적할당
    int *arr = new int[n];

    // 배열에 원소 저장
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 병합정렬 함수 호출
    merge_sort(arr, 0, n - 1);

    // 배열 원소 출력 함수 호출
    print_arr(arr, n);

    // 동적 할당 해제
    delete[] arr;

    return 0;
}