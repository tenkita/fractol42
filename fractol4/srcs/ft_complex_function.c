/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:56:28 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/24 19:26:29 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

// done

t_complex	ft_cexp(t_complex c)
{
	t_complex	res;

	res.real = exp(c.real) * cos(c.imag);
	res.imag = exp(c.real) * sin(c.imag);
	return (res);
}

t_complex	ft_cln(t_complex c)
{
	t_complex	res;

	res.real = log(ft_cabs(c));
	res.imag = ft_carg(c);
	return (res);
}

t_complex	ft_cpow(t_complex a, t_complex b)
{
	if (!a.imag && !b.imag)
		return ((t_complex){pow(a.real, b.real), 0});
	return (ft_cexp(ft_cmul(b, ft_cln(a))));
}

t_complex	ft_clog(t_complex a, t_complex b)
{
	if (!a.imag && !b.imag)
		return ((t_complex){log(a.real) / log(b.real), 0});
	return (ft_cdiv(ft_cln(a), ft_cln(b)));
}
