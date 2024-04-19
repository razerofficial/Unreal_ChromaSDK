// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Chroma_Sample : ModuleRules
{
//	public Chroma_Sample(TargetInfo Target) //___HACK_UE4_VERSION_4_15_OR_LESS
	public Chroma_Sample(ReadOnlyTargetRules Target) : base(Target) //___HACK_UE4_VERSION_4_16_OR_GREATER
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs; //___HACK_UE4_VERSION_4_16_OR_GREATER
		
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "RHI", "RenderCore", "UMG", "ChromaSDKPlugin" });

        PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

//		UEBuildConfiguration.bForceEnableExceptions = true; // ___HACK_UE4_VERSION_4_8_OR_LESS
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
