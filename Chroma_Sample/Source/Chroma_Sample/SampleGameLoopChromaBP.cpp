// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SampleGameLoopChromaBP.h" //___HACK_UE4_VERSION_4_16_OR_GREATER
#include "Chroma_Sample.h"
//#include "SampleGameLoopChromaBP.h" //___HACK_UE4_VERSION_4_15_OR_LESS
#include "ChromaSDKPluginBPLibrary.h"


DEFINE_LOG_CATEGORY(LogChromaSampleGameLoop);


#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

int32 USampleGameLoopChromaBP::_sSizeChromaLink = 0;
int32 USampleGameLoopChromaBP::_sSizeHeadset = 0;
int32 USampleGameLoopChromaBP::_sSizeKeyboard = 0;
int32 USampleGameLoopChromaBP::_sSizeKeyboardExtended = 0;
int32 USampleGameLoopChromaBP::_sSizeKeypad = 0;
int32 USampleGameLoopChromaBP::_sSizeMouse = 0;
int32 USampleGameLoopChromaBP::_sSizeMousepad = 0;

int32 USampleGameLoopChromaBP::_sAmbientColor = 0;

int32* USampleGameLoopChromaBP::_sColorsChromaLink = NULL;
int32* USampleGameLoopChromaBP::_sColorsHeadset = NULL;
int32* USampleGameLoopChromaBP::_sColorsKeyboard = NULL;
int32* USampleGameLoopChromaBP::_sColorsKeyboardExtended = NULL;
int32* USampleGameLoopChromaBP::_sColorsKeyboardKeys = NULL;
int32* USampleGameLoopChromaBP::_sColorsKeypad = NULL;
int32* USampleGameLoopChromaBP::_sColorsMouse = NULL;
int32* USampleGameLoopChromaBP::_sColorsMousepad = NULL;

int32* USampleGameLoopChromaBP::_sTempColorsChromaLink = NULL;
int32* USampleGameLoopChromaBP::_sTempColorsHeadset = NULL;
int32* USampleGameLoopChromaBP::_sTempColorsKeyboard = NULL;
int32* USampleGameLoopChromaBP::_sTempColorsKeyboardExtended = NULL;
int32* USampleGameLoopChromaBP::_sTempColorsKeypad = NULL;
int32* USampleGameLoopChromaBP::_sTempColorsMouse = NULL;
int32* USampleGameLoopChromaBP::_sTempColorsMousepad = NULL;

float USampleGameLoopChromaBP::_sTime = 0;
uint32 USampleGameLoopChromaBP::_sTimeMS = 0;

#endif


//USampleGameLoopChromaBP::USampleGameLoopChromaBP(const FPostConstructInitializeProperties& PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
//	: Super(PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
USampleGameLoopChromaBP::USampleGameLoopChromaBP(const FObjectInitializer& ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
	: Super(ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	_sSizeChromaLink = GetColorArraySize1D(EChromaSDKDevice1DEnum::DE_ChromaLink);
	_sSizeHeadset = GetColorArraySize1D(EChromaSDKDevice1DEnum::DE_Headset);
	_sSizeKeyboard = GetColorArraySize2D(EChromaSDKDevice2DEnum::DE_Keyboard);
	_sSizeKeyboardExtended = GetColorArraySize2D(EChromaSDKDevice2DEnum::DE_KeyboardExtended);
	_sSizeKeypad = GetColorArraySize2D(EChromaSDKDevice2DEnum::DE_Keypad);
	_sSizeMouse = GetColorArraySize2D(EChromaSDKDevice2DEnum::DE_Mouse);
	_sSizeMousepad = GetColorArraySize1D(EChromaSDKDevice1DEnum::DE_Mousepad);
#endif
}

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

int USampleGameLoopChromaBP::min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int USampleGameLoopChromaBP::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int USampleGameLoopChromaBP::GetKeyColorIndex(int row, int column)
{
	return UChromaSDKPluginBPLibrary::GetMaxColumn(EChromaSDKDevice2DEnum::DE_Keyboard) * row + column;
}

void USampleGameLoopChromaBP::SetKeyColor(int* colors, EChromaSDKKeyboardKey::Type key, int color)
{
	const int customFlag = 1 << 24;
	int rzkey = UChromaSDKPluginBPLibrary::GetKeyboardRzKey(key);
	int row = HIBYTE(rzkey);
	int column = LOBYTE(rzkey);
	colors[GetKeyColorIndex(row, column)] = customFlag | color;
}

void USampleGameLoopChromaBP::SetKeyColorRGB(int* colors, EChromaSDKKeyboardKey::Type key, int red, int green, int blue)
{
	SetKeyColor(colors, key, UChromaSDKPluginBPLibrary::GetBGRInt(red, green, blue));
}

const int USampleGameLoopChromaBP::GetColorArraySize1D(EChromaSDKDevice1DEnum::Type device)
{
	const int maxLeds = UChromaSDKPluginBPLibrary::GetMaxLeds(device);
	return maxLeds;
}

const int USampleGameLoopChromaBP::GetColorArraySize2D(EChromaSDKDevice2DEnum::Type device)
{
	const int maxRow = UChromaSDKPluginBPLibrary::GetMaxRow(device);
	const int maxColumn = UChromaSDKPluginBPLibrary::GetMaxColumn(device);
	return maxRow * maxColumn;
}

int USampleGameLoopChromaBP::MultiplyColor(int color1, int color2) {
	int redColor1 = color1 & 0xFF;
	int greenColor1 = (color1 >> 8) & 0xFF;
	int blueColor1 = (color1 >> 16) & 0xFF;

	int redColor2 = color2 & 0xFF;
	int greenColor2 = (color2 >> 8) & 0xFF;
	int blueColor2 = (color2 >> 16) & 0xFF;

	int red = (int)floor(255 * ((redColor1 / 255.0f) * (redColor2 / 255.0f)));
	int green = (int)floor(255 * ((greenColor1 / 255.0f) * (greenColor2 / 255.0f)));
	int blue = (int)floor(255 * ((blueColor1 / 255.0f) * (blueColor2 / 255.0f)));

	return UChromaSDKPluginBPLibrary::GetBGRInt(red, green, blue);
}

int USampleGameLoopChromaBP::AverageColor(int color1, int color2) {
	return UChromaSDKPluginBPLibrary::LerpColorBGR(color1, color2, 0.5f);
}

int USampleGameLoopChromaBP::AddColor(int color1, int color2) {
	int redColor1 = color1 & 0xFF;
	int greenColor1 = (color1 >> 8) & 0xFF;
	int blueColor1 = (color1 >> 16) & 0xFF;

	int redColor2 = color2 & 0xFF;
	int greenColor2 = (color2 >> 8) & 0xFF;
	int blueColor2 = (color2 >> 16) & 0xFF;

	int red = min(redColor1 + redColor2, 255) & 0xFF;
	int green = min(greenColor1 + greenColor2, 255) & 0xFF;
	int blue = min(blueColor1 + blueColor2, 255) & 0xFF;

	return UChromaSDKPluginBPLibrary::GetBGRInt(red, green, blue);
}

int USampleGameLoopChromaBP::SubtractColor(int color1, int color2) {
	int redColor1 = color1 & 0xFF;
	int greenColor1 = (color1 >> 8) & 0xFF;
	int blueColor1 = (color1 >> 16) & 0xFF;

	int redColor2 = color2 & 0xFF;
	int greenColor2 = (color2 >> 8) & 0xFF;
	int blueColor2 = (color2 >> 16) & 0xFF;

	int red = max(redColor1 - redColor2, 0) & 0xFF;
	int green = max(greenColor1 - greenColor2, 0) & 0xFF;
	int blue = max(blueColor1 - blueColor2, 0) & 0xFF;

	return UChromaSDKPluginBPLibrary::GetBGRInt(red, green, blue);
}

int USampleGameLoopChromaBP::MaxColor(int color1, int color2) {
	int redColor1 = color1 & 0xFF;
	int greenColor1 = (color1 >> 8) & 0xFF;
	int blueColor1 = (color1 >> 16) & 0xFF;

	int redColor2 = color2 & 0xFF;
	int greenColor2 = (color2 >> 8) & 0xFF;
	int blueColor2 = (color2 >> 16) & 0xFF;

	int red = max(redColor1, redColor2) & 0xFF;
	int green = max(greenColor1, greenColor2) & 0xFF;
	int blue = max(blueColor1, blueColor2) & 0xFF;

	return UChromaSDKPluginBPLibrary::GetBGRInt(red, green, blue);
}

int USampleGameLoopChromaBP::MinColor(int color1, int color2) {
	int redColor1 = color1 & 0xFF;
	int greenColor1 = (color1 >> 8) & 0xFF;
	int blueColor1 = (color1 >> 16) & 0xFF;

	int redColor2 = color2 & 0xFF;
	int greenColor2 = (color2 >> 8) & 0xFF;
	int blueColor2 = (color2 >> 16) & 0xFF;

	int red = min(redColor1, redColor2) & 0xFF;
	int green = min(greenColor1, greenColor2) & 0xFF;
	int blue = min(blueColor1, blueColor2) & 0xFF;

	return UChromaSDKPluginBPLibrary::GetBGRInt(red, green, blue);
}

int USampleGameLoopChromaBP::InvertColor(int color) {
	int red = 255 - (color & 0xFF);
	int green = 255 - ((color >> 8) & 0xFF);
	int blue = 255 - ((color >> 16) & 0xFF);

	return UChromaSDKPluginBPLibrary::GetBGRInt(red, green, blue);
}

int USampleGameLoopChromaBP::MultiplyNonZeroTargetColorLerp(int color1, int color2, int inputColor) {
	if (inputColor == 0)
	{
		return inputColor;
	}
	float red = (inputColor & 0xFF) / 255.0f;
	float green = ((inputColor & 0xFF00) >> 8) / 255.0f;
	float blue = ((inputColor & 0xFF0000) >> 16) / 255.0f;
	float t = (red + green + blue) / 3.0f;
	return UChromaSDKPluginBPLibrary::LerpColorBGR(color1, color2, t);
}

int USampleGameLoopChromaBP::Thresh(int color1, int color2, int inputColor) {
	float red = (inputColor & 0xFF) / 255.0f;
	float green = ((inputColor & 0xFF00) >> 8) / 255.0f;
	float blue = ((inputColor & 0xFF0000) >> 16) / 255.0f;
	float t = (red + green + blue) / 3.0f;
	if (t == 0.0)
	{
		return 0;
	}
	if (t < 0.5)
	{
		return color1;
	}
	else
	{
		return color2;
	}
}


void USampleGameLoopChromaBP::BlendAnimation1D(const FChromaSDKSceneEffect& effect, FChromaSDKDeviceFrameIndex& deviceFrameIndex, int device, EChromaSDKDevice1DEnum::Type device1d, const FString& animationName,
	int* colors, int* tempColors)
{
	const int size = GetColorArraySize1D(device1d);
	const int frameId = deviceFrameIndex.FrameIndex[device];
	const int frameCount = UChromaSDKPluginBPLibrary::GetFrameCountName(animationName);
	if (frameId < frameCount)
	{
		//cout << animationName << ": " << (1 + frameId) << " of " << frameCount << endl;
		float duration;
		int animationId = UChromaSDKPluginBPLibrary::GetAnimation(animationName);
		UChromaSDKPluginBPLibrary::GetFrameBGR(animationId, frameId, &duration, tempColors, size, nullptr, 0);
		for (int i = 0; i < size; ++i)
		{
			int color1 = colors[i]; //target
			int tempColor = tempColors[i]; //source

			// BLEND
			int color2;
			switch (effect.Blend)
			{
			case EChromaSDKSceneBlend::SB_None:
				color2 = tempColor; //source
				break;
			case EChromaSDKSceneBlend::SB_Invert:
				if (tempColor != 0) //source
				{
					color2 = InvertColor(tempColor); //source inverted
				}
				else
				{
					color2 = 0;
				}
				break;
			case EChromaSDKSceneBlend::SB_Threshold:
				color2 = Thresh(effect.PrimaryColor, effect.SecondaryColor, tempColor); //source
				break;
			case EChromaSDKSceneBlend::SB_Lerp:
			default:
				color2 = MultiplyNonZeroTargetColorLerp(effect.PrimaryColor, effect.SecondaryColor, tempColor); //source
				break;
			}

			// MODE
			switch (effect.Mode)
			{
			case EChromaSDKSceneMode::SM_Max:
				colors[i] = MaxColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Min:
				colors[i] = MinColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Average:
				colors[i] = AverageColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Multiply:
				colors[i] = MultiplyColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Add:
				colors[i] = AddColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Subtract:
				colors[i] = SubtractColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Replace:
			default:
				if (color2 != 0) {
					colors[i] = color2;
				}
				break;
			}
		}
		deviceFrameIndex.FrameIndex[device] = (frameId + frameCount + effect.Speed) % frameCount;
	}
}

void USampleGameLoopChromaBP::BlendAnimation2D(const FChromaSDKSceneEffect& effect, FChromaSDKDeviceFrameIndex& deviceFrameIndex, int device, EChromaSDKDevice2DEnum::Type device2D, const FString& animationName,
	int* colors, int* tempColors)
{
	const int size = GetColorArraySize2D(device2D);
	const int frameId = deviceFrameIndex.FrameIndex[device];
	const int frameCount = UChromaSDKPluginBPLibrary::GetFrameCountName(animationName);
	if (frameId < frameCount)
	{
		//cout << animationName << ": " << (1 + frameId) << " of " << frameCount << endl;
		float duration;
		int animationId = UChromaSDKPluginBPLibrary::GetAnimation(animationName);
		UChromaSDKPluginBPLibrary::GetFrameBGR(animationId, frameId, &duration, tempColors, size, nullptr, 0);
		for (int i = 0; i < size; ++i)
		{
			int color1 = colors[i]; //target
			int tempColor = tempColors[i]; //source

			// BLEND
			int color2;
			switch (effect.Blend)
			{
			case EChromaSDKSceneBlend::SB_None:
				color2 = tempColor; //source
				break;
			case EChromaSDKSceneBlend::SB_Invert:
				if (tempColor != 0) //source
				{
					color2 = InvertColor(tempColor); //source inverted
				}
				else
				{
					color2 = 0;
				}
				break;
			case EChromaSDKSceneBlend::SB_Threshold:
				color2 = Thresh(effect.PrimaryColor, effect.SecondaryColor, tempColor); //source
				break;
			case EChromaSDKSceneBlend::SB_Lerp:
			default:
				color2 = MultiplyNonZeroTargetColorLerp(effect.PrimaryColor, effect.SecondaryColor, tempColor); //source
				break;
			}

			// MODE
			switch (effect.Mode)
			{
			case EChromaSDKSceneMode::SM_Max:
				colors[i] = MaxColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Min:
				colors[i] = MinColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Average:
				colors[i] = AverageColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Multiply:
				colors[i] = MultiplyColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Add:
				colors[i] = AddColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Subtract:
				colors[i] = SubtractColor(color1, color2);
				break;
			case EChromaSDKSceneMode::SM_Replace:
			default:
				if (color2 != 0) {
					colors[i] = color2;
				}
				break;
			}
		}
		deviceFrameIndex.FrameIndex[device] = (frameId + frameCount + effect.Speed) % frameCount;
	}
}

void USampleGameLoopChromaBP::BlendAnimations(FChromaSDKScene& scene,
	int* colorsChromaLink, int* tempColorsChromaLink,
	int* colorsHeadset, int* tempColorsHeadset,
	int* colorsKeyboard, int* tempColorsKeyboard,
	int* colorsKeyboardExtended, int* tempColorsKeyboardExtended,
	int* colorsKeypad, int* tempColorsKeypad,
	int* colorsMouse, int* tempColorsMouse,
	int* colorsMousepad, int* tempColorsMousepad)
{
	// blend active animations
	TArray<FChromaSDKSceneEffect>& effects = scene.Effects;
	for (int effectId = 0; effectId < effects.Num(); ++effectId)
	{
		FChromaSDKSceneEffect& effect = effects[effectId];
		if (effect.State)
		{
			FChromaSDKDeviceFrameIndex& deviceFrameIndex = effect.FrameIndex;

			//iterate all device types
			for (int d = (int)EChromaSDKDeviceEnum::DE_ChromaLink; d < (int)EChromaSDKDeviceEnum::DE_MAX; ++d)
			{
				FString animationName = effect.Animation;

				switch ((EChromaSDKDeviceEnum::Type)d)
				{
				case EChromaSDKDeviceEnum::DE_ChromaLink:
					animationName += "_ChromaLink.chroma";
					BlendAnimation1D(effect, deviceFrameIndex, d, EChromaSDKDevice1DEnum::DE_ChromaLink, animationName, colorsChromaLink, tempColorsChromaLink);
					break;
				case EChromaSDKDeviceEnum::DE_Headset:
					animationName += "_Headset.chroma";
					BlendAnimation1D(effect, deviceFrameIndex, d, EChromaSDKDevice1DEnum::DE_Headset, animationName, colorsHeadset, tempColorsHeadset);
					break;
				case EChromaSDKDeviceEnum::DE_Keyboard:
					animationName += "_Keyboard.chroma";
					BlendAnimation2D(effect, deviceFrameIndex, d, EChromaSDKDevice2DEnum::DE_Keyboard, animationName, colorsKeyboard, tempColorsKeyboard);
					break;
				case EChromaSDKDeviceEnum::DE_KeyboardExtended:
					animationName += "_KeyboardExtended.chroma";
					BlendAnimation2D(effect, deviceFrameIndex, d, EChromaSDKDevice2DEnum::DE_KeyboardExtended, animationName, colorsKeyboardExtended, tempColorsKeyboardExtended);
					break;
				case EChromaSDKDeviceEnum::DE_Keypad:
					animationName += "_Keypad.chroma";
					BlendAnimation2D(effect, deviceFrameIndex, d, EChromaSDKDevice2DEnum::DE_Keypad, animationName, colorsKeypad, tempColorsKeypad);
					break;
				case EChromaSDKDeviceEnum::DE_Mouse:
					animationName += "_Mouse.chroma";
					BlendAnimation2D(effect, deviceFrameIndex, d, EChromaSDKDevice2DEnum::DE_Mouse, animationName, colorsMouse, tempColorsMouse);
					break;
				case EChromaSDKDeviceEnum::DE_Mousepad:
					animationName += "_Mousepad.chroma";
					BlendAnimation1D(effect, deviceFrameIndex, d, EChromaSDKDevice1DEnum::DE_Mousepad, animationName, colorsMousepad, tempColorsMousepad);
					break;
				}
			}
		}
	}
}

void USampleGameLoopChromaBP::InitArrayBGRInt(int32** colors, int32 size)
{
	if (colors == NULL ||
		*colors != NULL)
	{
		return;
	}
	(*colors) = new int[size];
}
void USampleGameLoopChromaBP::UninitArrayBGRInt(int32** colors)
{
	if (colors == NULL ||
		*colors == NULL)
	{
		return;
	}
	delete[] (*colors);
	(*colors) = NULL;
}

FLinearColor USampleGameLoopChromaBP::SampleGameLoopGenerateRandomColor()
{
	return UChromaSDKPluginBPLibrary::GetRGB(rand() % 256, rand() % 256, rand() % 256);
}

void USampleGameLoopChromaBP::SampleGameLoopSetAmbientColor(const FLinearColor& ambientColor)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	_sAmbientColor = UChromaSDKPluginBPLibrary::ToBGR(ambientColor);
#endif
}

void USampleGameLoopChromaBP::SetStaticColor(int* colors, int color, int size)
{
	for (int i = 0; i < size; ++i)
	{
		colors[i] = color;
	}
}

#endif

void USampleGameLoopChromaBP::SampleGameLoopSampleStart()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!UChromaSDKPluginBPLibrary::IsInitialized())
	{
		FChromaSDKAppInfoType appInfo;
		appInfo.Title = "UE4 Chroma Sample Game Loop Application";
		appInfo.Description = "A sample application using Razer Chroma SDK";
		appInfo.Author_Name = "Razer";
		appInfo.Author_Contact = "https://github.com/razerofficial/UE4_XDK_SampleApp";

		//appInfo.SupportedDevice = 
		//    0x01 | // Keyboards
		//    0x02 | // Mice
		//    0x04 | // Headset
		//    0x08 | // Mousepads
		//    0x10 | // Keypads
		//    0x20   // ChromaLink devices
		//    ;
		appInfo.SupportedDevice = (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20);
		appInfo.Category = 1;

		int32 result = UChromaSDKPluginBPLibrary::ChromaSDKInitSDK(appInfo);
		switch (result)
		{
		case RZRESULT_DLL_NOT_FOUND:
			UE_LOG(LogChromaSampleGameLoop, Log, TEXT("Chroma DLL is not found!"));
			break;
		case RZRESULT_DLL_INVALID_SIGNATURE:
			UE_LOG(LogChromaSampleGameLoop, Log, TEXT("Chroma DLL has an invalid signature!"));
			break;
		case RZRESULT_SUCCESS:
			//UE_LOG(LogChromaSampleGameLoop, Log, TEXT("Chroma has initialized successfully!"));
			break;
		default:
			// It's not an error for Chroma to not initialize.
			// The SDK might not be installed.
			// Just avoid making further calls to Chroma until next launch.
			UE_LOG(LogChromaSampleGameLoop, Log, TEXT("Failed to initialize Chroma!"));
			break;
		}
	}

	if (UChromaSDKPluginBPLibrary::IsInitialized())
	{
		InitArrayBGRInt(&_sColorsChromaLink, _sSizeChromaLink);
		InitArrayBGRInt(&_sColorsHeadset, _sSizeHeadset);
		InitArrayBGRInt(&_sColorsKeyboard, _sSizeKeyboard);
		InitArrayBGRInt(&_sColorsKeyboardExtended, _sSizeKeyboardExtended);
		InitArrayBGRInt(&_sColorsKeyboardKeys, _sSizeKeyboard);
		InitArrayBGRInt(&_sColorsKeypad, _sSizeKeypad);
		InitArrayBGRInt(&_sColorsMouse, _sSizeMouse);
		InitArrayBGRInt(&_sColorsMousepad, _sSizeMousepad);

		InitArrayBGRInt(&_sTempColorsChromaLink, _sSizeChromaLink);
		InitArrayBGRInt(&_sTempColorsHeadset, _sSizeHeadset);
		InitArrayBGRInt(&_sTempColorsKeyboard, _sSizeKeyboard);
		InitArrayBGRInt(&_sTempColorsKeyboardExtended, _sSizeKeyboardExtended);
		InitArrayBGRInt(&_sTempColorsKeypad, _sSizeKeypad);
		InitArrayBGRInt(&_sTempColorsMouse, _sSizeMouse);
		InitArrayBGRInt(&_sTempColorsMousepad, _sSizeMousepad);
	}
#endif
}

void USampleGameLoopChromaBP::SampleGameLoopSampleEnd()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (UChromaSDKPluginBPLibrary::IsInitialized())
	{
		UninitArrayBGRInt(&_sColorsChromaLink);
		UninitArrayBGRInt(&_sColorsHeadset);
		UninitArrayBGRInt(&_sColorsKeyboard);
		UninitArrayBGRInt(&_sColorsKeyboardExtended);
		UninitArrayBGRInt(&_sColorsKeyboardKeys);
		UninitArrayBGRInt(&_sColorsKeypad);
		UninitArrayBGRInt(&_sColorsMouse);
		UninitArrayBGRInt(&_sColorsMousepad);

		UninitArrayBGRInt(&_sTempColorsChromaLink);
		UninitArrayBGRInt(&_sTempColorsHeadset);
		UninitArrayBGRInt(&_sTempColorsKeyboard);
		UninitArrayBGRInt(&_sTempColorsKeypad);
		UninitArrayBGRInt(&_sTempColorsMouse);
		UninitArrayBGRInt(&_sTempColorsMousepad);

		UChromaSDKPluginBPLibrary::ChromaSDKUnInit();
	}
#endif
}

void USampleGameLoopChromaBP::SampleGameLoopUpdate(float deltaSeconds, FChromaSDKScene& scene, bool toggleHotkeys, bool toggleExtended, bool toggleAmmo)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

	const int MAX_FPS = 30;
	const float MAX_FPS_INV = 1 / (float)MAX_FPS;

	if (UChromaSDKPluginBPLibrary::IsInitialized())
	{
		_sTime += deltaSeconds;
		if (_sTime < MAX_FPS_INV)
		{
			return;
		}
		_sTime = 0;
		_sTimeMS += 1000 / MAX_FPS;

		// make sure arrays have initialized
		if (_sColorsChromaLink == NULL ||
			_sColorsHeadset == NULL ||
			_sColorsKeyboard == NULL ||
			_sColorsKeyboardExtended == NULL ||
			_sColorsKeyboardKeys == NULL ||
			_sColorsKeypad == NULL ||
			_sColorsMouse == NULL ||
			_sColorsMousepad == NULL ||
			_sTempColorsChromaLink == NULL ||
			_sTempColorsHeadset == NULL ||
			_sTempColorsKeyboard == NULL ||
			_sTempColorsKeyboardExtended == NULL ||
			_sTempColorsKeypad == NULL ||
			_sTempColorsMouse == NULL ||
			_sTempColorsMousepad == NULL)
		{
			return;
		}

		// start with a blank frame
		SetStaticColor(_sColorsChromaLink, _sAmbientColor, _sSizeChromaLink);
		SetStaticColor(_sColorsHeadset, _sAmbientColor, _sSizeHeadset);
		if (toggleExtended)
		{
			SetStaticColor(_sColorsKeyboardExtended, _sAmbientColor, _sSizeKeyboardExtended);
		}
		else
		{
			SetStaticColor(_sColorsKeyboard, _sAmbientColor, _sSizeKeyboard);
		}
		SetStaticColor(_sColorsKeyboardKeys, _sAmbientColor, _sSizeKeyboard);
		SetStaticColor(_sColorsKeypad, _sAmbientColor, _sSizeKeypad);
		SetStaticColor(_sColorsMouse, _sAmbientColor, _sSizeMouse);
		SetStaticColor(_sColorsMousepad, _sAmbientColor, _sSizeMousepad);

		BlendAnimations(scene,
			_sColorsChromaLink, _sTempColorsChromaLink,
			_sColorsHeadset, _sTempColorsHeadset,
			_sColorsKeyboard, _sTempColorsKeyboard,
			_sColorsKeyboardExtended, _sTempColorsKeyboardExtended,
			_sColorsKeypad, _sTempColorsKeypad,
			_sColorsMouse, _sTempColorsMouse,
			_sColorsMousepad, _sTempColorsMousepad);

		if (toggleAmmo)
		{
			// Show health animation
			{
				TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>> keys;
				keys.Add(EChromaSDKKeyboardKey::KK_F1);
				keys.Add(EChromaSDKKeyboardKey::KK_F2);
				keys.Add(EChromaSDKKeyboardKey::KK_F3);
				keys.Add(EChromaSDKKeyboardKey::KK_F4);
				keys.Add(EChromaSDKKeyboardKey::KK_F5);
				keys.Add(EChromaSDKKeyboardKey::KK_F6);
				int keysLength = keys.Num();

				float t = _sTimeMS * 0.002f;
				float hp = fabsf(cos(PI / 2.0f + t));
				for (int i = 0; i < keysLength; ++i) {
					int color;
					if (((i + 1) / ((float)keysLength + 1)) < hp) {
						color = UChromaSDKPluginBPLibrary::GetBGRInt(0, 255, 0);
					}
					else {
						color = UChromaSDKPluginBPLibrary::GetBGRInt(0, 100, 0);
					}
					SetKeyColor(_sColorsKeyboardKeys, keys[i], color);
				}
			}

			// Show ammo animation
			{
				TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>> keys;
				keys.Add(EChromaSDKKeyboardKey::KK_F7);
				keys.Add(EChromaSDKKeyboardKey::KK_F8);
				keys.Add(EChromaSDKKeyboardKey::KK_F9);
				keys.Add(EChromaSDKKeyboardKey::KK_F10);
				keys.Add(EChromaSDKKeyboardKey::KK_F11);
				keys.Add(EChromaSDKKeyboardKey::KK_F12);
				int keysLength = keys.Num();

				float t = _sTimeMS * 0.001f;
				float hp = fabsf(cos(PI / 2.0f + t));
				for (int i = 0; i < keysLength; ++i) {
					int color;
					if (((i + 1) / ((float)keysLength + 1)) < hp) {
						color = UChromaSDKPluginBPLibrary::GetBGRInt(255, 255, 0);
					}
					else {
						color = UChromaSDKPluginBPLibrary::GetBGRInt(100, 100, 0);
					}
					SetKeyColor(_sColorsKeyboardKeys, keys[i], color);
				}
			}
		}

		if (toggleHotkeys)
		{
			const int indexGradient1 = 0;
			const int indexGradient2 = 1;
			const int indexGradient3 = 2;
			const int indexGradient4 = 3;

			// Show hotkeys
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_ESC, 255, 255, 0);
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_H, 255, 0, 0);
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_E, 255, 0, 0);
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_A, 255, 0, 0);
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_1, 255, 0, 0);
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_1, 255, 0, 0);
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_2, 255, 0, 0);
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_3, 255, 0, 0);
			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_4, 255, 0, 0);

			if (toggleExtended)
			{
				SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_E, 0, 255, 0);
			}

			if (toggleAmmo)
			{
				SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_A, 0, 255, 0);
			}

			// Highlight if active
			if (scene.Effects[indexGradient1].State)
			{
				SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_1, 0, 255, 0);
			}

			// Highlight if active
			if (scene.Effects[indexGradient2].State)
			{
				SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_2, 0, 255, 0);
			}

			// Highlight if active
			if (scene.Effects[indexGradient3].State)
			{
				SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_3, 0, 255, 0);
			}

			// Highlight if active
			if (scene.Effects[indexGradient4].State)
			{
				SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_4, 0, 255, 0);
			}

			SetKeyColorRGB(_sColorsKeyboardKeys, EChromaSDKKeyboardKey::KK_H, 0, 255, 0);
		}

		UChromaSDKPluginBPLibrary::SetEffectCustom1D_BGR(EChromaSDKDevice1DEnum::DE_ChromaLink, _sColorsChromaLink);
		UChromaSDKPluginBPLibrary::SetEffectCustom1D_BGR(EChromaSDKDevice1DEnum::DE_Headset, _sColorsHeadset);
		UChromaSDKPluginBPLibrary::SetEffectCustom1D_BGR(EChromaSDKDevice1DEnum::DE_Mousepad, _sColorsMousepad);

		if (toggleExtended)
		{
			UChromaSDKPluginBPLibrary::SetEffectKeyboardCustom2D_BGR(EChromaSDKDevice2DEnum::DE_KeyboardExtended, _sColorsKeyboardExtended, _sColorsKeyboardKeys);
		}
		else
		{
			UChromaSDKPluginBPLibrary::SetEffectKeyboardCustom2D_BGR(EChromaSDKDevice2DEnum::DE_Keyboard, _sColorsKeyboard, _sColorsKeyboardKeys);
		}

		UChromaSDKPluginBPLibrary::SetEffectCustom2D_BGR(EChromaSDKDevice2DEnum::DE_Keypad, _sColorsKeypad);
		UChromaSDKPluginBPLibrary::SetEffectCustom2D_BGR(EChromaSDKDevice2DEnum::DE_Mouse, _sColorsMouse);
	}
#endif
}
