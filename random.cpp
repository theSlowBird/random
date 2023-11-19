#include <bits/stdc++.h>
int MONTH = 12, PERSONS = 100;
#include "Elemental_Resonance.h"
using namespace std;
#define CALC(x) calc(x, options::set_content(#x));

auto calc_my(const vector<artifact>& s20221102, derived_from_character auto tao)
{
	cout << string(20, '=') << "begin " name2str(calc_my) << string(40, '=') << endl;
	auto equip = add_set(tao, s20221102);
	show(typeid(equip).name());
	show(equip.reaction_multi());
	show(equip.reaction_extra());
	//show(equip.reaction_rate());
	show(equip.evaluate());
	show(gain2ddB(equip.evaluate()));
	show(equip.crit_damage());
	equip.print();
	cout << string(20, '=') << "end " name2str(calc_my) << string(40, '=') << endl;
	return equip.evaluate();
}

int main(int argc, char** argv)
{
	// argv[0] == self.path
	switch (argc)
	{
	case 3:MONTH = stoi(argv[2]);
	case 2:PERSONS = stoi(argv[1]);
	}
	assert(10 == probability.size());
	assert(12 == main_value.size());
	assert(12 == sub_value_ratio.size());


	//calc_my([] {auto s20220601 = get_std_sets({HP,bonus,CR});
	//s20220601[0].sub_stat = { CR,CRD,EM };
	//s20220601[0].sub_value = { 2.5,1.7,3 };
	//s20220601[1].sub_stat = { CR,CRD,EM,hp };
	//s20220601[1].sub_value = { 1.7,0.7,3.4,0.8 };
	//s20220601[2].sub_stat = { CR,EM,atk };
	//s20220601[2].sub_value = { 4,0.7,0.9 };
	//s20220601[3].sub_stat = { CR,EM,CRD,HP };
	//s20220601[3].sub_value = { 2.6,1.9,1.8,0.7 };
	//s20220601[4].sub_stat = { hp,HP,CRD };
	//s20220601[4].sub_value = { 0.8,1.5,3.3 }; return s20220601; }(), Crimson_Witch_of_Flames(Staff_of_Homa(Hu_Tao::get()), 1));

	//calc_my([] { auto s20221102 = get_std_sets({ EM,EM,EM });
	//s20221102[0].sub_stat = { EM,CR,CRD };
	//s20221102[0].sub_value = { 0.7,0.9,3.7 };
	//s20221102[1].sub_stat = { EM,CR,CRD,ATK };
	//s20221102[1].sub_value = { 1.7,0.8,1.9,2.3 };
	//s20221102[2].sub_stat = { CR,CRD };
	//s20221102[2].sub_value = { 0,2.4 };
	//s20221102[3].sub_stat = { CR,CRD };
	//s20221102[3].sub_value = { 1.5,1.6 };
	//s20221102[4].sub_stat = { CR,CRD,atk };
	//s20221102[4].sub_value = { 1.6,0,1.6 }; return s20221102; }(), Deepwood_Memories(A_Thousand_Floating_Dreams(Nahida<false>::get(), 0)));

	//return 0;
	try
	{
		timer(true);
		//calc(Deepwood_Memories(A_Thousand_Floating_Dreams(Nahida::get())));

#ifndef _DEBUG
		CALC(Crimson_Witch_of_Flames(Staff_of_Homa(Hu_Tao::get()), 1));
#endif // !_DEBUG

		//calc(Crimson_Witch_of_Flames(Primordial_Jade_Winged_Spear(Hu_Tao::get())));
		//calc(Crimson_Witch_of_Flames(Dragon_s_Bane(Hu_Tao::get())));
		//calc(Elemental_2(Bonus_2(Staff_of_Homa(Hu_Tao::get()))));
		//calc(Elemental_2(Bonus_2(Staff_of_Homa(Hu_Tao::get()))), false, set22);
		//calc(Gilded_Dreams(Staff_of_Homa(Hu_Tao::get()), 0));

		//calc([] {auto x = Soothing_Water(healing_2(healing_2(Everlasting_Moonglow(Kokomi::get())))); x.value[healing] += 0.2; return x; }());

		//return 0;

		//calc(Elemental_2(ATK_2(Kagura_s_Verity(Yae_Miko::get_with_Kazuha()))));

#define Nahida Nahida<false>

#ifndef _DEBUG
		CALC(Deepwood_Memories(A_Thousand_Floating_Dreams(Nahida::get(), 0)));
#endif // !_DEBUG


		//calc(Elemental_2(Elemental_2(A_Thousand_Floating_Dreams(Nahida::get(), 0))), false, set22);
		//calc(Deepwood_Memories(Magic_Guide(Nahida::get())));
		//calc(Bonus_2(Elemental_2(A_Thousand_Floating_Dreams(Nahida::get(), 0))));
		//calc(Elemental_2(Elemental_2(A_Thousand_Floating_Dreams(Nahida::get(), 0))));
		//calc(Deepwood_Memories(Lost_Prayer_to_the_Sacred_Winds(Nahida::get(), 4)));
		//calc(Bonus_2(Elemental_2(Magic_Guide(Nahida::get()))));
		//calc(Deepwood_Memories(Sacrificial_Fragments(Nahida::get())));
		//calc(Deepwood_Memories(Fruit_of_Fulfillment(Nahida::get())));
#undef Nahida

		//CALC(Deepwood_Memories(A_Thousand_Floating_Dreams(Nahida<true>::get(), 0)));

//#define yoimiya Enduring_Rock(Zhong_Li(Yun_Jin_3(Yoimiya::get())))
//		calc(Shimenawa_s_Reminiscence(Thundering_Pulse(yoimiya)), true);
//		calc(Crimson_Witch_of_Flames(Thundering_Pulse(yoimiya), 1));
//		calc(Echoes_of_an_Offering(Thundering_Pulse(yoimiya)));
//		calc(ATK_2(Bonus_2(Thundering_Pulse(yoimiya))));
//		calc(Elemental_2(Bonus_2(Thundering_Pulse(yoimiya))));
#define yoimiya Fervent_Flames(Zhong_Li(Bannett(Yoimiya::get())))
//#define yoimiya Yoimiya::get()
		//auto rel = calc_my([] {auto s20220929 = get_std_sets({ EM,bonus,CRD });
		//s20220929[0].sub_stat = { EM,CR,CRD,ATK };
		//s20220929[0].sub_value = { 2.6,0.9,2.7,0.9 };
		//s20220929[1].sub_stat = { CR,CRD,ATK };
		//s20220929[1].sub_value = { 1.6,2.5,1.4 };
		//s20220929[2].sub_stat = { CR,CRD };
		//s20220929[2].sub_value = { 1.6,1.9 };
		//s20220929[3].sub_stat = { atk,CRD };
		//s20220929[3].sub_value = { 1.6,1.7 };
		//s20220929[4].sub_stat = { CR,atk };
		//s20220929[4].sub_value = { 4.4,1 }; return s20220929; }(), Shimenawa_s_Reminiscence(Slingshot(yoimiya)));

		//auto rel = calc_my([] {auto s20230105 = get_std_sets({ ATK,bonus,CR });
		//s20230105[0].sub_stat = { EM,CR,CRD,ATK };
		//s20230105[0].sub_value = { 2.6,0.9,2.7,0.9 };
		//s20230105[1].sub_stat = { CR,CRD,ATK };
		//s20230105[1].sub_value = { 1.6,2.5,1.4 };
		//s20230105[2].sub_stat = { CR,CRD,atk };
		//s20230105[2].sub_value = { 1.5,1.8,2.4 };
		//s20230105[3].sub_stat = { atk,CR,CRD,EM };
		//s20230105[3].sub_value = { 0.8,1.5,2.7,2 };
		//s20230105[4].sub_stat = { CRD,ATK,atk };
		//s20230105[4].sub_value = { 4.2,1,1.5 }; return s20230105; }(), Shimenawa_s_Reminiscence(Rust(yoimiya, 4)));

		//calc(Shimenawa_s_Reminiscence(Rust(yoimiya, 4)), options::set_refer_value(rel));
		//calc(Gilded_Dreams(Rust(yoimiya, 4), 1), options::set_refer_value(rel));
		//calc(Crimson_Witch_of_Flames(Rust(yoimiya, 4), 1), options::set_refer_value(rel));
//#undef yoimiya
//#define yoimiya Yoimiya::get()
//		calc(Shimenawa_s_Reminiscence(Thundering_Pulse(yoimiya)), options::set_refer(true));
//		calc(Crimson_Witch_of_Flames(Thundering_Pulse(yoimiya), 1));
//		calc(Gilded_Dreams(Thundering_Pulse(yoimiya), 1));
		//calc(Echoes_of_an_Offering(Thundering_Pulse(yoimiya)));
		//calc(ATK_2(Bonus_2(Thundering_Pulse(yoimiya))));
		//calc(Elemental_2(Bonus_2(Thundering_Pulse(yoimiya))));
		//calc(Shimenawa_s_Reminiscence(Rust(Yoimiya::get())));

		//calc(Elemental_2(Elemental_2(Bloom::get())));
		//calc(Flower_of_Paradise_Lost(Bloom::get()));
		//calc(Gilded_Dreams(Bloom::get(), 0));
		//calc(Elemental_2(Elemental_2(Bloom::get())), false, set22);

		//calc(Shattering_Ice(Amenoma_Kageuchi(Blizzard_Strayer(Ayaka::get(), true))));
		//calc(Shattering_Ice(Mistsplitter_Reforged(Blizzard_Strayer(Ayaka::get(), true))));

		// 丘丘王
		//calc(Shattering_Ice(Amos_Bow(Blizzard_Strayer(Gan_Yu::get(), false), 5)));

		//CALC(Sacrificial_Jade(Marechaussee_Hunter(Nuevillette::get(3))));
		//CALC(Kaedehara_Kazuha(Zhong_Li(Sacrificial_Jade(Marechaussee_Hunter(Nuevillette::get(3))))));
		//CALC(Lost_Prayer_to_the_Sacred_Winds(Marechaussee_Hunter(Nuevillette::get(3)), 4));
		//CALC(Tome_of_the_Eternal_Flow(Marechaussee_Hunter(Nuevillette::get(2))));

		auto rel = calc_my([] {auto std = get_std_sets({ DEF,bonus,DEF });
		std[0].sub_stat = { hp,CR,CRD };
		std[0].sub_value = { (14065 - main_value[hp]) / (main_value[hp] / sub_value_ratio[hp]),.21 / (main_value[CR] / sub_value_ratio[CR]),1.041 / (main_value[CRD] / sub_value_ratio[CRD]) };
		return std; }(), Tome_of_the_Eternal_Flow_80(Marechaussee_Hunter(Nuevillette::get()))); // 17385
	}
	catch (const string& e)
	{
		cout << e << endl;
	}
}
