#pragma once

#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/PipboyDataGroup.h"

namespace RE
{
	class __declspec(novtable) PipboyMapData :
		public PipboyDataGroup,											// 00
		public BSTEventSink<TravelMarkerStateChange::Event>,			// 98
		public BSTEventSink<PlayerUpdateEvent>,
		public BSTEventSink<BGSActorCellEvent>,
		public BSTEventSink<TESQuestEvent::Event>,
		public BSTEventSink<PlayerCharacterQuestEvent::Event>,
		public BSTEventSink<CustomMarkerUpdate::Event>,
		public BSTEventSink<LocationMarkerArrayUpdate::Event>,
		public BSTEventSink<LocalMapCameraUpdate::Event>,
		public BSTEventSink<TESLocationClearedEvent>,
		public BSTEventSink<ActorValueEvents::ActorValueChangedEvent>
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyMapData };
		static constexpr auto VTABLE{ VTABLE::PipboyMapData };


		virtual ~PipboyMapData();

		// members
		PipboyObject*                                                                       mapObject;
		BSTHashMap<const MapMarkerData*, PipboyObject*> travelLocationsMarkers;
		BSTHashMap<std::uint32_t, BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21,5>>> travelLocationRefrHandles;
		BSTArray<PipboyObject*> doorMarkers;
		BSTArray<BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>>> doorRefHandles;
		BSTHashMap<BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>>, PipboyObject*> localQuestMarkers;
		BSTHashMap<BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>>, PipboyObject*> worldQuestMarkers;
		NiPoint3                                                                                 playerLastLocationPosition;
		NiPoint3                                                                                 playerLastWorldPosition;
		PipboyObject*                                                                            localPlayerMarker;
		PipboyObject*                                                                            worldPlayerMarker;
		PipboyObject*                                                                            localCustomMarker;
		PipboyObject*                                                                            worldCustomMarker;
		PipboyObject*                                                                            localPowerArmorMarker;
		PipboyObject*                                                                            worldPowerArmorMarker;
		PipboyObject*                                                                            worldMapExtents;
		PipboyObject*                                                                            localMapExtents;
	};
	static_assert(sizeof(PipboyMapData) == 0x238);
}
