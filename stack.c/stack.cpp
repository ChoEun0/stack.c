#include <stdio.h>
#include <stdlib.h>
// 구조체 선언 -> 초기화 -> 상태확인 -> 더하기 빼기 -> 현상태 확인
#define SIZE 5

typedef struct Stack {
	int data[SIZE];
	int top;
}Stack;


void init_Stack(Stack* s) {
	s->top = -1;
}

int empty_check(Stack* s) {
	if (s->top == -1) return 1;
	else return 0;
}

int full_check(Stack* s) {
	if (s->top == SIZE - 1) return 1;
	else return 0;
}

void add(Stack* s, int n) {
	if (full_check(s)) {
		printf("더 이상 입력할 수 없습니다");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = n;
	}
}

int get(Stack* s) {
	if (empty_check(s)) {
		printf("오류발생. 스택이 비어있음. 프로그램을 종료합니다.");
		exit(1);
	}
	else {
		return s->data[s->top--];
	}
}

int peek(Stack* s) {
	if (empty_check(s)) {
		printf("오류발생. 스택이 비어있음. 프로그램을 종료합니다.");
		exit(1);
	}
	else{
		return s->data[s->top];
	}
}

int main() {
	Stack s;
	init_Stack(&s);
	int number;
	printf("숫자를 5개 입력하세요.\n");
	for (int i = 0; i < 5; i++) {
		scanf_s("%d\n", &number);
	}
	add(&s, number);
	printf("%d\n", get(&s));

}