#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#define random(NumValues) ((int)(((double)(rand()) * (NumValues)) / (RAND_MAX + 1.0)))

#define iterations 6
#define test
#define testf
#define repeatable

int sum(int, int);
int product(int, int);
int difference(int, int);

int chapter1301() {
	int funsel = 0;
	int a = 3;
	int b = 6;
	int result = 0;
	
	int(*pfun[])(int, int) = { sum, product, difference };

#ifdef repeatable
	srand(1);
#else // repeatable
	srand((unsigned int)time(NULL));
#endif

	int element_count = sizeof(pfun) / sizeof(pfun[0]);
	for (int i = 0; i < iterations; i++) {
		funsel = random(element_count);
		if (funsel > element_count - 1) {
			printf_s("Random index = %d\n", funsel);
			exit(1);
		}

#ifdef test
		printf_s("Random index = %d\n", funsel);
#endif // test
		result = pfun[funsel](a, b);
		printf_s("result = %d\n", result);
	}
	return 0;
}


int sum(int x, int y) {
#ifdef testf
	printf_s("Function sum called args %d and %d.\n", x, y);
#endif // testf
	return x + y;
}

int product(int x, int y) {
#ifdef testf
	printf_s("Function product called args %d and %d.\n", x, y);
#endif // testf
	return x * y;
}

int difference(int x, int y) {
#ifdef testf
	printf_s("Function product called args %d and %d.\n", x, y);
#endif // testf
	return x - y;
}

int chapter1302() {
	int y = 5;
	for (int i = 0; i < 20; i++) {
		printf("i = %d  y = %d\n", i, y);
		assert(i < y);
	}
	return 0;
}

int chapter1303() {
	time_t calendar_start = time(NULL);
	clock_t cpu_start = clock();
	int count = 0;
	const long long iteration = 1000000000LL;
	char answer = 'y';
	double x = 0.0;
	printf_s("Install clock time = %lld initial calendar time = %lld\n", (long long)cpu_start, (long long)calendar_start);

	while (tolower(answer) == 'y') {
		for (long long i = 0LL; i < iteration; i++) {
			x = sqrt(3.14159265);
		}
		printf_s("%lld square roots completed.\n", iteration * (++count));
		printf_s("Do you want to run some more (y or n)? \n");
		scanf_s("\n%c", &answer, sizeof(answer));
	}

	clock_t cpu_end = clock();
	time_t calendar_end = time(NULL);

	printf_s("Final clock time = %lld Final calendar time = %lld\n", (long long)cpu_end, (long long)calendar_end);
	
	printf_s("CPU time for %lld iterations is %.2lf seconds.\n", count * iteration, ((double)(cpu_end - cpu_start)) / CLOCKS_PER_SEC);

	printf_s("Elapsed calendar time to execute the program is %8.2lf seconds.\n", difftime(calendar_end, calendar_start));

	return 0;
}

int chapter1304() {
	const char *day[7] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"
	};

	const char *month[12] = {
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};

	const char *suffix[] = { "st", "nd", "rd", "th" };
	enum sufindex {
		st, nd, rd, th
	} sufsel = th;

	struct tm ourT;

	time_t tVal = time(NULL);

//	if (!localtime_s(&tVal,&ourT)) {
//		fprintf_s(stderr, "Failed to populate tm struct.\n");
//		return -1;
//	}

	switch (ourT.tm_mday) {
	case 1:case 21: case 31:
		sufsel = st;
		break;
	case 2: case 22:
		sufsel = nd;
		break;
	case 3: case 23:
		sufsel = rd;
		break;
	default:
		sufsel = th;
		break;
	}

	printf_s("Today is %s the %d%s %s %d.", day[ourT.tm_wday], ourT.tm_mday, suffix[sufsel], month[ourT.tm_mon], 1900 + ourT.tm_year);

	printf_s("The time is %d : %d : %d.\n", ourT.tm_hour, ourT.tm_min, ourT.tm_sec);

	return 0;
}


int main() {
//	chapter1301();
//	chapter1302();
//	chapter1303();
	chapter1304();
}
