/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:02:03 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/22 13:49:04 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

int	argb2hex(int r, int g, int b, int a);
int	hsvt2hex(double h, double s, double v, double t);
int	colormap(double n);

#endif