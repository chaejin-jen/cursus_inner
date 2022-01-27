/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:41:49 by chaejkim          #+#    #+#             */
/*   Updated: 2022/01/27 19:21:41 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void check_fmt(char *fmt)
{
	if (*(fmt+1) == 'c')
		return ;
	if (*(fmt+1) == 's')
		return ;
	if (*(fmt+1) == 'i' || *(fmt+1) == 'd')
		return ;
	if (*(fmt+1) == 'u' || 
}

static void doprnt(const char *fmt, va_list *arg_ptr)
{
	char    *buf;
	
	while (*fmt)
	{
		if (*fmt != '%')
		{
			check_fmt(fmt);
			
		}
		else
			wrtie(1, fmt, 1);
		fmt++;
	}
}

void    printf(const char *fmt, ...)
{
	va_list	arg_ptr;

	// disable_preemption(); // 선점 비활성화 : 여러 프로세스에서 변수에 동시에 엑세스 하는 것을 막기 위함
	va_start(arg_ptr, fmt);
	doprnt(fmt, &arg_ptr)
	// _doprnt(fmt, &arg_ptr, conslog_putc, 16); // format, arguments, and stream 을 가지고 찍어내는거 va_arg 사용
		/*
		int args[] = { 1, 2, 3, 66 };
		_doprnt("%d %d %d %c\n", args, stdout);
		*/
	va_end(arg_ptr);
	// enable_preemption();
}