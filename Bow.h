#pragma once
#include "random.h"

// ·ÉÀ×Ö®ÏÒÕñ
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Thundering_Pulse(Tao chara)
{
	chara.baseATK += 608;
	chara.value[CRD] += 0.662;
	chara.value[ATK] += 0.2;
	chara.value[bonus] += 0.4;
	return chara;
}

// µ¯¹­
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Slingshot(Tao chara)
{
	chara.baseATK += 354;
	chara.value[CR] += 0.312;
	chara.value[bonus] += 0.6;
	return chara;
}

// ¹­²Ø
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Rust(Tao chara)
{
	chara.baseATK += 510;
	chara.value[ATK] += 0.413;
	chara.value[bonus] += 0.8;
	return chara;
}
