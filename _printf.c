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
	for (;*format; format++)
	{
		if (*format != '%')
		{
			printchar(*format);
			if (*format != '\0')
			{
				++numchar;
			}
			continue;
		}
		switch (*++format)
		{
		case '%':
			printchar('%');
			++numchar;
			break;
		case 'c':
			char_sp = va_arg(ap, int);
			printchar(char_sp);
			++numchar;
			break;
		case 's':
			for (str_sp = va_arg(ap, char *); *str_sp; str_sp++)
			{
				printchar(*str_sp);
				if (*str_sp != '\0')
				{
					++numchar;
				}
			}
			break;
		default:
			printchar(*format);
			if (*format != '\0')
			{
				++numchar;
			}
			break;
		}
	}
	va_end(ap);
	return (numchar);
}
