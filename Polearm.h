#pragma once
#include "random.h"

// 护摩之杖
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Staff_of_Homa(Tao chara)
{
	chara.baseATK += 608;
	chara.value[CRD] += 0.662;
	chara.value[HP] += 0.2;
	chara.HPrate += 0.018;
	return chara;
}

// 匣里灭辰
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Dragon_s_Bane(Tao chara)
{
	chara.baseATK += 454;
	chara.value[EM] += 221;
	chara.value[bonus] += 0.36;
	return chara;
}

// 和璞鸢
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Primordial_Jade_Winged_Spear(Tao chara)
{
	chara.baseATK += 674;
	chara.value[CR] += 0.221;
	chara.value[ATK] += 0.032 * 7;
	chara.value[bonus] += 0.12;
	return chara;
}