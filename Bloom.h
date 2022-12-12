#pragma once
#include "tools.h"

class Bloom : public character
{
public:
	Bloom(const character& chara) :character(chara) {}
	double evaluate()const
	{
		return 1446.85 * reaction_base * (1 + reaction_extra());
	}
	static Bloom get(double EM = 0)
	{
		Bloom bloom({ 0,0,0,{::HP,::HP,::HP},{::HP, ::DEF, ::ATK, atk, ER, CR, CRD, bonus, healing, no_bonus} });
		bloom.value[::EM] = EM;
		bloom.reaction_base = 3;
		return bloom;
	}
};