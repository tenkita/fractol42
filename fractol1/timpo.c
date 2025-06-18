#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}

int	main(int c, char **timp)
{
	int timpo_len1 = ft_strlen(timp[1]);
	char *str = timp[1];
	for (int i = 0; i < timpo_len1; i++)
	{
		int t = 0;
		for (int j = 0; j < i; j++)
		{
			if (str[j] == str[i])
				t = 1;
		}
		if (t == 0)
			write(1, &str[i], 1);
	}
	int timpo_len2 = ft_strlen(timp[2]);
	char *str2 = timp[2];
    for (int i = 0; i < timpo_len2; i++)
	{
		int t = 0;
		for (int j = 0; j < i; j++)
		{
			if (str2[j] == str2[i])
				t = 1;
		}
		for (int j = 0; j < timpo_len1; j++)
			if (str[j] == str2[i])
				t = 1;

		if (t == 0)
			write(1, &str2[i], 1);
	}
}