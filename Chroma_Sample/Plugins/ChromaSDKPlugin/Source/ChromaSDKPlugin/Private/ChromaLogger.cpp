// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#include "ChromaLogger.h"
#include <stdarg.h>

using namespace ChromaSDK;


void ChromaLogger::printf(const char* format, ...)
{
#ifdef _DEBUG
	va_list args;
	va_start(args, format);
	::vprintf(format, args);
	va_end(args);
#endif
}

void ChromaLogger::fprintf(FILE* stream, const char* format, ...)
{
#ifdef _DEBUG
	va_list args;
	va_start(args, format);
	::vfprintf(stream, format, args);
	va_end(args);
#endif
}

void ChromaLogger::wprintf(const wchar_t* format, ...)
{
#ifdef _DEBUG
	va_list args;
	va_start(args, format);
	::vwprintf(format, args);
	va_end(args);
#endif
}

void ChromaLogger::fwprintf(FILE* stream, const wchar_t* format, ...)
{
#ifdef _DEBUG
	va_list args;
	va_start(args, format);
	::vfwprintf(stream, format, args);
	va_end(args);
#endif
}
