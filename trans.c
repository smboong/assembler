#include "myas.h"

//trans.c
extern int is_valid(char *op,char* argF,char* argB);
extern int Check_kind(char *Sen);
extern char* Reg[8];

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
	char ITR = 8;

	if(is_valid(op,argF,argB)==0){
		printf("Error: %s %s is not valid\n",op,args);
		strcpy(mcode,"err");
		return 0;
	}
	else{
		if((Kind1==4) && (Kind2==4))
			strcpy(opcode,"89");
		else if((RegCheck(Kind1)==0) && (Kind2==3))
			strcpy(opcode,"a3");
		else if((Kind1==3) && (Kind2==4))
			strcpy(opcode,"8b");
		else if((Kind1==3) && (RegCheck(Kind2)==0))
			strcpy(opcode,"a1");
		else if((Kind1==2) && (Kind2==4)){
			ITR += RegCheck(Kind2);
			if(ITR >= 10)
				ITR = 'a' + (ITR -10);
			else
				ITR = ITR + '0';
			opcode[0] = 'b';
			opcode[1] = ITR;
			opcode[2] = 0;	
			}
		else
			strcpy(opcode,"err");
	}
	strcpy(mcode, opcode);

	printf("%s\n",mcode);
	return 1;
}
