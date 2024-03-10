/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torsini <torsini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:56:40 by torsini           #+#    #+#             */
/*   Updated: 2024/03/09 17:13:49 by torsini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// Cette fonction traite un argument de la liste d'arguments en fonction du format spécifié et renvoie sa longueur.
// Par exemple, ft_printf_arg(args, 'c') affichera le prochain argument de args comme un caractère et renverra 1.
int	ft_printf_arg(va_list args, const char format)
{
	if (format == 'c') // Si format est 'c'...
		return (ft_putchar(va_arg(args, int))); // ...traite le prochain argument comme un caractère et renvoie sa longueur.
	else if (format == 's') // Si format est 's'...
		return (ft_putstr(va_arg(args, char *))); // ...traite le prochain argument comme une chaîne de caractères et renvoie sa longueur.
	else if (format == 'p') // Si format est 'p'...
		return (ft_putpointer(va_arg(args, unsigned long long))); // ...traite le prochain argument comme une adresse mémoire et renvoie sa longueur.
	else if (format == 'd' || format == 'i') // Si format est 'd' ou 'i'...
		return (ft_putnumb(va_arg(args, int))); // ...traite le prochain argument comme un nombre entier et renvoie sa longueur.
	else if (format == 'u') // Si format est 'u'...
		return (ft_putunsigned(va_arg(args, unsigned int))); // ...traite le prochain argument comme un nombre non signé et renvoie sa longueur.
	else if (format == 'x' || format == 'X') // Si format est 'x' ou 'X'...
		return (ft_puthexadecimal(va_arg(args, unsigned int), format)); // ...traite le prochain argument comme un nombre hexadécimal et renvoie sa longueur.
	else if (format == '%') // Si format est '%'...
		return (ft_putchar('%')); // ...affiche un caractère '%' et renvoie 1.
	return (0); // Si format n'est pas reconnu, renvoie 0.
}

// Cette fonction est une implémentation simplifiée de printf. Elle prend une chaîne de format et une liste d'arguments variables,
// imprime les arguments en fonction du format et renvoie la longueur totale des arguments imprimés.
// Par exemple, ft_printf("Bonjour %s", "monde") affichera "Bonjour monde" à l'écran et renverra 12.
int	ft_printf(const char *format, ...)
{
	va_list	args; // Déclare une liste d'arguments.
	size_t	i; // Déclare un compteur pour parcourir la chaîne de format.
	int		length; // Déclare une variable pour stocker la longueur totale des arguments imprimés.

	if (!format) // Si format est NULL...
		return (-1); // ...renvoie -1.
	i = 0; // Initialise le compteur à 0.
	length = 0; // Initialise la longueur à 0.
	va_start(args, format); // Initialise la liste d'arguments avec format.
	while (format[i]) // Tant que le caractère actuel n'est pas le caractère de fin de chaîne...
	{
		if (format[i] == '%') // ...et si le caractère actuel est '%'...
		{
			length += ft_printf_arg(args, format[i + 1]); // ...traite le prochain argument en fonction du caractère suivant et ajoute sa longueur à length...
			i++; // ...et incrémente le compteur.
		}
		else // Si le caractère actuel n'est pas '%'...
			length += ft_putchar(format[i]); // ...affiche le caractère actuel et ajoute 1 à length.
		i++; // Incrémente le compteur.
	}
	va_end(args); // Termine la liste d'arguments.
	return (length); // Renvoie la longueur totale des arguments imprimés.
}
