#include <stdio.h>
#include <stdarg.h>
#include "printchar.c"

/**
 * _printf - prints formated string
 * @format: The string to print
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	char *str, char_sp, *str_sp;
	int numchar = 0;

	va_start(ap, format);
	for (str = format; *str; str++)
	{
		if (*str != '%')
		{
			printchar(*str);
			++numchar;
			continue;
		}
		switch (*++str)
		{
		case '%':
			printchar('%');
			break;
		case 'c':
			char_sp = va_arg(ap, char);
			printchar(char_sp);
			break;
		case 's':
			for (str_sp = va_arg(ap, char *); *str_sp; str_sp++)
			{
				printchar(*str_sp);
			}
			break;
		default:
			printchar(*str);
			break;
		}
	}
	va_end(ap);
}
