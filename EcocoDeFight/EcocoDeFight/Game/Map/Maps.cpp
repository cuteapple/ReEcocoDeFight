#include "stdafx.h"
#include "Maps.h"
#include "MapFiles\MapA1.h"
#include "MapFiles\MapA2.h"
#include "MapFiles\MapA3.h"
#include "MapFiles\MapA4.h"
#include "MapFiles\MapA5.h"
namespace EcocoDeFight{
	const StageMap GameA[] = { MapA::Map1::map, MapA::Map2::map, MapA::Map3::map, MapA::Map4::map};
	const unsigned int GameACount = sizeof(GameA) / sizeof(StageMap);
	const StageMap GameB[1] = { 0 };
	const StageMap GameC[1] = { 0 };
};