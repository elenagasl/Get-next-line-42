/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:10:35 by elengarc          #+#    #+#             */
/*   Updated: 2025/04/20 10:10:38 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void	print_lines(int fd)
{
	char	*line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	printf("\n\n");
	close(fd);
}

int	main(void)
{
	int	fd;

	// Caso 1: Fichero con líneas, con salto de línea al final
	fd = open("tests1.txt", O_RDONLY);
	printf ("Caso 1: líneas con \\n final \n");
	print_lines(fd);

	// Caso 2: Fichero con líneas, con salto de línea al final
	fd = open("tests2.txt", O_RDONLY);
	printf ("Caso 2: Líneas sin \\n final \n");
	print_lines(fd);


	// Caso 3: Archivo vacío
	fd = open("tests3.txt", O_RDONLY);
	printf ("Caso 3: Archivo vacío \n");
	print_lines(fd);

	// Caso 4: Una línea larga con salto de línea al final
	fd = open("tests4.txt", O_RDONLY);
	printf ("Caso 4: Línea larga con salto \n");
	print_lines(fd);

	// Caso 5: Una línea larga sin salto de línea
	fd = open("tests5.txt", O_RDONLY);
	printf ("Caso 5: Línea larga sin salto \n");
	print_lines(fd);

	// Caso 6: Fichero que no existe
	fd = open("tests6.txt", O_RDONLY);
	printf ("Caso 6: archivo que no existe \n");
	print_lines(fd);

	// Probar también buffer size incorrecto.

	return (0);
}
