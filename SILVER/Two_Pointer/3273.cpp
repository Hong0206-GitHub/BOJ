#include <iostream>

using namespace std;

// 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);


int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 원소 개수 입력 받기
    int n;
    cin >> n;

    // 동적 배열 할당 및 원소 채우기
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 조건 수 입력받기
    int x;
    cin >> x;

    // 투 포인터 선언
    // start = 시작인덱스, end = 끝 인덱스
    int start = 0, end = n - 1;

    // 답안 저장용 count 변수 선언
    int count = 0;

    // 배열 정렬 먼저
    merge_sort(arr, 0, n - 1);

    // 유효한 범위에 대해서만 반복
    while (start < end) {

        // 분기 확인용 sum 변수
        int sum = arr[start] + arr[end];

        // sum이 x와 같은 경우
        // count 1 증가 후,
        // end포인터와 start포인터를 범위를 좁히는 범위로 갱신
        if (sum == x) {
            count++;
            start++;
            end--;  // 중복 방지 위해 양쪽 다 이동
        }
        // sum이 x보다 더 큰 경우
        // sum이 작아져야 하므로, end 포인터 왼쪽 한 칸 이동
        else if (sum > x) {
            end--;
        }
        // sum이 x보다 더 작은 경우
        // sum이 커져야 하므로, start 포인터 오른쪽 한 칸 이동
        else {
            start++;
        }
    }

    // 결과 출력
    cout << count << '\n';

    return 0;
}

void merge(int *arr, int start, int mid, int end) {
    // 초기 변수 세팅
    int i = start, j = mid + 1, k = 0;
    // 정렬 된 원소를 담을 배열 동적 할당
    int *sorted = new int[end - start + 1];

    // 두 배열의 원소 비교해서 작은 원소만 정렬된 배열에 삽입
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) sorted[k++] = arr[i++];
        else sorted[k++] = arr[j++];
    }

    // 두 배열에서 남은 원소들 순서대로 정렬된 배열에 삽입
    while (i <= mid) sorted[k++] = arr[i++];
    while (j <= end) sorted[k++] = arr[j++];

    // 기존 배열에 정렬된 배열 복사
    for (int i = start, k = 0; i <= end; ++i, ++k) {
        arr[i] = sorted[k];
    }

    // 동적 할당 해제
    delete[] sorted;

}

void merge_sort(int *arr, int start, int end) {
    // 유효한 범위에 한해서
    if (start < end) {
        // mid값 세팅
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);    // 가운데 기준 왼쪽 배열 정렬
        merge_sort(arr, mid + 1, end);  // 가운데 기준 오른쪽 배열 정렬
        merge(arr, start, mid, end);    // 정렬된 두 배열 병합
    }
}
