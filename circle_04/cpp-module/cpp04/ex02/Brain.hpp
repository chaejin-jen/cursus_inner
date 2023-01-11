#pragma once
#ifndef __Brain_H__
#define __Brain_H__

#include <iostream>
#include <string>

// ************************************************************************** //
//                               BRAIN Class                                //
// ************************************************************************** //

class Brain {
	public:
		Brain(void);
		Brain(const Brain &other);
		Brain& operator=(const Brain& other);
		~Brain(void);
		void putIdeas(void) const;
		void setIdea(std::string idea, int idx) ;
		//void copyIdeas() ;

	protected:
		std::string	ideas[100];
		
		void	_empty_brain(void);
};

#endif /* __Brain_H__ */
