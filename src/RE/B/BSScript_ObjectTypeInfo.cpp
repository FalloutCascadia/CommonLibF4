#include "RE/B/BSScript_ObjectTypeInfo.h"

namespace RE
{
	namespace BSScript
	{
		BSFixedString ObjectTypeInfo::UserFlagInfo::GetUserFlag() const
		{
			auto sanitizedType = data & ~kSetOnObject;
			return *reinterpret_cast<BSFixedString*>(&sanitizedType);
		}

		auto ObjectTypeInfo::NamedStateInfo::GetFuncIter()
			-> Func*
		{
			return reinterpret_cast<Func*>((std::uintptr_t)this + memberFunctionOffset);
		}

		auto ObjectTypeInfo::NamedStateInfo::GetFuncIter() const
			-> const Func*
		{
			return reinterpret_cast<const Func*>((std::uintptr_t)this + memberFunctionOffset);
		}

		ObjectTypeInfo::~ObjectTypeInfo()
		{
			dtor();
		}

		const char* ObjectTypeInfo::GetName() const
		{
			return name.c_str();
		}

		ObjectTypeInfo* ObjectTypeInfo::GetParent()
		{
			return parentTypeInfo.get();
		}

		const ObjectTypeInfo* ObjectTypeInfo::GetParent() const
		{
			return parentTypeInfo.get();
		}

		TypeInfo::RawType ObjectTypeInfo::GetRawType() const
		{
			return TypeInfo::RawType::kObject;
		}

		auto ObjectTypeInfo::GetUnlinkedFunctionIter()
			-> UnlinkedNativeFunction*
		{
			return reinterpret_cast<UnlinkedNativeFunction*>(data);
		}

		auto ObjectTypeInfo::GetUnlinkedFunctionIter() const
			-> const UnlinkedNativeFunction*
		{
			return reinterpret_cast<const UnlinkedNativeFunction*>(data);
		}

		auto ObjectTypeInfo::GetUserFlagIter()
			-> UserFlagInfo*
		{
			return reinterpret_cast<UserFlagInfo*>(data);
		}

		auto ObjectTypeInfo::GetUserFlagIter() const
			-> const UserFlagInfo*
		{
			return reinterpret_cast<const UserFlagInfo*>(data);
		}

		std::uint32_t ObjectTypeInfo::GetTotalNumVariables() const
		{
			auto numVars = GetNumVariables();
			for (auto iter = GetParent(); iter; iter = iter->GetParent()) {
				numVars += iter->GetNumVariables();
			}
			return numVars;
		}

		auto ObjectTypeInfo::GetVariableIter()
			-> VariableInfo*
		{
			return reinterpret_cast<VariableInfo*>(GetUserFlagIter() + GetNumUserFlags());
		}

		auto ObjectTypeInfo::GetVariableIter() const
			-> const VariableInfo*
		{
			return reinterpret_cast<const VariableInfo*>(GetUserFlagIter() + GetNumUserFlags());
		}

		auto ObjectTypeInfo::GetInitialValueIter()
			-> InitialValueInfo*
		{
			return reinterpret_cast<InitialValueInfo*>(GetVariableIter() + GetNumVariables());
		}

		auto ObjectTypeInfo::GetInitialValueIter() const
			-> const InitialValueInfo*
		{
			return reinterpret_cast<const InitialValueInfo*>(GetVariableIter() + GetNumVariables());
		}

		auto ObjectTypeInfo::GetPropertyIter()
			-> PropertyInfo*
		{
			return reinterpret_cast<PropertyInfo*>(GetInitialValueIter() + GetNumInitalValues());
		}

		auto ObjectTypeInfo::GetPropertyIter() const
			-> const PropertyInfo*
		{
			return reinterpret_cast<const PropertyInfo*>(GetInitialValueIter() + GetNumInitalValues());
		}

		auto ObjectTypeInfo::GetGlobalFuncIter()
			-> GlobalFuncInfo*
		{
			return reinterpret_cast<GlobalFuncInfo*>(GetPropertyIter() + GetNumProperties());
		}

		auto ObjectTypeInfo::GetGlobalFuncIter() const
			-> const GlobalFuncInfo*
		{
			return reinterpret_cast<const GlobalFuncInfo*>(GetPropertyIter() + GetNumProperties());
		}

		auto ObjectTypeInfo::GetMemberFuncIter()
			-> MemberFuncInfo*
		{
			return reinterpret_cast<MemberFuncInfo*>(GetGlobalFuncIter() + GetNumGlobalFuncs());
		}

		auto ObjectTypeInfo::GetMemberFuncIter() const
			-> const MemberFuncInfo*
		{
			return reinterpret_cast<const MemberFuncInfo*>(GetGlobalFuncIter() + GetNumGlobalFuncs());
		}

		auto ObjectTypeInfo::GetNamedStateIter()
			-> NamedStateInfo*
		{
			return reinterpret_cast<NamedStateInfo*>(GetMemberFuncIter() + GetNumMemberFuncs());
		}

		auto ObjectTypeInfo::GetNamedStateIter() const
			-> const NamedStateInfo*
		{
			return reinterpret_cast<const NamedStateInfo*>(GetMemberFuncIter() + GetNumMemberFuncs());
		}

		std::uint32_t ObjectTypeInfo::GetPropertyIndex(const BSFixedString& a_name) const
		{
			const auto props = GetPropertyIter();
			if (props) {
				for (std::uint32_t i = 0; i < GetNumProperties(); ++i) {
					const auto& prop = props[i];
					if (prop.name == a_name) {
						return prop.info.autoVarIndex;
					}
				}
			}
			return static_cast<std::uint32_t>(-1);
		}

		constexpr bool ObjectTypeInfo::HasPropertyGroups() const
		{
			return propertyGroups.size();
		}

		auto ObjectTypeInfo::GetInitialState() const -> const BSFixedString*
		{
			BSFixedString thing = "hello";
			return reinterpret_cast<const BSFixedString*>(GetNamedStateIter() + GetNumNamedStates());
		}

		void ObjectTypeInfo::dtor()
		{
			using func_t = decltype(&ObjectTypeInfo::dtor);
			REL::Relocation<func_t> func{ ID::BSScript_ObjectTypeInfo::dtor };
			return func(this);
		}
	}
}
