#include "../includes/minishell.h"
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/history.h>
#include <string.h>

char	*ft_strjoin1(char *s1, char *s2)
{
	int		len;
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
		return NULL;
	len = strlen(s1) + strlen(s2);
	ptr = malloc(len + 1);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}

int	main(int ac, char **av)
{
	while (1)
	{
   		char cwd[PATH_MAX];
		char *path;
		path = readline("minishell-> ");
		if (path[0] == '~')
		{
			char *usr = "/Users/tnaceur";
			path = ft_strjoin1(usr, path + 1);
		}
		if (chdir(path) == -1)
		{
			perror(NULL);
			exit(1);
		}
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
	}

}
