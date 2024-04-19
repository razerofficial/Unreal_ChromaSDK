// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#include "SampleGameButton.h" //___HACK_UE4_VERSION_4_16_OR_GREATER
#include "Chroma_Sample.h"
//#include "SampleGameButton.h" //___HACK_UE4_VERSION_4_15_OR_LESS
#include "ChromaSDKPluginBPLibrary.h"
#include "SampleGameChromaBP.h"


DEFINE_LOG_CATEGORY(LogChromaSampleGameButton);


using namespace std;

mutex USampleGameButton::_sMutex;

//USampleGameButton::USampleGameButton(const class FPostConstructInitializeProperties& PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
//	: Super(PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
USampleGameButton::USampleGameButton(const FObjectInitializer& ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
: Super(ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
{
}

void USampleGameButton::HandleClick()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
    if (!UChromaSDKPluginBPLibrary::IsInitialized())
    {
        UE_LOG(LogChromaSampleGameButton, Error, TEXT("Chroma is not initialized!"));
        return;
    }

    lock_guard<mutex> guard(_sMutex);

    if (Name.Compare("Button_Effect1") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect1();
        USampleGameChromaBP::SampleGameShowEffect1ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect1Headset();
        USampleGameChromaBP::SampleGameShowEffect1Keypad();
        USampleGameChromaBP::SampleGameShowEffect1Mousepad();
        USampleGameChromaBP::SampleGameShowEffect1Mouse();
    }

    else if (Name.Compare("Button_Effect2") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect2();
        USampleGameChromaBP::SampleGameShowEffect2ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect2Headset();
        USampleGameChromaBP::SampleGameShowEffect2Keypad();
        USampleGameChromaBP::SampleGameShowEffect2Mousepad();
        USampleGameChromaBP::SampleGameShowEffect2Mouse();
    }

    else if (Name.Compare("Button_Effect3") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect3();
        USampleGameChromaBP::SampleGameShowEffect3ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect3Headset();
        USampleGameChromaBP::SampleGameShowEffect3Keypad();
        USampleGameChromaBP::SampleGameShowEffect3Mousepad();
        USampleGameChromaBP::SampleGameShowEffect3Mouse();
    }

    else if (Name.Compare("Button_Effect4") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect4();
        USampleGameChromaBP::SampleGameShowEffect4ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect4Headset();
        USampleGameChromaBP::SampleGameShowEffect4Keypad();
        USampleGameChromaBP::SampleGameShowEffect4Mousepad();
        USampleGameChromaBP::SampleGameShowEffect4Mouse();
    }

    else if (Name.Compare("Button_Effect5") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect5();
        USampleGameChromaBP::SampleGameShowEffect5ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect5Headset();
        USampleGameChromaBP::SampleGameShowEffect5Keypad();
        USampleGameChromaBP::SampleGameShowEffect5Mousepad();
        USampleGameChromaBP::SampleGameShowEffect5Mouse();
    }

    else if (Name.Compare("Button_Effect6") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect6();
        USampleGameChromaBP::SampleGameShowEffect6ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect6Headset();
        USampleGameChromaBP::SampleGameShowEffect6Keypad();
        USampleGameChromaBP::SampleGameShowEffect6Mousepad();
        USampleGameChromaBP::SampleGameShowEffect6Mouse();
    }

    else if (Name.Compare("Button_Effect7") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect7();
        USampleGameChromaBP::SampleGameShowEffect7ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect7Headset();
        USampleGameChromaBP::SampleGameShowEffect7Keypad();
        USampleGameChromaBP::SampleGameShowEffect7Mousepad();
        USampleGameChromaBP::SampleGameShowEffect7Mouse();
    }

    else if (Name.Compare("Button_Effect8") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect8();
        USampleGameChromaBP::SampleGameShowEffect8ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect8Headset();
        USampleGameChromaBP::SampleGameShowEffect8Keypad();
        USampleGameChromaBP::SampleGameShowEffect8Mousepad();
        USampleGameChromaBP::SampleGameShowEffect8Mouse();
    }

    else if (Name.Compare("Button_Effect9") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect9();
        USampleGameChromaBP::SampleGameShowEffect9ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect9Headset();
        USampleGameChromaBP::SampleGameShowEffect9Keypad();
        USampleGameChromaBP::SampleGameShowEffect9Mousepad();
        USampleGameChromaBP::SampleGameShowEffect9Mouse();
    }

    else if (Name.Compare("Button_Effect10") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect10();
        USampleGameChromaBP::SampleGameShowEffect10ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect10Headset();
        USampleGameChromaBP::SampleGameShowEffect10Keypad();
        USampleGameChromaBP::SampleGameShowEffect10Mousepad();
        USampleGameChromaBP::SampleGameShowEffect10Mouse();
    }

    else if (Name.Compare("Button_Effect11") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect11();
        USampleGameChromaBP::SampleGameShowEffect11ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect11Headset();
        USampleGameChromaBP::SampleGameShowEffect11Keypad();
        USampleGameChromaBP::SampleGameShowEffect11Mousepad();
        USampleGameChromaBP::SampleGameShowEffect11Mouse();
    }

    else if (Name.Compare("Button_Effect12") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect12();
        USampleGameChromaBP::SampleGameShowEffect12ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect12Headset();
        USampleGameChromaBP::SampleGameShowEffect12Keypad();
        USampleGameChromaBP::SampleGameShowEffect12Mousepad();
        USampleGameChromaBP::SampleGameShowEffect12Mouse();
    }

    else if (Name.Compare("Button_Effect13") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect13();
        USampleGameChromaBP::SampleGameShowEffect13ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect13Headset();
        USampleGameChromaBP::SampleGameShowEffect13Keypad();
        USampleGameChromaBP::SampleGameShowEffect13Mousepad();
        USampleGameChromaBP::SampleGameShowEffect13Mouse();
    }

    else if (Name.Compare("Button_Effect14") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect14();
        USampleGameChromaBP::SampleGameShowEffect14ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect14Headset();
        USampleGameChromaBP::SampleGameShowEffect14Keypad();
        USampleGameChromaBP::SampleGameShowEffect14Mousepad();
        USampleGameChromaBP::SampleGameShowEffect14Mouse();
    }

    else if (Name.Compare("Button_Effect15") == 0)
    {
        USampleGameChromaBP::SampleGameShowEffect15();
        USampleGameChromaBP::SampleGameShowEffect15ChromaLink();
        USampleGameChromaBP::SampleGameShowEffect15Headset();
        USampleGameChromaBP::SampleGameShowEffect15Keypad();
        USampleGameChromaBP::SampleGameShowEffect15Mousepad();
        USampleGameChromaBP::SampleGameShowEffect15Mouse();
    }

#endif
}
