#include "pch.h"
#include <stdio.h>
#include <limits.h>

#define PI	3.14159f

int chapter0202() {
	int salary;
	salary = 10000;
	printf("His salary is %d.\n", salary);
	return 0;
}

int chapter0203() {
	int brothers;
	int brides;

	brothers = 7;
	brides = 7;

	printf("%d brides for %d brothers\n", brides, brothers);
	return 0;
}

int chapter0204() {
	int total_pets;
	int cats;
	int dogs;
	int poines;
	int others;

	cats = 10;
	dogs = 3;
	poines = 4;
	others = 19;

	total_pets = cats + dogs + poines + others;

	printf("We have %d pets in total\n", total_pets);

	return 0;
}


int chapter0205() {
	int cookies = 5;
	int cookie_calories = 125;

	int total_eaten = 0;

	int eaten = 2;

	cookies = cookies - eaten;
	total_eaten = total_eaten + eaten;
	printf("\nI have eaten %d cookies. There are %d cookies left.", eaten, cookies);

	eaten = 3;
	cookies = cookies - eaten;
	total_eaten = total_eaten + eaten;
	printf("\nI have eaten %d more.Now threre are %d cookies left.\n", eaten, cookies);
	printf("\nTotal energy consumed is %d calories.\n", total_eaten * cookie_calories);

	return 0;
}

int chapter0206() {
	int cookies = 45;
	int children = 7;
	int cookies_pre_child = 0;
	int cookies_left_over = 0;

	cookies_pre_child = cookies / children;
	cookies_left_over = cookies % children;

	printf("You have %d children and %d cookies\n", children, cookies);
	printf("Give each child %d cookies.\n", cookies_pre_child);
	printf("There are %d cookies left over.\n", cookies_left_over);

	return 0;
}


int chapter0207() {
	float plank_length = 10.0f;
	float piece_count = 4.0f;
	float piece_length = 0.0f;

	piece_length = plank_length / piece_count;

	printf("A plank %.2f feet long can be cut into %.0f pieces %.2f feet long.\n", plank_length, piece_count, piece_length);

	return 0;
}

int chapter0208() {
	float radius = 0.0f;
	float diameter = 0.0f;
	float circumference = 0.0f;
	float area = 0.0f;
	float Pi = 3.14159265f;

	printf("Input the diameter of the table: ");
	scanf_s("%f", &diameter);
	
	radius = diameter / 2.0f;
	circumference = 2.0f * Pi * radius;
	area = Pi * radius * radius;

	printf("\nThe circumference is %.2f", circumference);
	printf("\nThe area is %.2f\n", area);

	return 0;
}

int chapter0209() {
	float radius = 0.0f;
	float diameter = 0.0f;
	float circumference = 0.0f;
	float area = 0.0f;

	printf("Input the diameter of the table: ");
	scanf_s("%f", &diameter);

	radius = diameter / 2.0f;
	circumference = 2.0f * PI * radius;
	area = PI * radius * radius;

	printf("\nThe circumference is %.2f", circumference);
	printf("\nThe area is %.2f\n", area);

	return 0;
}

int chapter0210() {
	float radius = 0.0f;
	float diameter = 0.0f;
	const float Pi = 3.14159f;

	printf("Input the diameter of the table: ");
	scanf_s("%f", &diameter);

	radius = diameter / 2.0f;

	printf("\nThe circumference is %.2f", 2.0f * PI * radius);
	printf("\nThe area is %.2f\n", PI * radius * radius);

	return 0;
}

int chapter0211() {
	printf("\nchar : %d - %d", CHAR_MIN, CHAR_MAX);
	printf("\nunsigned char : [0, %u]", UCHAR_MAX);
	printf("\nshort : [%d, %d]", SHRT_MIN, SHRT_MAX);
	printf("\nunsigned short : [0, %u]", USHRT_MAX);
	printf("\nint : [%d, %d]", INT_MIN, INT_MAX);
	printf("\nunsigned int : [0, %u]", UINT_MAX);
	printf("\nlong : [%ld, %ld]", LONG_MIN, LONG_MAX);
	printf("\nunsigned long : [0, %lu]", ULLONG_MAX);
	printf("\nlong : [%lld, %lld]", LLONG_MIN, LLONG_MAX);
	printf("\nunsigned long : [0, %llu]", ULLONG_MAX);

	return 0;
}

int chapter0212() {
	printf("\nchar[%u]", sizeof(char));
	printf("\nshort[%u]", sizeof(short));
	printf("\nint[%u]", sizeof(int));
	printf("\nlong[%u]", sizeof(long));
	printf("\nlong long[%u]", sizeof(long long));
	printf("\nfloat[%u]", sizeof(float));
	printf("\ndouble[%u]", sizeof(double));
	printf("\nlong double[%u]", sizeof(long double));
	return 0;
}

int chapter0213() {
	const float Revenu_Per_150 = 4.5f;

	short JanSold = 23500;
	short FebSold = 19300;
	short MarSold = 21600;

	float RevQuarter = 0.0f;

	unsigned long QuarterSold = JanSold + FebSold + MarSold;

	printf("Stock sold in \n Jan: %d.\n Feb: %d.\n Mar: %d\n", JanSold, FebSold, MarSold);
	printf("Total stock sold in first quarter: %d\n", QuarterSold);

	RevQuarter = QuarterSold * Revenu_Per_150 / 150;
	printf("Sales revenus this quarter is: $%.2f\n", RevQuarter);

	return 0;
}

int chapter0215() {
	char first = 'T';
	char second = 63;

	printf("first - %c\n", first);
	printf("first - %d\n", first);
	printf("second - %c\n", second);
	printf("second - %d\n", second);

	return 0;
}

int chapter0216() {
	char first = 'A';
	char second = 'B';
	char last = 'Z';

	char number = 40;

	char ex1 = first + 2;
	char ex2 = second - 1;
	char ex3 = last + 2;

	printf("Character value %-5c%-5c%-5c\n", ex1, ex2, ex3);
	printf("Character number value %-5d%-5d%-5d\n", ex1, ex2, ex3);
	printf("Number %d is code for character %c\n", number, number);

	return 0;
}



int main() {
//	chapter0202();
//	chapter0203();
//	chapter0204();
//	chapter0205();
//	chapter0206();
//	chapter0207();
//	chapter0208(); 
//	chapter0209();
//	chapter0210();
//	chapter0211();
//	chapter0212();
//	chapter0213();
//	chapter0215();
	chapter0216();
}
