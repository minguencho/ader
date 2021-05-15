#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 // 스택의 최대 크기
typedef int element; // 데이터의 자료형

element stack[MAX_STACK_SIZE]; // 1차원 배열
int count = 0;
int top = -1;

// 공백 상태 검출 함수
int is_empty()
{
	return (top == -1);
}
// 포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		stack[++top] = item;
		count++;
	}
}
// 삭제 함수
int pop()
{
	int k = stack[top];
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		--count;
		stack[top--];
		
	}
	return k;
}
//스택에 들어있는 정수의 개수 출력
void size(count) {
	printf("size : %d\n", count);
}
int main(void)
{
	int data;
	int i;
	int sum = 0;
	scanf("%d", &i); //i개의 줄에 정수가 1개씩 주어진다.
	for (int z = 0; z < i; z++) {
		scanf("%d", &data);
		if (data == 0) {
			printf("pop : %d \n", pop());
		}
		else {
			push(data);
			printf("push : %d\n", data);
		}
	}

	for (int i = 0; i <count; i++) {
		printf("%d/", stack[i]);
		sum = sum + stack[i];
		}
		printf(" sum : %d\n", sum);		
	return 0;
}
