dst, src 순서에 따라 in a or in b
flag 에 따라 print 문구 결정
info 에는 depth(이거에 따라 asc, decs??), size(이거에 따라 계속 재귀할지..)
void	sort(t_stack *dst, t_stack *src, t_flag flag, t_sort_info info)

push_sort(dst, src, flag, order)
	push_asc
	push_desc

swap_sort(dst, src, flag, location)
	swap_sort_in_top
	swap_sort_in_bottom

sort_asc_in_a
	1. sort_top (push_b_desc)    -> b 위
	2. sort_mid (push_b_asc, rr) -> b 아래로
	3. sort_bot (rr, sa)         -> a 아래
	4. merge_asc_in_a
sort_desc_in_a
	1. sort_top (push_b_asc)    -> b 위
	2. sort_mid (push_b_desc, rr) -> b 아래로
	3. sort_bot (rr, sa)         -> a 아래
	4. merge_desc_in_a
sort_asc_in_b
	1. sort_top (push_b_asc, rr) -> b 아래로
	2. sort_mid (rr, sa)         -> a 아래
	3. sort_bot (ra, rra, sa)    -> a 위
	4. merge_asc_in_b
sort_desc_in_b
	1. sort_top (push_b_desc, rr) -> b 아래로
	2. sort_mid (rr, sa)         -> a 아래
	3. sort_bot (ra, rra, sa)    -> a 위
	4. merge_desc_in_b

TOP - .... - T M B
MID - .... - T M B
BOT - .... - T M B

{
A
	T - B_TOP (B)
		T - B_BOT (B)
			T - B_BOT (B)
			M - A_BOT (A)
			B - A_TOP (A)
			merge
			//rrb
		M - A_BOT (A)
			T - B_TOP (B)
			M - B_BOT (B)
			B - A_BOT (A)
			merge
			//rra
		T, M rr
		B - A_TOP (A)
			T - B_TOP (B)
			M - B_BOT (B)
			B - A_BOT (A)
			merge
	M - B_BOT (B)
		T - B_BOT (B)
		M - A_BOT (A)
		B - A_TOP (A)
		merge
		//rrb
	B - A_BOT (A)
		T - B_TOP (B)
		M - B_BOT (B)
		B - A_BOT (A)
		merge
		//rra
	M-B rr
	merge

T - B_BOT (B)
M - A_BOT (A)
B - A_TOP (A)

T - B_TOP (B)
M - B_BOT (B)
B - A_BOT (A)

}
B_TOP -> B_BOT, A_BOT, A_TOP -> merge
		 (B_TOP, A_TOP, rr, A_TOP)
B_BOT -> B_BOT, A_BOT, A_TOP -> merge -> rr
		 (B_TOP, A_TOP, rr, A_TOP)
A_TOP -> B_TOP, B_BOT, A_BOT -> merge
		 (B_TOP, B_TOP, A_TOP, rr)
A_BOT -> B_TOP, B_BOT, A_BOT -> merge -> rr
		 (B_TOP, B_TOP, A_TOP, rr)

===========================

top_size = mid_size
		 = (int)(stack_size / 3)
bot_size
		 = (int)(stack_size / 3 + stack_size % 3)
===========================

TOP 무조건 B_BOT (오름차순)
		B_TOP (오름차순)
MID 무조건 A_BOT (오름차순)
		A_TOP (오름차순)
	rr 사용
BOT sort 할 위치 반대편 TOP
	A_TOP ()
	B_TOP (내림차순)

{
	A
		T - B_BOT (B) - 오름차순
			T - B_BOT (B)
			M - A_BOT (A)
			B - A_TOP (A)
			merge
			//rrb
		M - A_BOT (A) - 오름차순
			T - B_BOT (B)
			M - A_BOT (A)
			B - B_TOP (B)
			merge
			//rra
		rr(T, B)
		B - B_TOP (B) - 내림차순
			T - B_BOT (B) 내림차순
				T - B_BOT (B) 내림차순
				M - A_BOT (A) 내림차순
				B - A_TOP (A) 오름차순
				merge
				//rrb
			M - A_BOT (A) 내림차순
				T - B_BOT (B) 내림차순
				M - A_BOT (A) 내림차순
				B - B_TOP (B) 오름차순
				merge
				//rra
			rr (T, M)
			B - A_TOP (A) 오름차순
				T - B_BOT (B)
				M - A_BOT (A)
				B - B_TOP (B)
		merge

	T - B_BOT (B)
	M - A_BOT (A)
	B - A_TOP (A)

	T - B_BOT (B)
	M - A_BOT (A)
	B - B_TOP (B)
}

A
	BAB
		BAA
	T - B_BOT (B)
			T - B_BOT (B)
			M - A_BOT (A)
			B - A_TOP (A)
			merge
			//rrb
		M - A_BOT (A)
			T - B_BOT (B)
			M - A_BOT (A)
			B - B_TOP (B)
			merge
			//rra
		rr(T, B)
		B - B_TOP (B)
			T - B_BOT (B)
				T - B_BOT (B)
				M - A_BOT (A)
				B - A_TOP (A)
				merge
				//rrb
			M - A_BOT (A)
				T - B_BOT (B)
				M - A_BOT (A)
				B - B_TOP (B)
				merge
				//rra
			rr (T, M)
			B - A_TOP (A)
				T - B_BOT (B)
				M - A_BOT (A)
				B - B_TOP (B)

B_TOP -> B_BOT, A_BOT, A_TOP -> merge
		 (B_TOP, A_TOP, rr, A_TOP)
B_BOT -> B_BOT, A_BOT, A_TOP -> merge -> rr
		 (B_TOP, A_TOP, rr, A_TOP)
A_TOP -> B_BOT, A_BOT, B_TOP -> merge
		 (B_TOP, B_TOP, rr, A_TOP)
A_BOT -> B_BOT, A_BOT, B_TOP -> merge
		 (B_TOP, B_TOP, rr, A_TOP)
