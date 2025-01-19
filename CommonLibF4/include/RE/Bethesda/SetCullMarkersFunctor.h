#pragma once

namespace RE
{
	struct SetCullMarkersFunctor
	{
	public:
		// members
		bool cull;	// 00
	};
	static_assert(sizeof(SetCullMarkersFunctor) == 0x1);
}
