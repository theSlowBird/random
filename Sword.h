#pragma once
#include "random.h"

// ��ĿӰ��
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Amenoma_Kageuchi(Tao chara)
{
	chara.baseATK += 454;
	chara.value[ATK] += 0.551;
	return chara;
}

// ����֮�ع�
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Mistsplitter_Reforged(Tao chara)
{
	chara.baseATK += 674;
	chara.value[CRD] += 0.441;
	chara.value[bonus] += 0.12 + 0.28;
	return chara;
}