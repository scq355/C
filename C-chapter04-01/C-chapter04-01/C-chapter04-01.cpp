#include "pch.h"
#include <iostream>
#include <ctype.h>
#include <time.h>

int chapter0401() {
	int count = 1;
	for ( ; count <= 10; ++count) {
		printf("%d ", count);
	}
	printf("\nAnother the loop count has the value %d.", count);
	return 0;
}

int chapter0402() {
	printf("\n************");
	for (int i = 0; i < 8; ++i) {
		printf("\n*          *");
	}
	printf("\n************");
	return 0;
}

int chapter0403() {
	unsigned long long sum = 0LL;
	unsigned int count = 0;

	printf("\nEnter the number of integers you want you sum: ");
	scanf_s(" %u", &count);

	for (unsigned int i = 0; i < count; ++i) {
		sum += i;
	}

	printf("\nTotal of the first %u numbers is %llu\n", count, sum);
	return 0;
}

int chapter0404() {
	unsigned long long sum = 0LL;
	unsigned int count = 0;

	printf("\nEnter the number of integers you want you sum: ");
	scanf_s(" %u", &count);

	for (unsigned int i = 0; i < count; sum += i++);

	printf("\nTotal of the first %u numbers is %llu\n", count, sum);
	return 0;
}

int chapter0405() {
	unsigned long long sum = 0LL;
	unsigned int count = 0;

	printf("\nEnter the number of integers you want you sum: ");
	scanf_s(" %u", &count);

	for (unsigned int i = count; i >= 1; sum += i--);

	printf("\nTotal of the first %u numbers is %llu\n", count, sum);
	return 0;
}

int chapter0406() {
	char answer = 'N';
	double total = 0.0;
	double value = 0.0;
	unsigned int count = 0;

	printf("\nThis program calculates the average of any number of values.");

	for (; ; ) {
		printf("\nEnter a value");
		scanf_s(" %lf", &value);
		total += value;
		++count;

		printf("Do you want to enter another value? (Y or N): ");
		scanf_s(" %c", &answer);
		if (tolower(answer) == 'n') {
			break;
		}
	}

	printf("\nThe average is %.2lf\n", total / count);
	return 0;
}

int chapter0407() {
	int chosen = 0;
	int guess = 0;
	int count = 3;
	int limit = 20;

	srand(time(NULL));
	chosen = 1 + rand() % limit;

	printf("\nThis is a guessing game.");
	printf("\nI have chosen a number between 1 and 20 which you must guess.\n");

	for (; count > 0; --count) {
		printf("\nYou have %d tr%s left.", count, count == 1 ? "y" : "ies");
		printf("\nEnter a guess: ");
		scanf_s("%d", &guess);

		if (guess == chosen) {
			printf("\nCongratulations. You guessed it!\n");
			return 0;
		} else if (guess < 1 || guess > 20) {
			printf("I said the number is between 1 and 20.\n");
		} else {
			printf("Sorry, %d is wrong. My number is %s than that.\n", guess, chosen > guess ? "grater" : "less");
		}
	}

	printf("\nYou have had three tries and failed.The number was %d\n", chosen);
}

int chapter0408() {
	unsigned long sum = 0UL;
	unsigned int i = 1;
	unsigned int count = 0;

	printf("\nEnter the number of integers you want to sum: ");
	scanf_s(" %u", &count);

	while (i <= count) {
		sum += i++;
	}

	printf("Total of the first %u numbers is %lu\n", count, sum);
	return 0;
}

int chapter0409() {
	const unsigned int MIN_SIZE = 3;
	unsigned int width = 0;
	unsigned int height = 0;

	printf("Enter values for the width and height (minimum of %u): ", MIN_SIZE);
	scanf_s("%u%u", &width, &height);

	if (width < MIN_SIZE) {
		printf("\nWidth value of %u is too small.Setting it to %u.", width, MIN_SIZE);
		width = MIN_SIZE;
	}

	if (height < MIN_SIZE) {
		printf("\Height value of %u is too small.Setting it to %u.", height, MIN_SIZE);
	}

	for (unsigned int i = 0; i < width; ++i) {
		printf("*");
	}

	for (unsigned int i = 0; i < height - 2; ++i) {
		printf("\n*");
		for (unsigned int j = 0; j < width - 2; ++j) {
			printf(" ");
		}
		printf("*");
	}

	printf("\n");
	for (unsigned int i = 0; i < width; ++i) {
		printf("*");
	}

	printf("\n");
	
	return 0;
}

int chapter0410() {
	unsigned long sum = 0UL;
	unsigned int count = 0;

	printf("\nEnter the number of integers you want to sum: ");
	scanf_s(" %u", &count);

	for (unsigned int i = 1; i <= count; ++i) {
		sum = 0UL;
		for (unsigned int j = 1; j <= i; ++j) {
			sum += j;
		}
		printf("\n%u\t%5lu", i, sum);
	}
	printf("\n");
	return 0;
}

int chapter0411() {
	unsigned long sum = 1UL;
	unsigned int j = 1U;
	unsigned int count = 0;

	printf("\nEnter the number of integers you want to sum: ");
	scanf_s(" %u", &count);

	for (unsigned int i = 1; i <= count; i++) {
		sum = 1UL;
		j = 1;
		printf("\n1");
		while (j < i) {
			sum += ++j;
			printf(" + %u", j);
		}
		printf(" = %lu", sum);
	}
	printf("\n");
	return 0;
}

int chapter0412() {
	unsigned int number = 0;
	unsigned int rebmun = 0;
	unsigned int temp = 0;

	printf("\nEnter a positive integer: ");
	scanf_s(" %u", &number);

	temp = number;

	do {
		rebmun = 10 * rebmun + temp % 10;
		temp = temp / 10;
	} while (temp);

	printf("\nThe number %u reversed is %u rebmun ehT\n", number, rebmun);
	return 0;
}



int main() {
//	chapter0401();
//	chapter0402();
//	chapter0403();
//	chapter0404();
//	chapter0405();
//	chapter0406();
//  chapter0407();
//	chapter0408();
//	chapter0409();
//	chapter0410();
//	chapter0411();
	chapter0412();
}