#pragma once

namespace RE
{
	class HUDModeType;

	namespace SendHUDMessage
	{
		inline void PopHUDMode(const HUDModeType& a_hudMode)
		{
			using func_t = decltype(&SendHUDMessage::PopHUDMode);
			static REL::Relocation<func_t> func{ ID::SendHUDMessage::PopHUDMode };
			return func(a_hudMode);
		}

		inline void PushHUDMode(const HUDModeType& a_hudMode)
		{
			using func_t = decltype(&SendHUDMessage::PushHUDMode);
			static REL::Relocation<func_t> func{ ID::SendHUDMessage::PushHUDMode };
			return func(a_hudMode);
		}

		inline void SetPowerArmorMode(bool a_inPowerArmor)
		{
			using func_t = decltype(&SendHUDMessage::SetPowerArmorMode);
			static REL::Relocation<func_t> func{ ID::SendHUDMessage::SetPowerArmorMode };
			return func(a_inPowerArmor);
		}

		inline void ShowHUDMessage(const char* a_message, const char* a_sound, bool a_throttle, bool a_warning)
		{
			using func_t = decltype(&SendHUDMessage::ShowHUDMessage);
			static REL::Relocation<func_t> func{ ID::SendHUDMessage::ShowHUDMessage };
			return func(a_message, a_sound, a_throttle, a_warning);
		}
	}
}
