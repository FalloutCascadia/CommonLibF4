#pragma once

namespace RE
{
	class __declspec(novtable) BGSSaveLoadBuffer
	{
	public:
		// members
		char*         buffer;     // 00
	};
	static_assert(sizeof(BGSSaveLoadBuffer) == 0x08);
}
