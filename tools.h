#pragma once
#include "random.h"
#include "ddB.h"
#define name2str(x) #x
#define show(x) cerr << #x": " << x << endl;
extern int MONTH, PERSONS;

void timer(bool init = false)
{
	static auto begin_time = chrono::system_clock::now();
	if (init)
		return;
	decltype(begin_time) end_time;
	chrono::milliseconds duration;
	end_time = chrono::system_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(end_time - begin_time);
	cout << "timer " << duration.count() << " ms" << endl;
	begin_time = end_time;
}

auto add_set(derived_from_character auto tao, const vector<artifact>& artis)
{
	for (auto& i : artis)
	{
		tao.add(i);
	}
	return tao;
}

auto get_std_sets(const vector<attribute>& a)
{
	assert(3 == a.size());
	vector<artifact>std_sets(5);
	for (size_t i = 0; i < 5; i++)
	{
		do
		{
			std_sets[i] = artifact{ false };
		} while (!(std_sets[i].position == i
			&& (i != sands_of_eon || std_sets[i].main_stat == a[0])
			&& (i != goblet_of_enonthem || std_sets[i].main_stat == a[1])
			&& (i != circlet_of_logos || std_sets[i].main_stat == a[2])));
	}
	return std_sets;
}

double get_mean(const vector<double>& v)
{
	double sum = accumulate(v.begin(), v.end(), 0.);
	return sum / v.size();
}

double get_stdev(const vector<double>& v, double mean)
{
	double accum = 0;
	for (auto& i : v)
	{
		accum += (i - mean) * (i - mean);
	}
	return sqrt(accum / (v.size() - 1));
}

enum set_type
{
	set5, // 60% revise
	set4, // 4.5 per day
	set22 // 4.5 per day * 2
};

struct options
{
	bool refer = false;
	set_type set = set4;
	// 1 : k - 1, this set : others set
	// k == 1: no else
	// k == 3: equal else
	int k = 3;
	double refer_value = 0;
	string content;
	static options set_refer_value(double refer_value)
	{
		options op;
		op.refer_value = refer_value;
		return op;
	}
	static options set_refer(bool refer)
	{
		options op;
		op.refer = refer;
		return op;
	}
	static options set_content(const string& content)
	{
		options op;
		op.content = content;
		return op;
	}
};

namespace calc_data {
	static const vector<vector<int>> set22map{
		{0,0,1,1,2},
		{0,0,1,2,1},
		{0,0,2,1,1},

		{0,1,0,1,2},
		{0,1,0,2,1},
		{0,2,0,1,1},

		{0,1,1,0,2},
		{0,1,2,0,1},
		{0,2,1,0,1},

		{0,1,1,2,0},
		{0,1,2,1,0},
		{0,2,1,1,0},

		{1,0,0,1,2},
		{1,0,0,2,1},
		{2,0,0,1,1},

		{1,0,1,0,2},
		{1,0,2,0,1},
		{2,0,1,0,1},

		{1,0,1,2,0},
		{1,0,2,1,0},
		{2,0,1,1,0},

		{1,1,0,0,2},
		{1,2,0,0,1},
		{2,1,0,0,1},

		{1,1,0,2,0},
		{1,2,0,1,0},
		{2,1,0,1,0},

		{1,1,2,0,0},
		{1,2,1,0,0},
		{2,1,1,0,0},
	};
	// position, set_type, value
	static const auto set22invmap = [] {vector<vector<vector<int>>>set22invmap(5);
	for (size_t i = 0; i < 5; i++)
		set22invmap[i].resize(3);
	for (size_t i = 0; i < set22map.size(); i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			set22invmap[j][set22map[i][j]].push_back(i);
		}
	}
	return set22invmap; }();
}

template<derived_from_character Tao>
void calc(const Tao& tao, options op = {})
{
	cout << string(20, '=') << "begin " name2str(calc) << op.content << string(40, '=') << endl;
	static vector<double>reference;
	// get std_sets
	auto std_sets = get_std_sets(tao.basic);
	// parameter
	vector<vector<double>>ave(MONTH);
	cout << "PERSONS: " << PERSONS << endl;
	for (size_t i = 0; i < MONTH; i++)
		ave[i].reserve(PERSONS);
	// average attribute
	vector<vector<double>>show{ character::label_print().size() }, sub{ no_bonus };
	for (auto& i : show)
		i.reserve(PERSONS), sub.reserve(PERSONS);
	auto show_pb = [&show](const vector<double>& res) {for (size_t i = 0; i < show.size(); i++)show[i].push_back(res[i]); };
	auto sub_pb = [&sub, &tao](const vector<double>& now) {for (size_t i = 0; i < no_bonus; i++)sub[i].push_back(now[i] - tao.value[i]); };
	auto check_ban = [&tao](attribute stat) {for (auto& i : tao.ban)if (stat == i)return true; return false; };

	uniform_int_distribution<>rat(0, op.k);
	map<size_t, int>freq;
	auto show_odd = [&freq]() {for (auto& i : freq)cerr << "odd " << i.first << ": " << i.second << endl; cerr << endl; };
	switch (op.set)
	{
	case set5:
		for (size_t person = 0; person < PERSONS; person++)
		{
			auto sets(std_sets);
			Tao equip = add_set(tao, sets);
			auto damage = equip.evaluate();
			for (size_t month = 1; month <= MONTH; month++)
			{
				for (size_t i = 0; i < 270; i++)
				{
					if (uniform_int_distribution<>(0, 4)(gen) < 2)
						continue;
					artifact a{ false };
					if (check_ban(a.main_stat))
						continue;
					a.gen_sub();
					auto tmp_equip{ equip };
					tmp_equip.sub(sets[a.position]);
					tmp_equip.add(a);
					auto tmp_damage = tmp_equip.evaluate();
					if (tmp_damage > damage)
					{
						damage = tmp_damage;
						equip = tmp_equip;
						sets[a.position] = a;
					}
				}
				ave[month - 1].push_back(damage);
			}
			show_pb(equip.later_print());
			sub_pb(equip.value);
		}
		break;
	case set4:
		for (size_t person = 0; person < PERSONS; person++)
		{
			vector<vector<artifact>>set4;
			vector<Tao>equips;
			vector<double>damages;
			for (size_t i = 0; i < 5; i++)
			{
				set4.push_back(std_sets);
				equips.push_back(add_set(tao, std_sets));
				damages.push_back(equips.back().evaluate());
			}
			for (size_t month = 1; month <= MONTH; month++)
			{
				for (size_t i = 0; i < 135; i++)
				{
					// 额外算散件
					while (rat(gen) != 0)
					{
						artifact e{ false };
						if (check_ban(e.main_stat))
							continue;
						e.gen_sub();
						auto tmp_equip{ equips[e.position] };
						tmp_equip.sub(set4[e.position][e.position]);
						tmp_equip.add(e);
						auto tmp_damage = tmp_equip.evaluate();
						if (tmp_damage > damages[e.position])
						{
							damages[e.position] = tmp_damage;
							equips[e.position] = tmp_equip;
							set4[e.position][e.position] = e;
						}
					}
					artifact a{ false };
					if (check_ban(a.main_stat))
						continue;
					a.gen_sub();
					for (size_t i = 0; i < 5; i++)
					{
						auto tmp_equip{ equips[i] };
						tmp_equip.sub(set4[i][a.position]);
						tmp_equip.add(a);
						auto tmp_damage = tmp_equip.evaluate();
						if (tmp_damage > damages[i])
						{
							damages[i] = tmp_damage;
							equips[i] = tmp_equip;
							set4[i][a.position] = a;
						}
					}
				}
				ave[month - 1].push_back(*max_element(damages.begin(), damages.end()));
			}
			auto id = max_element(damages.begin(), damages.end()) - damages.begin();
			++freq[id];
			show_pb(equips[id].later_print());
			sub_pb(equips[id].value);
		}
		show_odd();
		break;
	case set22:
		using calc_data::set22map;
		using calc_data::set22invmap;
		for (size_t person = 0; person < PERSONS; person++)
		{
			vector<vector<artifact>>set22;
			vector<Tao>equips;
			vector<double>damages;
			for (size_t i = 0; i < set22map.size(); i++)
			{
				set22.push_back(std_sets);
				equips.push_back(add_set(tao, std_sets));
				damages.push_back(equips.back().evaluate());
			}
			for (size_t month = 1; month <= MONTH; month++)
			{
				for (size_t i = 0; i < 270; i++)
				{
					while (rat(gen) != 0)
					{
						artifact e{ false };
						if (check_ban(e.main_stat))
							continue;
						e.gen_sub();
						for (auto& i : set22invmap[e.position][2])
						{
							auto tmp_equip{ equips[i] };
							tmp_equip.sub(set22[i][e.position]);
							tmp_equip.add(e);
							auto tmp_damage = tmp_equip.evaluate();
							if (tmp_damage > damages[i])
							{
								damages[i] = tmp_damage;
								equips[i] = tmp_equip;
								set22[i][e.position] = e;
							}
						}
					}
					artifact a{ false };
					if (check_ban(a.main_stat))
						continue;
					a.gen_sub();
					auto set_id = uniform_int_distribution<>(0, 1)(gen);
					for (auto& id : { set_id,2 })
					{
						for (auto& i : set22invmap[a.position][id])
						{
							auto tmp_equip{ equips[i] };
							tmp_equip.sub(set22[i][a.position]);
							tmp_equip.add(a);
							auto tmp_damage = tmp_equip.evaluate();
							if (tmp_damage > damages[i])
							{
								damages[i] = tmp_damage;
								equips[i] = tmp_equip;
								set22[i][a.position] = a;
							}
						}
					}
				}
				ave[month - 1].push_back(*max_element(damages.begin(), damages.end()));
			}
			auto id = max_element(damages.begin(), damages.end()) - damages.begin();
			++freq[id];
			show_pb(equips[id].later_print());
			sub_pb(equips[id].value);
		}
		show_odd();
		break;
	}
	cout << left;
	auto ref = add_set(tao, std_sets);
	cout << "ref: " << ref.evaluate() << endl;
	auto label = character::label_print();
	for (size_t i = 0; i < label.size(); i++)
	{
		auto get_length = [&label]() {size_t ret = 0; for (auto& i : label)ret = max(ret, i.size()); return ret; };
		cout << setw(get_length()) << label[i] << ": " << get_mean(show[i]) << endl;
	}
	cout << endl;
	Tao mean = tao;
	for (size_t i = 0; i < no_bonus; i++)
	{
		mean.value[i] = get_mean(sub[i]) + tao.value[i];
		if (abs(mean.value[i] - ref.value[i]) < 1e-10)
			mean.value[i] = ref.value[i];
	}

	auto get_length = [] {size_t ret = 0; for (size_t i = 0; i < no_bonus; i++)ret = max(ret, name[i].size()); return ret; };
	cout << setw(get_length()) << "Attri" << ": "
		<< setw(9) << "mean" << " - "
		<< setw(9) << "ref" << " = "
		<< setw(9) << "D-value" << " => "
		<< setw(7) << "D-count" << ", "
		<< "ddB/count" << endl;
	for (size_t i = 0; i < no_bonus; i++)
	{
		Tao that = mean;
		artifact arti{ false };
		arti.main_stat = no_value;
		arti.sub_stat.push_back(static_cast<attribute>(i));
		arti.sub_value.push_back(0.85);
		that.sub(arti);
		cout << setw(get_length()) << name[i] << ": "
			<< setw(9) << mean.value[i] << " - "
			<< setw(9) << ref.value[i] << " = "
			<< setw(9) << mean.value[i] - ref.value[i] << " => "
			<< setw(7) << (mean.value[i] - ref.value[i]) / (main_value[i] / sub_value_ratio[i] * 0.85) << ", "
			<< gain2ddB(mean.evaluate() / that.evaluate()) << endl;
	}
	cout << endl;
	stringstream ss;
	ss << typeid(Tao).name() << ",MONTH=" << MONTH << ",PERSONS=" << PERSONS << ".csv";
	string filename = regex_replace(ss.str(), regex("[<>:\"/\\\\|?*]"), "_");
	show(filename);
	ofstream fout(filesystem::path("data") / filename);
	if (!fout)
	{
		cerr << "can not open file \"" + filename << '\"' << endl;
		exit(1);
	}
	cout << typeid(Tao).name() << endl;
	fout << "month,mean,stdev\n";
	// no reference, then force to reference
	if (reference.empty())
		op.refer = true;
	if (op.refer)
		reference.clear();
	// exists reference, then use this
	if (op.refer_value)
	{
		op.refer = false;
		reference = vector<double>(MONTH, op.refer_value);
	}
	for (size_t month = 0; month < MONTH; month += max(1, MONTH / 20))
	{
		auto mean = get_mean(ave[month]);
		auto stdev = get_stdev(ave[month], mean);
		auto get_length = [](size_t month) {for (size_t i = 1;; ++i, month /= 10)if (month < 10)return i; };
		cout << setw(get_length(MONTH)) << month + 1 << " month, ";
		cout << "person / expectation ~ N( " << setw(7) << mean << ", "
			<< setw(7) << stdev << " / "
			<< setw(7) << stdev / sqrt(PERSONS) << " ), ";
		//cout << "mean: " << setw(7) << mean << ", ";
		//cout << "stdev: " << setw(7) << stdev << ", ";
		cout << "at_crit ~ N( " << setw(7) << gain2ddB(mean / ref.evaluate()) << ", "
			<< setw(8) << gain2ddB((mean + stdev) / (mean - stdev)) / 2 << " / "
			<< setw(8) << gain2ddB((mean + stdev / sqrt(PERSONS)) / (mean - stdev / sqrt(PERSONS))) / 2 << " ), ";
		//cout << "crit/1w: " << setw(7) << gain2ddB(mean / 10000) << ", ";
		// restore reference
		if (op.refer)
			reference.push_back(mean);
		else
			cout << gain2ddB(mean / reference[month]);
		cout << endl;
		fout << month + 1 << ',' << mean << ',' << stdev << endl;
	}
	timer();
	fout << ref.evaluate() << ',' << op.content;
	cout << string(20, '=') << "end " name2str(calc) << string(40, '=') << endl;
}
