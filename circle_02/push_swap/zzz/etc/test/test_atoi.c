int	main(void)
{
	printf("%d\n",ft_atoi("2147483647"));
	printf("%d\n",ft_atoi("-2147483648"));
	printf("%d\n",ft_atoi("2147483648"));
	printf("%d\n",ft_atoi("-2147483649"));
	printf("%d\n",ft_atoi("4294967295"));
	printf("%d\n",ft_atoi("-4294967296"));
	printf("%d\n",ft_atoi("4294967296"));
	printf("%d\n",ft_atoi("-4294967297"));

	printf("%p\n",(void *)ft_atoi("1"));
	if ((void *)ft_atoi("1") == 1)
		printf("0x1 == 1\n");
	else
		printf("0x1 == 1\n")

}
