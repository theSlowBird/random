#pragma once
#include "Hu_Tao.h"
#include "Nahida.h"
#include "Yae_Miko.h"
#include "Kokomi.h"
#include "Yoimiya.h"
#include "Bloom.h"
#include "buff.h"

// ����֮ˮ
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Soothing_Water(Tao chara)
{
	chara.value[HP] += 0.25;
	return chara;
}

// �ᶨ֮��
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Enduring_Rock(Tao chara)
{
	chara.value[bonus] += 0.15;
	return chara;
}

// �ȳ�֮��
template<typename Tao, typename = enable_if_t<is_base_of<character, Tao>::value>>
auto Fervent_Flames(Tao chara)
{
	chara.value[ATK] += 0.25;
	return chara;
}