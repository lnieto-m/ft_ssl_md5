/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:47:15 by lnieto-m          #+#    #+#             */
/*   Updated: 2018/06/24 17:15:34 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libftprintf.h"
# include <stdint.h>
# include <math.h>

# define LEFT_ROTATE(n, d) ((n << d) | (n >> (32 - d)))

char    *md5(uint32_t *entry, size_t);

#endif
