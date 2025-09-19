#include <iostream>

using namespace std;

int main() {

    // n 입력받기
    int n = 0;
    cin >> n;

    // 동적 배열 할당
    int *arr = new int[n];

    // 배열에 원소 집어넣기
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 최대값과 총합을 구함
    int max = 0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        // max 값보다 배열의 어떤 원소가 더 클 경우, max 갱신
        if (max < arr[i]) {
            max = arr[i];
        }
        // 배열의 원소를 순차탐색하므로, 모든 원소에 접근함.
        // 따라서 모든 원소의 총합을 구할 수 있음.
        sum += arr[i];
    }

    // 조건에 맞게 출력
    cout << sum * 100 / max / n;

    // 동적 메모리 해제
    delete[] arr;
    return 0;
}