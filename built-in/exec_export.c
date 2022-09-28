
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
			j = i;
			i = 0;
		}
		i++ ;
	}
	return (small);
}

int	exec_export(char **cmd)
{
	int		i;
	int 	j;
	char	**expor;

	i = 0;
	(void)cmd;
	expor = ft_arrdup(g_glob.env);
	j = 0;
	while (expor[i])
	{
		j = the_sort(expor);
		printf("declare -x %s\n", g_glob.env[j]);
		free(expor[j]);
		expor[j] = ft_strdup("z");
		i++;
	}
	i = 0;
	while (expor[i])
	{
		free(expor[i]);
		i++;
	}
	free(expor);
	return (1);
}
