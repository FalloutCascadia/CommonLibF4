#pragma once

#include "RE/B/BGSLocalizedString.h"

namespace RE
{
	class TESQuest;
	class TESQuestTarget;

	class BGSQuestObjective
	{
	public:
		// members
<<<<<<< HEAD
		BGSLocalizedString displayText;  // 00
		TESQuest*          ownerQuest;   // 08
		TESQuestTarget**   targets;      // 10
		std::uint32_t      numTargets;   // 18
		std::uint16_t      index;        // 1C
		bool               initialized;  // 1E
		char               state;        // 1F
		std::uint32_t      flags;        // 20
=======
		BGSLocalizedString displayText;  // 00
		TESQuest*          ownerQuest;   // 08
		TESQuestTarget**   targets;      // 10
		std::uint32_t      numTargets;   // 18
		std::uint16_t      index;        // 1C
		bool               initialized;  // 1E
		char               state;        // 1F
		std::uint32_t      flags;        // 20
>>>>>>> 939cc4cc5162605a3d1790d39681fb97edfe85eb
	};
	static_assert(sizeof(BGSQuestObjective) == 0x28);
}
