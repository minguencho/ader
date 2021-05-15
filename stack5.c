#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _stack {
	int top;
	int* arr;
} StackType;

void StackInit(StackType* s) {
	s->top = -1;
	s->arr = malloc(sizeof(int) * 100);	//배열의 크기를 할당받음.
}

void Push(StackType* s, int data) {
	s->top++;
	s->arr[s->top] = data;
}

int Pop(StackType* s) {
	int data = s->arr[s->top];
	s->top--;

	return data;
}

int big(StackType* s) {
	int x, data;
	int target = Pop(s);
	x = s->top;

	while (1) {

		if (s->top == -1) {		//공백이면 -1 을 반환.(오큰수가 없다)
			s->top = x;
			return -1;
		}
			
		data = s->arr[s->top];	//data는 배열의 top의 노드값.

		if (target < data) {	//pop한 수보다 data가 크면 값을 반환해줌.
			s->top = x;
			return data;
		}

		s->top--;				//top을 하나 줄여줌.

	}

}

int main(void) {
	int l, * arr;
	StackType stack;
	StackInit(&stack);
	scanf("%d", &l);					//배열의 크기를 입력받음.

	arr = malloc(sizeof(int) * l);

	for (int i = 0; i < l; i++)			// 배열에 넣을 수를 입력받는다.
		scanf("%d", &arr[i]);

	for (int i = l - 1; i >= 0; i--)	// 배열에서 입력 받은 수를 push
		Push(&stack, arr[i]);

	for (int i = 0; i < l; i++) {		// big함수에서 얻은 값을 출력.
		printf("%d ", big(&stack));
	}

	free(arr);							//동적 할당받은 배열 반환.
	free(stack.arr);					//스택 반환.

	return 0;
}
