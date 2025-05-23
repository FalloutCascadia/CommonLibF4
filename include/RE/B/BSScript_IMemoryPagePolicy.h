#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class MemoryPage;

		class __declspec(novtable) IMemoryPagePolicy
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IMemoryPagePolicy };
			static constexpr auto VTABLE{ VTABLE::BSScript__IMemoryPagePolicy };

			enum class AllocationStatus;
			enum class NewPageStrategy;

			virtual ~IMemoryPagePolicy() = default;  // 00

			// add
			virtual std::uint32_t    MaximumPageSize() const = 0;                                                                                       // 01
			virtual std::uint32_t    MaximumStackDepth() const = 0;                                                                                     // 02
			virtual AllocationStatus AllocatePage(std::uint32_t a_sizeInBytes, NewPageStrategy a_strategy, BSTAutoPointer<MemoryPage>& a_newPage) = 0;  // 03
			virtual AllocationStatus GetLargestAvailablePage(BSTAutoPointer<MemoryPage>& a_newPage) = 0;                                                // 04
			virtual void             DisposePage(BSTAutoPointer<MemoryPage>& a_oldPage) = 0;                                                            // 05
		};
		static_assert(sizeof(IMemoryPagePolicy) == 0x8);
	}
}
