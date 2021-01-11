#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compress(int n, string s) {
    string answer = "\0";
    string tmp = s.substr(0, n);
    int cnt = 0, i = 0;

    for (int i = n; i < s.size(); i += n) {
        if (tmp == s.substr(i, n)) cnt++;
        else {
            if (cnt > 0) answer += to_string(++cnt);
            cnt = 0;
            answer += tmp;
            tmp = s.substr(i, n);
        }
    }
    if (cnt > 0) answer += to_string(++cnt);
    answer += tmp;
    return answer.size();
}
int solution(string s) {
    int answer = s.size(), tmp;
    for (int i = 1; i <= (s.size() / 2); i++)
        answer = min(answer, compress(i, s));
    return answer;
}