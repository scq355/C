#include "pch.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100
#define MAX_TOWN 10
#define LENGTH 50

void try_input(char *prompt, char *fromat);


void eatspace(void);
bool getinteger(int *n);
char *getname(char *name, size_t length);
bool isnewline(void);

int chapter1001() {
	char *param1 = const_cast<char*>("Entrt as input: -2.35 15 25 ready2go\n");
	char *param2 = const_cast<char*>("%f %d %d %[abcdefghijklmnopqrstuvwxyz] %*ld %s%n");
	try_input(param1, param2);

	char *param3 = const_cast<char*>("\nEntrt the same input again:");
	char *param4 = const_cast<char*>("%4f %4d %d %*d %[abcdefghijklmnopqrstuvwxyz] %*ld %[^o]%n");
	try_input(param3, param4);

	char *param5 = const_cast<char*>("\nEntrt as input: -2.3A 15 25 ready2go\n");
	char *param6 = const_cast<char*>("%4f %4d %d %*d %[abcdefghijklmnopqrstuvwxyz] %*ld %[^o]%n");
	try_input(param5, param6);

	return 0;
}

void try_input(char *prompt, char *format) {
	int value_count = 0;
	float fp1 = 0.0f;
	int i = 0;
	int j = 0;
	char word1[SIZE] = " ";
	char word2[SIZE] = " ";
	int byte_count = 0;
	printf(prompt);
	value_count = scanf_s(format, &fp1, &i, &j, word1, sizeof(word1), word2, sizeof(word2), &byte_count);
	fflush(stdin);
	printf("The input format string for scanf_s() is:\n \"%s\"\n", format);
	printf("fp1 = %f  i = %d  j = %d\n", fp1, i, j);
	printf("word1 = %s  word2 = %s\n", word1, word2);
}

int chapter1002() {
	int i = 0;
	int j = 0;
	int value_count = 0;
	float fp1 = 0.0;
	printf("Enter: fp1 = 3.14159 i = 7 8 \n");

	printf("\nInput:");
	value_count = scanf_s("fp1 = %f i = %d %d", &fp1, &i, &j);
	printf("\nOutput:\n");
	printf("Count of value read = %d\n", value_count);
	printf("fp1 = %f\t i = %d\t j = %d\n", fp1, i, j);

	return 0;
}

int chapter1003() {
	float f1 = 0.0f;
	float f2 = 0.0f;
	float f3 = 0.0f;

	int value_count = 0;
	printf("Enter: 3.14.314E1.0314e+02\n");

	printf("Input:\n");
	value_count = scanf_s("%f %f %f", &f1, &f2, &f3);
	printf("\nOutput:\n");
	printf("Count of value read = %d\n", value_count);
	printf("f1 = %f  f2 = %f  f3 = %f\n", f1, f2, f3);

	return 0;
}

int chapter1004() {
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;

	printf("Enter three integer values:");
	n = scanf_s("%d %x %o", &i, &j, &k);

	printf("Input:\n");
	printf("%d values read.\n", n);
	printf("i = %d  j = %d  k = %d\n", i, j, k);

	return 0;
}
 

int chapter1005() {
	char initial = ' ';
	char name[80] = { ' ' };
	char age[40] = { '0' };

	printf("Enter your first initial: ");
	scanf_s("%c", &initial, sizeof(initial));

	printf("Enter your first name: ");
	scanf_s("%s", name, sizeof(name));

	fflush(stdin);
	
	if (initial != name[0]) {
		printf("%s, you got initial wrong.\n", name);
	} else {
		printf("Hi, %s.Your initial is corrent. Well done!\n", name);
		printf("Enter your full name and your age sparated by a comma:\n");
		scanf_s("%[^,], %[0123456789]", name, sizeof(name), age, sizeof(age));
		printf("\nYour name is %s and you are %s years old.\n", name, age);
	}

	return 0;
}

int chapter1006() {
	char initial[3] = { ' ' };
	char name[80] = { ' ' };

	printf("Enter your first initial: ");
	gets_s(initial, sizeof(initial));

	printf("Enter your name: ");
	gets_s(name, sizeof(name));

	if (initial[0] != name[0]) {
		printf("%s, you got initial wrong.\n", name);
	} else {
		printf("Hi, %s.Your initial is corrent. Well done!\n", name);
	}

	return 0;
}

int chapter1007() {
	int number;
	char name[LENGTH] = { '\0' };
	printf("Enter a sequence of integers and alphabetic names in a single line:\n");
	while (!isnewline()) {
		if (getinteger(&number)) {
			printf("Integer value: %d\n", number);
		} else if (strnlen_s(getname(name, LENGTH), LENGTH) > 0) {
			printf("Name: %s\n", name);
		} else {
			printf("Invalid input.\n");
			return 1;
		}
	}
	return 0;
}

void eatspace(void) {
	char ch = 0;
	while (isspace(ch = (char)getchar()));
	ungetc(ch, stdin);
}

bool getinteger(int *n) {
	eatspace();
	int value = 0;
	int sign = 1;
	char ch = 0;

	if ((ch = (char)getchar()) == '-') {
		sign = -1;
	} else if (isdigit(ch)) {
		value = ch - '0';
	} else if (ch != '+') {
		ungetc(ch, stdin);
		return false;
	}

	while (isdigit(ch = (char)getchar())) {
		value = 10 * value + (ch - '0');
	}

	ungetc(ch, stdin);
	*n = value * sign;

	return true;
}

char* getname(char *name, size_t length) {
	eatspace();
	size_t count = 0;
	char ch = 0;
	while (isalpha(ch = (char)getchar())) {
		name[count++] = ch;
		if (count = length - 1) {
			break;
		}
	}

	name[count] = '\0';
	if (count < length - 1) {
		ungetc(ch, stdin);
	}

	return name;
}

bool isnewline(void) {
	char ch = 0;
	if ((ch = (char) getchar()) == '\n') {
		return true;
	}
	ungetc(ch, stdin);
	return false;
}


int chapter1008() {
	int i = 15;
	int j = 345;
	int k = 4567;
	long long li = 56789LL;
	long long lj = 67891234567LL;
	long long lk = 23456789LL;

	printf_s("i = %d   j = %d   k = %d   i = %6.3d   j = %6.3d   k = %6.3d\n",
		i, j, k, i, j, k);

	printf_s("i = %-d   j = %+d   k = %-d   i = %-6.3d   j = %-6.3d   k = %-6.3d\n",
		i, j, k, i, j, k);

	printf_s("li = %d   lj = %d   lk = %d\n", li, lj, lk);

	printf_s("li = %lld   lj = %lld   lk = %lld\n", li, lj, lk);

	return 0;
}

int chapter1009() {
	int k = 678;

	printf_s("%%d  %%o  %%x  %%X\n");
	printf_s("%d  %o  %x  %X\n", k, k, k, k);
	printf_s("\n|%%8d   |%%-8d   |%%+8d   |%%08d   |%%-+8d\n");
	printf_s("\n|%8d   |%-8d   |%+8d   |%08d   |%-+8d\n", k, k, k, k, k);

	return 0;
}


int chapter1010() {
	float fp1 = 345.678f;
	float fp2 = 1.234E6f;
	double fp3 = 234567898.0;
	double fp4 = 11.22334455e-6;

	printf_s("%f %+f %-10.4f %6.4f\n", fp1, fp2, fp1, fp2);
	printf_s("%e %+E\n", fp1, fp2);
	printf_s("%f %g %#+f %8.4f %10.4g\n", fp3, fp3, fp3, fp3, fp4);

	return 0;
}


int chapter1011() {
	int count = 0;
	printf_s("The printable characters are the following:\n");

	for (int i = 0; i < CHAR_MAX; i++) {
		char ch = (char)i;
		if (isprint(ch)) {
			if (i++ % 32 == 0) {
				printf_s("\n");
			}
			printf(" %c", ch);
		}
	}

	printf_s("\n");
	return 0;
}


int main() {
//	chapter1001();
//	chapter1002();
//	chapter1003();
//	chapter1004();
//	chapter1005();
//	chapter1006();
//	chapter1007();
//	chapter1008();
//	chapter1009();
//	chapter1010();
	chapter1011();
}
