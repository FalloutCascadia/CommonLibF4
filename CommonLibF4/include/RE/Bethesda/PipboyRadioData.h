#pragma once

#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class PipboyArray;

	namespace RadioManager
	{
		struct PipboyFrequencyDetectionEvent;
		struct PipboyRadioTuningEvent;
	}

	class _declspec(novtable) PipboyRadioData :
		public PipboyDataGroup,												// 00
		public BSTEventSink<RadioManager::PipboyFrequencyDetectionEvent>,	// 98
		public BSTEventSink<RadioManager::PipboyRadioTuningEvent>			// A0
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyRadioData };
		static constexpr auto VTABLE{ VTABLE::PipboyRadioData };

		virtual ~PipboyRadioData();

		virtual BSEventNotifyControl ProcessEvent(const RadioManager::PipboyFrequencyDetectionEvent& a_event, BSTEventSource<RadioManager::PipboyFrequencyDetectionEvent>* a_source);	// 01
		virtual BSEventNotifyControl ProcessEvent(const RadioManager::PipboyRadioTuningEvent& a_event, BSTEventSource<RadioManager::PipboyRadioTuningEvent>* a_source);					// 02

		virtual void Populate(bool a_arg1);		// 03
		virtual void DoClearData();				// 04
		virtual void DoClearSink();				// 05

		// members
		PipboyArray* radioStations;				// A8
	};
	static_assert(sizeof(PipboyRadioData) == 0xB0);
}
