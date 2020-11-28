// Eratosthenes' sieve

#include <string>
#include <vector>

using namespace std;

/*
int solution(int n) {
    int answer = 0;
    vector <int> num(n+1, 1);
    for (int i = 2; i <= n; i++) {
        if(num[i] == 0) continue;
        for (int j = 2; i*j <= n; j++) {
            if (num[i*j] == 0) continue;
            num[i*j] = 0;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (num[i] == 1) answer++;
    }
    return answer;
}
*/

// vector<bool> »ç¿ë

int solution(int n) {
    int answer = 0;
    vector <bool> num(n+1,true);

    for (int i = 2; i <= n; i++) {
        if (num[i]) {
            for (int j = 2; i * j <= n; j++)
                num[i * j] = false;
            answer++;
        }
    }
    return answer;
}