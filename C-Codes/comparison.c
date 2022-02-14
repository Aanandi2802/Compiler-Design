#include<stdio.h>
#include<string.h>
int main()
{
  printf("\n");
  FILE *file1;
  char Digit='a';
  int state='A',flag=0,count=0;
  file1=fopen("Program.txt","r");
  char keyword[16][20]={"Which" , "which" , "Is" , "is" , "From" , "from" ,"number" , "or" , "and" , "between" , "than" , "bigger" , "greater" , "larger" , "smaller" , "less"};
  while((Digit=getc(file1))!=EOF)
  {
    if(flag==0)
    {
      if(state=='A')
      {
        if(Digit>=48 && Digit<=57)//ascii value for digit 0=>48 && 9=>57
          {state='B';}
        else 
        {flag=1;}
      }
      else if(state=='B')
      {
        if(Digit>=48 && Digit<=57)
        {state='B';}
        else if(Digit=='.')
        {state='C';}
        else if(Digit=='E')
        {state='E';}
        else
        {flag=1;}
      }
      else if(state=='C')
      {
        if(Digit>=48&&Digit<=57)
        {state='D';}
        else
        {flag=1;}
      }
      else if(state=='D')
      {
        if(Digit>=48&&Digit<=57)
        {state='D';}
        else if(Digit=='E')
        {state='E';}
        else
        {flag=1;}
      }
      else if(state=='E')
      {
        if(Digit=='+'||Digit=='-')
        {state='F';}
        else if(Digit>=48&&Digit<=57)
        {state='G';}
        else
        {flag=1;}
        }
      else if(state=='F')
      {
        if(Digit>=48&&Digit<=57)
        {state='G';}
        else
        {flag=1;}
      }
      else if(state=='G')
      {
        if(Digit>=48&&Digit<=57)
        {state='G';}
        else{flag=1;}
      }
      if((state=='G'||state=='D') && Digit==' ')
      {
        printf("Float \n");
        count++;
        state='A';
      }
      else if(state=='B' && Digit==' ')
      {
        printf("Integer\n");
        count++;
        state='A';
      }
      else
      { }
    }
    if(flag==1)
    {
      char n[15]={'\0'};
      while(Digit!=' '&&Digit!=EOF&&Digit!='\n')
      {
        if(Digit=='?')
        {printf("'?' IS PUNCTUATION\n\nNEW LINE\n\n");count++;}
        strncat(n,&Digit,1);
        Digit=getc(file1);
      }
      for(int i=0;i<17;i++)
      {
        if(strcmp(n,keyword[i])==0)
        {
          printf("'%s' IS A KEYWORD\n",n);
          count++;
          flag=0;
          break;
        }  
      }
      if(flag==1)
      flag=0;
    }
  }
printf("Total no. of Tokens : %d",count);
printf("\n\n");
fclose(file1);
return 0;
}
