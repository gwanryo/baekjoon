#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    char *s = (char*) calloc(21, sizeof(char));
    while (scanf("%s", s) != EOF) {
        char c = getchar();
        for(int j = 20; j >= 0; j--) {
            if (s[j] > 0) {
                printf("%c", s[j]);
            }
        }
        if (c > 0) printf("%c", c);
        for(int j = 20; j >= 0; j--) s[j] = 0;
    }

    return 0;
}
