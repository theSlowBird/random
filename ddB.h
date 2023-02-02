#pragma once
#include <cmath>

double gain2ddB(double gain)
{
	return 100 * log10(gain);
}

double ddB2gain(double ddB)
{
	return pow(10, ddB / 100);
}