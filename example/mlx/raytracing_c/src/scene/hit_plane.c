/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 22:34:21 by namkim            #+#    #+#             */
/*   Updated: 2022/11/01 20:21:58 by chaejkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/structures.h"
//#include "../includes/utils.h"
//#include "../includes/trace.h"
//#include <math.h>
//#include <assert.h>

t_bool	hit_plane(t_object *pl_obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	double	dn;

	pl = pl_obj->element;
	dn = vdot(ray->dir, pl->normal);	//
	if (fabs(dn) <= EPSILON)	//EPSILON or Zero?
		return (FALSE);
	rec->t = vdot(vminus(pl->coord, ray->orig), pl->normal) / dn;
	rec->p = ray_at(ray, rec->t);	//
	rec->normal = pl->normal;	//??? 이게 아닌 것 같음
	rec->albedo = pl_obj->albedo;
//	printf("rec->t : %f\n", rec->t);
//	printf("is rec->t > 0? : %d\n", rec->t > 0);
	assert(rec->t < EPSILON);
	return (rec->t > -EPSILON);
}
