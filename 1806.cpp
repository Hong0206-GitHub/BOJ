#include <iostream>
#include <climits>
using namespace std;


int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n, s 입력받기
    int n;
    unsigned long s;
    cin >> n >> s;

    // 동적 배열 생성
    int *arr = new int[n];

    // 배열에 원소 채우기
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // 누적 합 길이 체크
    int min = INT_MAX;
    // 투 포인터
    int start = 0, end = 0;
    int sum = 0;

    while (true) {
        // sum 이 s보다 크거나 같으면 조건 만족
        // 범위를 줄여도 조건을 만족하는지 확인 할 필요가 있음
        // 즉 start 포인터를 오른쪽으로 한 칸 이동 후 sum을 갱신
        if (sum >= s) {
            int length = end - start;
            if (min > length) {
                min = length;
            }
            sum -= arr[start++];
        }
        // 범위 이탈 시 반복분 break
        else if (n == end) {
            break;
        }
        // sum 이 s보다 작으면 범위를 늘릴 필요가 있음
        // 따라서 end포인터를 오른쪽으로 한 칸 이동 후
        // sum 갱신
        else {
            sum += arr[end++];
        }
    }

    if (min == INT_MAX) cout << 0 << '\n';
    else cout << min << '\n';
    
    delete[] arr;

    return 0;
}