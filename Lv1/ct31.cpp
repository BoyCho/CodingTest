#include <string>
#include <vector>

using namespace std;
int gcd(int n, int m);
int lcm(int n, int m);

vector<int> solution(int n, int m) {
    return {gcd(n,m),lcm(n,m)};
}

int gcd(int n, int m) {
    int x = n < m ? n : m;
    while (n % x || m % x)
        x--;
    return x;
}

int lcm(int n, int m) {
    int x = n > m ? n : m;
    while (x % n || x % m)
        x++;
    return x;
}