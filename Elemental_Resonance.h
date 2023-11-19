#pragma once
#include "Artifacts.h"
#include "Catalyst.h"
#include "Polearm.h"
#include "Bow.h"
#include "Sword.h"

#include "Hu_Tao.h"
#include "Nahida.h"
#include "Yae_Miko.h"
#include "Kokomi.h"
#include "Yoimiya.h"
#include "Bloom.h"
#include "Ayaka.h"
#include "Gan_Yu.h"
#include "Nuevillette.h"

#include "buff.h"

// 愈疗之水
auto Soothing_Water(derived_from_character auto chara)
{
	chara.value[HP] += 0.25;
	return chara;
}

// 坚定之岩
auto Enduring_Rock(derived_from_character auto chara)
{
	chara.value[bonus] += 0.15;
	return chara;
}

// 热诚之火
auto Fervent_Flames(derived_from_character auto chara)
{
	chara.value[ATK] += 0.25;
	return chara;
}

// 粉碎之冰
auto Shattering_Ice(derived_from_character auto chara)
{
	chara.value[CR] += 0.15;
	return chara;
}