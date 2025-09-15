#include <iostream>
// 제곱 함수 사용하기 위해 include
#include <cmath>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 변환할 원본 수 입력 받기
    string num;
    cin >> num;

    // 원본 수의 진법 입력 받기
    int n;
    cin >> n;

    // 10진수로 변환한 것을 담을 변수 선언
    long long sum = 0;

    // 모든 자리에 대해 반복
    for (int i = 0; i < num.size(); ++i) {
        // 알파벳인 경우
        if (num[i] >= 'A' && num[i] <= 'Z') {
            sum += (num[i] - 'A' + 10) * pow(n, num.size() - 1 - i);
        }
        // 숫자인 경우
        else {
            sum += (num[i] - '0') * pow(n, num.size() - 1 - i);
        }
    }

    // 결과출력
    cout << sum << '\n';
    
    return 0;

}
