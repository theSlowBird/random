#pragma once
#include "random.h"

// 千夜浮梦
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto A_Thousand_Floating_Dreams(Tao chara, int same)
{
	if (!(same >= 0 && same <= 3))
		throw invalid(same);
	chara.baseATK += 542;
	chara.value[EM] += 265;
	chara.value[EM] += 32 * same;
	chara.value[bonus] += 0.1 * (3 - same);
	return chara;
}

// 四风原典
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Lost_Prayer_to_the_Sacred_Winds(Tao chara, int time4)
{
	if (!(time4 >= 0 && time4 <= 4))
		throw invalid(time4);
	chara.baseATK += 608;
	chara.value[CR] += 0.331;
	chara.value[bonus] += 0.08 * time4;
	return chara;
}

// 盈满之实
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Fruit_of_Fulfillment(Tao chara)
{
	chara.baseATK += 510;
	chara.value[ER] += 0.459;
	chara.value[EM] += 36 * 5;
	chara.value[ATK] -= 0.05 * 5;
	return chara;
}

// 魔导绪论
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Magic_Guide(Tao chara)
{
	chara.baseATK += 354;
	chara.value[EM] += 187;
	chara.value[bonus] += 0.24;
	return chara;
}

// 神乐之真意
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Kagura_s_Verity(Tao chara)
{
	chara.baseATK += 608;
	chara.value[CRD] += 0.662;
	chara.e_bonus += 0.12 * 3;
	chara.value[bonus] += 0.12;
	return chara;
}

// 试作金珀
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Prototype_Amber(Tao chara)
{
	chara.baseATK += 510;
	chara.value[HP] += 0.413;
	return chara;
}

// 不灭月华
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Everlasting_Moonglow(Tao chara)
{
	chara.baseATK += 608;
	chara.value[HP] += 0.496;
	chara.value[healing] += 0.1;
	return chara;
}

// 祭礼残章
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Sacrificial_Fragments(Tao chara)
{
	chara.baseATK += 454;
	chara.value[EM] += 221;
	return chara;
}

