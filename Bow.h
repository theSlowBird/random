#pragma once
#include "random.h"

// ����֮����
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Thundering_Pulse(Tao chara)
{
	chara.baseATK += 608;
	chara.value[CRD] += 0.662;
	chara.value[ATK] += 0.2;
	chara.value[bonus] += 0.4;
	return chara;
}

// ����
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Slingshot(Tao chara)
{
	chara.baseATK += 354;
	chara.value[CR] += 0.312;
	chara.value[bonus] += 0.6;
	return chara;
}

// ����
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Rust(Tao chara, int rank)
{
	chara.baseATK += 510;
	chara.value[ATK] += 0.413;
	chara.value[bonus] += 0.3 + rank * 0.1;
	return chara;
}

// ��Ī˹֮��
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Amos_Bow(Tao chara, int time)
{
	chara.baseATK += 608;
	chara.value[ATK] += 0.496;
	chara.value[bonus] += 0.12 + time * 0.08;
	return chara;
}
