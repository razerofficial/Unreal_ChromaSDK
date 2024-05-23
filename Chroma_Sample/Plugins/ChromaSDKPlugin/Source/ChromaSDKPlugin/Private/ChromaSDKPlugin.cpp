// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#include "IChromaSDKPlugin.h"
#include "ChromaSDKPluginPrivatePCH.h"

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

#include "ChromaAnimationAPI.h"

#include "Windows/AllowWindowsPlatformTypes.h" 

using namespace ChromaSDK;

DEFINE_LOG_CATEGORY(LogChromaPlugin);

class FChromaSDKPlugin : public IChromaSDKPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FChromaSDKPlugin, ChromaSDKPlugin )


void FChromaSDKPlugin::StartupModule()
{
#if defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE
	//UE_LOG(LogChromaPlugin, Log, TEXT("FChromaSDKPlugin::StartupModule()"));
#endif

	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	ChromaAnimationAPI::InitAPI();
#endif
}


void FChromaSDKPlugin::ShutdownModule()
{
#if defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE
	//UE_LOG(LogChromaPlugin, Log, TEXT("FChromaSDKPlugin::ShutdownModule()"));
#endif

	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

	if (ChromaAnimationAPI::GetIsInitializedAPI())
	{
		if (ChromaAnimationAPI::IsInitialized())
		{
			ChromaAnimationAPI::StopAll();
			ChromaAnimationAPI::CloseAll();
			RZRESULT result = ChromaAnimationAPI::Uninit();
			if (result != RZRESULT_SUCCESS)
			{
				UE_LOG(LogChromaPlugin, Error, TEXT("Failed to uninitialize Chroma!"));
			}
		}
		ChromaAnimationAPI::UninitAPI();
	}
	
#endif
}


#include "Windows/HideWindowsPlatformTypes.h"

#endif
