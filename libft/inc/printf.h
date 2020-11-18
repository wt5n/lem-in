/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:42:52 by hlikely           #+#    #+#             */
/*   Updated: 2020/11/18 01:38:11 by wtsn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"

typedef	struct				s_printf
{
	const char				*format;
	char					flags[6];
	char					*f_copy;
	size_t					width;
	size_t					precision;
	char					length[4];
	char					type;
	size_t					widthofline;
	size_t					widthofcontent;
	size_t					base;
	va_list					ap;
	int						cow;
	char					np;
	char					nw;
	int						i;
	size_t					len_of_x;
	char					*types;
	char					*args;
	char					*cons;
	int						floatzero;
	int						floatminimum;
}							t_printf;

typedef	union				u_double
{
	double					d;
	struct
	{
		unsigned long long	m:	52;
		unsigned long long	e:	11;
		unsigned long long	s:	1;
	}						part;
}							t_double;

typedef union				u_double_1
{
	long double				ld;
	struct
	{
		unsigned long long	m:	64;
		unsigned long long	e:	15;
		unsigned long long	s:	1;
	}						part1;
}							t_double_1;

void						display(t_printf *list);
int							ft_printf(const char *format, ...);
t_printf					*newlist_with_printf();
int							init(t_printf *list);
void						reset_list(t_printf *list);
t_printf					*flag(t_printf *list);
t_printf					*width(t_printf *list);
t_printf					*precision(t_printf *list);
t_printf					*length(t_printf *list);
t_printf					*type(t_printf *list);
void						type_c(t_printf *list);
void						c_width(t_printf *list, unsigned int c);
void						c_width_minus(t_printf *list, unsigned int c);
void						type_s(t_printf *list);
void						str_print_with_minus(t_printf *list, char *str);
void						str_print_without_minus(t_printf *list, char *str);
void						type_di(t_printf *list);
void						di_print_without_minus(t_printf *list, long long x);
void						di_print_with_minus(t_printf *list, long long x);
void						presicion_over_len(t_printf *list, long long x);
int							type_p(t_printf *list);
void						type_u(t_printf *list);
void						u_print_without_minus(t_printf *list, char *t);
void						u_presicion_over_len(t_printf *list, char *t);
void						u_print_with_minus(t_printf *list, char *t);
void						type_x(t_printf *list);
void						x_print_without_minus(t_printf *list, long long x,
								char *t);
void						x_presicion_over_len(t_printf *list, long long x,
								char *t);
void						x_print_with_minus(t_printf *list, long long x,
								char *t);
void						type_o(t_printf *list);
void						o_print_with_minus(t_printf *list,
								unsigned long long x, char *t);
void						o_presicion_over_len(t_printf *list,
								unsigned long long x, char *t);
void						o_print_without_minus(t_printf *list,
								unsigned long long x, char *t);
void						sharp_x(t_printf *list);
void						ft_putchar_cow(char c, t_printf *list);
void						ft_putstr_cow(char const *s, t_printf *list);
size_t						ft_len_of_int(long long i);
void						type_b(t_printf *list);
void						b_print_without_minus(t_printf *list, long long x);
void						b_presicion_over_len(t_printf *list, long long x);
void						b_print_with_minus(t_printf *list, long long x);
void						type_other(t_printf *list);
void						display_gap(t_printf *list, char c, int len, \
int update_len);
void						divis(unsigned long long *arr, int i, int num);
int							lennum(long long n);
char						*adv_ft_itoa(long long n, int base, char c);
size_t						lennum_base(long long n, int base);
void						type_f(t_printf *list);
void						handling_float(long double d, int countofel,
								int pow, t_printf *list);
char						*nole(void);
void						addit(unsigned long long *arr, int i, \
unsigned long long num);
void						mult(unsigned long long *arr, int i, int num, \
int end);
void						rounding(char *tmp, int p);
void						f_print_with_minus1(t_printf *list, long double x);
void						f_presicion_over_len1(t_printf *list,
								long double x);
void						f_print_without_minus1(t_printf *list,
								long double x);
void						handling_float_lf(long double d, int countofel,
								int pow, t_printf *list);
int							withnull(char *str, char *res, int len, int x);
char						*full_str(unsigned long long *arr, int i);
void						stars(t_printf *list);
void						nulz(long double d, t_printf *list);

#endif
