#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <stdint.h>
#include <string>
#include <iostream>

struct Data
{
	int	id;
	std::string	str;
	double	value;

	Data(int i, const std::string& s, double val) : id(i), str(s), value(val) {}
};


class Serializer {
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(const Serializer& value);
	Serializer&	operator=(const Serializer& val);
	~Serializer();
};

#endif