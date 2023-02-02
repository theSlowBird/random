#pragma once
#include "tools.h"

class Ayaka :public character
{
public:
	Ayaka(const character& chara) :character(chara) {}
	static Ayaka get()
	{
		Ayaka ayaka({ 12858,342,784,{::ATK,bonus,CRD},{no_bonus,::HP,::DEF,ER,healing,EM} });
		ayaka.value[CRD] += 0.384;
		ayaka.value[bonus] += 0.18;
		ayaka.rate = 2.02;
		ayaka.reaction_type = none;
		return ayaka;
	}
};