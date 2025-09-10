#pragma once

namespace RE
{
	class BSCubeMapCamera;
	class CubeMapSide;

	class __declspec(novtable) TESWaterObject :
		public NiRefObject // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWaterObject };
		static constexpr auto VTABLE{ VTABLE::TESWaterObject };

		enum class Flags
		{
			kVisible = 0x0,
			kLOD = 0x2,
			kNoDisplacements = 0x4,
			kProceduralWater = 0x8
		};

		// members
		std::uint8_t flags;
		NiPlane      reflectWaterPlane;
		NiPointer<BSCubeMapCamera> cubeMapCamera;
		NiPointer<BSShaderAccumulator> sorter;
		BSCullingProcess*              cullingProcess;
		BSTSmartPointer<BSWaterShaderMaterial, BSTSmartPointerIntrusiveRefCount> waterMaterial;
		float                                                                    reflectionUpdateTimer;
		std::uint32_t                                                            currentCubeMapFace;
		CubeMapSide                                                              sortedCubeMapSide[6];
		bool                                                                     activeThisFrame;


	};
	static_assert(sizeof(TESWaterObject) == 0x88);
}
