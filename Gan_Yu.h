#pragma once
#include "tools.h"

class Gan_Yu :public character
{
public:
	Gan_Yu(const character& chara) :character(chara) {}
	static Gan_Yu get()
	{
		Gan_Yu ganyu({ 9797,335,630,{::ATK,bonus,CRD},{no_bonus,::HP,::DEF,ER,healing,EM} });
		ganyu.value[CRD] += 0.384;
		// 霜华矢·霜华绽发
		ganyu.rate = 3.92;
		ganyu.reaction_type = none;
		return ganyu;
	}
};