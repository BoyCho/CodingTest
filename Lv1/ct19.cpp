#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int tens = 1;
    
    for (int i = s.size() - 1; i > 0; i--, tens *= 10)
        answer += (s[i] - '0') * tens;

    if('0' <= s[0] && s[0] <= '9')
        answer += (s[0] - '0') * tens;
    else if(s[0] == '-')
        answer *= -1;

    return answer;
}
/*
    int solution(string s) {
        int answer = stoi(s);
        return answer;
    }
*/