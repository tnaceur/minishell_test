
#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	while (1)
	{
		char	*token = readline("test_echo-> ");
		int		i;
		int		count;
		int		j;
		
		i = 0;
		j = 0;
		count = 0;
		while (token[i])
		{
			if (token[i + 1] && token[i + 2] && token[i] == '-'
				&& token[i + 1] == 'n' && token[i + 2] == ' ')
			{
				count++;
				j = i + 3;
			}
			i++;
		}
		if (count >= 1)
		{
			token += j;
			printf("%s", token);
		}
		else
			printf("%s\n", token);
	}
}
