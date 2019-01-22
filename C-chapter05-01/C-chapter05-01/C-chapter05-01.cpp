#include "pch.h"
#include <iostream>

int chapter0501() {
	int grade = 0;
	unsigned int count = 10;
	long sum = 0L;
	float average = 0.0f;

	for (unsigned int i = 0; i < count; i++) {
		printf("Enter a grade: ");
		scanf_s("%d", &grade);
		sum += grade;
	}

	average = (float) sum / count;
	printf("\nAverage of the ten grades entered is: %f\n", average);

	return 0;
}


int chapter0502() {
	int grade0 = 0, grade1 = 0, grade2 = 0, grade3 = 0, grade4 = 0;
	int grade5 = 0, grade6 = 0, grade7 = 0, grade8 = 0, grade9 = 0;

	long sum = 0L;
	float average = 0.0f;

	printf("Enter the first five grades,\n");
	printf("use a space or press Enter between each number.\n");
	scanf_s("%d%d%d%d%d", &grade0, &grade1, &grade2, &grade3, &grade4);

	printf("Enter the last five grades,\n");
	scanf_s("%d%d%d%d%d", &grade5, &grade6, &grade7, &grade8, &grade9);

	sum = grade0 + grade1 + grade2 + grade3 + grade4
		+ grade5 + grade6 + grade7 + grade8 + grade9;

	average = (float) sum / 10.0f;
	printf("\nAverage of the ten grades entered is: %f\n", average);

	return 0;
}

int chapter0503() {
	int grades[10];
	unsigned int count = 10;
	long sum = 0L;
	float average = 0.0f;

	printf("Enter the 10 grades,\n");
	for (unsigned int i = 0; i < count; i++) {
		printf("%2u> ", i + 1);
		scanf_s("%d", &grades[i]);
		sum += grades[i];
	}
	average = (float)sum / count;
	printf("\nAverage of the ten grades entered is: %.2f\n", average);

	return 0;
}

int chapter0504() {
	int grades[10];
	unsigned int count = 10;
	long sum = 0L;
	float average = 0.0f;

	printf("\nEnter the 10 grades:\n");

	for (unsigned int i = 0; i < count; i++) {
		printf("%2u> ", i + 1);
		scanf_s("%d", &grades[i]);
		sum += grades[i];
	}

	average = (float)sum / count;

	for (unsigned int i = 0; i < count; i++) {
		printf("\nGrade Number %2u is %3d", i + 1, grades[i]);
	}
	printf("\nAverage of the ten grades entered is: %.2f\n", average);
	
	return 0;
}

int chapter0505() {
	long a = 1L;
	long b = 2L;
	long c = 3L;

	double d = 4.0;
	double e = 5.0;
	double f = 6.0;

	printf("A variable of type long occupies %u bytes.", sizeof(long));
	printf("\nHere are the addresses of some variables of type long:");
	printf("\nThe address of a is: %p The address of b is: %p", &a, &b);
	printf("\nThe address of c is: %p ", &c);

	printf("\n\nA variable of type double occupies %u bytes.", sizeof(double));
	printf("\nThe address of d is: %p The address of e is: %p", &d, &e);
	printf("\nThe address of f is: %p ", &f);


	int data[5];
	for (unsigned int i = 0; i < 5; i++) {
		data[i] = 12 * (i + 1);
		printf("data[%d] Address: %p Contents: %d\n", i, &data[i], data[i]);
	}

	return 0;
}


int chapter0506() {
	char size[3][12] = {
		{'6', '6', '6', '6', '7', '7', '7', '7', '7', '7', '7', '7'},
		{'1', '5', '3', '7', ' ', '1', '1', '3', '1', '5', '3', '7'},
		{'2', '8', '4', '8', ' ', '8', '4', '8', '2', '8', '4', '8'}
	};

	int headsize[12] = { 164, 166, 172, 178, 181, 184, 188, 191, 194, 197 };
	float cranium = 0.0f;
	int your_head = 0;
	bool hat_found = false;

	printf("\nEnter the circumference of your head above your eyebrows in inches as a decimal value: ");
	scanf_s(" %f", &cranium);

	your_head = (int)(8.0f * cranium);

	// 循环索引i在循环之前声明，这样可以在循环外部使用
	size_t i = 0;
	if (your_head == headsize[i]) {
		hat_found = true;
	} else {
		for (i = 0; i < sizeof(headsize); i++) {
			if (your_head > headsize[i - 1] && your_head <= headsize[i]) {
				hat_found = true;
				break;
			}
		}
	}

	if (hat_found) {
		printf("\nYour hat size is %c %c%c%c\n", size[0][i], size[1][i], size[1][i] == ' ' ? ' ' : '/', size[2][i]);
	} else {
		if (your_head < headsize[0]) {
			printf("\nYou are the proverbial pinhead. No hat for you I'm afraid.\n");
		} else {
			printf("\nYou, in techinal parlance, are a fathead. No hat for you, I'm afraid.\n");
		}
	}

	return 0;
}

int chapter0507() {
	const size_t nGrades = 5;
	printf("Enter the number of grades: ");
	scanf_s("%zd", &nGrades);
	
	int grades[nGrades];
	long sum = 0L;
	float average = 0.0f;
	printf("\nEnter the %zd grades:\n", nGrades);

	for (size_t i = 0; i < nGrades; i++) {
		printf("%2zd> ", i + 1);
		scanf_s("%d", &grades[i]);
		sum += grades[i];
	}

	printf("The grades you entered are:\n");
	for (size_t i = 0; i < nGrades; i++) {
		printf("Grade[%2zd] = %3d\n", i + 1, grades[i]);

		if ((i + 1) % 5 == 0) {
			printf("\n");
		}
	}
	average = (float)sum / nGrades;

	printf("\nAverage of the %zd grades entered is: %.2f\n", nGrades, average);
	return 0;
}



int main() {
//	chapter0501();
//	chapter0502();
//	chapter0503();
//	chapter0504();
//	chapter0505();
//	chapter0506();
	chapter0507();
}
