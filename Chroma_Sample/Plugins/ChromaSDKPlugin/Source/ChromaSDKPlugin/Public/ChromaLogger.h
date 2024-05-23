// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#pragma once

#include <stdio.h>

namespace ChromaSDK
{
	class ChromaLogger
	{
	public:
		static void printf(const char* format, ...);
		static void fprintf(FILE* stream, const char* format, ...);

		static void wprintf(const wchar_t* format, ...);
		static void fwprintf(FILE* stream, const wchar_t* format, ...);
	};
}
