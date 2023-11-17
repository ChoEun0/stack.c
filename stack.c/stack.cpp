#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// 구조체 선언 -> 초기화 -> 상태확인 -> 더하기 빼기 -> 현상태 확인


typedef struct Stack {
	int size;
	int top;
	int* array;
}Stack;

Stack* createStack(int size) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	if (!s) return NULL;

	s->size = size;
	s->top = -1;
	s->array = (int*)malloc(s->size * sizeof(int));
	return s;
}


int empty_check(Stack* s) {
	return (s->top == -1);
}

int full_check(Stack* s) {
	return (s->top == s->size -1);
}

void add(struct Stack *s, int n) {
	if (full_check(s)) {
		s->size *= 2;
		s->array = (int*)realloc(s->array, s->size);
		printf("2배로 늘리기\n");

	}
	else {
		s->top++;
		s->array[s->top] = n;
		printf("%d push to stack\n", n);
	}
}

int get(Stack* s) {
	if (empty_check(s)) {
		printf("오류발생. 스택이 비어있음. 프로그램을 종료합니다.\n");
		exit(1);
	}
	else {
		return s->array[s->top--];
	}
}

int peek(Stack* s) {
	if (empty_check(s)) {
		printf("오류발생. 스택이 비어있음. 프로그램을 종료합니다.\n");
		exit(1);
	}
	else{
		return s->array[s->top];
	}
}

int main() {
	Stack* s = createStack(3);
	
	add(s, 1);
	add(s, 2);
	add(s, 3);
	add(s, 4);

	printf("%d pop from stack\n", get(s));

}