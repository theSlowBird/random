#pragma once
#include "tools.h"

class Hu_Tao :public character
{
public:
	Hu_Tao(const character& chara) :character(chara) {}
	double HPrate = 0.0626;
	double ATK()const override
	{
		return HP() * HPrate + character::ATK();
	}
	static Hu_Tao get()
	{
		Hu_Tao hutao({ 15552,106,876,{EM,bonus,CR},{no_bonus,::DEF,::ATK,ER,healing} });
		hutao.value[CRD] += 0.384;
		hutao.value[bonus] += 0.33;
		hutao.rate = 2.426;
		hutao.reaction_type = multi;
		hutao.reaction_base = 1.5;
		return hutao;
	}
};