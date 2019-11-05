//ū Ʋ�� �ۼ��߽��ϴ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//PC, IR�� ���������� ����
unsigned int PC, IR;

//simulator command�� ���� �Լ���
void loadInst(char* fname);
void jumpInst(char* start);
void goInst(void);
void stepInst(void);
void viewMemoryInst(char* start, char* end);
void viewRegisterInst(void);
void exitInst(void);
void srInst(char* regNum, char* value);
void smInst(char* location, char* value);
//�׿�
void ALU(int X, int Y, int C, int* Z);	//ALU�Լ�
void setPC(int a);	//PC ���� �Լ�

void main(void) {
	while (1) {
		//1. ��ɾ �Է¹޴´�
		char inst1[2] = { 0, }; //(ù��° �Է�) command
		char* inst2 = (unsigned char*)malloc(sizeof(unsigned char) * 20); //(�ι�° �Է�) l, j, m, sr, sm���� ���
		char* inst3 = (unsigned char*)malloc(sizeof(unsigned char) * 33); //(����° �Է�) sr, sm���� ���

		printf("����� �Է��ϼ���: ");
		scanf("%s %s %s", inst1, inst2, inst3);

		//2. command ����
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
	int size;	//��ü ũ��
	int DATAsize;	//������ ����
	int INSTsize;	//��ɾ� ����

	MEM = (unsigned char*)malloc(sizeof(unsigned char));

	//1. ���� �б�
	err = fopen_s(&pFile, fname, "rb");
	if (err) {
		printf("Cannot open file\n");
		return 1;
	}

	fseek(pFile, 0, SEEK_END);    // ���� �����͸� ������ ������ �̵���Ŵ
	size = ftell(pFile);          // ���� �������� ���� ��ġ�� ����
	fseek(pFile, 0, SEEK_SET);   // ���� �����͸� ������ ó������ �̵���Ŵ

	fread(MEM, 2, size, pFile);

	//2. �޸𸮿� �����Ͱ� ���� ��� �ִ��� Ȯ��
	for (int i = 0; i < 8; i++) {
		INSTsize += 2 * i * MEM[i];
	}
	for (int i = 9; i < 17; i++) {
		DATAsize += 2 * i * MEM[i];
	}

	//3. �޸𸮿� ����(�޸� �����Ǹ� �ۼ�)
	for (int i = 0; i < INSTsize * 4; i++) {
		//��ɾ� �޸𸮿� ����
	}
	for (int i = 0; i < DATAsize * 4; i++) {
		//������ �޸𸮿� ����
	}

	//4. �����ڵ� ���
}

void jumpInst(char* start) {
	//�޸� �����Ǹ� �ۼ�
	PC = start;
}

void goInst(void) {
	unsigned char start = PC;

	while (1) {
		//syscall 10�� ������ break
		if () {};

		//1. ��ɾ� ���ڵ�
		//2. ���ڵ��� ��ɾ ���� ����
	}

}
void stepInst(void) {
	//1. PC�� �̵�(PC���� ���� ������ ��ɾ��� �ּҰ� ����ִ�)
	unsigned char* start = PC;
	//2. PC�� �ִ� ��ɾ� �ּҷ� ���� ��ɾ� �ҷ�����
	unsigned char inst[33] = start;
	//3. ��ɾ �������� decode

	//4. ��ɾ� ����

	//5. PC += 1

}
void viewMemoryInst(char* start, char* end) {
	//��ɾ� ���
}
void viewRegisterInst(void) {
	//�������� ��� �Լ�(Register = �������� �迭)
	for (int i = 0; i < (sizeof(Register) / sizeof(Register[0])); i++) {
		printf("Register[");
		printf(i);
		printf("]: ");
		printf(Register[i]);
		printf("\n");
	}
}
void exitInst(void) {
	//���α׷� ����
	exit(1);
}
void srInst(char* regNum, char* value) {
	//Ư�� �������� �� ����
	Register[regNum] = value;
}
void smInst(char* location, char* value) {
	//Ư�� �޸� �� ����
	DataMEM[location] = value;
}

void ALU(int X, int Y, int C, int* Z) {	//���� ���� �ʿ�
	//PC ����
	setPC(1);

	//�Ϲݿ���(add)
	*Z = X + Y;

	//immediate value�� ���� ����(slti)
	if (X < C) {
		*Z = 1;
	}
	else {
		*Z = 0;
	}

	//data memory�� ����ϴ� ����(sw, lw)
	//sw
	X = C; //???
}

void setPC(int a) {
	//PC ����
	//a�� 1�϶� �����Ѵ�
	if (a == 1) {
		PC += 4;
	}
	else {
		PC -= 4;
	}
}