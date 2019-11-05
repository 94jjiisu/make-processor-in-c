//큰 틀만 작성했습니다

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//PC, IR을 전역변수로 설정
unsigned int PC, IR;

//simulator command에 따른 함수들
void loadInst(char* fname);
void jumpInst(char* start);
void goInst(void);
void stepInst(void);
void viewMemoryInst(char* start, char* end);
void viewRegisterInst(void);
void exitInst(void);
void srInst(char* regNum, char* value);
void smInst(char* location, char* value);
//그외
void ALU(int X, int Y, int C, int* Z);	//ALU함수
void setPC(int a);	//PC 갱신 함수

void main(void) {
	while (1) {
		//1. 명령어를 입력받는다
		char inst1[2] = { 0, }; //(첫번째 입력) command
		char* inst2 = (unsigned char*)malloc(sizeof(unsigned char) * 20); //(두번째 입력) l, j, m, sr, sm에서 사용
		char* inst3 = (unsigned char*)malloc(sizeof(unsigned char) * 33); //(세번째 입력) sr, sm에서 사용

		printf("명령을 입력하세요: ");
		scanf("%s %s %s", inst1, inst2, inst3);

		//2. command 실행
		switch (inst1[0]) {
		case 'l':
			loadInst(inst2);
		case 'j':
			jumpInst(inst2);
		case 'g':
			goInst();
		case 's':
			stepInst();
		case 'm':
			viewMemoryInst(inst2, inst3);
		case 'r':
			viewRegisterInst();
		case 'x':
			exitInst();
		case 'sr':
			srInst(inst2, inst3);
		case 'sm':
			smInst(inst2, inst3);

		}
	}
}

void loadInst(char* fname) {
	FILE* pFile = NULL;
	errno_t err;
	unsigned char* MEM;
	int size;	//전체 크기
	int DATAsize;	//데이터 갯수
	int INSTsize;	//명령어 갯수

	MEM = (unsigned char*)malloc(sizeof(unsigned char));

	//1. 파일 읽기
	err = fopen_s(&pFile, fname, "rb");
	if (err) {
		printf("Cannot open file\n");
		return 1;
	}

	fseek(pFile, 0, SEEK_END);    // 파일 포인터를 파일의 끝으로 이동시킴
	size = ftell(pFile);          // 파일 포인터의 현재 위치를 얻음
	fseek(pFile, 0, SEEK_SET);   // 파일 포인터를 파일의 처음으로 이동시킴

	fread(MEM, 2, size, pFile);

	//2. 메모리와 데이터가 각각 몇개씩 있는지 확인
	for (int i = 0; i < 8; i++) {
		INSTsize += 2 * i * MEM[i];
	}
	for (int i = 9; i < 17; i++) {
		DATAsize += 2 * i * MEM[i];
	}

	//3. 메모리에 저장(메모리 구현되면 작성)
	for (int i = 0; i < INSTsize * 4; i++) {
		//명령어 메모리에 저장
	}
	for (int i = 0; i < DATAsize * 4; i++) {
		//데이터 메모리에 저장
	}

	//4. 이진코드 출력
}

void jumpInst(char* start) {
	//메모리 구현되면 작성
	PC = start;
}

void goInst(void) {
	unsigned char start = PC;

	while (1) {
		//syscall 10을 만나면 break
		if () {};

		//1. 명령어 디코딩
		//2. 디코딩한 명령어에 따라 실행
	}

}
void stepInst(void) {
	//1. PC로 이동(PC에는 직후 실행할 명령어의 주소가 들어있다)
	unsigned char* start = PC;
	//2. PC에 있는 명령어 주소로 가서 명령어 불러오기
	unsigned char inst[33] = start;
	//3. 명령어가 무엇인지 decode

	//4. 명령어 실행

	//5. PC += 1

}
void viewMemoryInst(char* start, char* end) {
	//명령어 출력
}
void viewRegisterInst(void) {
	//레지스터 출력 함수(Register = 레지스터 배열)
	for (int i = 0; i < (sizeof(Register) / sizeof(Register[0])); i++) {
		printf("Register[");
		printf(i);
		printf("]: ");
		printf(Register[i]);
		printf("\n");
	}
}
void exitInst(void) {
	//프로그램 종료
	exit(1);
}
void srInst(char* regNum, char* value) {
	//특정 레지스터 값 설정
	Register[regNum] = value;
}
void smInst(char* location, char* value) {
	//특정 메모리 값 설정
	DataMEM[location] = value;
}

void ALU(int X, int Y, int C, int* Z) {	//인자 수정 필요
	//PC 갱신
	setPC(1);

	//일반연산(add)
	*Z = X + Y;

	//immediate value가 들어가는 연산(slti)
	if (X < C) {
		*Z = 1;
	}
	else {
		*Z = 0;
	}

	//data memory를 사용하는 연산(sw, lw)
	//sw
	X = C; //???
}

void setPC(int a) {
	//PC 갱신
	//a가 1일때 갱신한다
	if (a == 1) {
		PC += 4;
	}
	else {
		PC -= 4;
	}
}