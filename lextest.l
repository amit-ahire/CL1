%{
#include<stdio.h>
#include<string.h>
int count=0;
int word=0;
int line=0;
int digit=0;
int space=0;
int bcount=0;
void replace(char [],int );
%}

%%
print {return 0;}

[" "] {space++;}
[a-z] {count++;} 
[0-9] {digit++;} 
[.]|[\n] {line++;}
[b]+[a-z]* {
		printf("\n starts with b : %s ",yytext);
		bcount++; 
		count+=yyleng; 
		replace(yytext,yyleng);
	}
[a-zA-Z]* {word++;count+=yyleng;}

%%

void main()
{
yyin = fopen("sample.txt","r");
yylex();
printf("\nWords count : %d ",word);
printf("\nCharacter count : %d ",count);
printf("\nLine count : %d ",line);
printf("\nDigit count : %d ",digit);
printf("\nSpace count : %d ",space);
printf("\nStarts with b count : %d ",bcount);

}

void replace(char yytext[10],int len)
{
yytext[0]='B';
printf("\n Replaced string is %s",yytext);
}

yywrap()
{
return 1;
}
