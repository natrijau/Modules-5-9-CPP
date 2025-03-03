#ifndef	__SERIALIZER_HPP__
#define	__SERIALIZER_HPP__

#include 	<iostream>
#include	<stdint.h>

struct Data
{
	unsigned int	id;
	std::string		message;
};

class Serializer
{
	private:
	
		Serializer();
		Serializer(const Serializer &copy);
		Serializer& operator=(const Serializer&);
		~Serializer();

	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
