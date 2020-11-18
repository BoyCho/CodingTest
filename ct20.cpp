#include <string>
#include <vector>

using namespace std;

char caesar_pw(char c, int n) {
    if (c == ' ')
        return ' ';
    else if ('a' <= c && c <= 'z') {
        if ('z' - c < n)
            c = 'a' + n - ('z' - c) - 1;
        else
            c += n;
        return c;
    }
    else {
        if ('Z' - c < n)
            c = 'A' + n - ('Z' - c) - 1;
        else
            c += n;
        return c;
    }
}

string solution(string s, int n) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        answer += caesar_pw(s[i],n);
    }
    return answer;
}