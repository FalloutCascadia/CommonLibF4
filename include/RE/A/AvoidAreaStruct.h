#pragma once

#include "RE/B/BSPathingAvoidNode.h"

namespace RE
{
	class TESObjectREFR;

	struct AvoidAreaStruct
	{
		BSPathingAvoidNode avoideNode;  // 00
		float              timeExpire;  // 24
		TESObjectREFR*     refObj;      // 28
		AvoidAreaStruct*   next;        // 30
	};
	static_assert(sizeof(AvoidAreaStruct) == 0x38);
}
