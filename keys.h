/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:39:40 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 16:39:41 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# ifdef __linux__
#  define K_ESC         65307
#  define K_NUM_MULT    65450
#  define K_NUM_DIV     65455
#  define K_NUM_PLUS    65451
#  define K_NUM_MINUS   65453
#  define K_NUM_ENTER   65421
#  define K_NUM_0       65438
#  define K_UP          65362
#  define K_DOWN        65364
#  define K_LEFT        65361
#  define K_RIGHT       65363
#  define K_DIGIT_1     49
#  define K_L           108
# else
#  define K_ESC         53
#  define K_NUM_MULT    67
#  define K_NUM_DIV     75
#  define K_NUM_PLUS    69
#  define K_NUM_MINUS   78
#  define K_NUM_ENTER   76
#  define K_NUM_0       82
#  define K_UP          126
#  define K_DOWN        125
#  define K_LEFT        123
#  define K_RIGHT       124
#  define K_DIGIT_1     18
#  define K_L           37
# endif
#endif
