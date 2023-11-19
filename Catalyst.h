#pragma once
#include "random.h"

// 千夜浮梦
auto A_Thousand_Floating_Dreams(derived_from_character auto chara, int same)
{
	if (!(same >= 0 && same <= 3))
		throw invalid(same);
	chara.add_baseATK(542);
	chara.value[EM] += 265;
	chara.value[EM] += 32 * same;
	chara.value[bonus] += 0.1 * (3 - same);
	return chara;
}

// 四风原典
auto Lost_Prayer_to_the_Sacred_Winds(derived_from_character auto chara, int time4)
{
	if (!(time4 >= 0 && time4 <= 4))
		throw invalid(time4);
	chara.add_baseATK(608);
	chara.value[CR] += 0.331;
	chara.value[bonus] += 0.08 * time4;
	return chara;
}

// 盈满之实
auto Fruit_of_Fulfillment(derived_from_character auto chara)
{
	chara.add_baseATK(510);
	chara.value[ER] += 0.459;
	chara.value[EM] += 36 * 5;
	chara.value[ATK] -= 0.05 * 5;
	return chara;
}

// 魔导绪论
auto Magic_Guide(derived_from_character auto chara)
{
	chara.add_baseATK(354);
	chara.value[EM] += 187;
	chara.value[bonus] += 0.24;
	return chara;
}

// 神乐之真意
auto Kagura_s_Verity(derived_from_character auto chara)
{
	chara.add_baseATK(608);
	chara.value[CRD] += 0.662;
	chara.e_bonus += 0.12 * 3;
	chara.value[bonus] += 0.12;
	return chara;
}

// 试作金珀
auto Prototype_Amber(derived_from_character auto chara)
{
	chara.add_baseATK(510);
	chara.value[HP] += 0.413;
	return chara;
}

// 不灭月华
auto Everlasting_Moonglow(derived_from_character auto chara)
{
	chara.add_baseATK(608);
	chara.value[HP] += 0.496;
	chara.value[healing] += 0.1;
	return chara;
}

// 祭礼残章
auto Sacrificial_Fragments(derived_from_character auto chara)
{
	chara.add_baseATK(454);
	chara.value[EM] += 221;
	return chara;
}

// 遗祀玉珑
auto Sacrificial_Jade(derived_from_character auto chara, bool stay_no_10s = true)
{
	chara.add_baseATK(454);
	chara.value[CR] += .368;
	if (stay_no_10s)
	{
		chara.value[HP] += .32;
		chara.value[EM] += 40;
	}
	return chara;
}

// 万世流涌大典
auto Tome_of_the_Eternal_Flow(derived_from_character auto chara, int hp_change = 3)
{
	chara.add_baseATK(542);
	chara.value[CRD] += .882;
	chara.value[HP] += .16;
	if (hp_change)
	{
		chara.value[bonus] += .14 * hp_change;
	}
	return chara;
}

// 万世流涌大典
auto Tome_of_the_Eternal_Flow_80(derived_from_character auto chara, int hp_change = 3)
{
	chara.add_baseATK(475);
	chara.value[CRD] += .804;
	chara.value[HP] += .16;
	if (hp_change)
	{
		chara.value[bonus] += .14 * hp_change;
	}
	return chara;
}
