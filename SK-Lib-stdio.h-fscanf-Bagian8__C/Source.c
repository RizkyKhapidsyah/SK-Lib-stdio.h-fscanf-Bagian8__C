#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Source by Microsoft
    Modified For Learn by RK
    I.D.E : VS2019
*/

FILE* stream;

int main(void) {
    long l;
    float fp;
    char s[81];
    char c;

    errno_t err = fopen_s(&stream, "fscanf.out", "w+");
    if (err) {
        printf_s("The file fscanf.out was not opened\n");
    } else {
        fprintf_s(stream, "%s %ld %f%c", "a-string", 65000, 3.14159, 'x');
        fseek(stream, 0L, SEEK_SET);
        fscanf_s(stream, "%s", s, _countof(s));
        fscanf_s(stream, "%ld", &l);
        fscanf_s(stream, "%f", &fp);
        fscanf_s(stream, "%c", &c, 1);

        // Output data read:
        printf("%s\n", s);
        printf("%ld\n", l);
        printf("%f\n", fp);
        printf("%c\n", c);

        fclose(stream);
    }

    _getch();
    return 0;
}