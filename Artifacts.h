#pragma once
#include "random.h"

// 炽烈的炎之魔女
auto Crimson_Witch_of_Flames(derived_from_character auto chara, int e)
{
	chara.value[bonus] += 0.15 * (1 + e * 0.5);
	chara.reaction_multi_bonus += 0.15;
	chara.reaction_extra_bonus += 0.4;
	return chara;
}

// 获得15%某元素伤害加成。
auto Bonus_2(derived_from_character auto chara)
{
	chara.value[bonus] += 0.15;
	return chara;
}

// 饰金之梦
// 80 + 50 * 3
auto Gilded_Dreams(derived_from_character auto chara, int same)
{
	chara.value[EM] += 80 + 50 * (3 - same);
	chara.value[ATK] += 0.14 * same;
	return chara;
}

// 深林的记忆
auto Deepwood_Memories(derived_from_character auto chara)
{
	chara.value[bonus] += 0.15;
	chara.resistance -= 0.3;
	return chara;
}

// 元素精通提高80点。
auto Elemental_2(derived_from_character auto chara)
{
	chara.value[EM] += 80;
	return chara;
}

// 攻击力提高18%。
auto ATK_2(derived_from_character auto chara)
{
	chara.value[ATK] += 0.18;
	return chara;
}

// 治疗加成提高15%。
auto healing_2(derived_from_character auto chara)
{
	chara.value[healing] += 0.15;
	return chara;
}

// 追忆之注连
auto Shimenawa_s_Reminiscence(derived_from_character auto chara)
{
	chara.value[ATK] += 0.18;
	chara.value[bonus] += 0.5;
	return chara;
}

// 来歆余响
auto Echoes_of_an_Offering(derived_from_character auto chara)
{
	chara.value[ATK] += 0.18;
	chara.rate_add += 0.3;
	return chara;
}

// 乐园遗落之花
auto Flower_of_Paradise_Lost(derived_from_character auto chara)
{
	chara.value[EM] += 80;
	chara.reaction_extra_bonus += 0.8;
	return chara;
}

// 冰风迷途的勇士
auto Blizzard_Strayer(derived_from_character auto chara, bool freezable)
{
	chara.value[bonus] += 0.15;
	chara.value[CR] += 0.2 * (1 + freezable);
	return chara;
}

// 逐影猎人
auto Marechaussee_Hunter(derived_from_character auto chara, int hp_change = 3)
{
	chara.value[bonus] += 0.15;
	chara.value[CR] += 0.12 * hp_change;
	return chara;
}