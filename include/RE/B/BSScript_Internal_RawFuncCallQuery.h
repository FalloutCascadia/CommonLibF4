#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSScript_Internal_IFuncCallQuery.h"
#include "RE/B/BSScript_Variable.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class __declspec(novtable) RawFuncCallQuery :
				public IFuncCallQuery  // 00
			{
			public:
				static constexpr auto RTTI{ RTTI::BSScript__Internal__RawFuncCallQuery };
				static constexpr auto VTABLE{ VTABLE::BSScript__Internal__RawFuncCallQuery };

				virtual ~RawFuncCallQuery();  // 00

				// override (IFuncCallQuery)
				virtual bool GetFunctionCallInfo(
					CallType&                        a_callType,
					BSTSmartPointer<ObjectTypeInfo>& a_objectTypeInfo,
					BSFixedString&                   a_name,
					Variable&                        a_self,
					BSScrapArray<Variable>&          a_args) const override;  // 01

				// members
				CallType                        callType;  // 10
				std::uint32_t                   pad14;     // 14
				BSTSmartPointer<ObjectTypeInfo> objType;   // 18
				BSFixedString                   name;      // 20
				Variable                        self;      // 28
				BSTArray<Variable>              args;      // 38
			};
			static_assert(sizeof(RawFuncCallQuery) == 0x50);
		}
	}
}
