#pragma once
#include "tools.h"

class Nuevillette :public character
{
public:
	Nuevillette(const character& chara) :character(chara) {}
	double base_damage()const override
	{
		return rate * HP();
	}
	static Nuevillette get(int reaction_type = 2)
	{
		//Nuevillette nuevillette({ 14695,208,576,{::HP,bonus,CRD},{no_bonus,::ATK,::DEF,ER,healing,EM} });
		//nuevillette.value[CRD] += 0.384;
		//// 重击·衡平推裁
		//nuevillette.rate = 0.1447;
		Nuevillette nuevillette({ 12965,184,509,{::HP,bonus,CRD},{no_bonus,::ATK,::DEF,ER,healing,EM} });
		nuevillette.value[CRD] += 0.288;
		// 重击·衡平推裁
		nuevillette.rate = 0.1251;
		nuevillette.reaction_type = none;
		// 至高仲裁的纪律
		nuevillette.value[bonus] += 0.3;
		// 古海孑遗的权柄
		switch (reaction_type)
		{
		case 1:nuevillette.rate *= 1.1; break;
		case 2:nuevillette.rate *= 1.25; break;
		case 3:nuevillette.rate *= 1.6; break;
		default:
			break;
		}
		return nuevillette;
	}
};