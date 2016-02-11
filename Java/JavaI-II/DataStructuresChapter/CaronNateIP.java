/*
 Program Name: CaronNateIP.java
 Author: Nathan Caron
 Assignment #7
 Date: 4/21/2015
 Purpose: Converts a mathematical expression to postfix notation and solves it.
*/


import com.deitel.datastructures.StackComposition;
import java.lang.StringBuffer;
import java.util.Scanner;


public class CaronNateIP
{
	public static void main(String[] args)
	{
		Scanner input =  new Scanner(System.in);
		StringBuffer postfix, infix;
		int cont;

		System.out.print("Enter expression to convert to Postfix: ");
		infix = new StringBuffer(input.nextLine());

		postfix = convertToPostfix(infix);

		System.out.print("Expression in postfix form: ");
		System.out.println(postfix);

		System.out.print("Expression evaluated: ");
		System.out.println(evaluatePostfix(postfix));

	}

	public static int evaluatePostfix(StringBuffer postfix)
	{
		int index = 0;
		int result = 0, x, y;
		StackComposition<Integer> stack = new StackComposition<>();
		postfix.append(')');

		while(postfix.charAt(index) != ')')
		{
			if(isNumber(postfix.charAt(index)))
				stack.push(postfix.charAt(index) - 48);
			if(isOperator(postfix.charAt(index)))
			{
				if(stack.isEmpty())
				{
					System.out.println("Error");
					return 0;
				}
				x = stack.pop();
				if(stack.isEmpty())
				{
					System.out.println("Error");
					return 0;
				}
				y = stack.pop();
				result = calculate(y, x, postfix.charAt(index));
				stack.push(result);
			}
			index++;
		}

		return stack.pop();
	}

	public static int calculate(int y, int x, char o)
	{
		switch(o)
		{
			case '+': return y + x;
			case '-': return y - x;
			case '*': return y * x;
			case '/': if(y != 0)
						return y / x;
					  else
					  	return 0;
			case '^': return (int)Math.pow(y, x);
			case '%': return y % x;
			default: return 0;
		}

	}

	public static StringBuffer convertToPostfix(StringBuffer infix)
	{
		StackComposition<Character> stack = new StackComposition<>();
		StringBuffer postfix = new StringBuffer();
		int index = 0;

		stack.push('(');
		infix.append(')');

		while(!stack.isEmpty())
		{
			if(isNumber(infix.charAt(index)))
				postfix.append(infix.charAt(index));
			if(infix.charAt(index) == '(')
				stack.push('(');
			if(isOperator(infix.charAt(index)))
			{
				//while operator on stack is equal or higher precedence, pop and append it
				while(isOperator(stack.peek()) && precedence(infix.charAt(index), stack.peek()) <= 0)
				{
					postfix.append(stack.pop());
				}
				stack.push(infix.charAt(index));
			}
			if(infix.charAt(index) == ')')
			{
				while(stack.peek() != '(')
				{
					postfix.append(stack.pop());
				}
				//pop off '('
				stack.pop();
			}
			index++;

			if(index >= infix.length())
			{
				if(!stack.isEmpty())
					System.out.println("Invalid expression!");
				break;
			}
		}

		return postfix;
	}


	public static Boolean isOperator(char c)
	{
		switch(c)
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			case '%':
				return true;
			default:
				return false;
		}
	}

	public static Boolean isNumber(char c)
	{
		if(c >= 48 && c <= 57)
			return true;
		return false;
	}

	//returns 1 if a > b, 0 if equal, -1 if b > a
	public static int precedence(char a, char b)
	{
		int aPres = 0, bPres = 0;
		if(a == '+' || a == '-')
			aPres = 1;
		if(b == '+' || b == '-')
			bPres = 1;
		if(a == '*' || a == '/' || a == '%')
			aPres = 2;
		if(b == '*' || b == '/' || b == '%')
			bPres = 2;
		if(a == '^')
			aPres = 3;
		if(b == '^')
			bPres =3;
		if(aPres > bPres)
			return 1;
		else if(aPres == bPres)
			return 0;
		else
			return -1;
	}
}