#pragma once
#include <bits/stdc++.h>
#define invalid(x) "invalid "#x" = "+to_string(x)
using namespace std;

default_random_engine gen(static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count()));

enum attribute
{
	HP, hp, DEF, def, ATK, atk, ER, EM, CR, CRD, bonus, healing, no_bonus, no_value
};
const vector<string>name = { "HP", "hp", "DEF", "def", "ATK", "atk", "ER", "EM", "CR", "CRD", "bonus", "healing", "no_bonus", "no_value" };

enum part
{
	flower_of_life,
	plume_of_death,
	sands_of_eon,
	goblet_of_enonthem,
	circlet_of_logos
};

enum reaction
{
	extra, multi, rate, none
};

const vector<int>probability{ 4,6,4,6,4,6,4,4,3,3 };
const vector<double>main_value{ 0.466,4780,0.583,370.4,0.466,311,0.518,186.5,0.311,0.622,0.466,0.359 };
const vector<int>sub_value_ratio{ 8,16,8,16,8,16,8,8,8,8,8,8 };
const vector<double>initial_value{ 0,4780,0,0,0,311,1,0,0.05,0.5,0,0 };

int sum_probability(const vector<attribute>& v)
{
	int ret = 0;
	for (auto& i : v)
	{
		ret += probability[i];
	}
	return ret;
}

class artifact
{
public:
	part position;
	attribute main_stat;
	vector<attribute>sub_stat;
	vector<double>sub_value;
	artifact(bool full = true)
	{
		position = static_cast<part>(uniform_int_distribution<>(0, 4)(gen));
		// main_stat
		main_stat = no_value;
		switch (position)
		{
		case flower_of_life:main_stat = hp; break;
		case plume_of_death:main_stat = atk; break;
		case sands_of_eon:
			// 26.67 : 26.67 : 26.67 : 10 : 10
			switch (uniform_int_distribution<>(0, 4)(gen))
			{
			case 0:
				switch (uniform_int_distribution<>(0, 1)(gen))
				{
				case 0:main_stat = EM; break;
				case 1:main_stat = ER; break;
				}
				break;
			default:
				switch (uniform_int_distribution<>(0, 2)(gen))
				{
				case 0:main_stat = HP; break;
				case 1:main_stat = DEF; break;
				case 2:main_stat = ATK; break;
				}
			}
			break;
		case goblet_of_enonthem:
			if (uniform_real_distribution<>(0, 100)(gen) < 2.5 + 5 * 8)
			{
				switch (uniform_int_distribution<>(0, 16)(gen))
				{
				case 0:main_stat = EM; break;
				case 1:
				case 2:main_stat = bonus; break;
				default:
					main_stat = no_bonus;
				}
			}
			else
			{
				switch (uniform_int_distribution<>(0, 2)(gen))
				{
				case 0:main_stat = HP; break;
				case 1:main_stat = DEF; break;
				case 2:main_stat = ATK; break;
				}
			}
			break;
		case circlet_of_logos:
			if (uniform_int_distribution<>(0, 99)(gen) < 34)
			{
				if (uniform_int_distribution<>(0, 33)(gen) < 4)
				{
					main_stat = EM;
				}
				else
				{
					switch (uniform_int_distribution<>(0, 2)(gen))
					{
					case 0:main_stat = CRD; break;
					case 1:main_stat = CR; break;
					case 2:main_stat = healing; break;
					}
				}
			}
			else
			{
				switch (uniform_int_distribution<>(0, 2)(gen))
				{
				case 0:main_stat = HP; break;
				case 1:main_stat = DEF; break;
				case 2:main_stat = ATK; break;
				}
			}
			break;
		}
		if (full)
			gen_sub();
	}
	void gen_sub()
	{
		vector<attribute>list{ HP,hp,DEF,def,ATK,atk,ER,EM,CR,CRD };
		// sub_stat
		if (main_stat <= CRD)
		{
			list.erase(lower_bound(list.begin(), list.end(), main_stat));
		}
		for (size_t i = 0; i < SUB; i++)
		{
			int s = sum_probability(list);
			int x = uniform_int_distribution<>(0, s - 1)(gen);
			int now_sum = 0;
			for (size_t j = 0; j < list.size(); j++)
			{
				if (now_sum <= x && x < now_sum + probability[list[j]])
				{
					sub_stat.push_back(list[j]);
					list.erase(lower_bound(list.begin(), list.end(), list[j]));
					break;
				}
				now_sum += probability[list[j]];
			}
		}
		assert(list.size() + (main_stat <= CRD) == 6);
		// sub_values
		// 20%
		for (size_t i = 0; i < SUB; i++)
		{
			sub_value.push_back(uniform_int_distribution<>(7, 10)(gen) / 10.);
		}
		int upgrade = 4 + (uniform_int_distribution<>(0, 4)(gen) == 0);
		for (size_t i = 0; i < upgrade; i++)
		{
			sub_value[uniform_int_distribution<>(0, 3)(gen)] += uniform_int_distribution<>(7, 10)(gen) / 10.;
		}
	}
	bool have_attribute(attribute attr)const
	{
		//if (main_stat == attr)
		//	return true;
		for (auto& i : sub_stat)
		{
			if (i == attr)
				return true;
		}
		return false;
	}
private:
	static const int SUB = 4;
};

class character
{
public:
	double baseHP, baseATK, baseDEF;
	vector<double>value;
	double reaction_multi_bonus = 0;
	double reaction_extra_bonus = 0;
	double reaction_rate_bonus = 0;
	double rate = 0;
	reaction reaction_type = none;
	double reaction_base = 0;
	double defend = 0.5;
	double resistance = 0.1;
	vector<attribute>basic, ban;
	// for initialize
	character(double baseHP, double baseATK, double baseDEF, const vector<attribute>& basic, const vector<attribute>& ban) :baseHP(baseHP), baseATK(baseATK), baseDEF(baseDEF), basic(basic), ban(ban)
	{
		value.resize(no_bonus);
		value[CR] = 0.05;
		value[CRD] = 0.5;
		value[ER] = 1;
	}
	void add(const vector<attribute>& stat, const vector<double>& value)
	{
		for (size_t i = 0; i < stat.size(); i++)
		{
			if (stat[i] <= healing)
			{
				this->value[stat[i]] += value[i];
			}
		}
	}
	void add(const artifact& arti)
	{
		if (arti.main_stat <= healing)
		{
			value[arti.main_stat] += main_value[arti.main_stat];
		}
		for (size_t i = 0; i < arti.sub_stat.size(); i++)
		{
			value[arti.sub_stat[i]] += arti.sub_value[i] * main_value[arti.sub_stat[i]] / sub_value_ratio[arti.sub_stat[i]];
		}
	}
	void sub(const artifact& arti)
	{
		if (arti.main_stat <= healing)
		{
			value[arti.main_stat] -= main_value[arti.main_stat];
		}
		for (size_t i = 0; i < arti.sub_stat.size(); i++)
		{
			value[arti.sub_stat[i]] -= arti.sub_value[i] * main_value[arti.sub_stat[i]] / sub_value_ratio[arti.sub_stat[i]];
		}
	}
	void add_baseATK(double baseATK)
	{
		this->baseATK += baseATK;
	}
	double HP()const
	{
		return baseHP * (1 + value[::HP]) + value[hp];
	}
	virtual double ATK()const
	{
		return baseATK * (1 + value[::ATK]) + value[atk];
	}
	double DEF()const
	{
		return baseDEF * (1 + value[::DEF]) + value[def];
	}
	virtual double Bonus()const
	{
		return 1 + value[bonus];
	}
	virtual double cr()const
	{
		return value[CR];
	}
	double crd()const
	{
		return value[CRD];
	}
	virtual double em()const
	{
		return value[EM];
	}
	double crit()const
	{
		return max(0., min(1., cr())) * crd() + 1;
	}
	double reaction_multi()const
	{
		return reaction_multi_bonus + 2.78 * em() / (1400 + em());
	}
	double reaction_extra()const
	{
		return reaction_extra_bonus + 16 * em() / (2000 + em());
	}
	double reaction_rate()const
	{
		return reaction_rate_bonus + 5 * em() / (1200 + em());
	}
	virtual double base_damage()const
	{
		return ATK() * rate;
	}
	double Resistance()const
	{
		if (resistance > 0)
			return 1 - resistance;
		return 1 - resistance / 2;
	}
	virtual double evaluate()const
	{
		switch (reaction_type)
		{
		case multi:return base_damage() * Bonus() * crit() * reaction_base * (1 + reaction_multi()) * Resistance() * defend;
		case ::rate:return (base_damage() + reaction_base * 1446 * (1 + reaction_rate())) * Bonus() * crit() * Resistance() * defend;
		case none:return base_damage() * Bonus() * crit() * Resistance() * defend;
		}
		throw "no reaction_type";
	}
	double crit_damage()const
	{
		return evaluate() / crit() * (1 + crd());
	}
	vector<double> later_print()const
	{
		return { ATK(),base_damage(),HP(),value[EM],Bonus(),cr(),crd() };
	}
	static vector<string> label_print()
	{
		return { "atk","base_damage","hp","EM","bonus","cr","crd" };// , "raction_rate", "not_rate"
	}
	void print()const
	{
		auto label = label_print();
		auto value = later_print();
		for (size_t i = 0; i < label.size(); i++)
		{
			cout << label[i] << ": " << value[i] << endl;
		}
	}
};