#include <stdio.h>
#include <unistd.h>

int main() {
    char b[] = "Loading";
    while (1) {
        printf("\r%-13s", b);
        fflush(stdout);
        sleep(1);

        for (int i = 0; i < 5; i++) {
            printf("\r%s", b);
            for (int j = 0; j <= i; j++) printf(".");
            fflush(stdout);
            usleep(700000);
        }
    }
    return 0;
}
