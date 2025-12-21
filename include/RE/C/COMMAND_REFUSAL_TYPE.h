#pragma once

namespace RE
{
	enum class COMMAND_REFUSAL_TYPE : std::uint32_t
	{
		kNone = 0x0,
		kAny = 0x1,
		kImpossible = 0x2,
		kMoral = 0x3,
		
		kTotal = 0x4
	};
}
