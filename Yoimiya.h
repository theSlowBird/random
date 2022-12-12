#pragma once
#include "tools.h"

class Yoimiya :public character
{
public:
	Yoimiya(const character& chara) :character(chara) {}
	double reaction_rate_ = (0.6359 + 1.5859 + 1.8887) * 1.6174;
	double base_damage_add = 0;
	double rate_add = 0;
	double reaction_base_damage()const
	{
		return ATK() * (rate - reaction_rate_) + (base_damage_add + rate_add * ATK()) * 4
			+ (ATK() * reaction_rate_ + (base_damage_add + rate_add * ATK()) * 3) * reaction_base * (1 + reaction_multi());
	}
	double evaluate()const
	{
		return reaction_base_damage() * Bonus() * crit() * Resistance() * defend;
	}
	static Yoimiya get(const attribute& head = CR, int buff_self = 7)
	{
		Yoimiya yoimiya({ 10164,323,615,{EM,bonus,head},{no_bonus,::DEF,::HP,ER,healing} });
		yoimiya.value[CR] += 0.192;
		yoimiya.value[bonus] += 0.02 * buff_self;
		yoimiya.rate = (0.6359 * 2 + 1.2199 + 1.5859 + 0.8282 * 2 + 1.8887) * 1.6174;
		yoimiya.reaction_type = multi;
		yoimiya.reaction_base = 1.5;
		// ‘∆›¿£¨À´—“£¨÷”¿Î
		return yoimiya;
	}
};