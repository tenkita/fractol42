/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_basic_operator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:57:12 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/29 14:41:39 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

// only cdiv check

t_complex	ft_cadd(t_complex a, t_complex b)
{
	t_complex	res;

	res.real = a.real + b.real;
	res.imag = a.imag + b.imag;
	return (res);
}

t_complex	ft_csub(t_complex a, t_complex b)
{
	t_complex	res;

	res.real = a.real - b.real;
	res.imag = a.imag - b.imag;
	return (res);
}

t_complex	ft_cmul(t_complex a, t_complex b)
{
	t_complex	res;

	res.real = a.real * b.real - a.imag * b.imag;
	res.imag = a.real * b.imag + a.imag * b.real;
	return (res);
}

t_complex	ft_cdiv(t_complex a, t_complex b)
{
	t_complex	res;
	double		denominator;

	res = ft_cmul(a, ft_conj(b));
	denominator = b.real * b.real + b.imag * b.imag;
	res.real /= denominator;
	res.imag /= denominator;
	return (res);
}
