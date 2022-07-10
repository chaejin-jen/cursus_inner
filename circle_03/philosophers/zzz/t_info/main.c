/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:44:06 by chaejkim          #+#    #+#             */
/*   Updated: 2022/07/10 18:32:20 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_simulation_info	sinfo;
	t_table_info		table;

	if (set_simulation(argc, argv, &sinfo) != 0)
		return (1);
	if (run_simulation(&sinfo, table) != 0)
		return (1);
	// if (clear_table(&table, sinfo.number) != 0)
		// return (1);
	// clear_sinfo(&sinfo);
}
