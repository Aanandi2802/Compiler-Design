%{
	#include<stdio.h>
	int x=0;
%}
Keyword		"Which"|"which"|"Is"|"is"|"From"|"from"|"number"|"or"|"and"|"between"|"than"
Cmp		"bigger"|"greater"|"larger"|"smaller"|"less"
Digit		[0-9]
Qm		"?"
Dm		[\t\n]
Int		{Digit}+
Float		{Digit}+(\.{Digit}+)?(E[+\-]?{Digit}+)?
Space		{Dm}+
%%	

{Keyword}	{printf("Keyword : %s\n",yytext);x++;}
{Cmp}		{printf("Comparison : %s\n",yytext);x++;}
{Int}		{printf("Integer : %s\n",yytext);x++;}
{Float}		{printf("Float No : %s\n",yytext);x++;}
{Qm}		{printf("Punctuation : %s\n",yytext);x++;}
{Space}		{}
.		{}
%%
int yywrap(){return 1;}
int main()
{
	yylex();
	printf("Total No. of Tokens: %d\n",x);
	return 0;
}
