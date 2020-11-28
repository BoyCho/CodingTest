#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int scale = 1;
    int tmp = n;

    while (n != 0) {
        scale *= 3;
        n /= 3;
    }
    while (tmp != 0) {
        scale /= 3;
        answer += scale * (tmp % 3);
        tmp /= 3;
    }

    return answer;
}