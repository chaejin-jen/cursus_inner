	if (op.merge_dst == A)
	{
		// TOP   MID   BOT
		// B_BOT A_BOT B_TOP
		if (op.merge_loc == TOP)
			;// B_BOT 으로 보내야함
		else if (op.merge_loc == MID)
			;// A_BOT 으로 보내야함
		else
			;// B_TOP 으로 보내야함
		return ;
	}
	// TOP   MID   BOT
	// B_BOT A_BOT A_TOP
	if (op.merge_loc == TOP)
		;// B_BOT 에서 B로 보내야함
	else if (op.merge_loc == MID)
		;// A_BOT 에서 B로 보내야함
	else
		;// A_TOP 에서 B로 보내야함



====================

{
	long	n[2];
	int		i;

	i = -1;
	if (len[TOP])
		n[++i] = ;
	else if (len[MID])
		n[++i] = (long)(a->info.tail->content);
	else
	{
		if (op.merge_dst == A)
			n[++i] = (long)(b->info.head->content);
		else
			n[++i] = (long)(a->info.head->content);
	}
	if (op.order == ASCENDING)
	{
		if (n[0] > n[1])
		{
			if (len[TOP])
				return (TOP);
			if (len[MID])
				return (MID);
		}
	}
	if (n[0] < n[1])
		return (TOP);
