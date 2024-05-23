// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#pragma once


#include "Logging/LogMacros.h"
DECLARE_LOG_CATEGORY_EXTERN(LogChromaSampleGameButton, Log, All);


#include <mutex>
#include "SampleGameButton.generated.h"


UCLASS()
class USampleGameButton : public UObject
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	FString Name;

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "HandleClick", Keywords = "Dynamic function to handle button widget clicks"), Category = "Sample")
	void HandleClick();

private:
	static std::mutex _sMutex;
};
