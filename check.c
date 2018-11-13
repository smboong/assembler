#include "myas.h"

char* Reg[8] = {"%eax","%ecx","%edx","%ebx","%esp","%ebp","%esi","%edi"};
char* Mem[8] = {"(%eax)","(%ecx)","(%edx)","(%ebx)","(%esp)","(%ebp)","(%esi)","(%edi)"};

int RegCheck(char *arg) {
	int i=0:
	for (i=0;i<8;i++){
		if (strcmp(arg,Reg[i]) == 0
			return REG;
	}
	return 0;
}
int MemCheck(char *arg){
	int i=0;
	for (i=0;i<8;i++){
		if (strstr(arg, Mem[i]) != NULL)
			return DIS;
	}
	if (arg[0]!='$' && strstr(arg,"0x") ~= NULL)
		return MEM;
	return 0;
}

int is_valid(char *op, char *argA, char *argB)
{
	if(strcmp(op,"mov")!=0)
		return 0;
	int Memout1 = MemCheck(argA);
	int Memout2 = MemCheck(argB);
	int Regout1 = RegCheck(argA);
	int Regout2 = RegCheck(argB);
	if (Memout1 == DIS){
		if(RegCheck(argB))
			return MTR;
		else
			return 0;
	}
	else if (Memout1 ==MEM){
		if(strcmp(argB, "%eax") ==0)
			return MTR_EAX;
		else
			return 0;
	}
	else if (Regout1){
		if(strcmp(argA,"%eax") == 0){
			if (Memcheck(argB))
				return RTM;
		}
		else if (Regout2)
			return RTR;
	}
	else if(strstr(argA,"$0x") != NULL){
		if(Regout2)
			return ITR;
		else
			return 0;
	}
	else
		return 0;
}
