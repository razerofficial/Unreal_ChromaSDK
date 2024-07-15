// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#pragma once


#include "Logging/LogMacros.h"
DECLARE_LOG_CATEGORY_EXTERN(LogChromaSampleAppButton, Log, All);


#include "SampleAppButton.generated.h"

UCLASS()
class USampleAppButton : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	FString Name;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HandleClick", Keywords = "Dynamic function to handle button widget clicks"), Category = "Sample")
	void HandleClick();
};
