#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {

    // // 속도 증가
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    // 최대 수 입력 받기
    int n;
    cin >> n;

    // 스택에 들어간 수 중 최대값을 나타내는 변수
    int start = 0;

    // 스택 stk 선언
    stack<int> stk;

    // 답안 출력 저장용 vector 선언
    vector<char> vec;

    // 최대 n번 반복
    for (int i = 0; i < n; ++i) {
        
        // 수열 정수 입력 받기
        int temp;
        cin >> temp;

        // 스택에 들어간 수가 temp보다 작거나 같다면
        // start를 증가 시키면서 스택에 push
        while (start < temp) {
            stk.push(++start);
            vec.push_back('+');
        }

        // 스택의 top 값이 temp와 같다면
        // 스택에서 빼기
        if (stk.top() == temp) {
            stk.pop();
            vec.push_back('-');
        }
        // 논리 상 여기서 else로 빠지는 경우
        // 해당 수열을 만들 수 없는 경우 밖에 존재하지 않음
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }

    // for문을 잘 빠져나온 경우
    // vec에 저장된 문자열을 순서대로 출력하면 됨
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << '\n';
    }

    return 0;
}