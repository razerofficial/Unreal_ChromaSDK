#pragma once

#include <string>

namespace ChromaSDK
{
	class VerifyLibrarySignature
	{
	public:
		static bool VerifyModule(const std::wstring& filename);
		static bool IsFileVersionSameOrNewer(const std::wstring& filename, const int minMajor, const int minMinor, const int minRevision, const int minBuild);
	private:
		static bool IsFileSignedByRazer(const wchar_t* szFileName);
		static bool IsFileSigned(const wchar_t* szFileName);
	};
}
