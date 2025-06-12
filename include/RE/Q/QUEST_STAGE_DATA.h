#pragma once

namespace RE
{
	class QUEST_STAGE_DATA
	{
	public:
		// members
		std::uint16_t index;  // 00
		std::uint8_t  flags;  // 02
	};
	static_assert(sizeof(QUEST_STAGE_DATA) == 0x4);
}