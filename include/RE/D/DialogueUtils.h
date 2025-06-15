#pragma once

namespace RE
{
	namespace DialogueUtils
	{
		void OpenMenu()
		{
			using func_t = decltype(&DialogueUtils::OpenMenu);
			static REL::Relocation<func_t> func{ ID::DialogueUtils::OpenMenu };
			return func();
		}

		void CloseMenu()
		{
			using func_t = decltype(&DialogueUtils::CloseMenu);
			static REL::Relocation<func_t> func{ ID::DialogueUtils::CloseMenu };
			return func();
		}

		void ShowSpeechChallengeAnim()
		{
			using func_t = decltype(&DialogueUtils::ShowSpeechChallengeAnim);
			static REL::Relocation<func_t> func{ ID::DialogueUtils::ShowSpeechChallengeAnim };
			return func();
		}
	}
}
