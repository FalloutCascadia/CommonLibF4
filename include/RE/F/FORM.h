#pragma once

namespace RE
{
	class FORM
	{
	public:
		// members
		std::uint32_t form;            // 00
		std::uint32_t length;          // 04
		std::uint32_t flags;           // 08
		TESFormID     formID;          // 0C
		std::uint32_t versionControl;  // 10
		std::uint16_t formVersion;     // 14
		std::uint16_t vcVersion;       // 16
	};
	static_assert(sizeof(FORM) == 0x18);
}
