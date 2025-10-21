/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:56:34 by tpipi             #+#    #+#             */
/*   Updated: 2025/09/12 12:54:53 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include <stdlib.h>
#include <cctype>

static bool isOperand(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

static bool isIsolated(std::string str, int i)
{
	if (str[i] != ' ' && str[i + 1] && str[i + 1] != ' ')
		return false;
	return true;
}

static void	getTopElements(int *top1, int *top2, std::stack<int> *nbStack) {
	*top1 = nbStack->top();
	nbStack->pop();
	*top2 = nbStack->top();
	nbStack->pop();
}

static int	calcul(char operand, std::stack<int> *nbStack)
{
	int				tmpTop1;
	int				tmpTop2;
	getTopElements(&tmpTop1, &tmpTop2, nbStack);

	if (operand == '/' && tmpTop1 == 0)
		return 1;

	if (operand == '+')
		nbStack->push(tmpTop2 + tmpTop1);
	else if (operand == '-')
		nbStack->push(tmpTop2 - tmpTop1);
	else if (operand == '*')
		nbStack->push(tmpTop2 * tmpTop1);
	else if (operand == '/') 
		nbStack->push(tmpTop2 / tmpTop1);
	return 0;
}

int ft_rpn(std::string expression)
{
	int 			i = 0;
	std::stack<int>	nbStack;
	
	while (expression[i]) {
		if ((!isOperand(expression[i]) && !std::isdigit(expression[i]) && expression[i] != ' ') || !isIsolated(expression, i))
			return 1;
		else if (isOperand(expression[i])) {
			if (nbStack.size() < 2)
				return 2;
			else if (calcul(expression[i], &nbStack) == 1)
				return 3;
		}
		else if (std::isdigit(expression[i]))
			nbStack.push(atoi(&expression[i]));
		i++;
	}
	if (nbStack.size() > 1)
		return 4;
	std::cout << nbStack.top() << std::endl;
	return 0;
}
