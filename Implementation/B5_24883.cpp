#include <iostream>
#include <string>
using namespace std;

int main(void) {

    string str;
    cin >> str;

    if (str == "N" || str == "n") cout << "Naver D2\n";
    else cout << "Naver Whale\n";

    return 0;
}