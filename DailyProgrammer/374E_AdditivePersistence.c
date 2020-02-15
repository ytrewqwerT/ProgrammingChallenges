
#include <stdio.h>
#include <stdlib.h>

unsigned long long stoi(char *str) {
	unsigned long long num = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}

unsigned long long add(unsigned long long num) {
	unsigned long long sum = 0;
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}
	
	return sum;
}

unsigned long long main(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		unsigned long long num = stoi(argv[i]);
		int times = 0;
		while (num > 9) {
			num = add(num);
			times++;
		}
		printf("%d\n", times);
	}

	return 0;
}
