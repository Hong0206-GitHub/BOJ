#include <iostream>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // s, p 입력 받기
    int s, p;
    cin >> s >> p;

    // DNA 문자열 입력받기
    string arr;
    cin >> arr;

    // 조건 배열 생성
    int condition[4];

    // 조건 입력 받기
    for (int i = 0; i < 4; ++i) {
        cin >> condition[i];
    }

    // 슬라이딩 윈도우 알고리즘 사용
    // 범위 첫 포인터와 끝 포인터 선언
    int start = 0, end = p - 1;

    // 답안 저장용 변수 선언
    int count = 0;

    // DNA 문자열이 포함하고 있는 문자 개수 파악
    int contain[4]{0};
    for (int i = start; i <= end; ++i) {
        if (arr[i] == 'A') contain[0]++;
        else if (arr[i] == 'C') contain[1]++;
        else if (arr[i] == 'G') contain[2]++;
        else if (arr[i] == 'T') contain[3]++;
    }

    // 범위 끝 인덱스가 배열의 길이보다 작을 경우만 실행
    while (end < s) {
        
        // 조건 검사용 변수
        bool check = true;

        // 조건배열과 문자 개수 비교
        for (int i = 0; i < 4; ++i) {
            if (!(condition[i] <= contain[i])) {
                check = false;
                break;
            }
        }

        // 윈도우 범위 슬라이딩
        start++, end++;

        // 조건 통과시 count 증가
        if (check) {
            count++;
        }

        // 범위 조절 후 포함상태 변경
        if (arr[end] == 'A') contain[0]++;
        else if (arr[end] == 'C') contain[1]++;
        else if (arr[end] == 'G') contain[2]++;
        else if (arr[end] == 'T') contain[3]++;

        if (arr[start - 1] == 'A') contain[0]--;
        else if (arr[start - 1] == 'C') contain[1]--;
        else if (arr[start - 1] == 'G') contain[2]--;
        else if (arr[start - 1] == 'T') contain[3]--;
    }

    // 답안 출력
    cout << count << '\n';

    return 0;
}