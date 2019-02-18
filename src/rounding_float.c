
#include "ft_printf.h"
#include "libft.h"

char	*check_9(int count_digit, char *str, int precis)
{
	char *temp;
	int i;

	i = 0;
	temp = NULL;
//printf("\nstr: %s\n", str);
//999.99987
//012345678
	if(str[0] == '9')
	{
		while(i < count_digit + precis)
		{
			if(str[i] == '9')
				i++;
			else if (str[i] == '.')
				i++;
			else
				break;
		}
		if(str[i] != '9')
		 	i--;
		// printf("i: %d\n", i);
		// printf("count_digit: %d\n", count_digit);
		// printf("c+p: %d\n", count_digit + precis);
		if(i == count_digit + precis)
		{
			if(!(temp = ft_strnew((count_digit + precis + 1 + 1) + 1)))
				return(NULL);
			ft_memset(temp, '0', count_digit + precis + 2);
			temp[0] = '1';
			temp[count_digit + 1] = '.';
		//	printf("temp: %s\n", temp);
		}
	}
	else
	{
		i = 1;
		while(i < count_digit + precis)
		{
			if(str[i] == '9')
				i++;
			else if (str[i] == '.')
				i++;
			else
				break;
		}
		if(str[i] != '9')
		 	i--;
		// printf("i: %d\n", i);
		// printf("count_digit: %d\n", count_digit);
		// printf("c+p: %d\n", count_digit + precis);
		if(i == count_digit + precis)
		{
			if(!(temp = ft_strnew((count_digit + precis + 1) + 1)))
				return(NULL);
			ft_memset(temp, '0', count_digit + precis + 1);
			temp[0] = str[0] + 1;
			temp[count_digit] = '.';
		}
	}
	return (temp);
}

char *rounding_nbr(char *str, int precis)
{
	int i;
	char *temp;
	int count_digit;

	temp = NULL;
	count_digit = 0;
	//printf("\nstr: %s\n", str);
	while(str[count_digit] != '.')
		count_digit++;
	temp = check_9(count_digit, str, precis);
	//printf("temp: %s\n", temp);
	if(temp)
		return (temp);
	temp = str;
	//printf("temp : %s\n", temp);
	i = precis + count_digit;
	if (temp[precis + count_digit + 1] > '4')
	{
		if(temp[precis + count_digit] != '9')
			temp[precis + count_digit] += 1;
		else if (temp[precis + count_digit] == '9')
		{
			while(temp[i] == '9')
			{
				temp[i] = '0';
				i--;
			}
			if(temp[i] == '.')
				i--;
			temp[i] += 1;
		}
	}
		if(!(str = ft_strndup(temp, precis + count_digit + 1)))
			return (0);
		ft_strdel(&temp);
		return (str);
}

char *rounding_nbr_excp(char *str)
{
	int i;
	char *temp;
	int count_digit;

	temp = str;
	count_digit = 0;
	//printf("\nstr: %s\n", str);
	while(str[count_digit] != '.')
		count_digit++;
	//printf("count_digit: %d\n", count_digit);
	i = count_digit;
	if (temp[count_digit + 1] > '4')
	{
		if(temp[count_digit + 1] != '9')
			temp[count_digit - 1] += 1;
		else if (temp[count_digit + 1] == '9')
		{
			while(temp[i] == '9')
			{
				temp[i] = '0';
				i--;
			}
			if(temp[i] == '.')
				i--;
			temp[i] += 1;
		}
	}
		if(!(str = ft_strndup(temp, count_digit)))
			return (0);
		ft_strdel(&temp);
		return (str);
}
