/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 13:28:19 by lnieto-m          #+#    #+#             */
/*   Updated: 2018/06/24 18:23:17 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

char    *md5(uint32_t *entry, size_t size)
{
    char    *sum;
    int     rotate_nb[64];
    int     sinus_const[64];
    int     i;
    float   tmp;
    uint32_t    h0;
    uint32_t    h1;
    uint32_t    h2;
    uint32_t    h3;
    uint32_t    a;
    uint32_t    b;
    uint32_t    c;
    uint32_t    d;

    h0 = 0x67452301;
    h1 = 0xefcdab89;
    h2 = 0x98badcfe;
    h3 = 0x10325476;

    i = 0;
    while (i < 64) {
        if (i < 15)
        {
            rotate_nb[i] = 7;
            rotate_nb[i + 1] = 12;
            rotate_nb[i + 2] = 17;
            rotate_nb[i + 3] = 22;
        }
        else if (i < 31)
        {
            rotate_nb[i] = 5;
            rotate_nb[i + 1] = 9;
            rotate_nb[i + 2] = 14;
            rotate_nb[i + 3] = 20;
        }
        else if (i < 47)
        {
            rotate_nb[i] = 4;
            rotate_nb[i + 1] = 11;
            rotate_nb[i + 2] = 16;
            rotate_nb[i + 3] = 23;
        }
        else
        {
            rotate_nb[i] = 6;
            rotate_nb[i + 1] = 10;
            rotate_nb[i + 2] = 15;
            rotate_nb[i + 3] = 21;
        }
        i += 4;
    }
    i = 0;
    while (i < 64)
    {
        tmp = floor(fabs(sin(i + 1) * pow(2, 32)));
        sinus_const[i] = (uint32_t)tmp;
        i++;
    }
    uint32_t *msg;
    int new_size = size + 1;
    while (new_size * 32 % 512 != 448)
        new_size++;
    msg = malloc(sizeof(uint32_t) * new_size + 64);
    ft_bzero(msg, new_size);
    msg[size] = 128;
    ft_memcpy(msg, entry, size);
    uint32_t msg_size = size * 8;
    ft_memcpy(msg + new_size, &msg_size, 4);
    int lol = 0;
    while (lol < new_size) {
        printf("%s\n", ft_itoa_base(msg[lol], 2));
        lol++;
    }
    int j = 0;
    while (j < new_size) {
        a = h0;
        b = h1;
        c = h2;
        d = h3;

        i = 0;
        uint32_t f = 0;
        uint32_t g = 0;
        uint32_t temp = 0;
        while (i < 64) {
            if (i < 16)
            {
                f = (b & c) | ((~b) & d);
                g = i;
            }
            else if (i < 32)
            {
                f = (d & b) | ((~d) & c);
                g = (5 * i + 1) % 16;
            }
            else if (i < 48)
            {
                f = b ^ c ^ d;
                g = (3 * i + 5) % 16;
            }
            else
            {
                f = c ^ (b | (~d));
                g = (7 * i) % 16;
            }
            temp = d;
            d = c;
            c = b;
            b = LEFT_ROTATE((a + f + sinus_const[i] + entry[g + j]), rotate_nb[i]) + b;
            a = temp;
            printf("%x %x %x %x\n", a, b, c, d);
            i++;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        j += 16;
    }

    
    // ft_printf("%x%x%x%x\n", h0, h1, h2, h3);
    sum = (char *)malloc(4 * sizeof(uint32_t));
    return sum;
}
