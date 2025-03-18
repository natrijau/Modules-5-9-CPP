#ifndef	__EASYFIND_HPP__
#define	__EASYFIND_HPP__

#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<exception>

template <typename T>
typename T::iterator	easyfind(T &a, const int &nb)
{
	typename T::iterator it = std::find(a.begin(), a.end(), nb);
	if (it == a.end())
		throw	std::runtime_error("Nb not found!");
    return (it);
}

#endif