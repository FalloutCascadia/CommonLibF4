#pragma once

#include "RE/Bethesda/BSTSingleton.h"

#include "RE/Bethesda/PipboyDataGroup.h"
#include "RE/Bethesda/PipboyInventoryData.h"
#include "RE/Bethesda/PipboyLogData.h"
#include "RE/Bethesda/PipboyMapData.h"
#include "RE/Bethesda/PipboyQuestData.h"
#include "RE/Bethesda/PipboyRadioData.h"
#include "RE/Bethesda/PipboySpecialData.h"
#include "RE/Bethesda/PipboyThrottleManager.h"
#include "RE/Bethesda/PipboyValue.h"

namespace RE
{
	class _declspec(novtable) PipboyDataManager :
		public BSTSingletonSDM<PipboyDataManager>
	{
	public:
		[[nodiscard]] static PipboyDataManager* GetSingleton()
		{
			static REL::Relocation<PipboyDataManager**> singleton{ REL::ID(2689086) };
			return *singleton;
		}

		// members
		PipboyObject rootObject;					// 08
		void* statsData[39];						// A0 - PipboyStatsData 
		PipboySpecialData specialData;              // 1D8
		PipboyPerksData perksData;                  // 280
		PipboyInventoryData inventoryData;			// 358
		PipboyQuestData questData;					// 4F0
		void* workshopData[40];						// 5D8 - PipboyWorkshopData
		PipboyLogData logData;						// 718
		PipboyMapData mapData;                      // 7F0
		PipboyRadioData radioData;					// A28
		void* playerInfoData[33];					// AD8 - PipboyPlayerInfoData
		void* statusData[28];						// BE0 - PipboyStatusData 
		PipboyDataGroup* dataGroups[11];			// CC0
		PipboyThrottleManager throttleManager;		// D18
	};
	static_assert(sizeof(PipboyDataManager) == 0xD48);
}
