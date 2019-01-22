#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define __STDC_WANT_LIB_EXIT__ 1
#define CAP_INCR 10

int chapter0701() {
	int number = 0;
	int *pnumber = NULL;

	number = 10;
	printf("number's address: %p\n", &number);
	printf("number's address: %p\n", (void*)&number);
	printf("number's value: %d\n\n", number);

	pnumber = &number;
	printf("pnumber's address: %p\n", (void*)&pnumber);
	printf("pnumber's size: %zd bytes\n", sizeof(pnumber));
	printf("pnumber's value: %p\n", pnumber);
	printf("value pointed to: %d\n", *pnumber);

	return 0;
}

int chapter0702() {
	long num1 = 0L;
	long num2 = 0L;
	long *pnum = NULL;

	pnum = &num1;
	*pnum = 2L;
	++num2;
	num2 += *pnum;

	pnum = &num2;
	++*pnum;

	printf("num1 = %ld \nnum2 = %ld \n*pnum = %ld \n*pnum + num2  = %ld\n", 
		num1, num2, *pnum, *pnum + num2);

	return 0;
}

int chapter0703() {
	int value = 0;
	int *pvalue = &value;

	printf("Input an integer: ");
	scanf_s(" %d", pvalue);

	printf("You have entered %d.\n", value);
	return 0;
}

int chapter0704() {
	char multiple[] = "My string.";
	char *p = &multiple[0];
	printf("The address of the first array element: %p\n", p);
	
	p = multiple;
	printf("The address obtained from the array name: %p\n", multiple);

	return 0;
}

int chapter0705() {
	char multiple[] = "a string";
	char *p = multiple;

	for (int i = 0; i < strnlen_s(multiple, sizeof(multiple)); ++i) {
		printf("mutiple[%d] = %c * (p + %d) = %c &multiple[%d] = %p p + %d = %p\n",
			i, multiple[i], i, *(p + i), i, &multiple[i], i, p + i);
	}
	return 0;
}

int chapter0706() {
	long multiple[] = { 15L, 25L, 35L, 45L };
	long *p = multiple;

	for (int i = 0; i < sizeof(multiple) / sizeof(multiple[0]); ++i) {
		printf("address p + %d (&multiple[%d]): %llu * (p + %d) value: %d\n",
			i, i, (unsigned long long)(p + i), i, *(p + i));
	}

	printf("\n Type long occupies: %d bytes\n", (int) sizeof(long));
	return 0;
}

// 07 - 10
int chapter0707() {
	char board[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};

	printf("address of board: %p\n", board);
	printf("address of board[0][0]: %p\n", &board[0][0]);
	printf("value of board[0]: %p\n", board[0]);

	printf("value of board[0][0]: %c\n", board[0][0]);
	printf("value of board[0]: %c\n", *board[0]);
	printf("value of board: %c\n", **board);

	for (int i = 0; i < 9; ++i) {
		printf("board: %c\n", *(*board + i));
	}

	char *pboard = *board;
	for (int i = 0; i < 9; ++i) {
		printf("board: %c\n", *(pboard + i));
	}

	return 0;
}

int chapter0711() {
	unsigned long long *pPrimes = NULL;
	unsigned long long trail = 0;
	bool found = false;
	int total = 0;
	int count = 0;

	printf("How many primes would you like - you'll get at lest 4? ");
	scanf_s("%d", &total);
	total = total < 4 ? 4 : total;

	pPrimes = (unsigned long long*) malloc(total * sizeof(unsigned long long));

	if (!pPrimes) {
		printf("Not enough memory.It's the end I'm afraid.\n");
		return 1;
	}

	*pPrimes = 2ULL;
	*(pPrimes + 1) = 3ULL;
	*(pPrimes + 2) = 5ULL;

	count = 3;
	trail = 5ULL;

	while (count < total) {
		trail += 2ULL;
		for (int i = 0; i < count; i++) {
			if (!(found = (trail % *(pPrimes + i)))) {
				break;
			}
		}
		if (found) {
			*(pPrimes + count++) = trail;
		}
	}

	for (int i = 0; i < total; i++) {
		printf("%12llu", *(pPrimes + i));
		if (!((i + 1) % 5)) {
			printf("\n");
		}
	}
	printf("\n");

	free(pPrimes);
	pPrimes = NULL;
	return 0;

}

int chapter0712() {
	unsigned long long *pPrimes = NULL;
	bool found = false;
	unsigned long long limit = 0LL;
	int count = 0;

	printf("Enter the upper limit for primes you want to find: ");
	scanf_s("%llu", &limit);

	size_t capacity = 10;
	// calloc
	pPrimes = (unsigned long long *) calloc(capacity, sizeof(unsigned long long));
	if (!pPrimes) {
		printf("Not enough memory. It's the end I'm afraid.\n");
		return 1;
	}

	*pPrimes = 2ULL;
	*(pPrimes + 1) = 3ULL;
	*(pPrimes + 2) = 5ULL;
	count = 3;

	unsigned long long trail = *(pPrimes + 2) + 2ULL;
	unsigned long long *pTemp = NULL;

	while (trail <= limit) {
		for (int i = 0; i < count; i++) {
			if (!(found = (trail % *(pPrimes + i)))) {
				break;
			}
		}
		if (found) {
			if (count == capacity) {
				capacity += CAP_INCR;
				pTemp = (unsigned long long *) realloc(pPrimes, capacity * sizeof(unsigned long long));
				if (!pTemp) {
					printf("Unfortunately memory reallocation failed.\n");
					free(pPrimes);
					pPrimes = NULL;
					return 2;
				}
				pPrimes = pTemp;
			}
			*(pPrimes + count++) = trail;
		}
		trail += 2ULL;
	}

	printf("%d primes found up to %llu:\n", count, limit);
	for (int i = 0; i < count; i++) {
		printf("%12llu", *(pPrimes + i));
		if (!((i + 1) % 5)) {
			printf("\n");
		}
	}
	printf("\n");
	free(pPrimes);
	pPrimes = NULL;
	return 0;
}

int main() {
//	chapter0701();
//	chapter0702();
//	chapter0703();
//	chapter0704();
//	chapter0705();
//	chapter0706();
//	chapter0707();
//	chapter0711();
	chapter0712();
}

