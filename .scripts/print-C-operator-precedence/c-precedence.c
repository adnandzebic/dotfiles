#include <stdio.h>
#include <string.h>

// reference: https://en.cppreference.com/w/c/language/operator_precedence

void run(void);
void usage(char prog[]);
void version(void);
void black(void);
void red(void);
void green(void);
void yellow(void);
void blue(void);
void purple(void);
void cyan(void);
void white(void);
void reset(void);

int main(int argc, char *argv[]) {
	if (argc == 1) {
		run();
	} else if (argc == 2) {
		if (!strcmp(argv[1], "--version"))
			version();
		else
			usage(argv[0]);
	} else {
		usage(argv[0]);
	}

	return 0;
}

void run(void) {
	white();
	printf("==========================================================================================\n");
	printf("%-12s%-15s%-50s%-15s\n", "Precedence", "Operator", "Description", "Associativity");
	printf("==========================================================================================\n");
	green();
	printf("%-12s%-15s%-50s%-15s\n", "", "++ --", "Suffix/postfix increment and decrement", "Left-to-right");
	printf("%-12s%-15s%-50s%-15s\n", "", "()", "Function call", "");
	printf("%6s%6s%-15s%-50s%-15s\n", "1", "", "[]", "Array subscripting", "");
	printf("%-12s%-15s%-50s%-15s\n", "", ".", "Structure and union member access", "");
	printf("%-12s%-15s%-50s%-15s\n", "", "->", "Structure and union member access through pointer", "");
	printf("%-12s%-15s%-50s%-15s\n", "", "(type){list}", "Compound literal (C99)", "");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	cyan();
	printf("%-12s%-15s%-50s%-15s\n", "", "++ --", "Prefix increment and decrement", "Right-to-left");
	printf("%-12s%-15s%-50s%-15s\n", "", "+ -", "Unary plus and minus", "");
	printf("%-12s%-15s%-50s%-15s\n", "", "! ~", "Logical NOT and bitwise NOT", "");
	printf("%6s%6s%-15s%-50s%-15s\n", "2", "", "(type)", "Cast", "");
	printf("%-12s%-15s%-50s%-15s\n", "", "*", "Indirection (dereference)", "");
	printf("%-12s%-15s%-50s%-15s\n", "", "&", "Address-of", "");
	printf("%-12s%-15s%-50s%-15s\n", "", "sizeof", "Size-of", "");
	printf("%-12s%-15s%-50s%-15s\n", "", "_Alignof", "Alignment requirement (C11)", "");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	green();
	printf("%6s%6s%-15s%-50s%-15s\n", "3", "", "* / %", "Multiplication, division, and remainder", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	cyan();
	printf("%6s%6s%-15s%-50s%-15s\n", "4", "", "+ -", "Addition and subtraction", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	green();
	printf("%6s%6s%-15s%-50s%-15s\n", "5", "", "<< >>", "Bitwise left shift and right shift", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	cyan();
	printf("%6s%6s%-15s%-50s%-15s\n", "6", "", "< <=", "For relational operators < and <= respectively", "Left-to-right");
	printf("%12s%-15s%-50s%-15s\n", "", "> >=", "For relational operators > and >= respectively", "");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	green();
	printf("%6s%6s%-15s%-50s%-15s\n", "7", "", "== !=", "For relational == and != respectively", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	cyan();
	printf("%6s%6s%-15s%-50s%-15s\n", "8", "", "&", "Bitwise AND", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	green();
	printf("%6s%6s%-15s%-50s%-15s\n", "9", "", "^", "Bitwise XOR (exclusive or)", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	cyan();
	printf("%6s%6s%-15s%-50s%-15s\n", "10", "", "|", "Bitwise OR", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	green();
	printf("%6s%6s%-15s%-50s%-15s\n", "11", "", "&&", "Logical AND", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	cyan();
	printf("%6s%6s%-15s%-50s%-15s\n", "12", "", "||", "Logical OR", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	green();
	printf("%6s%6s%-15s%-50s%-15s\n", "13", "", "?:", "Ternary conditional", "Right-to-left");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	cyan();
	printf("%-12s%-15s%-50s%-15s\n", "", "=", "Simple assignment", "Right-to-left");
	printf("%-12s%-15s%-50s%-15s\n", "", "+= -=", "Assignment by sum and difference", "Right-to-left");
	printf("%6s%6s%-15s%-50s%-15s\n", "14", "", "*= /= %=", "Assignment by product, quotient, and remainder", "Right-to-left");
	printf("%-12s%-15s%-50s%-15s\n", "", "<<= >>=", "Assignment by bitwise left shift and right shift", "Right-to-left");
	printf("%-12s%-15s%-50s%-15s\n", "", "&= ^= |=", "Assignment by AND, XOR, and OR", "Right-to-left");
	white();
	printf("------------------------------------------------------------------------------------------\n");
	green();
	printf("%6s%6s%-15s%-50s%-15s\n", "15", "", ",", "Comma", "Left-to-right");
	white();
	printf("------------------------------------------------------------------------------------------\n");
}

void usage(char prog[]) {
	printf("Usage: %s\n", prog);
}

void version(void) {
	printf("Version: 0.0.1\n");
}
void black(void) {
  printf("\033[0;30m");
}

void red(void) {
  printf("\033[0;31m");
}

void green(void) {
  printf("\033[0;32m");
}

void yellow(void) {
  printf("\033[0;33m");
}

void blue(void) {
  printf("\033[0;34m");
}

void purple(void) {
  printf("\033[0;35m");
}

void cyan(void) {
  printf("\033[0;36m");
}

void white(void) {
  printf("\033[0;37m");
}

void reset(void) {
  printf("\033[0m");
}
