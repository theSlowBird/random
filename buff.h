#pragma once
#include "random.h"

template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Zhong_Li(Tao chara)
{
	chara.resistance -= 0.2;
	return chara;
}

template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Yun_Jin_3(Tao chara)
{
	chara.value[bonus] += 0.15;
	// color == 3
	chara.base_damage_add += 2594 * (0.6834 + 0.075);
	return chara;
}

template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Bannett(Tao chara)
{
	chara.value[atk] += 749 * 1.32;
	chara.value[ATK] += 0.2;
	return chara;
}