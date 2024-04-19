#include "ChromaSDKPluginTypes.h" //___HACK_UE4_VERSION_4_16_OR_GREATER
#include "ChromaSDKPluginPrivatePCH.h"
//#include "ChromaSDKPluginTypes.h" //___HACK_UE4_VERSION_4_15_OR_LESS


FChromaSDKGuid::FChromaSDKGuid()
{
#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
	Data = RZEFFECTID();
	Data.Data1 = 0;
	Data.Data2 = 0;
	Data.Data3 = 0;
	for (int i = 0; i < 8; ++i)
	{
		Data.Data4[i] = 0;
	}
#endif
}


FChromaSDKEffectResult::FChromaSDKEffectResult()
{
	Result = 0;
	EffectId = FChromaSDKGuid();
}


FChromaSDKColors::FChromaSDKColors()
{
}


FChromaSDKColorFrame1D::FChromaSDKColorFrame1D()
{
	Duration = 1;
}


FChromaSDKColorFrame2D::FChromaSDKColorFrame2D()
{
	Duration = 1;
}


FChromaSDKSceneEffect::FChromaSDKSceneEffect()
{
	Speed = 1;
}

void FChromaSDKScene::ToggleState(unsigned int effect)
{
	if (effect >= 0 && effect < (unsigned int)Effects.Num())
	{
		Effects[effect].State = !Effects[effect].State;
	}
}

FChromaSDKDeviceInfoType::FChromaSDKDeviceInfoType()
{
	DeviceType = EChromaSDKCoreDeviceTypeEnum::DEVICE_ALL;
	Connected = 0;
}

FChromaSDKDeviceInfoType::FChromaSDKDeviceInfoType(const FChromaSDKDeviceInfoType& rhs)
{
	DeviceType = rhs.DeviceType;
	Connected = rhs.Connected;
}
