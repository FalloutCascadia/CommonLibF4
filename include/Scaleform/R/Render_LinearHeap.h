#pragma once

namespace Scaleform
{
	class MemoryHeap;

	namespace Render
	{
		class LinearHeap
		{
		public:
			class PageType
			{
			public:
				// members
				std::byte* start;  // 00
				std::byte* end;    // 08
				std::byte* free;   // 10
			};
			static_assert(sizeof(PageType) == 0x18);

			// members
			MemoryHeap* heap;         // 00
			std::size_t granularity;  // 08
			PageType*   pagePool;     // 10
			PageType*   lastPage;     // 18
			std::size_t maxPages;     // 20
		};
		static_assert(sizeof(LinearHeap) == 0x28);
	}
}
