#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    unsigned long n = num;

    while (answer < 500) {
        if(n == 1)
            return answer;
        n = n & 1 ? n * 3 + 1 : n / 2;
        answer++;
    }
    return -1;
}