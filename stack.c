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
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else --count;
		return stack[top--];
}
//스택에 들어있는 정수의 개수 출력
void size(count) {
	printf("size : %d\n", count);
}
int main(void)
{
	int data;
	int i = -1;
	printf("select 1.push  2.pop  3.size\n");
	while (i !=4) {
		scanf("%d", &i);
		switch (i) {
		case 1:
			printf("push\n");
			scanf("%d", &data);
			push(data);
			printf("push : %d\n", data);
			break;
		case 2:
			printf("pop\n");
			printf("pop : %d\n", pop());
			break;
		case 3:
			printf("size\n");
			size(count);
			break;
		default:
			printf("out of the menu\n");
			continue;
		}
	}
	
	return 0;
}
