/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_basic_function.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:57:00 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/29 14:37:25 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

double	ft_cabs(t_complex c)
{
	return (sqrt((c.real * c.real) + (c.imag * c.imag)));
}

t_complex	ft_conj(t_complex c)
{
	c.imag *= -1;
	return (c);
}

double	ft_carg(t_complex c)
{
	return (atan2(c.imag, c.real));
}
