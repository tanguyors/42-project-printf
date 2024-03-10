/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:54:41 by torsini           #+#    #+#             */
/*   Updated: 2024/03/09 17:11:08 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h" // Inclut le fichier d'en-tête ft_printf.h qui est dans le répertoire parent.

// Cette fonction écrit un caractère sur la sortie standard (stdout, généralement l'écran) et renvoie 1.
// Par exemple, ft_putchar('a') affichera 'a' à l'écran.
int	ft_putchar(char c)
{
	write(1, &c, 1); // Écrit le caractère c sur la sortie standard.
	return (1); // Renvoie 1.
}

// Cette fonction écrit une chaîne de caractères sur la sortie standard et renvoie sa longueur.
// Par exemple, ft_putstr("Bonjour") affichera "Bonjour" à l'écran et renverra 7.
int	ft_putstr(char *str)
{
	int	len;

	if (!str) // Si str est NULL...
	{
		write(1, "(null)", 6); // ...écrit "(null)" sur la sortie standard...
		return (6); // ...et renvoie 6.
	}
	len = ft_strlen(str); // Calcule la longueur de str.
	write(1, str, len); // Écrit str sur la sortie standard.
	return (len); // Renvoie la longueur de str.
}

// Cette fonction convertit un nombre en une chaîne de caractères, l'écrit sur la sortie standard et renvoie sa longueur.
// Par exemple, ft_putnumb(123) affichera "123" à l'écran et renverra 3.
int	ft_putnumb(int n)
{
	int		len;
	char	*str;

	str = ft_itoa(n); // Convertit n en une chaîne de caractères.
	len = ft_putstr(str); // Écrit str sur la sortie standard et obtient sa longueur.
	free(str); // Libère la mémoire allouée par ft_itoa.
	return (len); // Renvoie la longueur de str.
}/* ************************************************************************** */
