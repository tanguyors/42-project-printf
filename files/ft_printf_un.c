/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:34:09 by torsini           #+#    #+#             */
/*   Updated: 2024/03/09 17:13:49 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h" // Inclut le fichier d'en-tête ft_printf.h qui est dans le répertoire parent.

// Cette fonction calcule la longueur d'un nombre non signé.
// Par exemple, ft_length_num(123) renverra 3 car 123 a trois chiffres.
int	ft_length_num(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0) // Tant que num n'est pas 0...
	{
		len++; // ...incrémente len...
		num /= 10; // ...et divise num par 10.
	}
	return (len); // Renvoie la longueur de num.
}

// Cette fonction convertit un nombre non signé en une chaîne de caractères.
// Par exemple, ft_utoa(123) renverra "123".
char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_length_num(n); // Calcule la longueur de n.
	num = (char *)malloc((len + 1) * sizeof(char *)); // Alloue de la mémoire pour la chaîne num.
	if (!num) // Si l'allocation de mémoire a échoué...
		return (NULL); // ...renvoie NULL.
	num[len] = '\0'; // Ajoute le caractère de fin de chaîne à la fin de num.
	while (n != 0) // Tant que n n'est pas 0...
	{
		num[len - 1] = n % 10 + 48; // ...ajoute le dernier chiffre de n à num...
		n = n / 10; // ...et supprime le dernier chiffre de n.
		len--; // Décrémente len.
	}
	return (num); // Renvoie la chaîne num.
}

// Cette fonction imprime un nombre non signé et renvoie sa longueur.
// Par exemple, ft_putunsigned(123) affichera "123" à l'écran et renverra 3.
int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0) // Si n est 0...
		len += write(1, "0", 1); // ...écrit "0" sur la sortie standard et incrémente len.
	else // Si n n'est pas 0...
	{
		num = ft_utoa(n); // ...convertit n en une chaîne de caractères...
		len += ft_putstr(num); // ...écrit num sur la sortie standard et ajoute sa longueur à len...
		free(num); // ...et libère la mémoire allouée par ft_utoa.
	}
	return (len); // Renvoie la longueur de n.
}
