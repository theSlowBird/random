#pragma once
#include "tools.h"

template<bool q>
class Nahida :public character
{
public:
	Nahida(const character& chara) :character(chara) {}
	double em()const
	{
		return value[EM] * (4 + q) / 4;
	}
	double Bonus()const
	{
		return 1 + value[bonus] + min(0.8, max(0., em() - 200) * 0.001);
	}
	double cr()const
	{
		return value[CR] + min(0.24, max(0., em() - 200) * 0.0003);
	}
	double base_damage()const
	{
		return character::base_damage() + 3.715 * em();
	}
	static Nahida get()
	{
		Nahida nahida({ 10360,299,630,{EM,EM,EM},{no_bonus,::HP,::DEF,ER,healing} });
		nahida.value[EM] += 115.2;
		nahida.rate = 1.858;
		nahida.reaction_type = ::rate;
		nahida.reaction_base = 1.25;
		return nahida;
	}
};

class Nahida_sub :public Nahida<false>
{
public:
	Nahida_sub(const character& chara) :Nahida(chara) {}
	double evaluate()const
	{
		return character::evaluate() * (value[EM] < 1000 ? pow(2, -10 / 31.) : 1);// 0.800
		//return character::evaluate() * min(1., value[EM] / 1000);
		//return character::evaluate() * (value[EM] < 1000 ? pow(value[EM] / 1000, 2) : 1);
	}
	static Nahida_sub get()
	{
		return Nahida_sub{ Nahida::get() };
	}
};