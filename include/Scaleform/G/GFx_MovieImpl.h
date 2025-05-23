#pragma once

#include "Scaleform/A/Array.h"
#include "Scaleform/G/GFx_ASIntervalTimerIntf.h"
#include "Scaleform/G/GFx_ASString.h"
#include "Scaleform/G/GFx_FocusGroupDescr.h"
#include "Scaleform/G/GFx_Movie.h"
#include "Scaleform/G/GFx_MultitouchInterface.h"
#include "Scaleform/G/GFx_Value.h"
#include "Scaleform/G/GFx_Viewport.h"
#include "Scaleform/L/List.h"
#include "Scaleform/N/NewOverrideBase.h"
#include "Scaleform/P/Ptr.h"
#include "Scaleform/R/Render_Color.h"
#include "Scaleform/R/Render_ContextImpl_Context.h"
#include "Scaleform/R/Render_ContextImpl_DisplayHandle.h"
#include "Scaleform/R/Render_Matrix.h"
#include "Scaleform/R/Render_Point.h"
#include "Scaleform/R/Render_ScreenToWorld.h"
#include "Scaleform/R/Render_TreeRoot.h"
#include "Scaleform/S/StatBasicValues.h"

namespace Scaleform
{
	class MemoryHeap;

	namespace Render
	{
		class DrawableImageContext;
		class ThreadCommandQueue;
		class TreeContainer;
		class TreeNode;
	}

	namespace GFx
	{
		class AmpStats;
		class ASMovieRootBase;
		class DisplayObjContainer;
		class DisplayObjectBase;

		class DrawingContext;
		class ExternalInterface;
		class ExternalLibPtr;
		class FontManagerStates;
		class FontResource;
		class FSCommandHandler;
		class IMECandidateListStyle;
		class InteractiveObject;
		class LoadQueueEntry;
		class LoadQueueEntryMT;
		class MovieDef;
		class MovieDefImpl;
		class MovieDefRootNode;
		class StateBagImpl;
		class UserEventHandler;

		class __declspec(novtable) alignas(0x10) MovieImpl :
			public Movie  // 00
		{
		public:
			using MultitouchInputMode = MultitouchInterface::MultitouchInputMode;
			using GestureMask = MultitouchInterface::GestureMask;

			class DragState
			{
			public:
				constexpr DragState() = default;

				// members
				InteractiveObject*   character{ nullptr };       // 00
				InteractiveObject*   topmostEntity{ nullptr };   // 08
				bool                 lockCenter{ false };        // 10
				bool                 bound{ false };             // 11
				Render::Point<float> boundLT{ 0.0f, 0.0f };      // 14
				Render::Point<float> boundRB{ 0.0f, 0.0f };      // 1C
				Render::Point<float> centerDelta{ 0.0f, 0.0f };  // 24
				std::uint32_t        mouseIndex;                 // 2C
			};
			static_assert(sizeof(DragState) == 0x30);

			class FontDesc
			{
			public:
				// members
				Ptr<MovieDef>     movieDef;
				Ptr<FontResource> font;
			};
			static_assert(sizeof(FontDesc) == 0x10);

			class IndirectTransPair
			{
			public:
				// members
				Ptr<Render::TreeNode>    transformParent;
				Ptr<DisplayObjectBase>   obj;
				Ptr<DisplayObjContainer> originalParent;
				mutable std::int32_t     origParentDepth{ -1 };
			};
			static_assert(sizeof(IndirectTransPair) == 0x20);

			class LevelInfo
			{
			public:
				// members
				std::int32_t           level;
				Ptr<InteractiveObject> sprite;
			};
			static_assert(sizeof(IndirectTransPair) == 0x20);

			class MDKillListEntry
			{
			public:
				// members
				std::uint64_t     killFrameId;
				Ptr<MovieDefImpl> movieDef;
			};
			static_assert(sizeof(MDKillListEntry) == 0x10);

			class ReturnValueHolder :
				public NewOverrideBase<kStatMV_ActionScript_Mem>
			{
			public:
				// members
				char*                                       charBuffer;      // 00
				std::uint32_t                               charBufferSize;  // 08
				ArrayCC<ASString, kStatMV_ActionScript_Mem> stringArray;     // 10
				std::uint32_t                               stringArrayPos;  // 30
			};
			static_assert(sizeof(ReturnValueHolder) == 0x38);

			// members
			LoadQueueEntry*                                      loadQueueHead;             // 0020
			std::uint32_t                                        lastLoadQueueEntryCount;   // 0028
			Ptr<AmpStats>                                        advanceStats;              // 0030
			Value::ObjectInterface*                              objectInterface;           // 0038
			MemoryHeap*                                          heap;                      // 0040
			Ptr<MovieDefImpl>                                    mainMovieDef;              // 0048
			InteractiveObject*                                   mainMovie;                 // 0050
			ArrayLH<LevelInfo, kStatMV_Other_Mem>                movieLevels;               // 0058
			List<MovieDefRootNode>                               rootMovieDefNodes;         // 0070
			Ptr<StateBagImpl>                                    stateBag;                  // 0080
			Ptr<Render::TreeRoot>                                renderRoot;                // 0088
			Render::ContextImpl::DisplayHandle<Render::TreeRoot> displayRoot;               // 0090
			Ptr<Render::TreeContainer>                           topMostRoot;               // 0098
			Viewport                                             viewport;                  // 00A0
			float                                                pixelScale;                // 00D4
			float                                                viewScaleX;                // 00D8
			float                                                viewScaleY;                // 00DC
			float                                                viewOffsetX;               // 00E8
			float                                                viewOffsetY;               // 00E4
			ScaleModeType                                        viewScaleMode;             // 00E8
			AlignType                                            viewAlignment;             // 00EC
			Render::Rect<float>                                  visibleFrameRect;          // 00F0
			Render::Rect<float>                                  safeRect;                  // 0100
			Render::Matrix2x4<float>                             viewportMatrix;            // 0110
			Render::ScreenToWorld                                screenToWorld;             // 0130
			mutable Ptr<Log>                                     cachedLog;                 // 0220
			Ptr<UserEventHandler>                                userEventHandler;          // 0228
			Ptr<FSCommandHandler>                                fsCommandHandler;          // 0230
			Ptr<ExternalInterface>                               externalInterfaceHandler;  // 0238
			Ptr<FontManagerStates>                               fontManagerStates;         // 0240
			ExternalLibPtr*                                      xmlObjectManager;          // 0248
			std::uint64_t                                        timeElapsed;               // 0250
			float                                                timeRemainder;             // 0258
			float                                                frameTime;                 // 025C
			std::uint32_t                                        forceFrameCatchUp;         // 0260
			std::byte                                            pad268[0x1F60];            // 0268 - GFx::InputEventsQueue
			Render::Color                                        backgroundColor;           // 21C8
			std::byte                                            pad21D0[0x50];             // 21D0 - MouseState[1]
			std::uint32_t                                        mouseCursorCount;          // 2220
			std::uint32_t                                        controllerCount;           // 2224
			void*                                                userData;                  // 2228
			std::byte                                            pad2230[0x688];            // 2230 - KeyboardState[1]
			ReturnValueHolder*                                   returnValueHolder;         // 28B8
			std::uint32_t                                        instanceNameCount;         // 28C0
			DragState                                            currentDragState;          // 28C8
			std::byte                                            pad28F8[0x8];              // 28F8 - ASStringHash<StickyVarNode*>
			ArrayLH<Ptr<InteractiveObject>, kStatMV_Other_Mem>   topmostLevelCharacters;    // 2900
			std::uint64_t                                        startTickMS;               // 2918
			std::uint64_t                                        pauseTickMS;               // 2920
			ArrayLH<Ptr<ASIntervalTimerIntf>, kStatMV_Other_Mem> intervalTimers;            // 2928
			std::int32_t                                         lastIntervalTimerId;       // 2940
			Ptr<Render::TreeContainer>                           focusRectContainerNode;    // 2948
			FocusGroupDescr                                      focusGroups[16];           // 2950
			std::uint32_t                                        focusGroupsCount;          // 2F50
			std::uint8_t                                         focusGroupIndexes[16];     // 2F54
			bool                                                 focusRectChanged;          // 2F64
			InteractiveObject*                                   playListHead;              // 2F68
			InteractiveObject*                                   playListOptHead;           // 2F70
			InteractiveObject*                                   unloadListHead;            // 2F78
			std::uint32_t                                        flags;                     // 2F80
			std::uint32_t                                        flags2;                    // 2F84
			IMECandidateListStyle*                               imeCandidateListStyle;     // 2F88
			LoadQueueEntryMT*                                    loadQueueMTHead;           // 2F90
			ArrayLH<FontDesc>                                    registeredFonts;           // 2F98
			List<DrawingContext>                                 drawingContextList;        // 2FB0
			Array<MDKillListEntry, kStatMV_Other_Mem>            movieDefKillList;          // 2FC0
			Ptr<ASMovieRootBase>                                 savedASMovieRoot;          // 2FD8
			Render::ContextImpl::Context                         renderContext;             // 2FE0
			std::int8_t                                          previouslyCaptured;        // 30F0
			Ptr<Render::DrawableImageContext>                    drawableImageContext;      // 30F8
			Render::ThreadCommandQueue*                          renderThreadCommandQueue;  // 3100
			Ptr<MultitouchInterface>                             multitouchHAL;             // 3108
			MultitouchInputMode                                  multitouchMode;            // 3110
			Ptr<InteractiveObject>                               gestureTopMostChar;        // 3118
			std::int32_t                                         deviceOrientation;         // 3120 - OrientationEvent::OrientationType
			ArrayLH<IndirectTransPair>                           indirectTransformPairs;
		};
		static_assert(sizeof(MovieImpl) == 0x3140);
	}
}
