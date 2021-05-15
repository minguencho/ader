#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef char element;

typedef struct {
	element* data;
	int top;
	int size;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->size = 1;
	s->data = (element*)malloc(100);
}

void push(StackType* s, element* item) {
	s->data[++(s->top)] = *item;	//마지막에 요소 추가
}

element pop(StackType* s) {
	if (s->top == -1) {
		return 0;
	}
	else
		return (s->data[(s->top)--]);
}

int main(void) {
	StackType Stack;
	char ch[50] = { 0, };
	int k = 0;
	int x = 0;
	scanf("%d", &x);

	for (int j = 0; j < x; j++) {
		init_stack(&Stack);
		scanf("%s", ch);
		for (int i = 0; i < sizeof(ch) / sizeof(char); i++) {
			switch (ch[i]) {
			case '(':
				push(&Stack, &ch[i]); // 스택에 추가
				break;

			case ')':
				k = pop(&Stack);	//스택에서 pop
				break;
			}
		}
		if (k == 0 || Stack.top != -1) {	//k가 0이거나 stack이 공백이 아니면 no
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}


}
