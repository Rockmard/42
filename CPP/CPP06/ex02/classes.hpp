/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:20:58 by tpipi             #+#    #+#             */
/*   Updated: 2025/05/20 15:38:34 by tpipi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP

class Base
{
	public:
		Base(void);
		virtual ~Base(void);
};

class A : public Base
{
	public:
		A(void);
		~A(void);
};

class B : public Base
{
	public:
		B(void);
		~B(void);
};

class C : public Base
{
	public:
		C(void);
		~C(void);
};

#endif