/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeherzi <xeherzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:08:32 by xeherzi           #+#    #+#             */
/*   Updated: 2023/08/23 12:27:39 by xeherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	exit_error(const char *message, int exit_code)

{
	fprintf(stderr, "Error: %s\n", message);
	exit(exit_code);
}
