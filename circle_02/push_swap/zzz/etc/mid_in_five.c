long	mid_in_five(long *n)
{
	int		i;
	int		j;
	long	tmp;

	i = -1;
	while (++i < 4)
	{
		j = i - 1;
		while (++j < 4)
		{
			if (n[i] > n[j])
			{
				tmp = n[i];
				n[i] = n[j];
				n[j] = tmp;
			}
		}
	}
	return (n[2]);
}
