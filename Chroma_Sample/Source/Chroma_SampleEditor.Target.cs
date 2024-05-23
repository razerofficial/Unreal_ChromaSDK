// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Chroma_SampleEditorTarget : TargetRules
{
//	public Chroma_SampleEditorTarget(TargetInfo Target) //___HACK_UE4_VERSION_4_15_OR_LESS
    public Chroma_SampleEditorTarget(TargetInfo Target) : base(Target) //___HACK_UE4_VERSION_4_16_OR_GREATER
    {
#if UE_5_4_OR_LATER
        DefaultBuildSettings = BuildSettingsVersion.Latest;
#endif

        Type = TargetType.Editor;

        ExtraModuleNames.AddRange(new string[] { "Chroma_Sample" }); //___HACK_UE4_VERSION_4_16_OR_GREATER
    }

	//
	// TargetRules interface.
	//

//	public override void SetupBinaries( //___HACK_UE4_VERSION_4_15_OR_LESS
//        TargetInfo Target, //___HACK_UE4_VERSION_4_15_OR_LESS
//        ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations, //___HACK_UE4_VERSION_4_15_OR_LESS
//        ref List<string> OutExtraModuleNames //___HACK_UE4_VERSION_4_15_OR_LESS
//        ) //___HACK_UE4_VERSION_4_15_OR_LESS
//    { //___HACK_UE4_VERSION_4_15_OR_LESS
//        OutExtraModuleNames.AddRange( new string[] { "Chroma_Sample" } ); //___HACK_UE4_VERSION_4_15_OR_LESS
//    } //___HACK_UE4_VERSION_4_15_OR_LESS
}
