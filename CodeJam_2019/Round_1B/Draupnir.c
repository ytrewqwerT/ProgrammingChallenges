
#include <stdio.h>

int main(void) {
    int T, W;
    scanf("%d %d", &T, &W);
    if (W < 6) return 1;
    for (int t = 1; t <= T; t++) {
        int R[6+1] = {0};
        long long day[6+1] = {0};
        for (int i = 1; i <= 6; i++) {
            printf("%d\n", i);
            fflush(stdout);

            int response;
            scanf("%d", &response);
            if (response == -1) return 1;
            day[i] = response;
        }

        R[6] = (12*day[1] - 2*day[2] - 6*day[3] - 5*day[5] + 3*day[6]) / 5;
        R[5] = -4*day[1] + 2*day[2] + 2*day[3] - day[4] + 2*day[5] - day[6] + R[6];
        R[4] = (4*day[1] - 2*day[2] - 2*day[3] + day[4] - R[5] - R[6]) / 2;
        R[3] = 2*day[1] - day[2] - R[4] - R[5] - R[6];
        R[2] = (4*day[1] - day[3] - 2*R[3] - 3*R[4] - 3*R[5] - 3*R[6]) / 2;
        R[1] = (day[1] - R[1] - R[2] - R[3] - R[4] - R[5] - R[6]) / 2;

        printf("%d %d %d %d %d %d\n", R[1], R[2], R[3], R[4], R[5], R[6]);
        fflush(stdout);
    }

    return 0;
}
