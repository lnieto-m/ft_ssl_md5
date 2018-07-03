/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 12:46:58 by lnieto-m          #+#    #+#             */
/*   Updated: 2018/06/24 17:41:52 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_ssl.h"

int main(int ac, char **av) {
	if (ac > 1) {
		printf("%s\n", md5((uint32_t *)av[1], ft_strlen(av[1])));
	}
	printf("%zu\n", sizeof(uint32_t));
	return (0);
}
