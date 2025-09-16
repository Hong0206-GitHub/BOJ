#include <iostream>

using namespace std;

int main(void) {


    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    // n 입력 받기
    int n;
    cin >> n;

    // 같은 위치의 투 포인터 선언
    int start_idx = 1;
    int end_idx = 1;

    // count 변수와 sum 변수 생성
    int count = 1; // n 그 자체의 경우 한 가지 추가
    int sum = 1; // 입력이 1 이상이므로 최소 1


    while (end_idx != n) {

        // sum > n
        // sum이 더 크면 범위를 줄여야함
        // start 포인터 1 증가, sum 갱신
        if (sum > n) {
            sum -= start_idx++;
        }
        
        // sum < n
        // n이 더 크면 범위를 늘려야함
        // end 포인터 1 증가, sum 갱신
        else if(sum < n) {
            sum += ++end_idx;
        }

        // sum == n
        // 같기 때문에 count 1 증가
        // 범위 늘려야하므로 end 포인터 1 증가, sum 갱신
        else {
            count++;
            sum += ++end_idx;
        }
    }

    // 결과 출력
    cout << count << '\n';

    return 0;
}