#pragma once

#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class PipboyArray;

	class _declspec(novtable) PipboyLogData :
		public PipboyDataGroup,						// 00
		public BSTEventSink<TESTrackedStatsEvent>	// 98
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyLogData };
		static constexpr auto VTABLE{ VTABLE::PipboyLogData };

		virtual ~PipboyLogData();

		virtual BSEventNotifyControl ProcessEvent(const TESTrackedStatsEvent& a_event, BSTEventSource<TESTrackedStatsEvent>* a_source);								// 01

		virtual void Populate(bool a_arg1);		// 02
		virtual void DoClearData();				// 03
		virtual void DoClearSink();				// 04

		// members
		PipboyArray* statTypeArray;								// A0
		BSTHashMap<BSFixedString, PipboyObject*> statMap;		// A8
	};
	static_assert(sizeof(PipboyLogData) == 0xD8);
}
