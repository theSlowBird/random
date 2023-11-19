#pragma once
#include "random.h"

// 天目影打刀
auto Amenoma_Kageuchi(derived_from_character auto chara)
{
	chara.add_baseATK(454);
	chara.value[ATK] += 0.551;
	return chara;
}

// 雾切之回光
auto Mistsplitter_Reforged(derived_from_character auto chara)
{
	chara.add_baseATK(674);
	chara.value[CRD] += 0.441;
	chara.value[bonus] += 0.12 + 0.28;
	return chara;
}