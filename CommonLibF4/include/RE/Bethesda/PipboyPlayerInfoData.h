#pragma once

#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class __declspec(novtable) PipboyPlayerInfoData :
		public PipboyDataGroup,
		public BSTEventSink<ActorValueEvents::ActorValueChangedEvent>,
		public BSTEventSink<BGSInventoryListEvent::Event>,
		public BSTEventSink<ActorEquipManagerEvent::Event>,
		public BSTEventSink<LevelIncrease::Event>,
		public BSTEventSink<PerkPointIncreaseEvent>,
		public BSTEventSink<PerkValueEvents::PerkEntryUpdatedEvent>,
		public BSTEventSink<HourPassed::Event>,
		public BSTEventSink<SPECIALMenuEvent::NameChangedEvent>,
		public BSTEventSink<PlayerUpdateEvent>,
		public BSTEventSink<BGSInventoryItemEvent::Event>,
		public BSTEventSink<PlayerActiveEffectChanged::Event>,
		public BSTEventSink<PlayerCharacterQuestEvent::Event>,
		public BSTEventSink<PlayerDifficultySettingChanged::Event>
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPlayerInfoData };
		static constexpr auto VTABLE{ VTABLE::PipboyPlayerInfoData };

		virtual ~PipboyPlayerInfoData() = default;

		virtual BSEventNotifyControl ProcessEvent(const ActorValueEvents::ActorValueChangedEvent& a_event, BSTEventSource<ActorValueEvents::ActorValueChangedEvent>* a_source);	// 01
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryListEvent::Event& a_event, BSTEventSource<BGSInventoryListEvent::Event>* a_source);							// 02
		virtual BSEventNotifyControl ProcessEvent(const ActorEquipManagerEvent::Event& a_event, BSTEventSource<ActorEquipManagerEvent::Event>* a_source);                       // 03
		virtual BSEventNotifyControl ProcessEvent(const LevelIncrease::Event& a_event, BSTEventSource<LevelIncrease::Event>* a_source);											// 04
		virtual BSEventNotifyControl ProcessEvent(const PerkPointIncreaseEvent& a_event, BSTEventSource<PerkPointIncreaseEvent>* a_source);                                     // 05
		virtual BSEventNotifyControl ProcessEvent(const PerkValueEvents::PerkEntryUpdatedEvent& a_event, BSTEventSource<PerkValueEvents::PerkEntryUpdatedEvent>* a_source);		// 06
		virtual BSEventNotifyControl ProcessEvent(const HourPassed::Event& a_event, BSTEventSource<HourPassed::Event>* a_source);                                               // 07
		virtual BSEventNotifyControl ProcessEvent(const SPECIALMenuEvent::NameChangedEvent& a_event, BSTEventSource<SPECIALMenuEvent::NameChangedEvent>* a_source);				// 08
		virtual BSEventNotifyControl ProcessEvent(const PlayerUpdateEvent& a_event, BSTEventSource<PlayerUpdateEvent>* a_source);                                               // 09
		virtual BSEventNotifyControl ProcessEvent(const BGSInventoryItemEvent::Event& a_event, BSTEventSource<BGSInventoryItemEvent::Event>* a_source);							// 0A
		virtual BSEventNotifyControl ProcessEvent(const PlayerActiveEffectChanged::Event& a_event, BSTEventSource<PlayerActiveEffectChanged::Event>* a_source);                 // 0B
		virtual BSEventNotifyControl ProcessEvent(const PlayerCharacterQuestEvent::Event& a_event, BSTEventSource<PlayerCharacterQuestEvent::Event>* a_source);					// 0C
		virtual BSEventNotifyControl ProcessEvent(const PlayerDifficultySettingChanged::Event& a_event, BSTEventSource<PlayerDifficultySettingChanged::Event>* a_source);       // 0D

		// override
		virtual void Populate(bool a_arg1) override;  // 0E
		virtual void DoClearData() override;          // 0F
		virtual void DoClearSink() override;          // 10

		// members
		PipboyObject* playerInfoObject;
	};
	static_assert(sizeof(PipboyPlayerInfoData) == 0x108);
}
