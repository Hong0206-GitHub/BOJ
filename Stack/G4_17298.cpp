#include <iostream>
#include <stack>

using namespace std;

int main(void) {

    // 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // N입력 받기
    int N;
    cin >> N;

    // N 크기의 동적 배열 할당
    unsigned int *arr = new unsigned int[N];

    // 결과 출력용 동적 배열 생성 및 -1로 초기화
    int *result = new int[N];
    fill(result, result + N, -1);
 
    // 스택 선언
    stack<unsigned int> stk;

    // 원소 입력 받기
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // 모든 원소에 대해서 반복   
    for (int i = 0; i < N; ++i) {
        
        // 스택에는 인덱스를 저장함.
        // 스택이 비어있지 않으면서, 스택의 최상단의 인덱스가 가리키는 값이, 현재 i가 가리키는 값보다 작다면,
        // i가 가리키는 값은 오큰수가 됨.
        // 스택에서 빼면서 해당 조건을 만족하는 모든 값에 대한 오큰수가 됨.
        while (!stk.empty() && arr[stk.top()] < arr[i]) {
            result[stk.top()] = arr[i];
            stk.pop();
        }
        // 값은 그대로 스택에 push
        stk.push(i);
    }

    // 결과 출력
    for (int i = 0; i < N; ++i) cout << result[i] << ' ';
    cout << '\n';

    // 동적 할당 해제
    delete[] arr;
    delete[] result;

    return 0;
}