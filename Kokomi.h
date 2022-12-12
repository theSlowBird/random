#pragma once
#include "tools.h"

class Kokomi :public character
{
public:
	Kokomi(const character& chara) :character(chara) {}
	double evaluate()const
	{
		return (0.0792 * HP() + 932.22) * (1 + value[healing]);
	}
	static Kokomi get()
	{
		Kokomi kokomi({ 13471,234,657,{::HP,::HP,healing},{no_bonus,::ATK,::DEF,ER,EM,CR,CRD,bonus} });
		kokomi.value[bonus] += 0.288;
		return kokomi;
	}
};