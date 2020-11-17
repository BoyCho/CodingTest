#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int max, min;

    a > b ? (max = a, min = b) : (max = b, min = a);

    for (int i = min; i <= max; i++)
        answer += i;

    return answer;
}