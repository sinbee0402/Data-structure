#include <stdio.h>
#define SIZE 3

int TOP = -1; // stack의 맨 윗부분
char stack[3];

int Full() { // stack이 포화 상태인지 검사
    if (TOP >= SIZE - 1) { // TOP가 최대 크기와 같거나 클 경우
        // SIZE -1인 이유는 배열이 0번부터 시작하기 때문
        printf("Stack is Full.\n"); // stack이 가득 찼다고 출력
        return 1; // 1 반환(true)
    }
    return 0; // 그렇지 않을 경우 0 반환(false)
}

int Empty() { // stack이 공백 상태인지 검사
    if (TOP == -1) { // TOP가 -1인 경우
        // TOP == -1인 경우가 stack이 비었다는 의미
        printf("Stack is Empty.\n"); // stack이 공백이라고 출력
        return 1; // 1 반환(true)
    }
    return 0; // 그렇지 않을 경우 0 반환(false)
}

void push(data) { // data 하나를 스택의 가장 윗 부분에 추가
    if (!Full()) { // stack이 포화 상태가 아닐 경우
        TOP++; // top을 1 증가
        stack[TOP] = data; // stack[TOP]에 data 삽입
    }
}

char peek() { // stack의 가장 위에 있는 data 반환
    if (!Empty()) { // stack이 공백 상태가 아닐 경우
        return stack[TOP]; // stack의 맨 위 값을 반환
    }
}

char pop() { // stack에서 가장 위에 있는 data 제거
    if (!Empty()) { // stack이 공백 상태가 아닐 경우
        char temp = stack[TOP]; // TOP 원소를 임시 변수 temp에 저장
        TOP--; // TOP 변수 1 감소
        return temp; // temp 반환
    }
}

void printStack() { // stack의 모든 data를 출력
    if (!Empty()) { //stack이 공백 상태가 아닐 경우
        for (int i = 0; i <= TOP; i++) { //stack의 data를 출력하기 위해 for문 사용
            printf("%c", stack[i]); // stack[i]에 해당하는 data 출력
        }
        printf("\n");
    }
}

int main() {
    printStack();
    push('1');
    push('2');
    push('3');
    printStack();
    pop();
    push('4');
    push('5');
    push('6');
    push('7');
    printStack();
    pop();
    pop();
    printStack();
}