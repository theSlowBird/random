#pragma once
#include "tools.h"

class Yae_Miko :public character
{
public:
	double e_bonus = 0;
	Yae_Miko(const character& chara) :character(chara) {}
	// no override
	double e_base()const
	{
		return (15 * ATK() * 1.706 + 5 * reaction_base * 1446 * (1 + reaction_rate())) * (0.0015 * em() + e_bonus + Bonus());
	}
	// no override
	double q_base()const
	{
		return (4.68 + 6.01 * 3) * ATK() + 4 * reaction_base * 1446 * (1 + reaction_rate()) * Bonus();
	}
	// 3e(15)+q
	double evaluate()const override
	{
		return (3 * e_base() + q_base()) * crit() * Resistance() * defend;
	}
	static Yae_Miko get()
	{
		Yae_Miko yae_miko({ 10372,340,569,{EM,bonus,CR},{no_bonus,::HP,::DEF,ER,healing} });
		yae_miko.value[CR] += 0.192;
		yae_miko.reaction_type = ::rate;
		yae_miko.reaction_base = 1.15;
		return yae_miko;
	}
	static Yae_Miko get_with_Kazuha()
	{
		Yae_Miko yae_miko(get());
		yae_miko.value[bonus] += 0.35;
		return yae_miko;
	}
};