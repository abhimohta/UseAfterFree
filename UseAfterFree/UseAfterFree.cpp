// UseAfterFree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _A {
	int *f;
} A;

void WorseStruc(A *y) {
	*(y->f) = 1;
	printf("%d", *(y->f));
}

void BadStruc() {
	A *y = (A *)malloc(sizeof(A));
	free(y);
	WorseStruc(y);

}

int main()
{
	BadStruc();
	return 0;
}

