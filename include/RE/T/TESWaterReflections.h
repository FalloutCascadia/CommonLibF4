#pragma once

namespace RE
{
	class BSMultiBoundAABB;
	class TESWaterNormals;
	class TESWaterDisplacement;

	class __declspec(novtable) TESWaterReflections :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWaterReflections };
		static constexpr auto VTABLE{ VTABLE::TESWaterReflections };

		enum class Flags
		{
			kDirty = 0x0,
			kStaticCubemap = 0x2,
			kDynamicCubemap = 0x4,
			kInterior = 0x8,
			kSilhouette = 0x10,
			kLODScene = 0x20,
			kFullScene = 0x40,
			kLand = 0x80,
			kSky = 0x100,
			kExplosions = 0x200,
			kSelective = 0x400,
			kDontUpdate = 0x800,
			kMapMode = 0x1000
		};

		// members
		NiPlane                                                      waterPlane;          // 10
		NiPointer<NiAVObject>                                        waterObject;         // 20
		NiPointer<NiAVObject>                                        waterRipplesObject;  // 28
		TESWaterForm*                                                waterType;           // 30
		NiPointer<TESWaterReflections>                               waterReflections;    // 38
		NiPointer<TESWaterNormals>                                   waterNormals;        // 40
		NiPointer<TESWaterDisplacement>                              waterDisplacement;   // 48
		BSTArray<NiPointer<BSMultiBoundAABB>, BSTArrayHeapAllocator> multiBoundShape;     // 50
		std::uint8_t                                                 flags;               // 68
	};
	static_assert(sizeof(TESWaterReflections) == 0x70);
}
