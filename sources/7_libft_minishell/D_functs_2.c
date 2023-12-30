/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   D_functs_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdyli <aabdyli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:21:44 by aabdyli           #+#    #+#             */
/*   Updated: 2023/10/23 14:21:45 by aabdyli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_putchar_error(char c);

void	ft_delete_char(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = str[i + 1];
}

void	ft_putnbr_error(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb > 10)
	{
		ft_putnbr_error(nb / 10);
		ft_putnbr_error(nb % 10);
	}
	else
		ft_putchar_error(nb + '0');
}

static void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (OK);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s, t_shell *shell)
{
	char	*str;
	size_t	size;

	str = (char *) s;
	if (!s)
		return (NULL);
	size = ft_strlen(str);
	str = ft_calloc(size + 1, shell);
	if (!shell && !str)
		return (NULL);
	size = 0;
	while (s[size])
	{
		str[size] = s[size];
		size++;
	}
	str[size] = '\0';
	return (str);
}
