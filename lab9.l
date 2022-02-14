%{
	#include<stdio.h>
	#include "y.tab.h"
	  int yyerror(char *errormsg);
	  int yyparse();
	int t=0;
%}
WH	"Which"
WHI	"which"
IS	"Is"
ISS "is"
FR	"From"
NU	"number"
OR	"or"
ND	"and"
BW	"between"
TN	"than"
BG	"bigger"
GR	"greater"
LG	"larger"
SM	"smaller"
LS	"less"
QM	"?"
Digit	[0-9]
Int	{Digit}+
Float	{Digit}+(\.{Digit}+)?(E[+\-]?{Digit}+)?
INTEGER	Int|Float
DELIM	[ \t\n]
WS	{DELIM}+

%%

{Int}	{return INTEGER;}
{Float}	{return INTEGER;}
{QM}	{return QM;}
{WH}	{return WH;}
{WHI}	{return WHI;}
{IS}	{return IS;}
{ISS} 	{return ISS;}
{FR}	{return FR;}
{NU}	{return NU;}
{OR}	{return OR;}
{ND}	{return ND;}
{BW}	{return BW;}
{TN}	{return TN;}
{BG}	{return BG;}
{GR}	{return GR;}
{LG}	{return LG;}
{SM}	{return SM;}
{LS}	{return LS;}
{WS}	{}
.	{yyerror("Error: Undefined character.");}
%%

int yywrap()
{
	return 1;
}
int main()
{
	printf("\n** Project-5 **\n\n");
	printf("Enter Input String: \n");
	yyparse();
	printf("\n");
    return 0;
}
int yyerror(char *ErrorHere)
{
    fprintf(stderr, "%s\n", ErrorHere);
    exit(1);
}