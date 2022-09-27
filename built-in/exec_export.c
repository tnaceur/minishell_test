
#include "../includes/minishell.h"

int	the_sort(char **env) {
	int i;
	int j;
	int	small;
	int big;

	i = 0;
	small = 0;
	big = 0;
	j = 1;
	while (env[i])
	{
		if (env[j] && ft_strcmp(env[j], env[i]) > 0)
		{
			small = i;
//			printf("%s\n", env[i]);
			break;
			j = i;
			i = 0;
		}
		i++ ;
	}
	return (small);
}

int	exec_export(char **cmd)
{
	int	i;

	i = 0;
	(void)cmd;
	int j = 0;
	while (g_glob.env[i])
	{
		j = the_sort(g_glob.env);
		printf("declare -x %s\n", g_glob.env[j]);
		i++;
	}
	return (1);
}
