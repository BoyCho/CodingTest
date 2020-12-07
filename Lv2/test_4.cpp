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
    �߸��� ��
    : 1,2,4 �� ���� ������� �ؼ��Ϸ� �Ͽ���
      4,1,2 �� �ؼ��Ͽ��ٸ� �� ������ ���� ..
    ��� ��
    : "string"[n]
*/