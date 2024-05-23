// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RzChromaSDKDefines.h"
#include "RzChromaSDKTypes.h"
#include "RzErrors.h"
#include "ChromaSDKPluginTypes.generated.h"

UENUM(BlueprintType)
namespace EChromaSDKDeviceTypeEnum
{
	enum Type
	{
		DE_1D			UMETA(DisplayName = "1D"),
		DE_2D			UMETA(DisplayName = "2D")
	};
}

UENUM(BlueprintType)
namespace EChromaSDKDevice1DEnum
{
	enum Type
	{
		DE_ChromaLink		UMETA(DisplayName = "ChromaLink"),
		DE_Headset			UMETA(DisplayName = "Headset"),
		DE_Mousepad			UMETA(DisplayName = "Mousepad"),
	};
}

UENUM(BlueprintType)
namespace EChromaSDKDevice2DEnum
{
	enum Type
	{
		DE_Keyboard				UMETA(DisplayName = "Keyboard"),
		DE_Keypad				UMETA(DisplayName = "Keypad"),
		DE_Mouse				UMETA(DisplayName = "Mouse"),
		DE_KeyboardExtended		UMETA(DisplayName = "KeyboardExtended"),
	};
}

UENUM(BlueprintType)
namespace EChromaSDKDeviceEnum
{
	enum Type
	{
		DE_ChromaLink			UMETA(DisplayName = "ChromaLink"),
		DE_Headset				UMETA(DisplayName = "Headset"),
		DE_Keyboard				UMETA(DisplayName = "Keyboard"),
		DE_Keypad				UMETA(DisplayName = "Keypad"),
		DE_Mouse				UMETA(DisplayName = "Mouse"),
		DE_Mousepad				UMETA(DisplayName = "Mousepad"),
		DE_KeyboardExtended		UMETA(DisplayName = "KeyboardExtended"),
		DE_MAX					UMETA(DisplayName = "Max"),
	};
}

UENUM(BlueprintType)
namespace EChromaSDKKeyboardKey
{
	enum Type
	{
		KK_ESC                           UMETA(DisplayName = "Esc (VK_ESCAPE)"),
		KK_F1                            UMETA(DisplayName = "F1 (VK_F1)"),
		KK_F2                            UMETA(DisplayName = "F2 (VK_F2)"),
		KK_F3                            UMETA(DisplayName = "F3 (VK_F3)"),
		KK_F4                            UMETA(DisplayName = "F4 (VK_F4)"),
		KK_F5                            UMETA(DisplayName = "F5 (VK_F5)"),
		KK_F6                            UMETA(DisplayName = "F6 (VK_F6)"),
		KK_F7                            UMETA(DisplayName = "F7 (VK_F7)"),
		KK_F8                            UMETA(DisplayName = "F8 (VK_F8)"),
		KK_F9                            UMETA(DisplayName = "F9 (VK_F9)"),
		KK_F10                           UMETA(DisplayName = "F10 (VK_F10)"),
		KK_F11                           UMETA(DisplayName = "F11 (VK_F11)"),
		KK_F12                           UMETA(DisplayName = "F12 (VK_F12)"),
		KK_1                             UMETA(DisplayName = "1 (VK_1)"),
		KK_2                             UMETA(DisplayName = "2 (VK_2)"),
		KK_3                             UMETA(DisplayName = "3 (VK_3)"),
		KK_4                             UMETA(DisplayName = "4 (VK_4)"),
		KK_5                             UMETA(DisplayName = "5 (VK_5)"),
		KK_6                             UMETA(DisplayName = "6 (VK_6)"),
		KK_7                             UMETA(DisplayName = "7 (VK_7)"),
		KK_8                             UMETA(DisplayName = "8 (VK_8)"),
		KK_9                             UMETA(DisplayName = "9 (VK_9)"),
		KK_0                             UMETA(DisplayName = "0 (VK_0)"),
		KK_A                             UMETA(DisplayName = "A (VK_A)"),
		KK_B                             UMETA(DisplayName = "B (VK_B)"),
		KK_C                             UMETA(DisplayName = "C (VK_C)"),
		KK_D                             UMETA(DisplayName = "D (VK_D)"),
		KK_E                             UMETA(DisplayName = "E (VK_E)"),
		KK_F                             UMETA(DisplayName = "F (VK_F)"),
		KK_G                             UMETA(DisplayName = "G (VK_G)"),
		KK_H                             UMETA(DisplayName = "H (VK_H)"),
		KK_I                             UMETA(DisplayName = "I (VK_I)"),
		KK_J                             UMETA(DisplayName = "J (VK_J)"),
		KK_K                             UMETA(DisplayName = "K (VK_K)"),
		KK_L                             UMETA(DisplayName = "L (VK_L)"),
		KK_M                             UMETA(DisplayName = "M (VK_M)"),
		KK_N                             UMETA(DisplayName = "N (VK_N)"),
		KK_O                             UMETA(DisplayName = "O (VK_O)"),
		KK_P                             UMETA(DisplayName = "P (VK_P)"),
		KK_Q                             UMETA(DisplayName = "Q (VK_Q)"),
		KK_R                             UMETA(DisplayName = "R (VK_R)"),
		KK_S                             UMETA(DisplayName = "S (VK_S)"),
		KK_T                             UMETA(DisplayName = "T (VK_T)"),
		KK_U                             UMETA(DisplayName = "U (VK_U)"),
		KK_V                             UMETA(DisplayName = "V (VK_V)"),
		KK_W                             UMETA(DisplayName = "W (VK_W)"),
		KK_X                             UMETA(DisplayName = "X (VK_X)"),
		KK_Y                             UMETA(DisplayName = "Y (VK_Y)"),
		KK_Z                             UMETA(DisplayName = "Z (VK_Z)"),
		KK_NUMLOCK                       UMETA(DisplayName = "Numlock (VK_NUMLOCK)"),
		KK_NUMPAD0                       UMETA(DisplayName = "Numpad 0 (VK_NUMPAD0)"),
		KK_NUMPAD1                       UMETA(DisplayName = "Numpad 1 (VK_NUMPAD1)"),
		KK_NUMPAD2                       UMETA(DisplayName = "Numpad 2 (VK_NUMPAD2)"),
		KK_NUMPAD3                       UMETA(DisplayName = "Numpad 3 (VK_NUMPAD3)"),
		KK_NUMPAD4                       UMETA(DisplayName = "Numpad 4 (VK_NUMPAD4)"),
		KK_NUMPAD5                       UMETA(DisplayName = "Numpad 5 (VK_NUMPAD5)"),
		KK_NUMPAD6                       UMETA(DisplayName = "Numpad 6 (VK_NUMPAD6)"),
		KK_NUMPAD7                       UMETA(DisplayName = "Numpad 7 (VK_NUMPAD7)"),
		KK_NUMPAD8                       UMETA(DisplayName = "Numpad 8 (VK_NUMPAD8)"),
		KK_NUMPAD9                       UMETA(DisplayName = "Numpad 9 (VK_ NUMPAD9)"),
		KK_NUMPAD_DIVIDE                 UMETA(DisplayName = "Divide (VK_DIVIDE)"),
		KK_NUMPAD_MULTIPLY               UMETA(DisplayName = "Multiply (VK_MULTIPLY)"),
		KK_NUMPAD_SUBTRACT               UMETA(DisplayName = "Subtract (VK_SUBTRACT)"),
		KK_NUMPAD_ADD                    UMETA(DisplayName = "Add (VK_ADD)"),
		KK_NUMPAD_ENTER                  UMETA(DisplayName = "Enter (VK_RETURN - Extended)"),
		KK_NUMPAD_DECIMAL                UMETA(DisplayName = "Decimal (VK_DECIMAL)"),
		KK_PRINTSCREEN                   UMETA(DisplayName = "Print Screen (VK_PRINT)"),
		KK_SCROLL                        UMETA(DisplayName = "Scroll Lock (VK_SCROLL)"),
		KK_PAUSE                         UMETA(DisplayName = "Pause (VK_PAUSE)"),
		KK_INSERT                        UMETA(DisplayName = "Insert (VK_INSERT)"),
		KK_HOME                          UMETA(DisplayName = "Home (VK_HOME)"),
		KK_PAGEUP                        UMETA(DisplayName = "Page Up (VK_PRIOR)"),
		KK_DELETE                        UMETA(DisplayName = "Delete (VK_DELETE)"),
		KK_END                           UMETA(DisplayName = "End (VK_END)"),
		KK_PAGEDOWN                      UMETA(DisplayName = "Page Down (VK_NEXT)"),
		KK_UP                            UMETA(DisplayName = "Up (VK_UP)"),
		KK_LEFT                          UMETA(DisplayName = "Left (VK_LEFT)"),
		KK_DOWN                          UMETA(DisplayName = "Down (VK_DOWN)"),
		KK_RIGHT                         UMETA(DisplayName = "Right (VK_RIGHT)"),
		KK_TAB                           UMETA(DisplayName = "Tab (VK_TAB)"),
		KK_CAPSLOCK                      UMETA(DisplayName = "Caps Lock(VK_CAPITAL)"),
		KK_BACKSPACE                     UMETA(DisplayName = "Backspace (VK_BACK)"),
		KK_ENTER                         UMETA(DisplayName = "Enter (VK_RETURN)"),
		KK_LCTRL                         UMETA(DisplayName = "Left Control(VK_LCONTROL)"),
		KK_LWIN                          UMETA(DisplayName = "Left Window (VK_LWIN)"),
		KK_LALT                          UMETA(DisplayName = "Left Alt (VK_LMENU)"),
		KK_SPACE                         UMETA(DisplayName = "Spacebar (VK_SPACE)"),
		KK_RALT                          UMETA(DisplayName = "Right Alt (VK_RMENU)"),
		KK_FN                            UMETA(DisplayName = "Function key"),
		KK_RMENU                         UMETA(DisplayName = "Right Menu (VK_APPS)"),
		KK_RCTRL                         UMETA(DisplayName = "Right Control (VK_RCONTROL)"),
		KK_LSHIFT                        UMETA(DisplayName = "Left Shift (VK_LSHIFT)"),
		KK_RSHIFT                        UMETA(DisplayName = "Right Shift (VK_RSHIFT)"),
		KK_MACRO1                        UMETA(DisplayName = "Macro Key 1"),
		KK_MACRO2                        UMETA(DisplayName = "Macro Key 2"),
		KK_MACRO3                        UMETA(DisplayName = "Macro Key 3"),
		KK_MACRO4                        UMETA(DisplayName = "Macro Key 4"),
		KK_MACRO5                        UMETA(DisplayName = "Macro Key 5"),
		KK_OEM_1                         UMETA(DisplayName = "~ (tilde/半角/全角) (VK_OEM_3)"),
		KK_OEM_2                         UMETA(DisplayName = "-- (minus) (VK_OEM_MINUS)"),
		KK_OEM_3                         UMETA(DisplayName = "= (equal) (VK_OEM_PLUS)"),
		KK_OEM_4                         UMETA(DisplayName = "[ (left sqaure bracket) (VK_OEM_4)"),
		KK_OEM_5                         UMETA(DisplayName = "] (right square bracket) (VK_OEM_6)"),
		KK_OEM_6                         UMETA(DisplayName = "\ (backslash) (VK_OEM_5)"),
		KK_OEM_7                         UMETA(DisplayName = "; (semi-colon) (VK_OEM_1)"),
		KK_OEM_8                         UMETA(DisplayName = "' (apostrophe) (VK_OEM_7)"),
		KK_OEM_9                         UMETA(DisplayName = ", (comma) (VK_OEM_COMMA)"),
		KK_OEM_10                        UMETA(DisplayName = ". (period) (VK_OEM_PERIOD)"),
		KK_OEM_11                        UMETA(DisplayName = "/ (forward slash) (VK_OEM_2)"),
		KK_EUR_1                         UMETA(DisplayName = "# (VK_OEM_5)"),
		KK_EUR_2                         UMETA(DisplayName = "\ (VK_OEM_102)"),
		KK_JPN_1                         UMETA(DisplayName = "¥ (0xFF)"),
		KK_JPN_2                         UMETA(DisplayName = "\ (0xC1)"),
		KK_JPN_3                         UMETA(DisplayName = "無変換 (VK_OEM_PA1)"),
		KK_JPN_4                         UMETA(DisplayName = "変換 (0xFF)"),
		KK_JPN_5                         UMETA(DisplayName = "ひらがな/カタカナ (0xFF)"),
		KK_KOR_1                         UMETA(DisplayName = "| (0xFF)"),
		KK_KOR_2                         UMETA(DisplayName = "(VK_OEM_5)"),
		KK_KOR_3                         UMETA(DisplayName = "(VK_OEM_102)"),
		KK_KOR_4                         UMETA(DisplayName = "(0xC1)"),
		KK_KOR_5                         UMETA(DisplayName = "(VK_OEM_PA1)"),
		KK_KOR_6                         UMETA(DisplayName = "한/영 (0xFF)"),
		KK_KOR_7                         UMETA(DisplayName = "(0xFF)"),
		KK_LOGO                          UMETA(DisplayName = "Razer logo"),
		KK_INVALID                       UMETA(DisplayName = "Invalid keys.")
	};
}

UENUM(BlueprintType)
namespace EChromaSDKMouseLed
{
	enum Type
	{
		ML_SCROLLWHEEL		UMETA(DisplayName = "Scroll Wheel LED"),
		ML_LOGO				UMETA(DisplayName = "Logo LED"),
		ML_BACKLIGHT		UMETA(DisplayName = "Backlight LED"),
		ML_LEFT_SIDE1		UMETA(DisplayName = "Left LED 1"),
		ML_LEFT_SIDE2		UMETA(DisplayName = "Left LED 2"),
		ML_LEFT_SIDE3		UMETA(DisplayName = "Left LED 3"),
		ML_LEFT_SIDE4		UMETA(DisplayName = "Left LED 4"),
		ML_LEFT_SIDE5		UMETA(DisplayName = "Left LED 5"),
		ML_LEFT_SIDE6		UMETA(DisplayName = "Left LED 6"),
		ML_LEFT_SIDE7		UMETA(DisplayName = "Left LED 7"),
		ML_BOTTOM1			UMETA(DisplayName = "Bottom LED 1"),
		ML_BOTTOM2			UMETA(DisplayName = "Bottom LED 2"),
		ML_BOTTOM3			UMETA(DisplayName = "Bottom LED 3"),
		ML_BOTTOM4			UMETA(DisplayName = "Bottom LED 4"),
		ML_BOTTOM5			UMETA(DisplayName = "Bottom LED 5"),
		ML_RIGHT_SIDE1		UMETA(DisplayName = "Right LED 1"),
		ML_RIGHT_SIDE2		UMETA(DisplayName = "Right LED 2"),
		ML_RIGHT_SIDE3		UMETA(DisplayName = "Right LED 3"),
		ML_RIGHT_SIDE4		UMETA(DisplayName = "Right LED 4"),
		ML_RIGHT_SIDE5		UMETA(DisplayName = "Right LED 5"),
		ML_RIGHT_SIDE6		UMETA(DisplayName = "Right LED 6"),
		ML_RIGHT_SIDE7		UMETA(DisplayName = "Right LED 7")
	};
}

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKGuid
{
	GENERATED_USTRUCT_BODY()

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	RZEFFECTID Data;
#endif

	//Constructor
	FChromaSDKGuid();
};

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKEffectResult
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "ChromaSDK")
	int32 Result;

	UPROPERTY(BlueprintReadOnly, Category = "ChromaSDK")
	FChromaSDKGuid EffectId;

	//Constructor
	FChromaSDKEffectResult();
};

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKColors
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "ChromaSDK")
	TArray<FLinearColor> Colors;

	//Constructor
	FChromaSDKColors();
};

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKColorFrame1D
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "ChromaSDK")
	TArray<FLinearColor> Colors;

	float Duration;

	//Constructor
	FChromaSDKColorFrame1D();
};

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKColorFrame2D
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "ChromaSDK")
	TArray<FChromaSDKColors> Colors;

	float Duration;

	//Constructor
	FChromaSDKColorFrame2D();
};

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKAppInfoType
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	FString Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	FString Author_Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	FString Author_Contact;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	int32 SupportedDevice;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	int32 Category;
};


USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKDeviceFrameIndex
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "ChromaSDK")
	TArray<int32> FrameIndex;

	//Constructor
	FChromaSDKDeviceFrameIndex()
	{
		for (int i = 0; i < (int)EChromaSDKDeviceEnum::DE_MAX; ++i)
		{
			FrameIndex.Add(0);
		}

		FrameIndex[(int)EChromaSDKDeviceEnum::DE_ChromaLink] = 0;
		FrameIndex[(int)EChromaSDKDeviceEnum::DE_Headset] = 0;
		FrameIndex[(int)EChromaSDKDeviceEnum::DE_Keyboard] = 0;
		FrameIndex[(int)EChromaSDKDeviceEnum::DE_Keypad] = 0;
		FrameIndex[(int)EChromaSDKDeviceEnum::DE_Mouse] = 0;
		FrameIndex[(int)EChromaSDKDeviceEnum::DE_Mousepad] = 0;
		FrameIndex[(int)EChromaSDKDeviceEnum::DE_KeyboardExtended] = 0;
	}
};

UENUM(BlueprintType)
namespace EChromaSDKSceneBlend
{
	enum Type
	{
		SB_None			UMETA(DisplayName = "None"),
		SB_Invert		UMETA(DisplayName = "Invert"),
		SB_Threshold	UMETA(DisplayName = "Threshold"),
		SB_Lerp			UMETA(DisplayName = "Lerp"),
	};
}

UENUM(BlueprintType)
namespace EChromaSDKSceneMode
{
	enum Type
	{
		SM_Replace		UMETA(DisplayName = "Replace"),
		SM_Max			UMETA(DisplayName = "Max"),
		SM_Min			UMETA(DisplayName = "Min"),
		SM_Average		UMETA(DisplayName = "Average"),
		SM_Multiply		UMETA(DisplayName = "Multiply"),
		SM_Add			UMETA(DisplayName = "Add"),
		SM_Subtract		UMETA(DisplayName = "Subtract"),
	};
}


USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKSceneEffect
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	FString Animation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	bool State;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	int32 PrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	int32 SecondaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	int32 Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	TEnumAsByte<EChromaSDKSceneBlend::Type> Blend;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	TEnumAsByte<EChromaSDKSceneMode::Type> Mode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	FChromaSDKDeviceFrameIndex FrameIndex;

	//constructor
	FChromaSDKSceneEffect();
};

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKScene
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	TArray<FChromaSDKSceneEffect> Effects;

	void ToggleState(unsigned int effect);
};

UENUM(BlueprintType)
namespace EChromaSDKStreamStatusEnum
{
	enum Type
	{
		READY = 0					UMETA(DisplayName = "READY"),
		AUTHORIZING = 1				UMETA(DisplayName = "AUTHORIZING"),
		BROADCASTING = 2			UMETA(DisplayName = "BROADCASTING"),
		WATCHING = 3				UMETA(DisplayName = "WATCHING"),
		NOT_AUTHORIZED = 4			UMETA(DisplayName = "NOT_AUTHORIZED"),
		BROADCAST_DUPLICATE = 5		UMETA(DisplayName = "BROADCAST_DUPLICATE"),
		SERVICE_OFFLINE = 6			UMETA(DisplayName = "SERVICE_OFFLINE"),
	};
}

UENUM(BlueprintType)
namespace EChromaSDKCoreDeviceTypeEnum
{
	enum Type
	{
		UNASSIGNED_INVALID = 0,
		DEVICE_KEYBOARD = 1			UMETA(DisplayName = "DEVICE_KEYBOARD"),
		DEVICE_MOUSE = 2			UMETA(DisplayName = "DEVICE_MOUSE"),
		DEVICE_HEADSET = 3			UMETA(DisplayName = "DEVICE_HEADSET"),
		DEVICE_MOUSEPAD = 4			UMETA(DisplayName = "DEVICE_MOUSEPAD"),
		DEVICE_KEYPAD = 5			UMETA(DisplayName = "DEVICE_KEYPAD"),
		DEVICE_SYSTEM = 6			UMETA(DisplayName = "DEVICE_SYSTEM"),
		DEVICE_SPEAKERS = 7			UMETA(DisplayName = "DEVICE_SPEAKERS"),
		DEVICE_CHROMALINK = 8		UMETA(DisplayName = "DEVICE_CHROMALINK"),
		DEVICE_ALL = 255			UMETA(DisplayName = "DEVICE_ALL"),
		INVALID						UMETA(DisplayName = "INVALID"),
	};
}

USTRUCT(BlueprintType)
struct CHROMASDKPLUGIN_API FChromaSDKDeviceInfoType
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	TEnumAsByte<EChromaSDKCoreDeviceTypeEnum::Type> DeviceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChromaSDK")
	int32 Connected;

	//constructor
	FChromaSDKDeviceInfoType();
	FChromaSDKDeviceInfoType(const FChromaSDKDeviceInfoType& rhs);
};
