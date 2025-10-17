#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 입력 개수 입력 받기
    int N;
    cin >> N;

    // 답안 저장용 변수 선언
    ll answer = 0;

    // 스택 선언
    stack<int> s;

    // 입력 개수 만큼 반복
    for (int i = 0; i < N; i++) {
        // 입력 값 저장
        int temp;
        cin >> temp;
    
        // 스택의 탑보다 입력값이 작거나 같은경우 모두 팝
        // 현재 건물보다 작거나 같은 건물은
        // 오른쪽에서 temp에 가려지므로, 더 이상 이후 건물을 볼 수 없음 -> pop
        while (!s.empty() && s.top() <= temp) s.pop();

        // 스택에 남아있는 건물들은 temp 보다 높아서
        // temp를 볼 수 있는 건물들임
        answer = s.size();

        // 해당 건물 스택에 집어넣기
        // 이후 들어올 건물들 시야를 가릴 수 있음
        s.push(temp);

    }

    // 답안 출력
    cout << answer << '\n';

    return 0;
}