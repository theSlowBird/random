﻿#include <bits/stdc++.h>
int MONTH = 12, PERSONS = 100;
#include "Artifacts.h"
#include "Catalyst.h"
#include "Polearm.h"
#include "Bow.h"
#include "Elemental_Resonance.h"
#define show(x) cout<<#x" = "<<x<<endl;
using namespace std;

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


	{auto s20220601 = get_std_sets({ HP,bonus,CR });
	s20220601[0].sub_stat = { CR,CRD,EM };
	s20220601[0].sub_value = { 2.5,1.7,3 };
	s20220601[1].sub_stat = { CR,CRD,EM,hp };
	s20220601[1].sub_value = { 1.7,0.7,3.4,0.8 };
	s20220601[2].sub_stat = { CR,EM,atk };
	s20220601[2].sub_value = { 4,0.7,0.9 };
	s20220601[3].sub_stat = { CR,EM,CRD,HP };
	s20220601[3].sub_value = { 2.6,1.9,1.8,0.7 };
	s20220601[4].sub_stat = { hp,HP,CRD };
	s20220601[4].sub_value = { 0.8,1.5,3.3 };

	Hu_Tao equip = add_set(Crimson_Witch_of_Flames(Staff_of_Homa(Hu_Tao::get()), 1), s20220601);
	show(typeid(equip).name());
	show(equip.reaction_multi());
	show(equip.reaction_extra());
	show(equip.reaction_rate());
	show(equip.evaluate());
	show(equip.crit_damage());
	equip.print();
	cout << endl; }

	{auto s20221102 = get_std_sets({ EM,EM,EM });
	s20221102[0].sub_stat = { EM,CR,CRD };
	s20221102[0].sub_value = { 0.7,0.9,3.7 };
	s20221102[1].sub_stat = { EM,CR,CRD,ATK };
	s20221102[1].sub_value = { 1.7,0.8,1.9,2.3 };
	s20221102[2].sub_stat = { CR,CRD };
	s20221102[2].sub_value = { 0,2.4 };
	s20221102[3].sub_stat = { CR,CRD };
	s20221102[3].sub_value = { 1.5,1.6 };
	s20221102[4].sub_stat = { CR,CRD,atk };
	s20221102[4].sub_value = { 1.6,0,1.6 };

	auto equip = add_set(Deepwood_Memories(A_Thousand_Floating_Dreams(Nahida<false>::get(), 0)), s20221102);
	show(typeid(equip).name());
	show(equip.reaction_multi());
	show(equip.reaction_extra());
	show(equip.reaction_rate());
	show(equip.evaluate());
	show(equip.crit_damage());
	equip.print();
	cout << endl; }

	//return 0;
	try
	{
		timer(true);
		//calc(Deepwood_Memories(A_Thousand_Floating_Dreams(Nahida::get())));

		calc(Crimson_Witch_of_Flames(Staff_of_Homa(Hu_Tao::get()), 1));
		//calc(Crimson_Witch_of_Flames(Primordial_Jade_Winged_Spear(Hu_Tao::get())));
		//calc(Crimson_Witch_of_Flames(Dragon_s_Bane(Hu_Tao::get())));
		//calc(Elemental_2(Bonus_2(Staff_of_Homa(Hu_Tao::get()))));
		//calc(Elemental_2(Bonus_2(Staff_of_Homa(Hu_Tao::get()))), false, set22);
		//calc(Gilded_Dreams(Staff_of_Homa(Hu_Tao::get()), 0));

		//calc([] {auto x = Soothing_Water(healing_2(healing_2(Everlasting_Moonglow(Kokomi::get())))); x.value[healing] += 0.2; return x; }());

		//return 0;

		//calc(Elemental_2(ATK_2(Kagura_s_Verity(Yae_Miko::get_with_Kazuha()))));

#define Nahida Nahida<false>
		//calc(Deepwood_Memories(A_Thousand_Floating_Dreams(Nahida::get(), 0)), true);
		//calc(Elemental_2(Elemental_2(A_Thousand_Floating_Dreams(Nahida::get(), 0))), false, set22);
		//calc(Deepwood_Memories(Magic_Guide(Nahida::get())));
		//calc(Bonus_2(Elemental_2(A_Thousand_Floating_Dreams(Nahida::get(), 0))));
		//calc(Elemental_2(Elemental_2(A_Thousand_Floating_Dreams(Nahida::get(), 0))));
		//calc(Deepwood_Memories(Lost_Prayer_to_the_Sacred_Winds(Nahida::get(), 4)));
		//calc(Bonus_2(Elemental_2(Magic_Guide(Nahida::get()))));
		//calc(Deepwood_Memories(Sacrificial_Fragments(Nahida::get())));
		//calc(Deepwood_Memories(Fruit_of_Fulfillment(Nahida::get())));

//#define yoimiya Enduring_Rock(Zhong_Li(Yun_Jin_3(Yoimiya::get())))
//		calc(Shimenawa_s_Reminiscence(Thundering_Pulse(yoimiya)), true);
//		calc(Crimson_Witch_of_Flames(Thundering_Pulse(yoimiya), 1));
//		calc(Echoes_of_an_Offering(Thundering_Pulse(yoimiya)));
//		calc(ATK_2(Bonus_2(Thundering_Pulse(yoimiya))));
//		calc(Elemental_2(Bonus_2(Thundering_Pulse(yoimiya))));
#define yoimiya Fervent_Flames(Zhong_Li(Bannett(Yoimiya::get())))
//#define yoimiya Yoimiya::get()
		{auto s20221102 = get_std_sets({ EM,bonus,CRD });
		s20221102[0].sub_stat = { EM,CR,CRD,ATK };
		s20221102[0].sub_value = { 2.6,0.9,2.7,0.9 };
		s20221102[1].sub_stat = { CR,CRD,ATK };
		s20221102[1].sub_value = { 1.6,2.5,1.4 };
		s20221102[2].sub_stat = { CR,CRD };
		s20221102[2].sub_value = { 1.6,1.9 };
		s20221102[3].sub_stat = { atk,CRD };
		s20221102[3].sub_value = { 1.6,1.7 };
		s20221102[4].sub_stat = { CR,atk };
		s20221102[4].sub_value = { 4.4,1 };

		auto equip = add_set(Shimenawa_s_Reminiscence(Slingshot(yoimiya)), s20221102);
		show(typeid(equip).name());
		show(equip.reaction_multi());
		show(equip.reaction_extra());
		//show(equip.reaction_rate());
		show(equip.evaluate());
		show(equip.crit_damage());
		equip.print();
		cout << endl; }
		//calc(Shimenawa_s_Reminiscence(Thundering_Pulse(yoimiya)));
		//calc(Crimson_Witch_of_Flames(Thundering_Pulse(yoimiya), 1));
		//calc(Echoes_of_an_Offering(Thundering_Pulse(yoimiya)));
		//calc(ATK_2(Bonus_2(Thundering_Pulse(yoimiya))));
		//calc(Elemental_2(Bonus_2(Thundering_Pulse(yoimiya))));
		calc(Shimenawa_s_Reminiscence(Slingshot(yoimiya)));
		//calc(Shimenawa_s_Reminiscence(Rust(Yoimiya::get())));

		//calc(Elemental_2(Elemental_2(Bloom::get())));
		//calc(Flower_of_Paradise_Lost(Bloom::get()));
		//calc(Gilded_Dreams(Bloom::get(), 0));
		//calc(Elemental_2(Elemental_2(Bloom::get())), false, set22);
	}
	catch (const string& e)
	{
		cout << e << endl;
	}
}
