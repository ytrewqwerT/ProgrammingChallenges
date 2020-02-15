
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int T;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		double A;
		scanf("%lf", &A);
		
		double lower = 0;
		double upper = M_PI/2;
		double angle = (upper + lower) / 2;
		if (A > 1.414213) {
			exit(EXIT_FAILURE);
		} else {
			while (fabs(sin(angle)+cos(angle) - A) > pow(10, -15)) {
				if (sin(angle)+cos(angle) > A) upper = angle;
				if (sin(angle)+cos(angle) < A) lower = angle;
				angle = (upper + lower) / 2;
			}
		}

		printf("Case #%d:\n", test);
		printf("%.10lf %.10lf %.10lf\n", 0.5*cos(angle), 0.5*sin(angle), 0);
		printf("%.10lf %.10lf %.10lf\n", 0.5*sin(angle), -0.5*cos(angle), 0);
		printf("%.10lf %.10lf %.10lf\n", 0, 0, 0.5);


	}

	return EXIT_SUCCESS;
}
