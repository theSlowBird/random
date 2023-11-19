#pragma once
#include "random.h"

auto Zhong_Li(derived_from_character auto chara)
{
	chara.resistance -= 0.2;
	return chara;
}

auto Yun_Jin_3(derived_from_character auto chara)
{
	chara.value[bonus] += 0.15;
	// color == 3
	chara.base_damage_add += 2594 * (0.6834 + 0.075);
	return chara;
}

auto Bannett(derived_from_character auto chara)
{
	chara.value[atk] += 749 * 1.32;
	chara.value[ATK] += 0.2;
	return chara;
}

auto Kaedehara_Kazuha(derived_from_character auto chara)
{
	chara.resistance -= 0.4;
	chara.value[bonus] += 0.4;
	return chara;
}
