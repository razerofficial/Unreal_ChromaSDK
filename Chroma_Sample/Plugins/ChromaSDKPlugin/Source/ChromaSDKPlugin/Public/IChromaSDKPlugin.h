// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

#if PLATFORM_WINDOWS || PLATFORM_XBOXONE

DECLARE_LOG_CATEGORY_EXTERN(LogChromaPlugin, Log, All);

#endif

/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules 
 * within this plugin.
 */
class IChromaSDKPlugin : public IModuleInterface
{

public:

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IChromaSDKPlugin& Get()
	{
		return FModuleManager::LoadModuleChecked< IChromaSDKPlugin >( "ChromaSDKPlugin" );
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "ChromaSDKPlugin" );
	}
};
