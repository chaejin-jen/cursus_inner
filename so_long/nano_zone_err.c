// https://opensource.apple.com/source/libmalloc/libmalloc-140.40.1/src/nano_malloc.c
// src/nano_malloc.c

#if NANO_PREALLOCATE_BAND_VM
	// Unconditionally preallocate the VA space set aside for nano malloc to
	// reserve it in all configurations. rdar://problem/33392283
	// nano malloc이 모든 구성에서 예약할 수 있도록 VA 공간을 무조건 사전 할당합니다.
	boolean_t preallocated = nano_preallocate_band_vm();
	if (!preallocated && _malloc_engaged_nano) {
		_malloc_printf(ASL_LEVEL_NOTICE, "nano zone abandoned due to inability to preallocate reserved vm space.\n");
		_malloc_engaged_nano = 0;
	}
#endif
