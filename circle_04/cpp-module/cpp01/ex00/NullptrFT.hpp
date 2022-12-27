#pragma once
#ifndef __NULLPTRFT_H__
#define __NULLPTRFT_H__

// ************************************************************************** //
//                               NULLPTRFT Class                                //
// ************************************************************************** //

const							/* this is a const object...	 */
class NullptrFT
{
public:
	template<typename T>
	operator T*() const			/* convertible to any type of null non-member pointer... */
	{ return 0; }

	template<typename C, typename T> 
	operator T C::*() const		/* or any type of null member pointer...			*/
	{ return 0; }	

private:
	void operator&() const;		/* Can't take address of NullptrFT */

} nullptrFT = {};					/* and whose name is NullptrFT	 */

#endif /* __NULLPTRFT_H__ */