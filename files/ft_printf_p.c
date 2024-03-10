/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:49:51 by torsini           #+#    #+#             */
/*   Updated: 2024/03/09 17:13:49 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h" // Inclut le fichier d'en-tête ft_printf.h qui est dans le répertoire parent.

// Cette fonction calcule la longueur d'une adresse mémoire en hexadécimal.
// Par exemple, ft_countpointer(0xFF) renverra 2 car 0xFF en hexadécimal est FF.
static int	ft_countpointer(unsigned long long prt)
{
	int	count;

	count = 0;
	while (prt != 0) // Tant que prt n'est pas 0...
	{
		count++; // ...incrémente count...
		prt = prt / 16; // ...et divise prt par 16.
	}
	return (count); // Renvoie le nombre de chiffres en hexadécimal.
}

// Cette fonction imprime une adresse mémoire en hexadécimal.
// Par exemple, ft_printpointer(0xFF) affichera "ff" à l'écran.
int	ft_printpointer(unsigned long long prt)
{
	if (prt >= 16) // Si prt est supérieur ou égal à 16...
	{
		ft_printpointer(prt / 16); // ...appelle ft_printpointer avec prt divisé par 16...
		ft_printpointer(prt % 16); // ...et avec le reste de la division de prt par 16.
	}
	else // Si prt est inférieur à 16...
	{
		if (prt <= 9) // ...et si prt est inférieur ou égal à 9...
			ft_putchar(prt + 48); // ...affiche prt comme un chiffre.
		else // Si prt est supérieur à 9...
			ft_putchar(prt - 10 + 'a'); // ...affiche prt comme une lettre minuscule.
	}
	return (ft_countpointer(prt)); // Renvoie la longueur de prt en hexadécimal.
}

// Cette fonction imprime une adresse mémoire en hexadécimal et renvoie sa longueur.
// Par exemple, ft_putpointer(0xFF) affichera "0xff" à l'écran et renverra 4.
int	ft_putpointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0) // Si ptr est 0...
	{
		len += write(1, "(nil)", 5); // ...écrit "(nil)" sur la sortie standard...
		return (len); // ...et renvoie la longueur de "(nil)".
	}
	len = write(1, "0x", 2); // Écrit "0x" sur la sortie standard et obtient sa longueur.
	len += ft_printpointer(ptr); // Écrit ptr en hexadécimal sur la sortie standard et ajoute sa longueur à len.
	return (len); // Renvoie la longueur totale.
}
