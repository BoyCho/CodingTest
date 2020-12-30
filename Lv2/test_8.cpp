#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int insert = 0, start_h = 0, start_w = 0, num = n, num_w = n;
    int i, j, ans = 0;
    int* answer = (int*)calloc(n * (n + 1) / 2, sizeof(int));
    int** arr = (int**)calloc(n, sizeof(int*));
    for (int i = 0, j = 1; i < n; i++, j++)
        arr[i] = (int*)calloc(j, sizeof(int));

    while (true) {
        for (i = start_h; i < num; i++)
            arr[i][start_w] = ++insert;
        for (j = start_w, i--, insert--; j < num_w; j++)
            arr[i][j] = ++insert;
        for (i = num - 1, j = num_w - 1, insert--; i > start_h; i--, j--)
            arr[i][j] = ++insert;
        start_h += 2;
        start_w += 1;
        num -= 1;
        num_w -= 2;
        if (num - start_h == 1) {
            arr[start_h][start_w] = ++insert;
            break;
        }
        if (num - start_h <= 0)
            break;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++, ans++) {
            printf("%d\t", arr[i][j]);
            answer[ans] = arr[i][j];
        }
        printf("\n");
    }
    return answer;
}

int main() {
    int n = 6;
    solution(n);
}