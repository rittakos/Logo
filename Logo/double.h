#ifndef DOUBLE_H
#define DOUBLE_H

#define EPSILON 0.01



class Double
{
public:
	Double(double d) : value{d}{}
	operator double()
	{
		return value;
	}
private:
	double value;
};

bool operator==(Double d1, Double d2)
{
	std::cout << d1 << std::endl;
	if (d1 - EPSILON < d2 && d2 < d1 + EPSILON)
		return true;
	return false;
}

bool operator==(Double d, int i)
{
	if (d - EPSILON < i && i < d + EPSILON)
		return true;
	return false;
}

#endif
