%{
  #include <stdio.h>
  #include <stdlib.h>
  int yylex(void);
  int yyerror(const char *s);
%}

%token INTEGER QM WH WHI IS ISS FR NU OR ND BW TN BG GR LG SM LS 

%% 

program:
   wh iss bg nu int or int qm 
   fr int nd int whi iss lg qm 
   is int bg tn int qm
   is int sm tn int qm
   wh iss sm bw int nd int qm 
   wh iss sm nu int or int qm
   is int ls tn int qm
   is int gr tn int qm
   ;
	 
int: INTEGER {printf("Here : Integer\n");} ;
	
wh:	WH {printf("Keyword : Which\n");} ;
	
whi: WHI {printf("Keyword : which\n");} ;
	
is:	IS	{printf("Keyword : Is\n");} ;

fr:	FR	{printf("Keyword : From\n");} ;

iss: ISS {printf("Keyword : is\n");} ;
	
nu:	NU	{printf("Keyword : number\n");} ;

or:	OR	{printf("Keyword : or\n");}	;

nd:	ND	{printf("Keyword : and\n");} ;

bw:	BW	{printf("Keyword : between\n");} ;

tn:	TN	{printf("Keyword : than\n");} ;

bg:	BG	{printf("Keyword : bigger\n");}	;

gr:	GR	{printf("Keyword : greater\n");} ;

lg:	LG	{printf("Keyword : larger\n");}	;

sm:	SM	{printf("Keyword : smaller\n");} ;

ls:	LS	{printf("Keyword : less\n");} ;

qm:	QM {printf("Punctuation : ?\n\n----------------------------------------------\n\n");} ;