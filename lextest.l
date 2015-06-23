%{
#include<stdio.h>
#include<string.h>
int count=0;
int line=0;
int digit=0;
int space=0;
%}

%%
print {return 0;}

[" "] {space++;}
[a-z] {count++;} 
[0-9] {digit++;} 
[.]|[\n] {line++;}


%%

void main()
{
yylex();
printf("Character count : %d ",count);
printf("Line count : %d ",line);
printf("Digit count : %d ",digit);
printf("Space count : %d ",space);
}

yywrap()
{
return 1;
}
