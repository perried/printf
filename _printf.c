#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints formated string
 * @format: The string to print
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char char_sp, *str_sp;
	int numchar = 0;

	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			printchar(*format);
			++numchar;
			*format++;
			continue;
		}
		switch (*++format)
		{
		case '%':
			printchar('%');
			break;
		case 'c':
			char_sp = va_arg(ap, int);
			printchar(char_sp);
			break;
		case 's':
			for (str_sp = va_arg(ap, char *); *str_sp; str_sp++)
			{
				printchar(*str_sp);
			}
			break;
		default:
			printchar(*format);
			break;
		}
	}
	va_end(ap);
	return (numchar);
}
