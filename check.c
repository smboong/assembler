#include "myas.h"

char* Reg[8] = {"%eax","%ecx","%edx","%ebx","%esp","%ebp","%esi","%edi"};
char* Mem[8] = {"(%eax)","(%ecx)","(%edx)","(%ebx)","(%esp)","(%ebp)","(%esi)","(%edi)"};
/*   */

int RegCheck(char *arg) {
	int i=0;
	for (i=0;i<8;i++){
		if (strcmp(arg,Reg[i]) == 0)
			return 2;
	}
	return 0;
}
int MemCheck(char *arg){
	int i=0;
	for (i=0;i<8;i++){
		if (strstr(arg, Mem[i]) != NULL)
			return 4;
	}
	if (arg[0]!='$' && strstr(arg,"0x") != NULL)
		return 3;
	return 0;
}

int is_valid(char *op, char *argA, char *argB)
{
	int Memx = MemCheck(argA);
	int Regx = RegCheck(argA);
	int Regy = RegCheck(argB);
	if (Memx == 3){
		if(strcmp(argB, "%eax") ==0)
			return 7;
		else
			return 0;
	}
	else if (Memx == 4){
		if(RegCheck(argB))
			return 6;
		else
			return 0;
	}
	else if (Regx){
		if(strcmp(argA,"%eax") == 0){
			if (MemCheck(argB))
				return 8;
		}
		else if (Regy)
			return 5;
	}
	else if(strstr(argA,"$0x") != NULL){
		if(Regy)
			return 9;
		else
			return 0;
	}
	else
		return 0;
}
