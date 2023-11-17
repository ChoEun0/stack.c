#include <stdio.h>
#include <stdlib.h>
// ����ü ���� -> �ʱ�ȭ -> ����Ȯ�� -> ���ϱ� ���� -> ������ Ȯ��
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
		printf("�� �̻� �Է��� �� �����ϴ�");
		return;
	}
	else {
		s->top++;
		s->data[s->top] = n;
	}
}

int get(Stack* s) {
	if (empty_check(s)) {
		printf("�����߻�. ������ �������. ���α׷��� �����մϴ�.");
		exit(1);
	}
	else {
		return s->data[s->top--];
	}
}

int peek(Stack* s) {
	if (empty_check(s)) {
		printf("�����߻�. ������ �������. ���α׷��� �����մϴ�.");
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
	printf("���ڸ� 5�� �Է��ϼ���.\n");
	for (int i = 0; i < 5; i++) {
		scanf_s("%d\n", &number);
	}
	add(&s, number);
	printf("%d\n", get(&s));

}