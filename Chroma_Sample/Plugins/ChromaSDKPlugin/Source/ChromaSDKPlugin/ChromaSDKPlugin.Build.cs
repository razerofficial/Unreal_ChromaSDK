// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class ChromaSDKPlugin : ModuleRules
	{
//		public ChromaSDKPlugin(TargetInfo Target) //___HACK_UE4_VERSION_4_15_OR_LESS
		public ChromaSDKPlugin(ReadOnlyTargetRules Target) : base(Target) //___HACK_UE4_VERSION_4_16_OR_GREATER
		{
            // https://answers.unrealengine.com/questions/51798/how-can-i-enable-unwind-semantics-for-c-style-exce.html
//            UEBuildConfiguration.bForceEnableExceptions = true;//___HACK_UE4_VERSION_4_9_TO_VERSION_4_15
			
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs; //___HACK_UE4_VERSION_4_16_OR_GREATER

#if UE_5_4_OR_LATER
			DefaultBuildSettings = BuildSettingsVersion.Latest;
#endif

            PrivateDefinitions.Add("CHECK_CHROMA_LIBRARY_SIGNATURE=1");
            PublicDefinitions.Add("CHECK_CHROMA_LIBRARY_SIGNATURE=1");

            PublicIncludePaths.AddRange(
				new string[] {
                    ModuleDirectory + "/Public",
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
                    ModuleDirectory + "/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
                    "CoreUObject",
                    "InputCore",
                    "Engine",
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
		}
	}
}