#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiPoint.h"
#include "RE/R/ReferenceEffectController.h"

namespace RE
{
	class __declspec(novtable) ActiveEffectReferenceEffectController :
		public ReferenceEffectController  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ActiveEffectReferenceEffectController };
		static constexpr auto VTABLE{ VTABLE::ActiveEffectReferenceEffectController };

		// override (ReferenceEffectController)
		void             HandleEvent(const BSFixedString& a_event) override;                 // 01 - return { effect->HandleEvent(a_event); }
		float            GetElapsedTime() override;                                          // 02 - return { effect->elapsedSeconds; }
		float            GetScale() override;                                                // 03
		void             SwitchAttachedRoot(NiNode* a_root, NiNode* a_attachRoot) override;  // 04 - return { effect->SwitchAttachedRoot(a_root, a_attachRoot); }
		const NiPoint3&  GetSourcePosition() override;                                       // 05
		bool             GetUseSourcePosition() override;                                    // 06
		bool             GetNoInitialFlare() override;                                       // 07
		bool             GetEffectPersists() override;                                       // 08
		bool             GetGoryVisuals() override;                                          // 09
		void             RemoveHitEffect(ReferenceEffect* a_refEffect) override;             // 0A
		TESObjectREFR*   GetTargetReference() override;                                      // 0B
		BGSArtObject*    GetHitEffectArt() override;                                         // 0C
		TESEffectShader* GetHitEffectShader() override;                                      // 0D
		bool             GetManagerHandlesSaveLoad() override;                               // 0E - { return false; }
		bool             EffectShouldFaceTarget() override;                                  // 17
		TESObjectREFR*   GetFacingTarget() override;                                         // 18
		void             SetWindPoint(const NiPoint3& a_point) override;                     // 1E - { windPoint = a_point; }
		const NiPoint3&  GetWindPoint() override;                                            // 1F - { return windPoint; }
		bool             GetAllowNo3D() override;                                            // 20
		void             SaveGame(BGSSaveGameBuffer* a_buf) override;                        // 21
		void             LoadGame(BGSLoadGameBuffer* a_buf) override;                        // 22

		// members
		ActiveEffect*   effect;     // 08
		NiPoint3        windPoint;  // 10
		ObjectRefHandle target;     // 18
	};
	static_assert(sizeof(ActiveEffectReferenceEffectController) == 0x20);
}
