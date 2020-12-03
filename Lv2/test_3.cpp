#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}
long long solution(int w, int h) {
    long long whole = (long long)w * h;
    int white = w + h - gcd(w, h);

    return whole - white;
}

int main() {
    cout << solution(99999999,99999999);
}

// ���� ��� �� �ڷ��� ����
// double �Ҽ��� 53�ڸ� �̻��� �ѱ�� ������ �ذ��ϰ� ������, ����� �����⸦ ���������� �д�