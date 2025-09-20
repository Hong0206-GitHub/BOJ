#include <iostream>
// deque 자료구조 사용하기 위함
#include <deque>
// pair 자료형 사용하기 위함
#include <utility>

using namespace std;

// Node 라는 타입 정의
// Node 타입은 pair 자료형을 사용하고, 두 개의 int 값을 저장 할 수 있음
// 두 개의 int 값 중 첫 번재는 idx를, 두 번째는 값을 저장함
using Node = pair<int, int>;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // n과 l 입력 받기
    int n, l;
    cin >> n >> l;

    // deque 선언
    // deque이 저장하고 있는 타입은 위에서 선언한 Node 타입
    deque<Node> myDeque;

    for (int i = 0; i < n; ++i) {
        
        // 값 입력받기
        int value;
        cin >> value;

        // 덱이 비어있지 않으면서, 덱의 마지막 원소의 값이 현재 들어갈 값보다 큰 경우
        // 덱의 마지막 원소 뽑기
        while (myDeque.size() && myDeque.back().second > value) 
            myDeque.pop_back();
        
        // 덱에 값 추가
        myDeque.push_back(Node(i, value));

        // 덱의 첫번째 원소의 idx를 비교해서
        // 윈도우 크기를 l로 맞춤
        if (myDeque.front().first <= i - l)
            myDeque.pop_front();

        // 결과 출력
        cout << myDeque.front().second << ' ';

    }

    return 0;

}
