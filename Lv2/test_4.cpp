#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    while (n) {
        answer = "412"[n % 3] + answer;
        if (!n % 3) n--;
        n /= 3;
    }
    return answer;
}

/*
    잘못한 점
    : 1,2,4 를 굳이 순서대로 해석하려 하였다
      4,1,2 로 해석하였다면 더 쉬웠을 것을 ..
    배운 점
    : "string"[n]
*/