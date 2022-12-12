#pragma once
#include "random.h"

// 炽烈的炎之魔女
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Crimson_Witch_of_Flames(Tao chara, int e)
{
	chara.value[bonus] += 0.15 * (1 + e * 0.5);
	chara.reaction_multi_bonus += 0.15;
	chara.reaction_extra_bonus += 0.4;
	return chara;
}

// 获得15%某元素伤害加成。
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Bonus_2(Tao chara)
{
	chara.value[bonus] += 0.15;
	return chara;
}

// 饰金之梦
// 80 + 50 * 3
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Gilded_Dreams(Tao chara, int same)
{
	chara.value[EM] += 80 + 50 * (3 - same);
	chara.value[ATK] += 0.14 * same;
	return chara;
}

// 深林的记忆
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Deepwood_Memories(Tao chara)
{
	chara.value[bonus] += 0.15;
	chara.resistance -= 0.3;
	return chara;
}

// 元素精通提高80点。
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Elemental_2(Tao chara)
{
	chara.value[EM] += 80;
	return chara;
}

// 	攻击力提高18%。
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto ATK_2(Tao chara)
{
	chara.value[ATK] += 0.18;
	return chara;
}

// 	治疗加成提高15%。
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto healing_2(Tao chara)
{
	chara.value[healing] += 0.15;
	return chara;
}

// 	追忆之注连
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Shimenawa_s_Reminiscence(Tao chara)
{
	chara.value[ATK] += 0.18;
	chara.value[bonus] += 0.5;
	return chara;
}

// 	来歆余响
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Echoes_of_an_Offering(Tao chara)
{
	chara.value[ATK] += 0.18;
	chara.rate_add += 0.3;
	return chara;
}

// 	乐园遗落之花
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Flower_of_Paradise_Lost(Tao chara)
{
	chara.value[EM] += 80;
	chara.reaction_extra_bonus += 0.8;
	return chara;
}