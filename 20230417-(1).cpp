#include<stdio.h>

int plus(int a, int b);
int minus(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int div(int a, int b, int c);
float div(float a, float b);

int main() {
	int resultA = 0, resultB = 0, resultC = 0, a = 0, b =0;
	float resultD = 0;
	scanf("%d %d", &a, &b);
	resultD = (float)div(a, b);
	printf("%f", (float)resultD);
	
	return 0;
}

int plus(int a, int b) {
	return a + b;
}

int minus(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int div(int a, int b) {
	int a / b;
}

int div(int a, int b, int c) {
	int a / b / c;
}

float div(float a, float b) {
	return a / b;
}
