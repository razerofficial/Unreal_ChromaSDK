// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "InputCoreTypes.h"
#include <map>
#include "IChromaSDKPlugin.h"
#include "ChromaSDKPluginTypes.h"
#include "ChromaSDKPluginBPLibrary.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogChromaBlueprintLibrary, Log, All);


UCLASS()
class CHROMASDKPLUGIN_API UChromaSDKPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

#pragma region Auto sort blueprint methods

	/*
	Add source color to target where color is not black for frame id, reference
	source and target by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroAllKeys", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void AddNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);

	/*
	Add source color to target where color is not black for all frames, reference
	source and target by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroAllKeysAllFrames", Keywords = "Add nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void AddNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	/*
	Add source color to target where color is not black for all frames, reference
	source and target by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroAllKeysAllFramesName", Keywords = "Add nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void AddNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	/*
	Add source color to target where color is not black for all frames starting
	at offset for the length of the source, reference source and target by
	id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroAllKeysAllFramesOffset", Keywords = "Add nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void AddNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset);

	/*
	Add source color to target where color is not black for all frames starting
	at offset for the length of the source, reference source and target by
	name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroAllKeysAllFramesOffsetName", Keywords = "Add nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void AddNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset);

	/*
	Add source color to target where color is not black for frame id, reference
	source and target by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroAllKeysName", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void AddNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);

	/*
	Add source color to target where the target color is not black for all frames,
	reference source and target by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroTargetAllKeysAllFrames", Keywords = "Add nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void AddNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	/*
	Add source color to target where the target color is not black for all frames,
	reference source and target by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroTargetAllKeysAllFramesName", Keywords = "Add nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void AddNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	/*
	Add source color to target where the target color is not black for all frames
	starting at offset for the length of the source, reference source and target
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroTargetAllKeysAllFramesOffset", Keywords = "Add nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void AddNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset);

	/*
	Add source color to target where the target color is not black for all frames
	starting at offset for the length of the source, reference source and target
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddNonZeroTargetAllKeysAllFramesOffsetName", Keywords = "Add nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void AddNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset);

	/*
	Append all source frames to the target animation, reference source and target
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AppendAllFrames", Keywords = "Append animation frames to another animation"), Category = "ChromaSDK")
	static void AppendAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	/*
	Append all source frames to the target animation, reference source and target
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AppendAllFramesName", Keywords = "Append animation frames to another animation"), Category = "ChromaSDK")
	static void AppendAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectCustom1D", Keywords = "Create a custom color effect using one-dimensional array"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectCustom1D(EChromaSDKDevice1DEnum::Type device, const TArray<FLinearColor>& colors);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectCustom2D", Keywords = "Create a custom color effect using two-dimensional array"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectCustom2D(EChromaSDKDevice2DEnum::Type device, const TArray<FChromaSDKColors>& colors);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectKeyboardCustom2D", Keywords = "Create a custom color keyboard effect using two-dimensional array"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectKeyboardCustom2D(const TArray<FChromaSDKColors>& colors);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectNone", Keywords = "Clear the color effect"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectNone(EChromaSDKDeviceEnum::Type device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateEffectStatic", Keywords = "Create a static color effect"), Category = "ChromaSDK")
	static FChromaSDKEffectResult ChromaSDKCreateEffectStatic(EChromaSDKDeviceEnum::Type device, const FLinearColor& colorParam);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DeleteEffect", Keywords = "Delete Effect with Effect Id"), Category = "ChromaSDK")
	static int32 ChromaSDKDeleteEffect(const FChromaSDKGuid& effectId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Init", Keywords = "Initialize the ChromaSDK"), Category = "ChromaSDK")
	static int32 ChromaSDKInit();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InitSDK", Keywords = "Initialize the ChromaSDK with AppInfo"), Category = "ChromaSDK")
	static int32 ChromaSDKInitSDK(const FChromaSDKAppInfoType& appInfo);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetEffect", Keywords = "Set Effect with Effect Id"), Category = "ChromaSDK")
	static int32 ChromaSDKSetEffect(const FChromaSDKGuid& effectId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UnInit", Keywords = "Uninitialize the ChromaSDK"), Category = "ChromaSDK")
	static int32 ChromaSDKUnInit();

	/*
	`PluginClearAll` will issue a `CLEAR` effect for all devices.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ClearAll", Keywords = "Clear all devices"), Category = "ChromaSDK")
	static void ClearAll();

	/*
	`PluginClearAnimationType` will issue a `CLEAR` effect for the given device.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ClearAnimationType", Keywords = "Clear the device"), Category = "ChromaSDK")
	static void ClearAnimationType(EChromaSDKDeviceEnum::Type device);

	/*
	`PluginCloseAll` closes all open animations so they can be reloaded from
	disk. The set of animations will be stopped if playing.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CloseAll", Keywords = "Close all animations"), Category = "ChromaSDK")
	static void CloseAll();

	/*
	Closes the `Chroma` animation to free up resources referenced by id. Returns
	the animation id upon success. Returns negative one upon failure. This
	might be used while authoring effects if there was a change necessitating
	re-opening the animation. The animation id can no longer be used once closed.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CloseAnimation", Keywords = "Close the *.chroma Animation"), Category = "ChromaSDK")
	static void CloseAnimation(const int32 animationId);

	/*
	Closes the `Chroma` animation referenced by name so that the animation can
	be reloaded from disk.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CloseAnimationName", Keywords = "Close the *.chroma Animation"), Category = "ChromaSDK")
	static void CloseAnimationName(const FString& animationName);

	/*
	Copy source animation to target animation for the given frame. Source and
	target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyAllKeys", Keywords = "Copy color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void CopyAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyAllKeysAllFrames", Keywords = "Copy color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyAllKeysAllFramesName", Keywords = "Copy color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	/*
	Copy source animation to target animation for the given frame. Source and
	target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyAllKeysName", Keywords = "Copy color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void CopyAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);

	/*
	Copy animation to named target animation in memory. If target animation
	exists, close first. Source is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyAnimation", Keywords = "Copy animation to the named animation"), Category = "ChromaSDK")
	static void CopyAnimation(int32 sourceAnimationId, const FString& targetAnimationName);

	/*
	Copy animation to named target animation in memory. If target animation
	exists, close first. Source is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyAnimationName", Keywords = "Copy animation to the named animation"), Category = "ChromaSDK")
	static void CopyAnimationName(const FString& sourceAnimationName, const FString& targetAnimationName);

	/*
	Copy animation key color from the source animation to the target animation
	for the given frame. Reference the source and target by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeyColor", Keywords = "Copy color from a source animation to a target animation for a key"), Category = "ChromaSDK")
	static void CopyKeyColor(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex, EChromaSDKKeyboardKey::Type key);

	/*
	Copy animation key color from the source animation to the target animation
	for the given frame.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeyColorName", Keywords = "Copy color from a source animation to a target animation for a key"), Category = "ChromaSDK")
	static void CopyKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 frameIndex, EChromaSDKKeyboardKey::Type key);

	/*
	Copy animation color for a set of keys from the source animation to the
	target animation for the given frame. Reference the source and target by
	id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeysColor", Keywords = "Copy color from a source animation to a target animation for a set of keys"), Category = "ChromaSDK")
	static void CopyKeysColor(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys);

	/*
	Copy animation color for a set of keys from the source animation to the
	target animation for all frames. Reference the source and target by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeysColorAllFrames", Keywords = "Copy color from a source animation to a target animation for a set of keys for all frames"), Category = "ChromaSDK")
	static void CopyKeysColorAllFrames(int32 sourceAnimationId, int32 targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys);

	/*
	Copy animation color for a set of keys from the source animation to the
	target animation for all frames. Reference the source and target by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeysColorAllFramesName", Keywords = "Copy color from a source animation to a target animation for a set of keys for all frames"), Category = "ChromaSDK")
	static void CopyKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys);

	/*
	Copy animation color for a set of keys from the source animation to the
	target animation for the given frame. Reference the source and target by
	name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyKeysColorName", Keywords = "Copy color from a source animation to a target animation for a set of keys"), Category = "ChromaSDK")
	static void CopyKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys);

	/*
	Copy source animation to target animation for the given frame. Source and
	target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeys", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void CopyNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);

	/*
	Copy nonzero colors from a source animation to a target animation for all
	frames. Reference source and target by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeysAllFrames", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	/*
	Copy nonzero colors from a source animation to a target animation for all
	frames. Reference source and target by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeysAllFramesName", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	/*
	Copy nonzero colors from a source animation to a target animation for all
	frames starting at the offset for the length of the source animation. The
	source and target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeysAllFramesOffset", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset);

	/*
	Copy nonzero colors from a source animation to a target animation for all
	frames starting at the offset for the length of the source animation. The
	source and target are referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeysAllFramesOffsetName", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset);

	/*
	Copy nonzero colors from source animation to target animation for the specified
	frame. Source and target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeysName", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void CopyNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);

	/*
	Copy nonzero colors from the source animation to the target animation from
	the source frame to the target offset frame. Source and target are referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeysOffset", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void CopyNonZeroAllKeysOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId, int32 offset);

	/*
	Copy nonzero colors from the source animation to the target animation from
	the source frame to the target offset frame. Source and target are referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeysOffsetName", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void CopyNonZeroAllKeysOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId, int32 offset);

	/*
	Copy animation key color from the source animation to the target animation
	for the given frame where color is not zero.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeyColor", Keywords = "Copy nonzero color from a source animation to a target animation for a key"), Category = "ChromaSDK")
	static void CopyNonZeroKeyColor(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex, EChromaSDKKeyboardKey::Type key);

	/*
	Copy animation key color from the source animation to the target animation
	for the given frame where color is not zero.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeyColorName", Keywords = "Copy nonzero color from a source animation to a target animation for a key"), Category = "ChromaSDK")
	static void CopyNonZeroKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 frameIndex, EChromaSDKKeyboardKey::Type key);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeysColor", Keywords = "Copy nonzero color from a source animation to a target animation for a set of keys"), Category = "ChromaSDK")
	static void CopyNonZeroKeysColor(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeysColorAllFrames", Keywords = "Copy nonzero color from a source animation to a target animation for a set of keys for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroKeysColorAllFrames(int32 sourceAnimationId, int32 targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeysColorAllFramesName", Keywords = "Copy nonzero color from a source animation to a target animation for a set of keys for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroKeysColorName", Keywords = "Copy nonzero color from a source animation to a target animation for a set of keys"), Category = "ChromaSDK")
	static void CopyNonZeroKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys);

	/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for the specified frame. Source and target
	are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeys", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void CopyNonZeroTargetAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);

	/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for all frames. Source and target are referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroTargetAllKeysAllFrames", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for all frames. Source and target are referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroTargetAllKeysAllFramesName", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for all frames. Source and target are referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroTargetAllKeysAllFramesOffset", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset);

	/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for all frames starting at the target offset
	for the length of the source animation. Source and target animations are
	referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroTargetAllKeysAllFramesOffsetName", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset);

	/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for the specified frame. The source and target
	are referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyNonZeroAllKeysName", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void CopyNonZeroTargetAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);

	/*
	Copy nonzero color from source animation to target animation where target
	is zero for all frames. Source and target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyZeroTargetAllKeysAllFrames", Keywords = "Copy nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	/*
	Copy nonzero color from source animation to target animation where target
	is zero for all frames. Source and target are referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CopyZeroTargetAllKeysAllFramesName", Keywords = "Copy zero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void CopyZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateColors1D", Keywords = "Create a blank one-dimensional color array"), Category = "ChromaSDK")
	static TArray<FLinearColor> CreateColors1D(EChromaSDKDevice1DEnum::Type device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateColors2D", Keywords = "Create a blank two-dimensional color array"), Category = "ChromaSDK")
	static TArray<FChromaSDKColors> CreateColors2D(EChromaSDKDevice2DEnum::Type device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateRandomColors1D", Keywords = "Create a random one-dimensional color array"), Category = "ChromaSDK")
	static TArray<FLinearColor> CreateRandomColors1D(EChromaSDKDevice1DEnum::Type device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateRandomColors2D", Keywords = "Create a random two-dimensional color array"), Category = "ChromaSDK")
	static TArray<FChromaSDKColors> CreateRandomColors2D(EChromaSDKDevice2DEnum::Type device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateRandomColorsBlackAndWhite1D", Keywords = "Create a random one-dimensional black and white color array"), Category = "ChromaSDK")
	static TArray<FLinearColor> CreateRandomColorsBlackAndWhite1D(EChromaSDKDevice1DEnum::Type device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateRandomColorsBlackAndWhite2D", Keywords = "Create a random two-dimensional black and white color array"), Category = "ChromaSDK")
	static TArray<FChromaSDKColors> CreateRandomColorsBlackAndWhite2D(EChromaSDKDevice2DEnum::Type device);

	/*
	Duplicate the first animation frame so that the animation length matches
	the frame count. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DuplicateFirstFrame", Keywords = "Duplicate the first frame for total the number of frames"), Category = "ChromaSDK")
	static void DuplicateFirstFrame(int32 animationId, int32 frameCount);

	/*
	Duplicate the first animation frame so that the animation length matches
	the frame count. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DuplicateFirstFrameName", Keywords = "Duplicate the first frame for total the number of frames"), Category = "ChromaSDK")
	static void DuplicateFirstFrameName(const FString& animationName, int32 frameCount);

	/*
	Duplicate all the frames of the animation to double the animation length.
	Frame 1 becomes frame 1 and 2. Frame 2 becomes frame 3 and 4. And so on.
	The animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DuplicateFrames", Keywords = "Double the number of frames"), Category = "ChromaSDK")
	static void DuplicateFrames(int32 animationId);

	/*
	Duplicate all the frames of the animation to double the animation length.
	Frame 1 becomes frame 1 and 2. Frame 2 becomes frame 3 and 4. And so on.
	The animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DuplicateFramesName", Keywords = "Double the number of frames"), Category = "ChromaSDK")
	static void DuplicateFramesName(const FString& animationName);

	/*
	Duplicate all the animation frames in reverse so that the animation plays
	forwards and backwards. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DuplicateMirrorFrames", Keywords = "Duplicate and mirror the animation"), Category = "ChromaSDK")
	static void DuplicateMirrorFrames(int32 animationId);

	/*
	Duplicate all the animation frames in reverse so that the animation plays
	forwards and backwards. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "DuplicateMirrorFramesName", Keywords = "Duplicate and mirror the animation"), Category = "ChromaSDK")
	static void DuplicateMirrorFramesName(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamGetStatus", Keywords = "Get Stream Status"), Category = "ChromaSDK")
	static const EChromaSDKStreamStatusEnum::Type StreamGetStatus();

	/*
	Fade the animation to black starting at the fade frame index to the end
	of the animation. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FadeEndFrames", Keywords = "Fade the end of the animation"), Category = "ChromaSDK")
	static void FadeEndFrames(int32 animationId, int32 fade);

	/*
	Fade the animation to black starting at the fade frame index to the end
	of the animation. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FadeEndFramesName", Keywords = "Fade the end of the animation"), Category = "ChromaSDK")
	static void FadeEndFramesName(const FString& animationName, int32 fade);

	/*
	Fade the animation from black to full color starting at 0 to the fade frame
	index. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FadeStartFrames", Keywords = "Fade the start of the animation"), Category = "ChromaSDK")
	static void FadeStartFrames(int32 animationId, int32 fade);

	/*
	Fade the animation from black to full color starting at 0 to the fade frame
	index. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FadeStartFramesName", Keywords = "Fade the start of the animation"), Category = "ChromaSDK")
	static void FadeStartFramesName(const FString& animationName, int32 fade);

	/*
	Set the RGB value for all colors in the specified frame. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillColor", Keywords = "Set the RGB value for all colors in the specified frame"), Category = "ChromaSDK")
	static void FillColor(int32 animationId, int32 frameId, const FLinearColor& colorParam);

	/*
	Set the RGB value for all colors for all frames. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillColorAllFrames", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillColorAllFrames(int32 animationId, const FLinearColor& colorParam);

	/*
	Set the RGB value for all colors for all frames. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillColorAllFramesName", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillColorAllFramesName(const FString& animationName, const FLinearColor& colorParam);

	/*
	Set the RGB value for all colors for all frames. Use the range of 0 to 255
	for red, green, and blue parameters. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillColorAllFramesRGB", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillColorAllFramesRGB(int32 animationId, int32 red, int32 green, int32 blue);

	/*
	Set the RGB value for all colors for all frames. Use the range of 0 to 255
	for red, green, and blue parameters. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillColorAllFramesRGBName", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillColorAllFramesRGBName(const FString& animationName, int32 red, int32 green, int32 blue);

	/*
	Set the RGB value for all colors in the specified frame. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillColorName", Keywords = "Set the RGB value for all colors in the specified frame"), Category = "ChromaSDK")
	static void FillColorName(const FString& animationName, int32 frameId, const FLinearColor& colorParam);

	/*
	Set the RGB value for all colors in the specified frame. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillColorRGB", Keywords = "Set the RGB value for all colors in the specified frame"), Category = "ChromaSDK")
	static void FillColorRGB(int32 animationId, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	Set the RGB value for all colors in the specified frame. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillColorRGBName", Keywords = "Set the RGB value for all colors in the specified frame"), Category = "ChromaSDK")
	static void FillColorRGBName(const FString& animationName, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillNonZeroColor", Keywords = "Set the RGB value for all nonzero colors in the specified frame"), Category = "ChromaSDK")
	static void FillNonZeroColor(int32 animationId, int32 frameId, const FLinearColor& colorParam);

	/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillNonZeroColorAllFrames", Keywords = "Set the RGB value for all colors for all frames if the destination color is not black"), Category = "ChromaSDK")
	static void FillNonZeroColorAllFrames(int32 animationId, const FLinearColor& colorParam);

	/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillNonZeroColorAllFramesName", Keywords = "Set the RGB value for all colors for all frames if the destination color is not black"), Category = "ChromaSDK")
	static void FillNonZeroColorAllFramesName(const FString& animationName, const FLinearColor& colorParam);

	/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Use the range of 0 to 255 for red, green, and blue parameters. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillNonZeroColorAllFramesRGB", Keywords = "Set the RGB value for all colors for all frames if the destination color is not black"), Category = "ChromaSDK")
	static void FillNonZeroColorAllFramesRGB(int32 animationId, int32 red, int32 green, int32 blue);

	/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Use the range of 0 to 255 for red, green, and blue parameters. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillNonZeroColorAllFramesRGBName", Keywords = "Set the RGB value for all colors for all frames if the destination color is not black"), Category = "ChromaSDK")
	static void FillNonZeroColorAllFramesRGBName(const FString& animationName, int32 red, int32 green, int32 blue);

	/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillNonZeroColorName", Keywords = "Set the RGB value for all nonzero colors in the specified frame"), Category = "ChromaSDK")
	static void FillNonZeroColorName(const FString& animationName, int32 frameId, const FLinearColor& colorParam);

	/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Use the range of 0 to 255 for red, green, and blue parameters. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroNonColorRGB", Keywords = "Set the RGB value for all nonzero colors in the specified frame"), Category = "ChromaSDK")
	static void FillNonZeroColorRGB(int32 animationId, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Use the range of 0 to 255 for red, green, and blue parameters. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillNonZeroColorRGBName", Keywords = "Set the RGB value for all nonzero colors in the specified frame"), Category = "ChromaSDK")
	static void FillNonZeroColorRGBName(const FString& animationName, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	Fill the frame with random RGB values for the given frame. Animation is
	referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillRandomColors", Keywords = "Fill the frame with random colors"), Category = "ChromaSDK")
	static void FillRandomColors(int32 animationId, int32 frameId);

	/*
	Fill the frame with random RGB values for all frames. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillRandomColorsAllFrames", Keywords = "Fill all frames with random colors"), Category = "ChromaSDK")
	static void FillRandomColorsAllFrames(int32 animationId);

	/*
	Fill the frame with random RGB values for all frames. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillRandomColorsAllFramesName", Keywords = "Fill all frames with random colors"), Category = "ChromaSDK")
	static void FillRandomColorsAllFramesName(const FString& animationName);

	/*
	Fill the frame with random black and white values for the specified frame.
	Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillRandomColorsBlackAndWhite", Keywords = "Fill the frame with random black and white colors"), Category = "ChromaSDK")
	static void FillRandomColorsBlackAndWhite(int32 animationId, int32 frameId);

	/*
	Fill the frame with random black and white values for all frames. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillRandomColorsBlackAndWhiteAllFrames", Keywords = "Fill all frames with random black and white colors"), Category = "ChromaSDK")
	static void FillRandomColorsBlackAndWhiteAllFrames(int32 animationId);

	/*
	Fill the frame with random black and white values for all frames. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillRandomColorsBlackAndWhiteAllFramesName", Keywords = "Fill all frames with random black and white colors"), Category = "ChromaSDK")
	static void FillRandomColorsBlackAndWhiteAllFramesName(const FString& animationName);

	/*
	Fill the frame with random black and white values for the specified frame.
	Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillRandomColorsBlackAndWhiteName", Keywords = "Fill the frame with random black and white colors"), Category = "ChromaSDK")
	static void FillRandomColorsBlackAndWhiteName(const FString& animationName, int32 frameId);

	/*
	Fill the frame with random RGB values for the given frame. Animation is
	referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillRandomColorsName", Keywords = "Fill the frame with random colors"), Category = "ChromaSDK")
	static void FillRandomColorsName(const FString& animationName, int32 frameId);

	/*
	Fill all frames with RGB color where the animation color is less than the
	RGB threshold. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdColorsAllFrames", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillThresholdColorsAllFrames(int32 animationId, int32 threshold, const FLinearColor& colorParam);

	/*
	Fill all frames with RGB color where the animation color is less than the
	RGB threshold. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdColorsAllFramesName", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillThresholdColorsAllFramesName(const FString& animationName, int32 threshold, const FLinearColor& colorParam);

	/*
	Fill all frames with RGB color where the animation color is less than the
	threshold. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdColorsAllFramesRGB", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillThresholdColorsAllFramesRGB(int32 animationId, int32 threshold, int32 red, int32 green, int32 blue);

	/*
	Fill all frames with RGB color where the animation color is less than the
	threshold. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdColorsAllFramesRGBName", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillThresholdColorsAllFramesRGBName(const FString& animationName, int32 threshold, int32 red, int32 green, int32 blue);

	/*
	Fill all frames with the min RGB color where the animation color is less
	than the min threshold AND with the max RGB color where the animation is
	more than the max threshold. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdColorsMinMaxAllFramesRGB", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillThresholdColorsMinMaxAllFramesRGB(int32 animationId, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue);

	/*
	Fill all frames with the min RGB color where the animation color is less
	than the min threshold AND with the max RGB color where the animation is
	more than the max threshold. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdColorsMinMaxAllFramesRGBName", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillThresholdColorsMinMaxAllFramesRGBName(const FString& animationName, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue);

	/*
	Fill the specified frame with RGB color where the animation color is less
	than the RGB threshold. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdColorsRGB", Keywords = "Set the RGB value for all colors in the specified frame"), Category = "ChromaSDK")
	static void FillThresholdColorsRGB(int32 animationId, int32 frameId, int32 threshold, int32 red, int32 green, int32 blue);

	/*
	Fill the specified frame with RGB color where the animation color is less
	than the RGB threshold. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdColorsRGBName", Keywords = "Set the RGB value for all colors in the specified frame"), Category = "ChromaSDK")
	static void FillThresholdColorsRGBName(const FString& animationName, int32 frameId, int32 threshold, int32 red, int32 green, int32 blue);

	/*
	Fill all frames with RGB color where the animation color is less than the
	RGB threshold. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdRGBColorsAllFramesRGB", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillThresholdRGBColorsAllFramesRGB(int32 animationId, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, int32 red, int32 green, int32 blue);

	/*
	Fill all frames with RGB color where the animation color is less than the
	RGB threshold. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillThresholdRGBColorsAllFramesRGBName", Keywords = "Set the RGB value for all colors for all frames"), Category = "ChromaSDK")
	static void FillThresholdRGBColorsAllFramesRGBName(const FString& animationName, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, int32 red, int32 green, int32 blue);

	/*
	Fill the specified frame with RGB color where the animation color is zero.
	Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroColor", Keywords = "Set the RGB value for all zero colors in the specified frame"), Category = "ChromaSDK")
	static void FillZeroColor(int32 animationId, int32 frameId, const FLinearColor& colorParam);

	/*
	Fill all frames with RGB color where the animation color is zero. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroColorAllFrames", Keywords = "Set the RGB value for all zero colors in all frames"), Category = "ChromaSDK")
	static void FillZeroColorAllFrames(int32 animationId, const FLinearColor& colorParam);

	/*
	Fill all frames with RGB color where the animation color is zero. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroColorAllFramesName", Keywords = "Set the RGB value for all zero colors in all frames"), Category = "ChromaSDK")
	static void FillZeroColorAllFramesName(const FString& animationName, const FLinearColor& colorParam);

	/*
	Fill all frames with RGB color where the animation color is zero. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroColorAllFramesRGB", Keywords = "Set the RGB value for all zero colors in all frames"), Category = "ChromaSDK")
	static void FillZeroColorAllFramesRGB(int32 animationId, int32 red, int32 green, int32 blue);

	/*
	Fill all frames with RGB color where the animation color is zero. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroColorAllFramesRGBName", Keywords = "Set the RGB value for all zero colors in all frames"), Category = "ChromaSDK")
	static void FillZeroColorAllFramesRGBName(const FString& animationName, int32 red, int32 green, int32 blue);

	/*
	Fill the specified frame with RGB color where the animation color is zero.
	Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroColorName", Keywords = "Set the RGB value for all zero colors in the specified frame"), Category = "ChromaSDK")
	static void FillZeroColorName(const FString& animationName, int32 frameId, const FLinearColor& colorParam);

	/*
	Fill the specified frame with RGB color where the animation color is zero.
	Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroColorRGB", Keywords = "Set the RGB value for all zero colors in the specified frame"), Category = "ChromaSDK")
	static void FillZeroColorRGB(int32 animationId, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	Fill the specified frame with RGB color where the animation color is zero.
	Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "FillZeroColorRGBName", Keywords = "Set the RGB value for all zero colors in the specified frame"), Category = "ChromaSDK")
	static void FillZeroColorRGBName(const FString& animationName, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	Get the animation id for the named animation.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimation", Keywords = "Get the animation by name from disk or cache"), Category = "ChromaSDK")
	static int32 GetAnimation(const FString& animationName);

	/*
	`PluginGetAnimationCount` will return the number of loaded animations.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimationCount", Keywords = "Get the number of open animations"), Category = "ChromaSDK")
	static int32 GetAnimationCount();

	/*
	`PluginGetAnimationId` will return the `animationId` given the `index` of
	the loaded animation. The `index` is zero-based and less than the number
	returned by `PluginGetAnimationCount`. Use `PluginGetAnimationName` to
	get the name of the animation.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimationId", Keywords = "Get the animation id"), Category = "ChromaSDK")
	static int32 GetAnimationId(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimationIdByIndex", Keywords = "Get the animationId for the open animation index"), Category = "ChromaSDK")
	static int32 GetAnimationIdByIndex(int32 index);

	/*
	`PluginGetAnimationName` takes an `animationId` and returns the name of
	the animation of the `.chroma` animation file. If a name is not available
	then an empty string will be returned.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetAnimationName", Keywords = "Get the animation name"), Category = "ChromaSDK")
	static FString GetAnimationName(const int32 animationId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetBGRInt", Keywords = "Convert RGB to BGR Int"), Category = "ChromaSDK")
	static int32 GetBGRInt(int32 red, int32 green, int32 blue);

	/*
	Get the current frame of the animation referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetCurrentFrame", Keywords = "Get the current frame"), Category = "ChromaSDK")
	static int32 GetCurrentFrame(int32 animationId);

	/*
	Get the current frame of the animation referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetCurrentFrameName", Keywords = "Get the current frame"), Category = "ChromaSDK")
	static int32 GetCurrentFrameName(const FString& animationName);

	/*
	Returns the frame count of a `Chroma` animation upon success. Returns negative
	one upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetFrameCount", Keywords = "Get the .chroma animation frame count"), Category = "ChromaSDK")
	static int32 GetFrameCount(const int32 animationId);

	/*
	Returns the frame count of a `Chroma` animation upon success. Returns negative
	one upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetFrameCountName", Keywords = "Get the .chroma animation frame count"), Category = "ChromaSDK")
	static int32 GetFrameCountName(const FString& animationName);

	/*
	Returns the duration of an animation frame in seconds upon success. Returns
	zero upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetFrameDuration", Keywords = "Get the duration of a frame"), Category = "ChromaSDK")
	static float GetFrameDuration(int32 animationId, int32 frameId);
	/*
	Returns the duration of an animation frame in seconds upon success. Returns
	zero upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetFrameDurationName", Keywords = "Get the duration of a frame"), Category = "ChromaSDK")
	static float GetFrameDurationName(const FString& animationName, int32 frameId);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetKeyboardKeyColor", Keywords = "Get the key to the supplied color"), Category = "ChromaSDK")
	static FLinearColor GetKeyboardKeyColor(EChromaSDKKeyboardKey::Type key, UPARAM(ref) TArray<FChromaSDKColors>& colors);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetKeyboardRazerKey", Keywords = "Convert FKey to RZKEY"), Category = "ChromaSDK")
	static EChromaSDKKeyboardKey::Type GetKeyboardRazerKey(FKey key);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetKeyboardRzKey", Keywords = "Convert to RZKEY int"), Category = "ChromaSDK")
	static int32 GetKeyboardRzKey(EChromaSDKKeyboardKey::Type key);

	/*
	Get the color of an animation key for the given frame referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetKeyColor", Keywords = "Get the color from the animation frame's key"), Category = "ChromaSDK")
	static FLinearColor GetKeyColor(int32 animationId, int32 frameIndex, EChromaSDKKeyboardKey::Type key);

	/*
	Get the color of an animation key for the given frame referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetKeyColorName", Keywords = "Get the color from the animation frame's key"), Category = "ChromaSDK")
	static FLinearColor GetKeyColorName(const FString& animationName, const int32 frameIndex, EChromaSDKKeyboardKey::Type key);

	/*
	Returns the `MAX COLUMN` given the `EChromaSDKDevice2DEnum` device as an
	integer upon success. Returns negative one upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetMaxColumn", Keywords = "Get the max column size for the device"), Category = "ChromaSDK")
	static int32 GetMaxColumn(EChromaSDKDevice2DEnum::Type device);

	/*
	Returns the MAX LEDS given the `EChromaSDKDevice1DEnum` device as an integer
	upon success. Returns negative one upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetMaxLeds", Keywords = "Get the max led size for the device"), Category = "ChromaSDK")
	static int32 GetMaxLeds(EChromaSDKDevice1DEnum::Type device);

	/*
	Returns the `MAX ROW` given the `EChromaSDKDevice2DEnum` device as an integer
	upon success. Returns negative one upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetMaxRow", Keywords = "Get the max row size for the device"), Category = "ChromaSDK")
	static int32 GetMaxRow(EChromaSDKDevice2DEnum::Type device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetMouseLedColor", Keywords = "Get the led to the supplied color"), Category = "ChromaSDK")
	static FLinearColor GetMouseLedColor(EChromaSDKMouseLed::Type led, UPARAM(ref) TArray<FChromaSDKColors>& colors);

	/*
	`PluginGetPlayingAnimationCount` will return the number of playing animations.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetPlayingAnimationCount", Keywords = "Get the number of playing animations"), Category = "ChromaSDK")
	static int32 GetPlayingAnimationCount();

	/*
	`PluginGetPlayingAnimationId` will return the `animationId` given the `index`
	of the playing animation. The `index` is zero-based and less than the number
	returned by `PluginGetPlayingAnimationCount`. Use `PluginGetAnimationName`
	to get the name of the animation.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetPlayingAnimationId", Keywords = "Get the animationId for the playing animation index"), Category = "ChromaSDK")
	static int32 GetPlayingAnimationId(int32 index);

	/*
	Get the RGB color given red, green, and blue.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetRGB", Keywords = "Convert RGB to LinearColor"), Category = "ChromaSDK")
	static FLinearColor GetRGB(int32 red, int32 green, int32 blue);

	/*
	Returns the total duration of an animation in seconds upon success. Returns
	zero upon failure. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetTotalDuration", Keywords = "Get total duration of the animation"), Category = "ChromaSDK")
	static float GetTotalDuration(int32 animationId);

	/*
	Returns the total duration of an animation in seconds upon success. Returns
	zero upon failure. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetTotalDurationName", Keywords = "Get total duration of the animation"), Category = "ChromaSDK")
	static float GetTotalDurationName(const FString& animationName);

	/*
	Insert an animation delay by duplicating the frame by the delay number of
	times. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InsertDelay", Keywords = "Duplicate frames to create a delay at the frame index"), Category = "ChromaSDK")
	static void InsertDelay(int32 animationId, int32 frameId, int32 delay);

	/*
	Insert an animation delay by duplicating the frame by the delay number of
	times. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InsertDelayName", Keywords = "Duplicate frames to create a delay at the frame index"), Category = "ChromaSDK")
	static void InsertDelayName(const FString& animationName, int32 frameId, int32 delay);

	/*
	Duplicate the source frame index at the target frame index. Animation is
	referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InsertFrame", Keywords = "Insert a copy of the frame at the given target frame index"), Category = "ChromaSDK")
	static void InsertFrame(int32 animationId, int32 sourceFrame, int32 targetFrame);

	/*
	Duplicate the source frame index at the target frame index. Animation is
	referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InsertFrameName", Keywords = "Insert a copy of the frame at the given target frame index"), Category = "ChromaSDK")
	static void InsertFrameName(const FString& animationName, int32 sourceFrame, int32 targetFrame);

	/*
	Invert all the colors for all frames. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InvertColorsAllFrames", Keywords = "Invert animation colors"), Category = "ChromaSDK")
	static void InvertColorsAllFrames(int32 animationId);

	/*
	Invert all the colors for all frames. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "InvertColorsAllFramesName", Keywords = "Invert animation colors"), Category = "ChromaSDK")
	static void InvertColorsAllFramesName(const FString& animationName);

	/*
	Check if the application or game has the Chroma focus
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsActive", Keywords = "Check if the application has Chroma focus"), Category = "ChromaSDK")
	static int32 IsActive(UPARAM(ref) bool& active);

	/*
	Check if the animation is playing
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsAnimationPlaying", Keywords = "Is the *.chroma Animation playing?"), Category = "ChromaSDK")
	static bool IsAnimationPlaying(const FString& animationName);

	/*
	Check if the animation type is playing
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsAnimationTypePlaying", Keywords = "Is the Animation type playing?"), Category = "ChromaSDK")
	static bool IsAnimationTypePlaying(EChromaSDKDeviceEnum::Type device);

	/*
	Check if a Chroma device type is connected
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsConnected", Keywords = "Check if Chroma devices are connected"), Category = "ChromaSDK")
	static int32 IsConnected(UPARAM(ref) FChromaSDKDeviceInfoType& deviceInfoType);

	/*
	Returns true if the plugin has been initialized. Returns false if the plugin
	is uninitialized.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsInitialized", Keywords = "Return true if the blueprint library is initialized"), Category = "ChromaSDK")
	static bool IsInitialized();

	/*
	Check if the current platform is Windows
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "IsPlatformWindows", Keywords = "Returns true on the Windows Platform"), Category = "ChromaSDK")
	static bool IsPlatformWindows();

	/*
	Do a lerp math operation on a float.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Lerp", Keywords = "Lerp floating point over 0 to 1"), Category = "ChromaSDK")
	static float Lerp(float start, float end, float amt);

	/*
	Lerp from one color to another given t in the range 0.0 to 1.0.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LerpColor", Keywords = "Lerp from one color to another over 0 to 1"), Category = "ChromaSDK")
	static FLinearColor LerpColor(FLinearColor colorParam1, FLinearColor colorParam2, float t);

	/*
	Lerp from bgr int to another bgr int over the range 0.0 to 1.0.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LerpColorBGR", Keywords = "Lerp from one color to another over 0 to 1"), Category = "ChromaSDK")
	static int32 LerpColorBGR(int32 from, int32 to, float t);

	/*
	Loads `Chroma` effects so that the animation can be played immediately.
	Returns the animation id upon success. Returns negative one upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LoadAnimation", Keywords = "Load the *.chroma Animation"), Category = "ChromaSDK")
	static void LoadAnimation(const int32 animationId);

	/*
	Load the named animation.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "LoadAnimationName", Keywords = "Load the *.chroma Animation"), Category = "ChromaSDK")
	static void LoadAnimationName(const FString& animationName);

	/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color defaults to color. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeBlankFrames", Keywords = "Make sure animation has the number of blank frames"), Category = "ChromaSDK")
	static void MakeBlankFrames(int32 animationId, int32 frameCount, float duration, const FLinearColor& colorParam);

	/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color defaults to color. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeBlankFramesName", Keywords = "Make sure animation has the number of blank frames"), Category = "ChromaSDK")
	static void MakeBlankFramesName(const FString& animationName, int32 frameCount, float duration, const FLinearColor& colorParam);

	/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color is random. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeBlankFramesRandom", Keywords = "Make sure animation has the number of random color frames"), Category = "ChromaSDK")
	static void MakeBlankFramesRandom(int32 animationId, int32 frameCount, float duration);

	/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color is random black and white. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeBlankFramesRandomBlackAndWhite", Keywords = "Make sure animation has the number of random black and white frames"), Category = "ChromaSDK")
	static void MakeBlankFramesRandomBlackAndWhite(int32 animationId, int32 frameCount, float duration);

	/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color is random black and white. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeBlankFramesRandomBlackAndWhiteName", Keywords = "Make sure animation has the number of random black and white frames"), Category = "ChromaSDK")
	static void MakeBlankFramesRandomBlackAndWhiteName(const FString& animationName, int32 frameCount, float duration);

	/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color is random. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeBlankFramesRandomName", Keywords = "Make sure animation has the number of random color frames"), Category = "ChromaSDK")
	static void MakeBlankFramesRandomName(const FString& animationName, int32 frameCount, float duration);

	/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color defaults to color. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeBlankFramesRGB", Keywords = "Make sure animation has the number of blank frames"), Category = "ChromaSDK")
	static void MakeBlankFramesRGB(int32 animationId, int32 frameCount, float duration, int32 red, int32 green, int32 blue);

	/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color defaults to color. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MakeBlankFramesRGBName", Keywords = "Make sure animation has the number of blank frames"), Category = "ChromaSDK")
	static void MakeBlankFramesRGBName(const FString& animationName, int32 frameCount, float duration, int32 red, int32 green, int32 blue);

	/*
	Multiply the color intensity with the lerp result from color 1 to color
	2 using the frame index divided by the frame count for the `t` parameter.
	Animation is referenced in id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyColorLerpAllFrames", Keywords = "Lerp between colors using the frame ratio as the intensity"), Category = "ChromaSDK")
	static void MultiplyColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2);

	/*
	Multiply the color intensity with the lerp result from color 1 to color
	2 using the frame index divided by the frame count for the `t` parameter.
	Animation is referenced in name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyColorLerpAllFramesName", Keywords = "Lerp between colors using the frame ratio as the intensity"), Category = "ChromaSDK")
	static void MultiplyColorLerpAllFramesName(const FString& animationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2);

	/*
	Multiply all the colors in the frame by the intensity value. The valid the
	intensity range is from 0.0 to 255.0. RGB components are multiplied equally.
	An intensity of 0.5 would half the color value. Black colors in the frame
	will not be affected by this method.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensity", Keywords = "Multiply all the colors in the frame by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensity(int32 animationId, int32 frameId, float intensity);

	/*
	Multiply all the colors for all frames by the intensity value. The valid
	the intensity range is from 0.0 to 255.0. RGB components are multiplied
	equally. An intensity of 0.5 would half the color value. Black colors in
	the frame will not be affected by this method.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityAllFrames", Keywords = "Multiply all the colors for all frames by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityAllFrames(int32 animationId, float intensity);

	/*
	Multiply all the colors for all frames by the intensity value. The valid
	the intensity range is from 0.0 to 255.0. RGB components are multiplied
	equally. An intensity of 0.5 would half the color value. Black colors in
	the frame will not be affected by this method.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityAllFramesName", Keywords = "Multiply all the colors for all frames by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityAllFramesName(const FString& animationName, float intensity);

	/*
	Multiply all frames by the RBG color intensity. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityAllFramesRGB", Keywords = "Multiply all the colors for all frames by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityAllFramesRGB(int32 animationId, int32 red, int32 green, int32 blue);

	/*
	Multiply all frames by the RBG color intensity. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityAllFramesRGBName", Keywords = "Multiply all the colors for all frames by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityAllFramesRGBName(const FString& animationName, int32 red, int32 green, int32 blue);

	/*
	Multiply the specific frame by the RBG color intensity. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityColor", Keywords = "Multiply all the colors in the frame by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityColor(int32 animationId, int32 frameId, const FLinearColor& colorParam);

	/*
	Multiply all frames by the RBG color intensity. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityColorAllFrames", Keywords = "Multiply all the colors for all frames by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityColorAllFrames(int32 animationId, const FLinearColor& colorParam);

	/*
	Multiply all frames by the RBG color intensity. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityColorAllFramesName", Keywords = "Multiply all the colors for all frames by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityColorAllFramesName(const FString& animationName, const FLinearColor& colorParam);

	/*
	Multiply the specific frame by the RBG color intensity. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityColorName", Keywords = "Multiply all the colors in the frame by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityColorName(const FString& animationName, int32 frameId, const FLinearColor& colorParam);

	/*
	Multiply all the colors in the frame by the intensity value. The valid the
	intensity range is from 0.0 to 255.0. RGB components are multiplied equally.
	An intensity of 0.5 would half the color value. Black colors in the frame
	will not be affected by this method.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityName", Keywords = "Multiply all the colors in the frame by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityName(const FString& animationName, int32 frameId, float intensity);

	/*
	Multiply the specific frame by the RBG color intensity. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensity", Keywords = "Multiply all the colors in the frame by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityRGB(int32 animationId, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	Multiply the specific frame by the RBG color intensity. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyIntensityName", Keywords = "Multiply all the colors in the frame by the intensity value"), Category = "ChromaSDK")
	static void MultiplyIntensityRGBName(const FString& animationName, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	Multiply all frames by the color lerp result between color 1 and 2 using
	the frame color value as the `t` value. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyNonZeroTargetColorLerpAllFrames", Keywords = "Lerp between colors using the nonzero target colors as the intensity"), Category = "ChromaSDK")
	static void MultiplyNonZeroTargetColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2);

	/*
	Multiply all frames by the color lerp result between color 1 and 2 using
	the frame color value as the `t` value. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyNonZeroTargetColorLerpAllFramesName", Keywords = "Lerp between colors using the nonzero target colors as the intensity"), Category = "ChromaSDK")
	static void MultiplyNonZeroTargetColorLerpAllFramesName(const FString& animationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2);

	/*
	Multiply all frames by the color lerp result between color 1 and 2 using
	the frame color value as the `t` value. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyTargetColorLerpAllFrames", Keywords = "Lerp between colors using the target colors as the intensity"), Category = "ChromaSDK")
	static void MultiplyTargetColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2);

	/*
	Multiply all frames by the color lerp result between color 1 and 2 using
	the frame color value as the `t` value. Animation is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "MultiplyTargetColorLerpAllFramesName", Keywords = "Lerp between colors using the target colors as the intensity"), Category = "ChromaSDK")
	static void MultiplyTargetColorLerpAllFramesName(const FString& animationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2);

	/*
	Offset all colors in the frame using the RGB offset. Use the range of -255
	to 255 for red, green, and blue parameters. Negative values remove color.
	Positive values add color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OffsetColors", Keywords = "Offset all colors in the frame using the RGB offset"), Category = "ChromaSDK")
	static void OffsetColors(int32 animationId, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	Offset all colors for all frames using the RGB offset. Use the range of
	-255 to 255 for red, green, and blue parameters. Negative values remove
	color. Positive values add color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OffsetColorsAllFrames", Keywords = "Offset all colors for all frames using the RGB offset"), Category = "ChromaSDK")
	static void OffsetColorsAllFrames(int32 animationId, int32 red, int32 green, int32 blue);

	/*
	Offset all colors for all frames using the RGB offset. Use the range of
	-255 to 255 for red, green, and blue parameters. Negative values remove
	color. Positive values add color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OffsetColorsAllFramesName", Keywords = "Offset all colors for all frames using the RGB offset"), Category = "ChromaSDK")
	static void OffsetColorsAllFramesName(const FString& animationName, int32 red, int32 green, int32 blue);

	/*
	Offset all colors in the frame using the RGB offset. Use the range of -255
	to 255 for red, green, and blue parameters. Negative values remove color.
	Positive values add color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OffsetColorsName", Keywords = "Offset all colors in the frame using the RGB offset"), Category = "ChromaSDK")
	static void OffsetColorsName(const FString& animationName, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors in the frame using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OffsetNonZeroColors", Keywords = "Offset all colors in the frame using the RGB offset if the destination color is not black"), Category = "ChromaSDK")
	static void OffsetNonZeroColors(int32 animationId, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors for all frames using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OffsetNonZeroColorsAllFrames", Keywords = "Offset all colors for all frames using the RGB offset if the destination color is not black"), Category = "ChromaSDK")
	static void OffsetNonZeroColorsAllFrames(int32 animationId, int32 red, int32 green, int32 blue);

	/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors for all frames using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OffsetNonZeroColorsAllFramesName", Keywords = "Offset all colors for all frames using the RGB offset if the destination color is not black"), Category = "ChromaSDK")
	static void OffsetNonZeroColorsAllFramesName(const FString& animationName, int32 red, int32 green, int32 blue);

	/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors in the frame using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OffsetNonZeroColorsName", Keywords = "Offset all colors in the frame using the RGB offset if the destination color is not black"), Category = "ChromaSDK")
	static void OffsetNonZeroColorsName(const FString& animationName, int32 frameId, int32 red, int32 green, int32 blue);

	/*
	Opens a `Chroma` animation data from memory so that it can be played. `Data`
	is a pointer to BYTE array of the loaded animation in memory. `Name` will
	be assigned to the animation when loaded. Returns an animation id >= 0
	upon success. Returns negative one if there was a failure. The animation
	id is used in most of the API methods.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OpenAnimationFromMemory", Keywords = "Open animation from memory"), Category = "ChromaSDK")
	static void OpenAnimationFromMemory(const TArray<uint8>& data, const FString& animationName);

	/*
	Override the duration of all frames with the `duration` value. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "OverrideFrameDurationName", Keywords = "Set the Chroma custom flag for keyboard"), Category = "ChromaSDK")
	static void OverrideFrameDurationName(const FString& animationName, float duration);

	/*
	Plays the `Chroma` animation. This will load the animation, if not loaded
	previously. Returns the animation id upon success. Returns negative one
	upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayAnimation", Keywords = "Play the *.chroma Animation"), Category = "ChromaSDK")
	static void PlayAnimation(const FString& animationName, bool loop);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayAnimationComposite", Keywords = "Play a set of *_Device.chroma Animations"), Category = "ChromaSDK")
	static void PlayAnimationComposite(const FString& animationName, bool loop);

	/*
	`PluginPlayAnimationName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The animation
	will play with looping `on` or `off`.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayAnimationName", Keywords = "Play the *.chroma Animation"), Category = "ChromaSDK")
	static void PlayAnimationName(const FString& animationName, bool loop);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PlayAnimations", Keywords = "Play an array of *.chroma Animations"), Category = "ChromaSDK")
	static void PlayAnimations(const TArray<FString>& animationNames, bool loop);

	/*
	Displays the `Chroma` animation frame on `Chroma` hardware given the `frameIndex`.
	Returns the animation id upon success. Returns negative one upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PreviewFrame", Keywords = "Display a specific animation frame"), Category = "ChromaSDK")
	static int32 PreviewFrame(int32 animationId, int32 frameId);

	/*
	Displays the `Chroma` animation frame on `Chroma` hardware given the `frameIndex`.
	Animaton is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "PreviewFrameName", Keywords = "Display a specific animation frame"), Category = "ChromaSDK")
	static void PreviewFrameName(const FString& animationName, int32 frameId);

	/*
	Reduce the frames of the animation by removing every nth element. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ReduceFrames", Keywords = "Reduce every nth frame"), Category = "ChromaSDK")
	static void ReduceFrames(int32 animationId, int32 n);

	/*
	Reduce the frames of the animation by removing every nth element. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ReduceFramesName", Keywords = "Reduce every nth frame"), Category = "ChromaSDK")
	static void ReduceFramesName(const FString& animationName, int32 n);

	/*
	Reverse the animation frame order of the `Chroma` animation. Animation is
	referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ReverseAllFrames", Keywords = "Reverse the order of all frames"), Category = "ChromaSDK")
	static void ReverseAllFrames(int32 animationId);

	/*
	Reverse the animation frame order of the `Chroma` animation. Animation is
	referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ReverseAllFramesName", Keywords = "Reverse the order of all frames"), Category = "ChromaSDK")
	static void ReverseAllFramesName(const FString& animationName);

	/*
	When custom color is set, the custom key mode will be used. The animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetChromaCustomColorAllFramesName", Keywords = "Set the custom color mask on all the colors"), Category = "ChromaSDK")
	static void SetChromaCustomColorAllFramesName(const FString& animationName);

	/*
	Set the Chroma custom key color flag on all frames. `True` changes the layout
	from grid to key. `True` changes the layout from key to grid. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetChromaCustomFlagName", Keywords = "Set the Chroma custom flag for keyboard"), Category = "ChromaSDK")
	static void SetChromaCustomFlagName(const FString& animationName, bool flag);

	/*
	Set the current frame of the animation referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetCurrentFrame", Keywords = "Set the current frame"), Category = "ChromaSDK")
	static void SetCurrentFrame(int32 animationId, int32 frameId);

	/*
	Set the current frame of the animation referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetCurrentFrameName", Keywords = "Set the current frame"), Category = "ChromaSDK")
	static void SetCurrentFrameName(const FString& animationName, int32 frameId);

	/*
	Name the Chroma event to add extras like haptics to supplement the event
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetEventName", Keywords = "Name Chroma events to add extras"), Category = "ChromaSDK")
	static int32 SetEventName(const FString& name);

	/*
	When the idle animation is used, the named animation will play when no other
	animations are playing. Reference the animation by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetIdleAnimationName", Keywords = "Set idle animation for the device"), Category = "ChromaSDK")
	static void SetIdleAnimationName(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyboardKeyColor", Keywords = "Set the key to the supplied color"), Category = "ChromaSDK")
	static void SetKeyboardKeyColor(EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam, UPARAM(ref) TArray<FChromaSDKColors>& colors);

	/*
	Set animation key to a static color for the given frame.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyColor", Keywords = "Set the animation frame's key to the supplied color"), Category = "ChromaSDK")
	static void SetKeyColor(int32 animationId, int32 frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);

	/*
	Set the key to the specified key color for all frames. Animation is referenced
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyColorAllFrames", Keywords = "Set the key to the supplied color for all animation frames"), Category = "ChromaSDK")
	static void SetKeyColorAllFrames(int32 animationId, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);

	/*
	Set the key to the specified key color for all frames. Animation is referenced
	by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyColorAllFramesName", Keywords = "Set the key to the supplied color for all animation frames"), Category = "ChromaSDK")
	static void SetKeyColorAllFramesName(const FString& animationName, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);

	/*
	Set animation key to a static color for the given frame.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyColorName", Keywords = "Set the animation frame's key to the supplied color"), Category = "ChromaSDK")
	static void SetKeyColorName(const FString& animationName, const int32 frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);

	/*
	Set animation key to a static color for the given frame if the existing
	color is not already black.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyNonZeroColor", Keywords = "Set the animation frame's key to the supplied color if the key is not already black"), Category = "ChromaSDK")
	static void SetKeyNonZeroColor(int32 animationId, int32 frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyNonZeroColorAllFrames", Keywords = "Set the key to the supplied color for all animation frames if the key is not already black"), Category = "ChromaSDK")
	static void SetKeyNonZeroColorAllFrames(int32 animationId, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyNonZeroColorAllFramesName", Keywords = "Set the key to the supplied color for all animation frames if the key is not already black"), Category = "ChromaSDK")
	static void SetKeyNonZeroColorAllFramesName(const FString& animationName, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);

	/*
	Set animation key to a static color for the given frame if the existing
	color is not already black.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyNonZeroColorName", Keywords = "Set the animation frame's key to the supplied color if the key is not already black"), Category = "ChromaSDK")
	static void SetKeyNonZeroColorName(const FString& animationName, const int32 frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);

	/*
	Set animation key by row and column to a static color for the given frame.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeyRowColumnColorName", Keywords = "Set the animation frame's row/column to the supplied color"), Category = "ChromaSDK")
	static void SetKeyRowColumnColorName(const FString& animationName, const int32 frameIndex, const int32 row, const int32 column, const FLinearColor& colorParam);

	/*
	Set an array of animation keys to a static color for the given frame. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColor", Keywords = "Set the animation frame to the supplied color for a set of keys"), Category = "ChromaSDK")
	static void SetKeysColor(int32 animationId, int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam);

	/*
	Set an array of animation keys to a static color for all frames. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorAllFrames", Keywords = "Set the keys to the supplied color for all animation frames"), Category = "ChromaSDK")
	static void SetKeysColorAllFrames(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam);

	/*
	Set an array of animation keys to a static color for all frames. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorAllFramesName", Keywords = "Set the keys to the supplied color for all animation frames"), Category = "ChromaSDK")
	static void SetKeysColorAllFramesName(const FString& animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam);

	/*
	Set an array of animation keys to a static color for all frames. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorAllFramesRGB", Keywords = "Set the keys to the supplied color for all animation frames"), Category = "ChromaSDK")
	static void SetKeysColorAllFramesRGB(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int32 red, int32 green, int32 blue);

	/*
	Set an array of animation keys to a static color for all frames. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorAllFramesRGBName", Keywords = "Set the keys to the supplied color for all animation frames"), Category = "ChromaSDK")
	static void SetKeysColorAllFramesRGBName(const FString& animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int32 red, int32 green, int32 blue);

	/*
	Set an array of animation keys to a static color for the given frame.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorName", Keywords = "Set the animation frame to the supplied color for a set of keys"), Category = "ChromaSDK")
	static void SetKeysColorName(const FString& animationName, const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam);

	/*
	Set an array of animation keys to a static color for the given frame. Animation
	is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorRGB", Keywords = "Set the animation frame to the supplied color for a set of keys"), Category = "ChromaSDK")
	static void SetKeysColorRGB(int32 animationId, int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int32 red, int32 green, int32 blue);

	/*
	Set an array of animation keys to a static color for the given frame. Animation
	is referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysColorRGBName", Keywords = "Set the animation frame to the supplied color for a set of keys"), Category = "ChromaSDK")
	static void SetKeysColorRGBName(const FString& animationName, const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int32 red, int32 green, int32 blue);

	/*
	Set an array of animation keys to a static color for the given frame if
	the existing color is not already black.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysNonZeroColor", Keywords = "Set the animation frame to the supplied color for a set of keys if the key is not already black"), Category = "ChromaSDK")
	static void SetKeysNonZeroColor(int32 animationId, int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam);

	/*
	Set an array of animation keys to a static color for the given frame where
	the color is not black. Animation is referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysNonZeroColorAllFrames", Keywords = "Set the keys to the supplied color for all animation frames if the key is not already black"), Category = "ChromaSDK")
	static void SetKeysNonZeroColorAllFrames(int32 animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam);

	/*
	Set an array of animation keys to a static color for all frames if the existing
	color is not already black. Reference animation by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysNonZeroColorAllFramesName", Keywords = "Set the keys to the supplied color for all animation frames if the key is not already black"), Category = "ChromaSDK")
	static void SetKeysNonZeroColorAllFramesName(const FString& animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam);

	/*
	Set an array of animation keys to a static color for the given frame if
	the existing color is not already black. Reference animation by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetKeysNonZeroColorName", Keywords = "Set the animation frame to the supplied color for a set of keys if the key is not already black"), Category = "ChromaSDK")
	static void SetKeysNonZeroColorName(const FString& animationName, const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetMouseLedColor", Keywords = "Set the led to the supplied color"), Category = "ChromaSDK")
	static void SetMouseLedColor(EChromaSDKMouseLed::Type led, const FLinearColor& colorParam, UPARAM(ref) TArray<FChromaSDKColors>& colors);

	/*
	Sets the target device to the static color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetStaticColor", Keywords = "Set the target device to the static color"), Category = "ChromaSDK")
	static void SetStaticColor(EChromaSDKDeviceEnum::Type device, const FLinearColor& color);

	/*
	Sets all devices to the static color.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetStaticColorAll", Keywords = "Set the all devices to the static color"), Category = "ChromaSDK")
	static void SetStaticColorAll(const FLinearColor& color);

	/*
	`PluginStopAll` will automatically stop all animations that are playing.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAll", Keywords = "Stop playing all animations"), Category = "ChromaSDK")
	static void StopAll();

	/*
	Stops animation playback if in progress. Returns the animation id upon success.
	Returns negative one upon failure.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAnimation", Keywords = "Stop the *.chroma Animation"), Category = "ChromaSDK")
	static void StopAnimation(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAnimationComposite", Keywords = "Stop a set of *_Device.chroma Animations"), Category = "ChromaSDK")
	static void StopAnimationComposite(const FString& animationName);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAnimations", Keywords = "Stop an array *.chroma Animations"), Category = "ChromaSDK")
	static void StopAnimations(const TArray<FString>& animationNames);

	/*
	`PluginStopAnimationType` automatically handles initializing the `ChromaSDK`.
	If any animation is playing for the `deviceType` and `device` combination,
	it will be stopped.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StopAnimationType", Keywords = "Stop playing the Animation type"), Category = "ChromaSDK")
	static void StopAnimationType(EChromaSDKDeviceEnum::Type device);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamBroadcast", Keywords = "Start Chroma Broadcasting"), Category = "ChromaSDK")
	static void StreamBroadcast(const FString& streamId, const FString& streamKey);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamBroadcastEnd", Keywords = "End Chroma Broadcasting"), Category = "ChromaSDK")
	static void StreamBroadcastEnd();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamGetAuthShortcode", Keywords = "Get Stream Shortcode for Authorization"), Category = "ChromaSDK")
	static FString StreamGetAuthShortcode(const FString& platform, const FString& title);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamGetFocus", Keywords = "Get Stream Focus"), Category = "ChromaSDK")
	static FString StreamGetFocus();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamGetId", Keywords = "Get Stream Id"), Category = "ChromaSDK")
	static FString StreamGetId(const FString& shortcode);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamGetKey", Keywords = "Get Stream Id"), Category = "ChromaSDK")
	static FString StreamGetKey(const FString& shortcode);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamGetStatusString", Keywords = "Get Status Stream String"), Category = "ChromaSDK")
	static FString StreamGetStatusString(const EChromaSDKStreamStatusEnum::Type status);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamReleaseShortcode", Keywords = "Release Stream Shortcode"), Category = "ChromaSDK")
	static bool StreamReleaseShortcode(const FString& shortcode);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamSetFocus", Keywords = "Stream Set Focus"), Category = "ChromaSDK")
	static bool StreamSetFocus(const FString& streamFocus);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamWatch", Keywords = "Start Chroma Watching"), Category = "ChromaSDK")
	static void StreamWatch(const FString& streamId, int32 timestamp);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "StreamWatchEnd", Keywords = "End Chroma Watching"), Category = "ChromaSDK")
	static void StreamWatchEnd();

	/*
	Subtract the source color from the target color for the frame where the
	target color is not black. Source and target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroAllKeys", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void SubtractNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId);

	/*
	Subtract the source color from the target color for all frames where the
	target color is not black. Source and target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroAllKeysAllFrames", Keywords = "Subtract nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void SubtractNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	/*
	Subtract the source color from the target color for all frames where the
	target color is not black. Source and target are referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroAllKeysAllFramesName", Keywords = "Subtract nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void SubtractNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	/*
	Subtract the source color from the target color for all frames where the
	target color is not black starting at offset for the length of the source.
	Source and target are referenced by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroAllKeysAllFramesOffset", Keywords = "Remove nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void SubtractNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset);

	/*
	Subtract the source color from the target color for all frames where the
	target color is not black starting at offset for the length of the source.
	Source and target are referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroAllKeysAllFramesOffsetName", Keywords = "Remove nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void SubtractNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset);

	/*
	Subtract the source color from the target color for the frame where the
	target color is not black. Source and target are referenced by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroAllKeysName", Keywords = "Copy nonzero color from a source animation to a target animation for a frame"), Category = "ChromaSDK")
	static void SubtractNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId);

	/*
	Subtract the source color from the target color where the target color is
	not black for all frames. Reference source and target by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroTargetAllKeysAllFrames", Keywords = "Subtract nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void SubtractNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId);

	/*
	Subtract the source color from the target color where the target color is
	not black for all frames. Reference source and target by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroTargetAllKeysAllFramesName", Keywords = "Subtract nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void SubtractNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName);

	/*
	Subtract the source color from the target color where the target color is
	not black for all frames starting at the target offset for the length of
	the source. Reference source and target by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroTargetAllKeysAllFramesOffset", Keywords = "Subtract nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void SubtractNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset);

	/*
	Subtract the source color from the target color where the target color is
	not black for all frames starting at the target offset for the length of
	the source. Reference source and target by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SubtractNonZeroTargetAllKeysAllFramesOffsetName", Keywords = "Subtract nonzero color from a source animation to a target animation for all frames"), Category = "ChromaSDK")
	static void SubtractNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SupportsStreaming", Keywords = "Release Stream Shortcode"), Category = "ChromaSDK")
	static bool SupportsStreaming();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ToBGR", Keywords = "Convert LinearColor to BGR int"), Category = "ChromaSDK")
	static int32 ToBGR(const FLinearColor& colorParam);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ToLinearColor", Keywords = "Convert BGR int to LinearColor"), Category = "ChromaSDK")
	static FLinearColor ToLinearColor(int32 colorParam);

	/*
	Trim the end of the animation. The length of the animation will be the lastFrameId
	plus one. Reference the animation by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TrimEndFrames", Keywords = "Trim the end of the animation"), Category = "ChromaSDK")
	static void TrimEndFrames(int32 animationId, int32 lastFrameId);

	/*
	Trim the end of the animation. The length of the animation will be the lastFrameId
	plus one. Reference the animation by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TrimEndFramesName", Keywords = "Trim the end of the animation"), Category = "ChromaSDK")
	static void TrimEndFramesName(const FString& animationName, int32 lastFrameId);

	/*
	Remove the frame from the animation. Reference animation by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TrimFrame", Keywords = "Remove the given frame"), Category = "ChromaSDK")
	static void TrimFrame(int32 animationId, int32 frameId);

	/*
	Remove the frame from the animation. Reference animation by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TrimFrameName", Keywords = "Remove the given frame"), Category = "ChromaSDK")
	static void TrimFrameName(const FString& animationName, int32 frameId);

	/*
	Trim the start of the animation starting at frame 0 for the number of frames.
	Reference the animation by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TrimStartFrames", Keywords = "Trim the start of the animation"), Category = "ChromaSDK")
	static void TrimStartFrames(int32 animationId, int32 numberOfFrames);

	/*
	Trim the start of the animation starting at frame 0 for the number of frames.
	Reference the animation by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "TrimStartFramesName", Keywords = "Trim the start of the animation"), Category = "ChromaSDK")
	static void TrimStartFramesName(const FString& animationName, int32 numberOfFrames);

	/*
	Unloads `Chroma` effects to free up resources. Returns the animation id
	upon success. Returns negative one upon failure. Reference the animation
	by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UnloadAnimation", Keywords = "Unload the *.chroma Animation"), Category = "ChromaSDK")
	static void UnloadAnimation(const int32 animationId);

	/*
	Unload the animation effects. Reference the animation by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UnloadAnimationName", Keywords = "Unload the *.chroma Animation"), Category = "ChromaSDK")
	static void UnloadAnimationName(const FString& animationName);

	/*
	On by default, `UseForwardChromaEvents` sends the animation name to `CoreSetEventName`
	automatically when `PlayAnimationName` is called.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UseForwardChromaEvents", Keywords = "Automatically forward animation names as Chroma event names"), Category = "ChromaSDK")
	static void UseForwardChromaEvents(bool toggle);

	/*
	When the idle animation flag is true, when no other animations are playing,
	the idle animation will be used. The idle animation will not be affected
	by the API calls to PluginIsPlaying, PluginStopAnimationType, PluginGetPlayingAnimationId,
	and PluginGetPlayingAnimationCount. Then the idle animation flag is false,
	the idle animation is disabled. `Device` uses `EChromaSDKDeviceEnum` enums.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UseIdleAnimation", Keywords = "Set device flag for idle animation"), Category = "ChromaSDK")
	static void UseIdleAnimation(EChromaSDKDeviceEnum::Type device, bool flag);

	/*
	Set idle animation flag for all devices.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UseIdleAnimations", Keywords = "Set all idle animation flags"), Category = "ChromaSDK")
	static void UseIdleAnimations(bool flag);

	/*
	Set preloading animation flag, which is set to true by default. Reference
	animation by id.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UsePreloading", Keywords = "Set preloading animation flag"), Category = "ChromaSDK")
	static void UsePreloading(int32 animationId, bool flag);

	/*
	Set preloading animation flag, which is set to true by default. Reference
	animation by name.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "UsePreloadingName", Keywords = "Set preloading animation flag"), Category = "ChromaSDK")
	static void UsePreloadingName(const FString& animationName, bool flag);


#pragma endregion

	
	/*
		Gets the frame colors and duration (in seconds) for a `Chroma` animation.
		The `color` is expected to be an array of the expected dimensions for the
		`deviceType/device`. The `length` parameter is the size of the `color`
		array. For `EChromaSDKDevice1DEnum` the array size should be `MAX LEDS`.
		For `EChromaSDKDevice2DEnum` the array size should be `MAX ROW` * `MAX
		COLUMN`. Returns the animation id upon success. Returns -1 upon failure.
	*/
	static int32 GetFrameBGR(int32 animationId, int32 frameIndex, float* duration, int32* colors, int32 length, int32* keys, int32 keysLength);

	/*
		Directly set 1D effect from an int32 color array
	*/
	static RZRESULT SetEffectCustom1D_BGR(EChromaSDKDevice1DEnum::Type device, int32* colors);

	/*
		Directly set 2D effect from an int32 color array
	*/
	static RZRESULT SetEffectCustom2D_BGR(EChromaSDKDevice2DEnum::Type device, int32* colors);

	/*
		Set the custom color mask on the int32 color array
	*/
	static RZRESULT SetCustomColorFlag2D_BGR(EChromaSDKDevice2DEnum::Type device, int32* colors);

	/*
		Directly set the custom color keyboard effect from an int32 color array
	*/
	static RZRESULT SetEffectKeyboardCustom2D_BGR(EChromaSDKDevice2DEnum::Type device, int32* colors, int32* keys);

#if PLATFORM_WINDOWS || PLATFORM_XBOXONE
private:

#pragma region Helper color functions
	static int UtilGetRGB(const int red, const int green, const int blue);
	static int UtilToBGR(const FLinearColor& color);

	static int min(const int a, const int b);
	static int max(const int a, const int b);
#pragma endregion

	static std::map<FKey, EChromaSDKKeyboardKey::Type> _sKeyboardFKeyMap;
	static std::map<EChromaSDKKeyboardKey::Type, int32> _sKeyboardEnumMap;
	static std::map<EChromaSDKMouseLed::Type, ChromaSDK::Mouse::RZLED2> _sMouseEnumMap;

	static bool _sInitialized;

#endif
};
