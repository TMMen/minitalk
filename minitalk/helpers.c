#include "minitalk.h"

static int	ft_isspace(const char a)
{
	if (a == ' ' || a == '\n' || a == '\t'
		|| a == '\r' || a == '\v' || a == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	number;

	minus = 0;
	number = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			minus++;
	while (*str >= '0' && *str <= '9')
		number = number * 10 + *str++ - '0';
	if (minus % 2 == 1)
		number = -number;
	return (number);
}
