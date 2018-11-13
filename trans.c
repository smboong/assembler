#include "myas.h"

extern int is_valid(char *op, char* argA, char* argB);
extern char* Reg[8];

int Regtype(char *arg){
	int i=0;
	for (i=0;i<8;i++){
		if(strcmp(arg,Reg[i])==0)
			return i;
	}
}

int instr_trans(char *op, char *args, char* mcode)
{
	char token[256];
	int reval;
	char j=8;
	char *argx = strtok(token, ",");
	char *argy = strtok(NULL, ",");
	char code[10] = "00";
	strcpy(token, args);
	
	printf("%s %s ", argx, argy);

	if(!(reval = is_valid(op, argx, argy))){
		printf("Error: %s %s is not valid\n", op, args);
		strcpy(mcode, "error");
		return 0;
	}

	if(reval == 5)
		strcpy(code,"89");
	else if(reval == 6)
		strcpy(code, "8b");
	else if(reval == 7)
		strcpy(code, "a1");
	else if(reval == 8)
		strcpy(code, "a3");
	else if(reval == 9){
		j = j + Regtype(argy);
		if(j >= 10){
			j=j-10;
			j='a'+j;
		}
		else
			j=j+'0';

		code[0]='b';
		code[1]=j;
		code[2]=0;
	}
	else{
		strcpy(code,"error");
	}
	strcpy(mcode, code);
	printf("%s\n",mcode);
	
	return 1;
}
