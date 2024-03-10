/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:52:07 by torsini           #+#    #+#             */
/*   Updated: 2024/03/09 17:11:06 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h" // Inclut le fichier d'en-tête ft_printf.h qui est dans le répertoire parent.

// Cette fonction calcule la longueur d'un nombre en hexadécimal.
// Par exemple, ft_hexlen(255) renverra 2 car 255 en hexadécimal est FF.
int	ft_hexlen(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0) // Tant que num n'est pas 0...
	{
		num = num / 16; // ...divise num par 16...
		length++; // ...et incrémente length.
	}
	return (length); // Renvoie la longueur.
}

// Cette fonction imprime un nombre en hexadécimal.
// Par exemple, ft_printhex(255, 'x') affichera "ff" à l'écran.
void	ft_printhex(unsigned int num, const char format)
{
	if (num >= 16) // Si num est supérieur ou égal à 16...
	{
		ft_printhex(num / 16, format); // ...appelle ft_printhex avec num divisé par 16...
		ft_printhex(num % 16, format); // ...et avec le reste de la division de num par 16.
	}
	else // Si num est inférieur à 16...
	{
		if (num <= 9) // ...et si num est inférieur ou égal à 9...
			ft_putchar((num + '0')); // ...affiche num comme un chiffre.
		else // Si num est supérieur à 9...
		{
			if (format == 'x') // ...et si format est 'x'...
				ft_putchar((num - 10 + 'a')); // ...affiche num comme une lettre minuscule.
			if (format == 'X') // ...et si format est 'X'...
				ft_putchar((num - 10 + 'A')); // ...affiche num comme une lettre majuscule.
		}
	}
}

// Cette fonction imprime un nombre en hexadécimal et renvoie sa longueur.
// Par exemple, ft_puthexadecimal(255, 'x') affichera "ff" à l'écran et renverra 2.
int	ft_puthexadecimal(unsigned int num, const char type)
{
	if (num == 0) // Si num est 0...
		return (write(1, "0", 1)); // ...écrit "0" sur la sortie standard et renvoie 1.
	else // Si num n'est pas 0...
		ft_printhex(num, type); // ...appelle ft_printhex avec num et type.
	return (ft_hexlen(num)); // Renvoie la longueur de num en hexadécimal.
}
