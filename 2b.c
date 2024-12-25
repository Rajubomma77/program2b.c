#include <stdio.h>
#include <string.h>

char str[50], pat[20], rep[20], res[50];
int c = 0, m = 0, i = 0, j = 0, k, flag = 0;

void stringmatch() {
    while (str[c] != '\0') {
        if (str[c] == pat[i]) {
            m = c;
            i++;
            while (pat[i] != '\0' && str[m] == pat[i]) {
                m++;
                i++;
            }
            if (pat[i] == '\0') {
                flag = 1;
                k = 0;
                while (rep[k] != '\0') {
                    res[j++] = rep[k++];
                }
                c = m;
                i = 0;
            } else {
                res[j++] = str[c++];
                i = 0;
            }
        } else {
            res[j++] = str[c++];
        }
    }
    res[j] = '\0';
}

int main() {
    printf("Enter the main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the pattern string: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';

    printf("Enter the replace string: ");
    fgets(rep, sizeof(rep), stdin);
    rep[strcspn(rep, "\n")] = '\0';

    printf("The string before pattern match: %s\n", str);

    stringmatch();

    if (flag) {
        printf("The string after pattern match: %s\n", res);
    } else {
        printf("Pattern not found in the string.\n");
    }

    return 0;
}

