#pragma once
#include "Hu_Tao.h"
#include "Nahida.h"
#include "Yae_Miko.h"
#include "Kokomi.h"
#include "Yoimiya.h"
#include "Bloom.h"
#include "buff.h"

// 愈疗之水
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Soothing_Water(Tao chara)
{
	chara.value[HP] += 0.25;
	return chara;
}

// 坚定之岩
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Enduring_Rock(Tao chara)
{
	chara.value[bonus] += 0.15;
	return chara;
}

// 热诚之火
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Fervent_Flames(Tao chara)
{
	chara.value[ATK] += 0.25;
	return chara;
}