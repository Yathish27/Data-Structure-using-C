int precedence(char ch)
{
switch(ch)
case '+':
	'-':return 1;

case '*':
'/':return 1;

case'^':return 3;
default: return 0;
}

void conversion(char* infix)
{
stack_t s;
initialize_Stack(&s);
char postfix[30];
char k;
int j=0;
for (int i=0;i<strlen(infix);++i)
{
ch=infix[i];
switch(ch)
{
case '(':push(&s,ch);break;
case ')':while(x=pop(&s)!='(')
		postfix[j++]=k;break;

case '^':push(&s,ch);break;
case '+':
     '-':
     '*':
     '/':while(!isEmpty(&s) && precedence(peep(&s))>=precedence(ch))
		 postfix[j++]=pop(&s);
		 push(&s,ch);break;
default:postfix[j++]=ch;

}

}
while(s.sp!=0)
{
postfix[j++]=pop(&s);
}
postfix[j]='\0';
printf("postfix array is ",postfix);
}
