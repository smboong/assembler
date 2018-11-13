#include "myas.h"

//check.c

int Check_kind(char *Sen)
{
	int i=0;
	if(Sen[0] == '$')
		return 2;//imm
	else if(Sen[0] == '(' || Sen[0] == ')' || Sen[0] == '0' || Sen[0] == '-')
		return 3;//mem
	else if (Sen[0] == '%')
		return 4;//reg
	else
		return 0;//error
}

int is_valid(char *op, char *argF, char *argB)
{
	if((Check_kind(argF)==3) && (Check_kind(argB)==3))
		return 0;
	else if(Check_kind(argB)==2)
		return 0;
	else if((Check_kind(argF)==0) || (Check_kind(argB)==0))
		return 0;
	else
		return 1;
}
