#include "pch.h"
#include <iostream>
#include <limits.h>

int chapter0301() {
	int number = 0;
	printf("\nEnter an integer betweent 1 and 10:");
	scanf_s("%d", &number);
	
	if (number > 5) {
		printf("you entered %d is greater than 5\n", number);
	}

	if (number < 6) {
		printf("you entered %d is less than 5\n", number);
	}

	return 0;
}


int chapter0302() {
	const double unit_price = 3.50;
	int quantity = 0;
	printf("Enter the number that you want to buy: ");
	scanf_s("%d", &quantity);

	double total = 0.0;
	if (quantity > 10) {
		total = quantity * unit_price * 0.95;
	} else {
		total = quantity * unit_price;
	}
	
	printf("the price for %d is $%.2f\n", quantity, total);
	
	return 0;
}


int chapter0303() {
	long test = 0L;

	printf("Enter an integer less than %ld\n", LONG_MAX);
	scanf_s("%ld", &test);

	if (test % 2L == 0) {
		printf("The number %ld is even.\n", test);
		if ((test / 2L) % 2L == 0) {
			printf("\nHalf of %ld is also even", test);
			printf("\nThat's interesting isn't it?\n");
		}
	} else {
		printf("The number %ld is odd\n", test);
	}
	
	return 0;
}

int chapter0304() {
	char letter = 0;

	printf("Enter an uppercase letter:");
	scanf_s("%c", &letter);

	if (letter >= 'A') {
		if (letter <= 'Z') {
			letter = letter - 'A' + 'a';
			printf("you entered an uppercase %c\n", letter);
		} else {
			printf("try using shift key! I want a chapital letter.\n");
		}
	}

	return 0;
}

int chapter0305() {
	char letter = 0;

	printf("Enter an uppercase letter:");
	scanf_s("%c", &letter);

	if ((letter >= 'A') && (letter <= 'Z')) {
		letter = letter - 'A' + 'a';
		printf("you entered an uppercase %c\n", letter);
	} else {
			printf("try using shift key! I want a chapital letter.\n");
	}

	return 0;
}

int chapter0306() {
	const double unit_price = 3.50;
	const double discount1 = 0.05;
	const double discount2 = 0.1;
	const double discount3 = 0.15;
	double total_price = 0.0;
	int quantity = 0;

	printf("Enter the number you want to buy:");
	scanf_s(" %d", &quantity);

	total_price = quantity * unit_price * (1.0 - (quantity > 50 ? discount3 : (quantity > 20 ? discount2 : (quantity > 10 ? discount1 : 0.0))));
	printf("The price for %d is $%.2f\n", quantity, total_price);

	return 0;
}


int chapter0307() {
	int age = 0;
	int college = 0;
	int subject = 0;
	bool interview = false;

	printf("\nwhat college? 1 for H, 2 for Y, 3 for other:");
	scanf_s("%d", &college);

	printf("\nwhat subject? 1 for C, 2 for E, 3 for other:");
	scanf_s("%d", &subject);

	printf("\nhow old is the applicant?");
	scanf_s("%d", &age);

	if ((age > 25 && subject == 1) && (college == 3 || college == 1)) {
		interview = true;
	}
	if (college == 2 && subject == 1) {
		interview = true;
	}
	if (college == 1 && subject == 2 && !(age > 28)) {
		interview = true;
	}
	if (college == 2 && (subject == 2 || subject == 3) && age > 25) {
		interview = true;
	}

	if (interview) {
		printf("\nGive' em an interview\n");
	} else {
		printf("\nReject'em\n");
	}

	return 0;
}

int chapter0308() {
	int choice = 0;

	printf("Pick a number between 1 and 10 and you may win a peize!\n");
	scanf_s("%d", &choice);

	if ((choice > 10) || (choice < 1)) {
		choice = 11;
	}
	switch (choice) {
		case 7:
			printf("Entered 7");
			break;
		case 6:
			printf("Entered 6");
			break;
		default:
			printf("sorroy you lose!");
			break;
	}
	return 0;
}

int chapter0309() {
	char answer = 0;
	
	printf("enter Y or N: ");
	scanf_s(" %c", &answer);

	switch (answer) {
		case 'Y': case 'y':
			printf("you responed in the affirmative.\n");
			break;
		case 'N': case 'n':
			printf("you responed in the negative.\n");
			break;
		default:
			printf("you not correctly.\n");
			break;
	}

	return 0;
}

int chapter0310() {
	unsigned int original = 0xABC;
	unsigned int result = 0;
	unsigned int mask = 0xF;

	printf("\n original = %X", original);

	result |= original & mask;

	original >>= 4;
	result <<= 4;
	result |= original & mask;

	original >>= 4;
	result <<= 4;
	result |= original & mask;

	printf("\t result = %X\n", result);

	return 0;
}

//TODO: 有点问题 
int chapter0311() {
	double number1 = 0.0;
	double number2 = 0.0;
	char operation = 0;

	printf("\nEnter the calculation\n");
	scanf_s("%lf %c %lf", &number1, &operation, &number2);

	switch (operation) {
		case '+':
			printf(" = %lf", number1 + number2);
			break;
		case '-':
			printf(" = %lf", number1 - number2);
			break;
		case '*':
			printf(" = %lf", number1 * number2);
			break;
		case '/':
			if (number2 == 0) {
				printf("\nDivision by zero error!\n");
			} else {
				printf(" = %lf", number1 / number2);
			}
			break;
		case '%':
			if ((long) number2 == 0) {
				printf("\nDivision by zero error!\n");
			} else {
				printf(" = %ld", (long) number1 % (long) number2);
			}
			break;
		default:
			printf("ILLegal operation");
			break;
	}
	return 0;
}

int main() {
//	chapter0301();
//	chapter0302();
//	chapter0303();
//	chapter0304();
//	chapter0305();
//	chapter0306();
//	chapter0307();
//	chapter0308();
//	chapter0309();
//	chapter0310();
	chapter0311();
}

