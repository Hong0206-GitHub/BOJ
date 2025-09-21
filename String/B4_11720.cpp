#include <iostream>
using namespace std;

int main(void) {

    // n값 입력받기
    int n = 0;
    cin >> n;

    // 문자열로 숫자 전체 입력받기
    string numbers;
    cin >> numbers;

    // 답을 저장할 변수 선언
    int sum = 0;

    // 숫자 개수만큼 배열 순회
    for (int i = 0; i < n; i++) {
        // char 연산을 통해 정수 도출
        // 문자 "정수" - "0" = 정수형(정수)
        sum += numbers[i] - '0';
    }

    cout << sum;

    return 0;
}