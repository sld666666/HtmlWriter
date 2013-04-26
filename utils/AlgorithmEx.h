/** 
* @file         AlgorithmEx.h 
* @Synopsis       
* @author         diwu.sld
* @version      1.0
* @date         2013-4-25
*/

#ifndef UTILS_UTILS_ALGORITHMEX_H
#define UTILS_UTILS_ALGORITHMEX_H


template <class InputIterator, class OutputIterator, class UnaryPredicate>
OutputIterator copy_if (InputIterator first, InputIterator last,
						OutputIterator result, UnaryPredicate pred)
{
	while (first!=last) {
		if (pred(*first)) {
			*result = *first;
			++result;
		}
		++first;
	}
	return result;
}

#endif
