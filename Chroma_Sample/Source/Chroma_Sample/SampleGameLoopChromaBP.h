// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "ChromaSDKPluginTypes.h"
#include "SampleGameLoopChromaBP.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogChromaSampleGameLoop, Log, All);


UCLASS()
class USampleGameLoopChromaBP : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	static int32 min(int32 a, int32 b);
	static int32 max(int32 a, int32 b);

	static int32 GetKeyColorIndex(int32 row, int32 column);
	static void SetKeyColor(int32* colors, EChromaSDKKeyboardKey::Type key, int32 color);
	static void SetKeyColorRGB(int32* colors, EChromaSDKKeyboardKey::Type key, int32 red, int32 green, int32 blue);
	static const int32 GetColorArraySize1D(EChromaSDKDevice1DEnum::Type device);
	static const int32 GetColorArraySize2D(EChromaSDKDevice2DEnum::Type device);
	static int32 MultiplyColor(int32 color1, int32 color2);
	static int32 AverageColor(int32 color1, int32 color2);
	static int32 AddColor(int32 color1, int32 color2);
	static int32 SubtractColor(int32 color1, int32 color2);
	static int32 MaxColor(int32 color1, int32 color2);
	static int32 MinColor(int32 color1, int32 color2);
	static int32 InvertColor(int32 color);
	static int32 MultiplyNonZeroTargetColorLerp(int32 color1, int32 color2, int32 inputColor);
	static int32 Thresh(int32 color1, int32 color2, int32 inputColor);
	static void BlendAnimation1D(const FChromaSDKSceneEffect& effect, FChromaSDKDeviceFrameIndex& deviceFrameIndex, int32 device, EChromaSDKDevice1DEnum::Type device1d, const FString& animationName,
		int32* colors, int32* tempColors);
	static void BlendAnimation2D(const FChromaSDKSceneEffect& effect, FChromaSDKDeviceFrameIndex& deviceFrameIndex, int32 device, EChromaSDKDevice2DEnum::Type device2D, const FString& animationName,
		int32* colors, int32* tempColors);
	static void BlendAnimations(FChromaSDKScene& scene,
		int32* colorsChromaLink, int32* tempColorsChromaLink,
		int32* colorsHeadset, int32* tempColorsHeadset,
		int32* colorsKeyboard, int32* tempColorsKeyboard,
		int32* colorsKeyboardExtended, int32* tempColorsKeyboardExtended,
		int32* colorsKeypad, int32* tempColorsKeypad,
		int32* colorsMouse, int32* tempColorsMouse,
		int32* colorsMousepad, int32* tempColorsMousepad);
	static void InitArrayBGRInt(int32** colors, int32 size);
	static void UninitArrayBGRInt(int32** colors);
	static void SetStaticColor(int* colors, int color, int size);
#endif


	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameLoopSampleStart", Keywords = "Init at the start of the application"), Category = "Sample")
	static void SampleGameLoopSampleStart();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameLoopSampleEnd", Keywords = "Uninit at the end of the application"), Category = "Sample")
	static void SampleGameLoopSampleEnd();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameLoopUpdate", Keywords = "Example"), Category = "Sample")
	static void SampleGameLoopUpdate(float deltaSeconds, UPARAM(ref) FChromaSDKScene& scene, bool toggleHotkeys, bool toggleExtended, bool toggleAmmo);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameLoopGenerateRandomColor", Keywords = "Example"), Category = "Sample")
	static FLinearColor SampleGameLoopGenerateRandomColor();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameLoopSetAmbientColor", Keywords = "Example"), Category = "Sample")
	static void SampleGameLoopSetAmbientColor(const FLinearColor& ambientColor);

private:

#if PLATFORM_WINDOWS || PLATFORM_XBOXONE

	static int32 _sSizeChromaLink;
	static int32 _sSizeHeadset;
	static int32 _sSizeKeyboard;
	static int32 _sSizeKeyboardExtended;
	static int32 _sSizeKeypad;
	static int32 _sSizeMouse;
	static int32 _sSizeMousepad;

	static int32 _sAmbientColor;

	static int32* _sColorsChromaLink;
	static int32* _sColorsHeadset;
	static int32* _sColorsKeyboard;
	static int32* _sColorsKeyboardExtended;
	static int32* _sColorsKeyboardKeys;
	static int32* _sColorsKeypad;
	static int32* _sColorsMouse;
	static int32* _sColorsMousepad;

	static int32* _sTempColorsChromaLink;
	static int32* _sTempColorsHeadset;
	static int32* _sTempColorsKeyboard;
	static int32* _sTempColorsKeyboardExtended;
	static int32* _sTempColorsKeypad;
	static int32* _sTempColorsMouse;
	static int32* _sTempColorsMousepad;

	static float _sTime;
	static uint32 _sTimeMS;

#endif

};
