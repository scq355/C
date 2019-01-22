#include "pch.h"
#include <stdio.h>

#define INCHES_PER_FOOT 12

int chapter0101() {
	printf("Hello world! \n");
	return 0;
}

int chapter0102() {
	printf("\"If at first you don't successed, try, try, try again!\"\n");
	return 0;
}

int chapter0103() { //函数chapter0103()
	printf("Beware the Ides of March!\n");
	return 0;
}

int chapter0104() {
	printf("My formula for success?\nRise early, work late, strike oil.\n");
	return 0;
}

int chapter0105() {
	printf("\"It is a wise father that knows his own child.\"\nShakespear\n");
	return 0;
}

int chapter0106() {
	printf("[Be careful!]\n\a");
	printf("What??!\n");
	return 0;
}

int chapter0107() {
	printf("There are %d includes in a foot.\n", INCHES_PER_FOOT);
	return 0;
}

/*	
 * 文档注释
*/
int main() {
	chapter0101(); // 调用chapter0101
	chapter0102(); // 调用chapter0102
	chapter0103();
	chapter0104();
	chapter0105();
	chapter0107();
	chapter0106();
}