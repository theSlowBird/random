#pragma once
#include "random.h"

// 飞雷之弦振
auto Thundering_Pulse(derived_from_character auto chara)
{
	chara.add_baseATK(608);
	chara.value[CRD] += 0.662;
	chara.value[ATK] += 0.2;
	chara.value[bonus] += 0.4;
	return chara;
}

// 弹弓
auto Slingshot(derived_from_character auto chara)
{
	chara.add_baseATK(354);
	chara.value[CR] += 0.312;
	chara.value[bonus] += 0.6;
	return chara;
}

// 弓藏
auto Rust(derived_from_character auto chara, int rank)
{
	chara.add_baseATK(510);
	chara.value[ATK] += 0.413;
	chara.value[bonus] += 0.3 + rank * 0.1;
	return chara;
}

// 阿莫斯之弓
auto Amos_Bow(derived_from_character auto chara, int time)
{
	chara.add_baseATK(608);
	chara.value[ATK] += 0.496;
	chara.value[bonus] += 0.12 + time * 0.08;
	return chara;
}
