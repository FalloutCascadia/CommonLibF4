#include "F4SE/Impl/WinAPI.h"

#define WIN32_LEAN_AND_MEAN

#define NOGDICAPMASKS
#define NOVIRTUALKEYCODES
//#define NOWINMESSAGES
#define NOWINSTYLES
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define NOSHOWWINDOW
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
//#define NOCTLMGR
#define NODRAWTEXT
#define NOGDI
#define NOKERNEL
//#define NOUSER
#define NONLS
//#define NOMB
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
//#define NOMSG
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOWINOFFSETS
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#include <Windows.h>

#undef GetFileVersionInfo
#undef GetFileVersionInfoSize
#undef GetModuleFileName
#undef GetModuleHandle
#undef MessageBox
#undef VerQueryValue

extern "C" IMAGE_DOS_HEADER __ImageBase;

namespace F4SE
{
	namespace WinAPI
	{
		void*(GetCurrentModule)() noexcept
		{
			return static_cast<void*>(
				std::addressof(__ImageBase));
		}

		std::uint32_t(GetCurrentThreadID)() noexcept
		{
			return static_cast<std::uint32_t>(
				::GetCurrentThreadId());
		}

		bool(GetFileVersionInfo)(
			const char* a_filename,
			std::uint32_t a_handle,
			std::uint32_t a_len,
			void* a_data) noexcept
		{
			return static_cast<bool>(
				::GetFileVersionInfoA(
					static_cast<::LPCSTR>(a_filename),
					static_cast<::DWORD>(a_handle),
					static_cast<::DWORD>(a_len),
					static_cast<::LPVOID>(a_data)));
		}

		bool(GetFileVersionInfo)(
			const wchar_t* a_filename,
			std::uint32_t a_handle,
			std::uint32_t a_len,
			void* a_data) noexcept
		{
			return static_cast<bool>(
				::GetFileVersionInfoW(
					static_cast<::LPCWSTR>(a_filename),
					static_cast<::DWORD>(a_handle),
					static_cast<::DWORD>(a_len),
					static_cast<::LPVOID>(a_data)));
		}

		std::uint32_t(GetFileVersionInfoSize)(
			const char* a_filename,
			std::uint32_t* a_handle) noexcept
		{
			return static_cast<std::uint32_t>(
				::GetFileVersionInfoSizeA(
					static_cast<::LPCSTR>(a_filename),
					reinterpret_cast<::LPDWORD>(a_handle)));
		}

		std::uint32_t(GetFileVersionInfoSize)(
			const wchar_t* a_filename,
			std::uint32_t* a_handle) noexcept
		{
			return static_cast<std::uint32_t>(
				::GetFileVersionInfoSizeW(
					static_cast<::LPCWSTR>(a_filename),
					reinterpret_cast<::LPDWORD>(a_handle)));
		}

		std::size_t(GetMaxPath)() noexcept
		{
			return static_cast<std::size_t>(MAX_PATH);
		}

		std::uint32_t(GetModuleFileName)(
			void* a_module,
			char* a_filename,
			std::uint32_t a_size) noexcept
		{
			return static_cast<std::uint32_t>(
				::GetModuleFileNameA(
					static_cast<::HMODULE>(a_module),
					static_cast<::LPSTR>(a_filename),
					static_cast<::DWORD>(a_size)));
		}

		std::uint32_t(GetModuleFileName)(
			void* a_module,
			wchar_t* a_filename,
			std::uint32_t a_size) noexcept
		{
			return static_cast<std::uint32_t>(
				::GetModuleFileNameW(
					static_cast<::HMODULE>(a_module),
					static_cast<::LPWSTR>(a_filename),
					static_cast<::DWORD>(a_size)));
		}

		void*(GetModuleHandle)(
			const char* a_moduleName) noexcept
		{
			return static_cast<void*>(
				::GetModuleHandleA(
					static_cast<::LPCSTR>(a_moduleName)));
		}

		void*(GetModuleHandle)(
			const wchar_t* a_moduleName) noexcept
		{
			return static_cast<void*>(
				::GetModuleHandleW(
					static_cast<::LPCWSTR>(a_moduleName)));
		}

		std::int32_t(MessageBox)(
			void* a_wnd,
			const char* a_text,
			const char* a_caption,
			unsigned int a_type) noexcept
		{
			return static_cast<std::int32_t>(
				::MessageBoxA(
					static_cast<::HWND>(a_wnd),
					static_cast<::LPCSTR>(a_text),
					static_cast<::LPCSTR>(a_caption),
					static_cast<::UINT>(a_type)));
		}

		std::int32_t(MessageBox)(
			void* a_wnd,
			const wchar_t* a_text,
			const wchar_t* a_caption,
			unsigned int a_type) noexcept
		{
			return static_cast<std::int32_t>(
				::MessageBoxW(
					static_cast<::HWND>(a_wnd),
					static_cast<::LPCWSTR>(a_text),
					static_cast<::LPCWSTR>(a_caption),
					static_cast<::UINT>(a_type)));
		}

		bool(VirtualFree)(
			void* a_address,
			std::size_t a_size,
			std::uint32_t a_freeType) noexcept
		{
			return static_cast<bool>(
				::VirtualFree(
					static_cast<::LPVOID>(a_address),
					static_cast<::SIZE_T>(a_size),
					static_cast<::DWORD>(a_freeType)));
		}

		bool(VerQueryValue)(
			const void* a_block,
			const char* a_subBlock,
			void** a_buffer,
			unsigned int* a_len) noexcept
		{
			return static_cast<bool>(
				::VerQueryValueA(
					static_cast<::LPCVOID>(a_block),
					static_cast<::LPCSTR>(a_subBlock),
					static_cast<::LPVOID*>(a_buffer),
					static_cast<::PUINT>(a_len)));
		}

		bool(VerQueryValue)(
			const void* a_block,
			const wchar_t* a_subBlock,
			void** a_buffer,
			unsigned int* a_len) noexcept
		{
			return static_cast<bool>(
				::VerQueryValueW(
					static_cast<::LPCVOID>(a_block),
					static_cast<::LPCWSTR>(a_subBlock),
					static_cast<::LPVOID*>(a_buffer),
					static_cast<::PUINT>(a_len)));
		}

		bool(VirtualProtect)(
			void* a_address,
			std::size_t a_size,
			std::uint32_t a_newProtect,
			std::uint32_t* a_oldProtect) noexcept
		{
			return static_cast<bool>(
				::VirtualProtect(
					static_cast<::LPVOID>(a_address),
					static_cast<::SIZE_T>(a_size),
					static_cast<::DWORD>(a_newProtect),
					reinterpret_cast<::PDWORD>(a_oldProtect)));
		}
	}
}
