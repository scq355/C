#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define __STDC_WANT_LIB_EXT1__ 1
#define MAX_LENGTH 21
#define BUF_SIZE 100
#define TEXT_LEN 100
#define SUBSTR_LEN 40

int chapter0601() {
	printf("The character \0 is used to terminate a string.");
	return 0;
}

int chapter0602() {
	char str1[] = "To be or not to be";
	char str2[] = ", that is the question";

	unsigned int count = 0;
	while (str1[count] != '\0') {
		++count;
	}
	printf("The length of string \"%s\" is %d characters.\n", str1, count);

	count = 0;
	while (str2[count] != '\0') {
		++count;
	}
	printf("The length of string \"%s\" is %d characters.\n", str2, count);

	return 0;
}

int chapter0603() {
	char str[][70] = {
		"Computers do what you tell them to do, not you want them to do.",
		"When you put something in memory, remember where you put it.",
		"Never test for a condition you don't know what to do with."
	};

	unsigned int count = 0;
	unsigned int strCount = sizeof(str) / sizeof(str[0]);
	printf("There are %u strings.\n", strCount);

	for (unsigned int i = 0; i < strCount; i++) {
		count = 0;
		while (str[i][count]) {
			++count;
		}
		printf("The string: \n \"%s\"\n contains %u characters.\n", str[i], count);
	}

	return 0;
}


int chapter0604() {
#if defined __STDC_LIB_EXT1__
	printf("Optional function are defined.\n");
#else
	printf("Optional functions are not defined.\n");
#endif // defined __STDC_LIB_EXT1__
	return 0;
}


int chapter0606() {
	char word1[MAX_LENGTH];
	char word2[MAX_LENGTH];

	printf("Type the first word (maximum %d characters): ", MAX_LENGTH - 1);
	int retval = scanf_s("%s", word1, sizeof(word1));
	if (EOF == retval) {
		printf("Error reading the word.\n");
		return 1;
	}

	printf("Type the second word (maximum %d characters): ", MAX_LENGTH - 1);
	retval = scanf_s("%s", word2, sizeof(word2));
	if (EOF == retval) {
		printf("Error reading the word.\n");
		return 2;
	}

	if (strcmp(word1, word2) == 0) {
		printf("You have entered indentical words.");
	} else {
		printf("%s precedes %s \n", 
			(strcmp(word1, word2) < 0) ? word1 : word2, 
			(strcmp(word1, word2) < 0) ? word2 : word1);
	}
	return 0;
}

int chapter0607() {
	char str1[] = "This string contains the holy girl";
	char str2[] = "the holy girl";
	char str3[] = "the holy girll";

	if (strstr(str1, str2)) {
		printf("\"%s\" was found in \"%s\" \n", str2, str1);
	} else {
		printf("\n\"%s\" was not found.", str2);
	}
	if (!strstr(str1, str3)) {
		printf("\"%s\" was not found.\n", str3);
	} else {
		printf("\n We shouldn't get to here!");
	}
	return 0;
}

int chapter0608() {
	char buf[BUF_SIZE];
	int nLetters = 0;
	int nDigits = 0;
	int nPunct = 0;

	printf("Enter an interesting string of less than %d characters:\n", BUF_SIZE);
	if (!gets_s(buf, sizeof(buf))) {
		printf("Error reading string.\n");
		return 1;
	}
	size_t i = 0;
	while (buf[i]) {
		if (isalpha(buf[i])) {
			++nLetters;
		} else if(isdigit(buf[i])) {
			++nDigits;
		} else if (ispunct(buf[i])) {
			++nPunct;
		}
		++i;
	}
	printf("\n Your string contained %d lettere, %d digits and %d puncation characters.\n", nLetters, nDigits, nPunct);
	return 0;
}

int chapter0609() {
	char text[TEXT_LEN];
	char substring[SUBSTR_LEN];

	printf("Enter the string to be searched(less than %d characters):\n", TEXT_LEN);
	gets_s(text, TEXT_LEN);

	printf("\nEnter the string sought (less than %d characters):\n", SUBSTR_LEN);
	gets_s(substring, SUBSTR_LEN);

	printf("\nFirst string entered:\n%s\n", text);
	printf("Second string entered:\n%s\n", substring);

	for (int i = 0; (text[i] = toupper(text[i]) != '\0'); ++i);
	for (int i = 0; (substring[i] = toupper(substring[i])) != '\0'; ++i);

	printf("The second string %s found in the first.\n", (strstr(text, substring) == NULL) ? "was not" : "was");
	return 0;
}

int main() {
//	chapter0601();
//	chapter0602();
//	chapter0603();
//	chapter0604();
//	chapter0606();
//	chapter0607();
//	chapter0608();
	chapter0609();
}