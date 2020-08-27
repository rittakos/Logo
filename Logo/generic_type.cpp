#ifndef GENERIC_TYPE_HPP
#define GENERIC_TYPE_HPP

template<class T>
class Type
{
public:
	explicit Type(T* p = nullptr) { ptr = p; }
private:
	T* ptr;
};

#endif