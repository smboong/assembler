#include "myas.h"

//trans.c
char* Reg[8] = { "%eax","%ecx","%edx","%ebx","%esp","%ebp","%esi","%edi"};
extern int is_valid(char *op,char* argF,char* argB);
extern int Check_kind(char *Sen);

int RegCheck(char *regK){
        int i=0;
        for (i=0;i<8;i++){
                if(strcmp(regK,Reg[i])==0)
                        return i;
        }
	return 100;
}


int instr_trans(char *op, char *args, char* mcode)
{
	char Word[256];
	char opcode[10] = "00";
	strcpy(Word,args);
	char *argF = strtok(Word, ",");
	char *argB = strtok(NULL, ",");
	int Kind1 = Check_kind(argF);
	int Kind2 = Check_kind(argB);
	char ITR;

	if(is_valid(op,argF,argB)==0){
		printf("Error: %s %s is not valid\n",op,args);
		strcpy(mcode,"err");
		return 0;
	}
	else{
		if((Kind1==4) && (Kind2==4))
			strcpy(opcode,"89");
		else if((RegCheck(argF)==0) && (Kind2==3))
			strcpy(opcode,"a3");
		else if((Kind1==3) && (Kind2==4))
			strcpy(opcode,"8b");
		else if((Kind1==3) && (RegCheck(argB)==0))
			strcpy(opcode,"a1");
		else if((Kind1==2) && (Kind2==4)){
			ITR = RegCheck(argB);
			if(ITR==0)
				strcpy(opcode,"b8");
			else if(ITR==1)
				strcpy(opcode,"b9");
			else if(ITR==2)
				strcpy(opcode,"ba");
			else if(ITR==3)
				strcpy(opcode,"bb");
			else if(ITR==4)
				strcpy(opcode,"bc");
			else if(ITR==5)
				strcpy(opcode,"bd");
			else if(ITR==6)
				strcpy(opcode,"be");
			else
				strcpy(opcode,"bf");
			}
		else
			strcpy(opcode,"err");
	}
	strcpy(mcode, opcode);

	printf("%s\n",mcode);
	return 1;
}
