// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "UMG.h"
#include "SampleGameButton.h"
#include "SampleGameChromaBP.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(LogChromaSampleGame, Log, All);


UCLASS()
class USampleGameChromaBP : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

    static int min(int a, int b);
	static int max(int a, int b);

    UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameSetupButtonsEffects", Keywords = "Setup an array of button widgets"), Category = "Sample")
	static void SampleGameSetupButtonsEffects(const TArray<UButton*>& buttons);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameSampleStart", Keywords = "Init at the start of the application"), Category = "Sample")
	static void SampleGameSampleStart();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameSampleEnd", Keywords = "Uninit at the end of the application"), Category = "Sample")
	static void SampleGameSampleEnd();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect1", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect1();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect1ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect1ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect1Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect1Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect1Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect1Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect1Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect1Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect1Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect1Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect2", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect2();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect2ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect2ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect2Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect2Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect2Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect2Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect2Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect2Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect2Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect2Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect3", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect3();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect3ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect3ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect3Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect3Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect3Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect3Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect3Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect3Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect3Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect3Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect4", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect4();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect4ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect4ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect4Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect4Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect4Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect4Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect4Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect4Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect4Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect4Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect5", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect5();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect5ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect5ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect5Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect5Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect5Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect5Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect5Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect5Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect5Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect5Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect6", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect6();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect6ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect6ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect6Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect6Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect6Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect6Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect6Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect6Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect6Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect6Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect7", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect7();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect7ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect7ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect7Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect7Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect7Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect7Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect7Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect7Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect7Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect7Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect8", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect8();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect8ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect8ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect8Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect8Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect8Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect8Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect8Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect8Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect8Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect8Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect9", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect9();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect9ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect9ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect9Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect9Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect9Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect9Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect9Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect9Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect9Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect9Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect10", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect10();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect10ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect10ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect10Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect10Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect10Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect10Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect10Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect10Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect10Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect10Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect11", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect11();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect11ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect11ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect11Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect11Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect11Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect11Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect11Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect11Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect11Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect11Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect12", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect12();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect12ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect12ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect12Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect12Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect12Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect12Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect12Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect12Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect12Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect12Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect13", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect13();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect13ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect13ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect13Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect13Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect13Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect13Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect13Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect13Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect13Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect13Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect14", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect14();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect14ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect14ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect14Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect14Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect14Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect14Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect14Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect14Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect14Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect14Keypad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect15", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect15();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect15ChromaLink", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect15ChromaLink();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect15Headset", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect15Headset();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect15Mousepad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect15Mousepad();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect15Mouse", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect15Mouse();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SampleGameShowEffect15Keypad", Keywords = "Example"), Category = "Sample")
	static void SampleGameShowEffect15Keypad();

private:
	static TArray<USampleGameButton*> _sSampleButtons;
};
