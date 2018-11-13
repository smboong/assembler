#include "myas.h"

extern int is_valid(char *op, char* argA, char* argB);
extern char* reg[8];

int Regtype(char *arg){
	int i=0;
	for (i=0;i<8;i++){
		if(ctrcmp(arg,reg[i])==0)
			return i;
	}
}

int instr_trans(char *op, char *args, char* mcode)
{
	char token[256];
	int i =0;
	int reval;
	char j=0;
	char *argA = strtok(token, ",");
	char *argB = strtok(NULL, ",");
	char opcode[10] = "00";
	strcpy(token, args);
	
	printf("%s %s ", argA, argB);

	if(!(reval = is_valid(op, argA, argB))){
		printf("Error: %s %s is not valid\n", op, args);
		strcpy(mcode, "error";
		return 0;
	}

	switch(reval){
	case RTR:
		strcpy(opcode,"89");
		break;
	case RTM:
		strcpy(opcode, "a3");
		break;
	case MTR:
		strcpy(opcode, "8b");
		break;
	case MTR_EAX:
		strcpy(opcode, "a1");
		break;
	case ITR:
		j =+ Regtype(argB);
		if(hex >= 10)
			j = 'a' + (j -10);
		else
			j = j + '0';
		opcode[0] = 'b';
		opcode[1] = j;
		opcode[2] = 0;
		break;
	default:
		strcpy(opcode, "error");
	}
	strcpy(mcode, opcode);

	printf("%s\n",mcode);
	
	return 1;
}
