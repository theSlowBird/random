#pragma once
#include "random.h"

// ���ҵ���֮ħŮ
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Crimson_Witch_of_Flames(Tao chara, int e)
{
	chara.value[bonus] += 0.15 * (1 + e * 0.5);
	chara.reaction_multi_bonus += 0.15;
	chara.reaction_extra_bonus += 0.4;
	return chara;
}

// ���15%ĳԪ���˺��ӳɡ�
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Bonus_2(Tao chara)
{
	chara.value[bonus] += 0.15;
	return chara;
}

// �ν�֮��
// 80 + 50 * 3
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Gilded_Dreams(Tao chara, int same)
{
	chara.value[EM] += 80 + 50 * (3 - same);
	chara.value[ATK] += 0.14 * same;
	return chara;
}

// ���ֵļ���
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Deepwood_Memories(Tao chara)
{
	chara.value[bonus] += 0.15;
	chara.resistance -= 0.3;
	return chara;
}

// Ԫ�ؾ�ͨ���80�㡣
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Elemental_2(Tao chara)
{
	chara.value[EM] += 80;
	return chara;
}

// 	���������18%��
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto ATK_2(Tao chara)
{
	chara.value[ATK] += 0.18;
	return chara;
}

// 	���Ƽӳ����15%��
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto healing_2(Tao chara)
{
	chara.value[healing] += 0.15;
	return chara;
}

// 	׷��֮ע��
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Shimenawa_s_Reminiscence(Tao chara)
{
	chara.value[ATK] += 0.18;
	chara.value[bonus] += 0.5;
	return chara;
}

// 	�������
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Echoes_of_an_Offering(Tao chara)
{
	chara.value[ATK] += 0.18;
	chara.rate_add += 0.3;
	return chara;
}

// 	��԰����֮��
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Flower_of_Paradise_Lost(Tao chara)
{
	chara.value[EM] += 80;
	chara.reaction_extra_bonus += 0.8;
	return chara;
}