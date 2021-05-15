#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 200
#include <stdio.h>
#include <string.h>

char stack[MAXSIZE] = { 0, };
int top = -1;

void init_stack() {    //스택 초기화 함수
    for (int i = 0; i < 101; i++) {
        stack[i] = 0;
    }
    top = -1;
}

void push(char data) {   //'(' 나 '[' push
    top++;
    stack[top] = data;
}

int pop(char data) {    //만약 top에 있는 괄호와 입력받은 괄호가 같으면 pop하고 1 리턴 , 아니면 0 
    if (top > -1) {
        if ((stack[top] == '[' && data == ']') || (stack[top] == '(' && data == ')')) {
            stack[top] = 0;
            top--;
            return 1;
        }
        else return 0;
    }
    else return 0;


}

int main(void) {
    while (1) {
        int result = 0;
        char arr[MAXSIZE] = { 0, };
        fgets(arr, sizeof(arr), stdin);   //문자열 입력

        if (arr[0] == '.') break; //문장에서 처음에 . 이나오면 바로 BREAK

        for (int i = 0; i < strlen(arr); i++) {    //문자열을 돌아가면서 ( 나  [ 를 찾고 PUSH.
            if (arr[i] == '(' || arr[i] == '[') {
                push(arr[i]);
            }
            else if (arr[i] == ')' || arr[i] == ']') {
                if (pop(arr[i]) == 0) { // 스택에 (이나 [이 없을 경우
                    result++;    
                }
            }
        }
        if (top == -1 && result == 0) {
            printf("yes\n");
        }
        if (top != -1 || result != 0) {
            printf("no\n");
        }
        init_stack();    //스택 초기화
    }

    return 0;
}
