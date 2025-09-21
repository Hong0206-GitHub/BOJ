#include <iostream>

using namespace std;

// 오름차순 병합 정렬 함수 선언
void merge(int *arr, int start, int mid, int end);
void merge_sort(int *arr, int start, int end);

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N 입력 받기
    int N;
    cin >> N;

    // 문제에서 말한 배열 동적 할당
    int *A = new int[N];
    int *B = new int[N];
    int *P = new int[N];

    // A 베열 입력으로 채우고 B배열도 A배열과 똑같은 상태로 만듦
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        B[i] = A[i];
    }
    
    // B 배열은 문제 조건에 맞게 오름차순 정렬
    merge_sort(B, 0, N - 1);

    // P 배열을 구하기 위해 i를 P의 index로 사용
    for (int i = 0; i < N; ++i) {
        // 사용한 원소는 -1로 변경하여
        // 중복 사용 방지
        for (int j = 0; j < N; ++j) {
            if (A[i] == B[j] && B[j] > 0) {
                P[i] = j;   
                B[j] = -1;        
                break;
            }
        }   
    }

    // 조건에 맞게 출력
    for (int i = 0; i < N; ++i) cout << P[i] << ' ';
    cout << '\n';

    // 동적 할당 해제
    delete[] A;
    delete[] B;
    delete[] P;

    return 0;
}

void merge(int *arr, int start, int mid, int end) {
    int i = start, j = mid + 1, k = 0;
    int *sorted = new int[end - start + 1];

    while (i <= mid && j <= end) {
        if (arr[i] > arr[j]) sorted[k++] = arr[j++];
        else sorted[k++] = arr[i++];
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