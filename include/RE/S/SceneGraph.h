#pragma once

namespace RE
{
	class __declspec(novtable) SceneGraph :
		public BSSceneGraph  // 000
	{
		static constexpr auto RTTI{ RTTI::SceneGraph };
		static constexpr auto VTABLE{ VTABLE::SceneGraph };
		static constexpr auto Ni_RTTI{ Ni_RTTI::SceneGraph };

		// members
		float customNearDistance;
		float customFarDistance;
		bool  customNearDistanceActive;
		bool  customFarDistanceActive;
	};
	static_assert(sizeof(SceneGraph) == 0x170);
}
