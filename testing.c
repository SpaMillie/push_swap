#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\r')
		return (1);
	if (c == ' ' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	int				i;
	unsigned long	num;

	i = 0;
	num = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	sign = ft_sign(str[i]);
	if (sign != 0)
		i++;
	while (ft_isnum(str[i]) == 1)
	{
		num = num * 10 + (str[i++] - '0');
		if (sign == -1 && num > 9223372036854775808ULL)
			return (0);
		if ((sign == 1 || sign == 0) && num > 9223372036854775807)
			return (-1);
	}
	if (sign != 0 && num != 0)
		return (sign * num);
	return (num);
}

void	*ft_memset(void *array, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = array;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (array);
}
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;
	size_t	bytes;

	bytes = size * count;
	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (bytes / size != count)
		return (0);
	space = malloc(count * size);
	if (space != NULL)
		ft_bzero(space, count * size);
	return (space);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize > 0)
	{
		while (i + 1 < dstsize && i < srcsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}
char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	s1_cpy = (char *)malloc(i + 1);
	if (s1_cpy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s1_cpy[i] = (char)s1[i];
		i++;
	}
	s1_cpy[i] = '\0';
	return (s1_cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_s;
	size_t			str_len;

	if (s == 0)
		return (0);
	str_len = ft_strlen(s);
	if (str_len < start)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub_s = (char *)malloc(len + 1);
	if (sub_s == NULL)
		return (NULL);
	ft_strlcpy(sub_s, s + start, len + 1);
	return (sub_s);
}
int	count_word(const char *s, char c)
{
	int	words;
	int	i;
	int	prev_i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		prev_i = i;
		while (s[i] && s[i] != c)
			i++;
		if (prev_i != i)
			words++;
	}
	return (words);
}

char	**free_all(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (0);
}

char	**ft_short(const char *s, char c, char **res, int c_word)
{
	int	prev_i;
	int	temp_count;
	int	i;

	temp_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		prev_i = i;
		while (s[i] && s[i] != c)
			i++;
		if (prev_i != i && temp_count < c_word)
		{
			res[temp_count] = ft_substr(s, prev_i, i - prev_i);
			if (!res[temp_count])
				return (free_all(res));
			temp_count++;
		}
	}
	res[temp_count] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		c_word;

	c_word = count_word(s, c);
	res = ft_calloc(c_word + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	res = ft_short(s, c, res, c_word);
	return (res);
}

int	*create_a(char **str, int j)
{
	int		i;
	char	**list;
	int		*a;

	// j = params->args;
	i = 0;
	if (j == 2)
	{
		printf("checking the string %s\n", str[i]);
		list = ft_split(str[i], ' ');
		if (list == NULL)
			return (NULL);
	}
	else
		list = str;
	i = 0;
	while (list[i] != '\0')
		i++;
	a = malloc(sizeof(int) * i);
	if (!a)
	{
		if (j == 2)
			free(list);
		return(NULL);
	}
	i = 0;
	while (j > 1)
	{
		a[i] = ft_atoi(list[i]);
		i++;
		j--;
	}
	if (j == 2)
		free(list);
	return (a);
}
int	main (int argc, char **argv)
{
	int *list;
	list = create_a(argv + 1, argc);
	free(list);
}
