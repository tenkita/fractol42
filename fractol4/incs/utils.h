/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkitago <tkitago@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:00:44 by tkitago           #+#    #+#             */
/*   Updated: 2024/12/19 14:37:07 by tkitago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "renderer.h"
# include "types.h"

# define SCROLLUP 4
# define SCROLLDOWN 5

unsigned int	*index2addr(t_data_addr *data_addr, int index[2]);
t_position		index2position(int index[2], t_position center, t_size size,
					double scale);

#endif