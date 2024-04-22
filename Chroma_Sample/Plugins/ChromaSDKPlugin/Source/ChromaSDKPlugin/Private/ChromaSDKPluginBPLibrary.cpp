// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "ChromaSDKPluginBPLibrary.h" //___HACK_UE4_VERSION_4_16_OR_GREATER
#include "ChromaSDKPluginPrivatePCH.h"
//#include "ChromaSDKPluginBPLibrary.h" //___HACK_UE4_VERSION_4_15_OR_LESS

#include "ChromaAnimationAPI.h"
#include <string>


DEFINE_LOG_CATEGORY(LogChromaBlueprintLibrary);


#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

#include "Misc/Paths.h"
#include "Windows/AllowWindowsPlatformTypes.h" 


using namespace ChromaSDK;
using namespace std;

// fkey map
std::map<FKey, EChromaSDKKeyboardKey::Type> UChromaSDKPluginBPLibrary::_sKeyboardFKeyMap =
	std::map<FKey, EChromaSDKKeyboardKey::Type>();
// keyboard map
std::map<EChromaSDKKeyboardKey::Type, int> UChromaSDKPluginBPLibrary::_sKeyboardEnumMap =
	std::map<EChromaSDKKeyboardKey::Type, int>();

// mouse map
std::map<EChromaSDKMouseLed::Type, ChromaSDK::Mouse::RZLED2> UChromaSDKPluginBPLibrary::_sMouseEnumMap =
	std::map<EChromaSDKMouseLed::Type, ChromaSDK::Mouse::RZLED2>();

bool UChromaSDKPluginBPLibrary::_sInitialized = false;

#endif

//UChromaSDKPluginBPLibrary::UChromaSDKPluginBPLibrary(const FPostConstructInitializeProperties& PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
//	: Super(PCIP) //___HACK_UE4_VERSION_4_8_OR_LESS
UChromaSDKPluginBPLibrary::UChromaSDKPluginBPLibrary(const FObjectInitializer& ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
	: Super(ObjectInitializer) //___HACK_UE4_VERSION_4_9_OR_GREATER
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	// fkey mapping
	_sKeyboardFKeyMap[EKeys::Escape] = EChromaSDKKeyboardKey::KK_ESC;
	_sKeyboardFKeyMap[EKeys::F1] = EChromaSDKKeyboardKey::KK_F1;
	_sKeyboardFKeyMap[EKeys::F2] = EChromaSDKKeyboardKey::KK_F2;
	_sKeyboardFKeyMap[EKeys::F3] = EChromaSDKKeyboardKey::KK_F3;
	_sKeyboardFKeyMap[EKeys::F4] = EChromaSDKKeyboardKey::KK_F4;
	_sKeyboardFKeyMap[EKeys::F5] = EChromaSDKKeyboardKey::KK_F5;
	_sKeyboardFKeyMap[EKeys::F6] = EChromaSDKKeyboardKey::KK_F6;
	_sKeyboardFKeyMap[EKeys::F7] = EChromaSDKKeyboardKey::KK_F7;
	_sKeyboardFKeyMap[EKeys::F8] = EChromaSDKKeyboardKey::KK_F8;
	_sKeyboardFKeyMap[EKeys::F9] = EChromaSDKKeyboardKey::KK_F9;
	_sKeyboardFKeyMap[EKeys::F10] = EChromaSDKKeyboardKey::KK_F10;
	_sKeyboardFKeyMap[EKeys::F11] = EChromaSDKKeyboardKey::KK_F11;
	_sKeyboardFKeyMap[EKeys::F12] = EChromaSDKKeyboardKey::KK_F12;
	_sKeyboardFKeyMap[EKeys::One] = EChromaSDKKeyboardKey::KK_1;
	_sKeyboardFKeyMap[EKeys::Two] = EChromaSDKKeyboardKey::KK_2;
	_sKeyboardFKeyMap[EKeys::Three] = EChromaSDKKeyboardKey::KK_3;
	_sKeyboardFKeyMap[EKeys::Four] = EChromaSDKKeyboardKey::KK_4;
	_sKeyboardFKeyMap[EKeys::Five] = EChromaSDKKeyboardKey::KK_5;
	_sKeyboardFKeyMap[EKeys::Six] = EChromaSDKKeyboardKey::KK_6;
	_sKeyboardFKeyMap[EKeys::Seven] = EChromaSDKKeyboardKey::KK_7;
	_sKeyboardFKeyMap[EKeys::Eight] = EChromaSDKKeyboardKey::KK_8;
	_sKeyboardFKeyMap[EKeys::Nine] = EChromaSDKKeyboardKey::KK_9;
	_sKeyboardFKeyMap[EKeys::Zero] = EChromaSDKKeyboardKey::KK_0;
	_sKeyboardFKeyMap[EKeys::A] = EChromaSDKKeyboardKey::KK_A;
	_sKeyboardFKeyMap[EKeys::B] = EChromaSDKKeyboardKey::KK_B;
	_sKeyboardFKeyMap[EKeys::C] = EChromaSDKKeyboardKey::KK_C;
	_sKeyboardFKeyMap[EKeys::D] = EChromaSDKKeyboardKey::KK_D;
	_sKeyboardFKeyMap[EKeys::E] = EChromaSDKKeyboardKey::KK_E;
	_sKeyboardFKeyMap[EKeys::F] = EChromaSDKKeyboardKey::KK_F;
	_sKeyboardFKeyMap[EKeys::G] = EChromaSDKKeyboardKey::KK_G;
	_sKeyboardFKeyMap[EKeys::H] = EChromaSDKKeyboardKey::KK_H;
	_sKeyboardFKeyMap[EKeys::I] = EChromaSDKKeyboardKey::KK_I;
	_sKeyboardFKeyMap[EKeys::J] = EChromaSDKKeyboardKey::KK_J;
	_sKeyboardFKeyMap[EKeys::K] = EChromaSDKKeyboardKey::KK_K;
	_sKeyboardFKeyMap[EKeys::L] = EChromaSDKKeyboardKey::KK_L;
	_sKeyboardFKeyMap[EKeys::M] = EChromaSDKKeyboardKey::KK_M;
	_sKeyboardFKeyMap[EKeys::N] = EChromaSDKKeyboardKey::KK_N;
	_sKeyboardFKeyMap[EKeys::O] = EChromaSDKKeyboardKey::KK_O;
	_sKeyboardFKeyMap[EKeys::P] = EChromaSDKKeyboardKey::KK_P;
	_sKeyboardFKeyMap[EKeys::Q] = EChromaSDKKeyboardKey::KK_Q;
	_sKeyboardFKeyMap[EKeys::R] = EChromaSDKKeyboardKey::KK_R;
	_sKeyboardFKeyMap[EKeys::S] = EChromaSDKKeyboardKey::KK_S;
	_sKeyboardFKeyMap[EKeys::T] = EChromaSDKKeyboardKey::KK_T;
	_sKeyboardFKeyMap[EKeys::U] = EChromaSDKKeyboardKey::KK_U;
	_sKeyboardFKeyMap[EKeys::V] = EChromaSDKKeyboardKey::KK_V;
	_sKeyboardFKeyMap[EKeys::W] = EChromaSDKKeyboardKey::KK_W;
	_sKeyboardFKeyMap[EKeys::X] = EChromaSDKKeyboardKey::KK_X;
	_sKeyboardFKeyMap[EKeys::Y] = EChromaSDKKeyboardKey::KK_Y;
	_sKeyboardFKeyMap[EKeys::Z] = EChromaSDKKeyboardKey::KK_Z;
	_sKeyboardFKeyMap[EKeys::NumLock] = EChromaSDKKeyboardKey::KK_NUMLOCK;
	_sKeyboardFKeyMap[EKeys::NumPadZero] = EChromaSDKKeyboardKey::KK_NUMPAD0;
	_sKeyboardFKeyMap[EKeys::NumPadOne] = EChromaSDKKeyboardKey::KK_NUMPAD1;
	_sKeyboardFKeyMap[EKeys::NumPadTwo] = EChromaSDKKeyboardKey::KK_NUMPAD2;
	_sKeyboardFKeyMap[EKeys::NumPadThree] = EChromaSDKKeyboardKey::KK_NUMPAD3;
	_sKeyboardFKeyMap[EKeys::NumPadFour] = EChromaSDKKeyboardKey::KK_NUMPAD4;
	_sKeyboardFKeyMap[EKeys::NumPadFive] = EChromaSDKKeyboardKey::KK_NUMPAD5;
	_sKeyboardFKeyMap[EKeys::NumPadSix] = EChromaSDKKeyboardKey::KK_NUMPAD6;
	_sKeyboardFKeyMap[EKeys::NumPadSeven] = EChromaSDKKeyboardKey::KK_NUMPAD7;
	_sKeyboardFKeyMap[EKeys::NumPadEight] = EChromaSDKKeyboardKey::KK_NUMPAD8;
	_sKeyboardFKeyMap[EKeys::NumPadNine] = EChromaSDKKeyboardKey::KK_NUMPAD9;
	//_sKeyboardFKeyMap[EKeys::Divide] = EChromaSDKKeyboardKey::KK_NUMPAD_DIVIDE;
	//_sKeyboardFKeyMap[EKeys::Multiply] = EChromaSDKKeyboardKey::KK_NUMPAD_MULTIPLY;
	//_sKeyboardFKeyMap[EKeys::Subtract] = EChromaSDKKeyboardKey::KK_NUMPAD_SUBTRACT;
	//_sKeyboardFKeyMap[EKeys::Add] = EChromaSDKKeyboardKey::KK_NUMPAD_ADD;
	//_sKeyboardFKeyMap[EKeys::Enter] = EChromaSDKKeyboardKey::KK_NUMPAD_ENTER;
	//_sKeyboardFKeyMap[EKeys::Decimal] = EChromaSDKKeyboardKey::KK_NUMPAD_DECIMAL;
	//_sKeyboardFKeyMap[EKeys::PrintScreen] = EChromaSDKKeyboardKey::KK_PRINTSCREEN;
	_sKeyboardFKeyMap[EKeys::ScrollLock] = EChromaSDKKeyboardKey::KK_SCROLL;
	_sKeyboardFKeyMap[EKeys::Pause] = EChromaSDKKeyboardKey::KK_PAUSE;
	_sKeyboardFKeyMap[EKeys::Insert] = EChromaSDKKeyboardKey::KK_INSERT;
	_sKeyboardFKeyMap[EKeys::Home] = EChromaSDKKeyboardKey::KK_HOME;
	_sKeyboardFKeyMap[EKeys::PageUp] = EChromaSDKKeyboardKey::KK_PAGEUP;
	_sKeyboardFKeyMap[EKeys::Delete] = EChromaSDKKeyboardKey::KK_DELETE;
	_sKeyboardFKeyMap[EKeys::End] = EChromaSDKKeyboardKey::KK_END;
	_sKeyboardFKeyMap[EKeys::PageDown] = EChromaSDKKeyboardKey::KK_PAGEDOWN;
	_sKeyboardFKeyMap[EKeys::Up] = EChromaSDKKeyboardKey::KK_UP;
	_sKeyboardFKeyMap[EKeys::Left] = EChromaSDKKeyboardKey::KK_LEFT;
	_sKeyboardFKeyMap[EKeys::Down] = EChromaSDKKeyboardKey::KK_DOWN;
	_sKeyboardFKeyMap[EKeys::Right] = EChromaSDKKeyboardKey::KK_RIGHT;
	_sKeyboardFKeyMap[EKeys::Tab] = EChromaSDKKeyboardKey::KK_TAB;
	_sKeyboardFKeyMap[EKeys::CapsLock] = EChromaSDKKeyboardKey::KK_CAPSLOCK;
	_sKeyboardFKeyMap[EKeys::BackSpace] = EChromaSDKKeyboardKey::KK_BACKSPACE;
	_sKeyboardFKeyMap[EKeys::Enter] = EChromaSDKKeyboardKey::KK_ENTER;
	_sKeyboardFKeyMap[EKeys::LeftControl] = EChromaSDKKeyboardKey::KK_LCTRL;
	//_sKeyboardFKeyMap[EKeys::LeftCommand] = EChromaSDKKeyboardKey::KK_LWIN;
	_sKeyboardFKeyMap[EKeys::LeftAlt] = EChromaSDKKeyboardKey::KK_LALT;
	_sKeyboardFKeyMap[EKeys::SpaceBar] = EChromaSDKKeyboardKey::KK_SPACE;
	_sKeyboardFKeyMap[EKeys::RightAlt] = EChromaSDKKeyboardKey::KK_RALT;
	//_sKeyboardFKeyMap[EKeys::Function] = EChromaSDKKeyboardKey::KK_FN;
	//_sKeyboardFKeyMap[EKeys::RightMenu] = EChromaSDKKeyboardKey::KK_RMENU;
	_sKeyboardFKeyMap[EKeys::RightControl] = EChromaSDKKeyboardKey::KK_RCTRL;
	_sKeyboardFKeyMap[EKeys::LeftShift] = EChromaSDKKeyboardKey::KK_LSHIFT;
	_sKeyboardFKeyMap[EKeys::RightShift] = EChromaSDKKeyboardKey::KK_RSHIFT;
	//_sKeyboardFKeyMap[EKeys::Macro1] = EChromaSDKKeyboardKey::KK_MACRO1;
	//_sKeyboardFKeyMap[EKeys::Macro2] = EChromaSDKKeyboardKey::KK_MACRO2;
	//_sKeyboardFKeyMap[EKeys::Macro3] = EChromaSDKKeyboardKey::KK_MACRO3;
	//_sKeyboardFKeyMap[EKeys::Macro4] = EChromaSDKKeyboardKey::KK_MACRO4;
	//_sKeyboardFKeyMap[EKeys::Macro5] = EChromaSDKKeyboardKey::KK_MACRO5;
	_sKeyboardFKeyMap[EKeys::Tilde] = EChromaSDKKeyboardKey::KK_OEM_1; //~
	_sKeyboardFKeyMap[EKeys::Subtract] = EChromaSDKKeyboardKey::KK_OEM_2; //-
	_sKeyboardFKeyMap[EKeys::Add] = EChromaSDKKeyboardKey::KK_OEM_3; //+
	_sKeyboardFKeyMap[EKeys::LeftBracket] = EChromaSDKKeyboardKey::KK_OEM_4; //[
	_sKeyboardFKeyMap[EKeys::RightBracket] = EChromaSDKKeyboardKey::KK_OEM_5; //]
	_sKeyboardFKeyMap[EKeys::Backslash] = EChromaSDKKeyboardKey::KK_OEM_6; /* \ */
	_sKeyboardFKeyMap[EKeys::Semicolon] = EChromaSDKKeyboardKey::KK_OEM_7; //;
	_sKeyboardFKeyMap[EKeys::Quote] = EChromaSDKKeyboardKey::KK_OEM_8; //'
	_sKeyboardFKeyMap[EKeys::Comma] = EChromaSDKKeyboardKey::KK_OEM_9; //,
	_sKeyboardFKeyMap[EKeys::Period] = EChromaSDKKeyboardKey::KK_OEM_10; //.
	_sKeyboardFKeyMap[EKeys::Slash] = EChromaSDKKeyboardKey::KK_OEM_11; ///
	// keyboard mapping
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_ESC] = Keyboard::RZKEY::RZKEY_ESC;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F1] = Keyboard::RZKEY::RZKEY_F1;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F2] = Keyboard::RZKEY::RZKEY_F2;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F3] = Keyboard::RZKEY::RZKEY_F3;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F4] = Keyboard::RZKEY::RZKEY_F4;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F5] = Keyboard::RZKEY::RZKEY_F5;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F6] = Keyboard::RZKEY::RZKEY_F6;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F7] = Keyboard::RZKEY::RZKEY_F7;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F8] = Keyboard::RZKEY::RZKEY_F8;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F9] = Keyboard::RZKEY::RZKEY_F9;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F10] = Keyboard::RZKEY::RZKEY_F10;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F11] = Keyboard::RZKEY::RZKEY_F11;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F12] = Keyboard::RZKEY::RZKEY_F12;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_1] = Keyboard::RZKEY::RZKEY_1;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_2] = Keyboard::RZKEY::RZKEY_2;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_3] = Keyboard::RZKEY::RZKEY_3;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_4] = Keyboard::RZKEY::RZKEY_4;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_5] = Keyboard::RZKEY::RZKEY_5;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_6] = Keyboard::RZKEY::RZKEY_6;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_7] = Keyboard::RZKEY::RZKEY_7;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_8] = Keyboard::RZKEY::RZKEY_8;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_9] = Keyboard::RZKEY::RZKEY_9;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_0] = Keyboard::RZKEY::RZKEY_0;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_A] = Keyboard::RZKEY::RZKEY_A;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_B] = Keyboard::RZKEY::RZKEY_B;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_C] = Keyboard::RZKEY::RZKEY_C;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_D] = Keyboard::RZKEY::RZKEY_D;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_E] = Keyboard::RZKEY::RZKEY_E;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_F] = Keyboard::RZKEY::RZKEY_F;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_G] = Keyboard::RZKEY::RZKEY_G;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_H] = Keyboard::RZKEY::RZKEY_H;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_I] = Keyboard::RZKEY::RZKEY_I;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_J] = Keyboard::RZKEY::RZKEY_J;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_K] = Keyboard::RZKEY::RZKEY_K;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_L] = Keyboard::RZKEY::RZKEY_L;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_M] = Keyboard::RZKEY::RZKEY_M;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_N] = Keyboard::RZKEY::RZKEY_N;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_O] = Keyboard::RZKEY::RZKEY_O;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_P] = Keyboard::RZKEY::RZKEY_P;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_Q] = Keyboard::RZKEY::RZKEY_Q;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_R] = Keyboard::RZKEY::RZKEY_R;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_S] = Keyboard::RZKEY::RZKEY_S;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_T] = Keyboard::RZKEY::RZKEY_T;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_U] = Keyboard::RZKEY::RZKEY_U;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_V] = Keyboard::RZKEY::RZKEY_V;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_W] = Keyboard::RZKEY::RZKEY_W;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_X] = Keyboard::RZKEY::RZKEY_X;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_Y] = Keyboard::RZKEY::RZKEY_Y;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_Z] = Keyboard::RZKEY::RZKEY_Z;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMLOCK] = Keyboard::RZKEY::RZKEY_NUMLOCK;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD0] = Keyboard::RZKEY::RZKEY_NUMPAD0;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD1] = Keyboard::RZKEY::RZKEY_NUMPAD1;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD2] = Keyboard::RZKEY::RZKEY_NUMPAD2;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD3] = Keyboard::RZKEY::RZKEY_NUMPAD3;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD4] = Keyboard::RZKEY::RZKEY_NUMPAD4;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD5] = Keyboard::RZKEY::RZKEY_NUMPAD5;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD6] = Keyboard::RZKEY::RZKEY_NUMPAD6;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD7] = Keyboard::RZKEY::RZKEY_NUMPAD7;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD8] = Keyboard::RZKEY::RZKEY_NUMPAD8;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD9] = Keyboard::RZKEY::RZKEY_NUMPAD9;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD_DIVIDE] = Keyboard::RZKEY::RZKEY_NUMPAD_DIVIDE;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD_MULTIPLY] = Keyboard::RZKEY::RZKEY_NUMPAD_MULTIPLY;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD_SUBTRACT] = Keyboard::RZKEY::RZKEY_NUMPAD_SUBTRACT;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD_ADD] = Keyboard::RZKEY::RZKEY_NUMPAD_ADD;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD_ENTER] = Keyboard::RZKEY::RZKEY_NUMPAD_ENTER;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_NUMPAD_DECIMAL] = Keyboard::RZKEY::RZKEY_NUMPAD_DECIMAL;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_PRINTSCREEN] = Keyboard::RZKEY::RZKEY_PRINTSCREEN;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_SCROLL] = Keyboard::RZKEY::RZKEY_SCROLL;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_PAUSE] = Keyboard::RZKEY::RZKEY_PAUSE;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_INSERT] = Keyboard::RZKEY::RZKEY_INSERT;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_HOME] = Keyboard::RZKEY::RZKEY_HOME;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_PAGEUP] = Keyboard::RZKEY::RZKEY_PAGEUP;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_DELETE] = Keyboard::RZKEY::RZKEY_DELETE;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_END] = Keyboard::RZKEY::RZKEY_END;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_PAGEDOWN] = Keyboard::RZKEY::RZKEY_PAGEDOWN;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_UP] = Keyboard::RZKEY::RZKEY_UP;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_LEFT] = Keyboard::RZKEY::RZKEY_LEFT;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_DOWN] = Keyboard::RZKEY::RZKEY_DOWN;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_RIGHT] = Keyboard::RZKEY::RZKEY_RIGHT;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_TAB] = Keyboard::RZKEY::RZKEY_TAB;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_CAPSLOCK] = Keyboard::RZKEY::RZKEY_CAPSLOCK;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_BACKSPACE] = Keyboard::RZKEY::RZKEY_BACKSPACE;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_ENTER] = Keyboard::RZKEY::RZKEY_ENTER;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_LCTRL] = Keyboard::RZKEY::RZKEY_LCTRL;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_LWIN] = Keyboard::RZKEY::RZKEY_LWIN;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_LALT] = Keyboard::RZKEY::RZKEY_LALT;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_SPACE] = Keyboard::RZKEY::RZKEY_SPACE;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_RALT] = Keyboard::RZKEY::RZKEY_RALT;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_FN] = Keyboard::RZKEY::RZKEY_FN;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_RMENU] = Keyboard::RZKEY::RZKEY_RMENU;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_RCTRL] = Keyboard::RZKEY::RZKEY_RCTRL;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_LSHIFT] = Keyboard::RZKEY::RZKEY_LSHIFT;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_RSHIFT] = Keyboard::RZKEY::RZKEY_RSHIFT;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_MACRO1] = Keyboard::RZKEY::RZKEY_MACRO1;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_MACRO2] = Keyboard::RZKEY::RZKEY_MACRO2;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_MACRO3] = Keyboard::RZKEY::RZKEY_MACRO3;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_MACRO4] = Keyboard::RZKEY::RZKEY_MACRO4;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_MACRO5] = Keyboard::RZKEY::RZKEY_MACRO5;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_1] = Keyboard::RZKEY::RZKEY_OEM_1;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_2] = Keyboard::RZKEY::RZKEY_OEM_2;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_3] = Keyboard::RZKEY::RZKEY_OEM_3;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_4] = Keyboard::RZKEY::RZKEY_OEM_4;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_5] = Keyboard::RZKEY::RZKEY_OEM_5;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_6] = Keyboard::RZKEY::RZKEY_OEM_6;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_7] = Keyboard::RZKEY::RZKEY_OEM_7;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_8] = Keyboard::RZKEY::RZKEY_OEM_8;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_9] = Keyboard::RZKEY::RZKEY_OEM_9;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_10] = Keyboard::RZKEY::RZKEY_OEM_10;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_OEM_11] = Keyboard::RZKEY::RZKEY_OEM_11;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_EUR_1] = Keyboard::RZKEY::RZKEY_EUR_1;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_EUR_2] = Keyboard::RZKEY::RZKEY_EUR_2;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_JPN_1] = Keyboard::RZKEY::RZKEY_JPN_1;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_JPN_2] = Keyboard::RZKEY::RZKEY_JPN_2;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_JPN_3] = Keyboard::RZKEY::RZKEY_JPN_3;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_JPN_4] = Keyboard::RZKEY::RZKEY_JPN_4;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_JPN_5] = Keyboard::RZKEY::RZKEY_JPN_5;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_KOR_1] = Keyboard::RZKEY::RZKEY_KOR_1;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_KOR_2] = Keyboard::RZKEY::RZKEY_KOR_2;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_KOR_3] = Keyboard::RZKEY::RZKEY_KOR_3;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_KOR_4] = Keyboard::RZKEY::RZKEY_KOR_4;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_KOR_5] = Keyboard::RZKEY::RZKEY_KOR_5;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_KOR_6] = Keyboard::RZKEY::RZKEY_KOR_6;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_KOR_7] = Keyboard::RZKEY::RZKEY_KOR_7;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_LOGO] = Keyboard::RZLED::RZLED_LOGO;
	_sKeyboardEnumMap[EChromaSDKKeyboardKey::KK_INVALID] = Keyboard::RZKEY::RZKEY_INVALID;

	// mouse mapping
	_sMouseEnumMap[EChromaSDKMouseLed::ML_SCROLLWHEEL] = Mouse::RZLED2::RZLED2_SCROLLWHEEL;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_LOGO] = Mouse::RZLED2::RZLED2_LOGO;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_BACKLIGHT] = Mouse::RZLED2::RZLED2_BACKLIGHT;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_LEFT_SIDE1] = Mouse::RZLED2::RZLED2_LEFT_SIDE1;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_LEFT_SIDE2] = Mouse::RZLED2::RZLED2_LEFT_SIDE2;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_LEFT_SIDE3] = Mouse::RZLED2::RZLED2_LEFT_SIDE3;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_LEFT_SIDE4] = Mouse::RZLED2::RZLED2_LEFT_SIDE4;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_LEFT_SIDE5] = Mouse::RZLED2::RZLED2_LEFT_SIDE5;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_LEFT_SIDE6] = Mouse::RZLED2::RZLED2_LEFT_SIDE6;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_LEFT_SIDE7] = Mouse::RZLED2::RZLED2_LEFT_SIDE7;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_BOTTOM1] = Mouse::RZLED2::RZLED2_BOTTOM1;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_BOTTOM2] = Mouse::RZLED2::RZLED2_BOTTOM2;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_BOTTOM3] = Mouse::RZLED2::RZLED2_BOTTOM3;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_BOTTOM4] = Mouse::RZLED2::RZLED2_BOTTOM4;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_BOTTOM5] = Mouse::RZLED2::RZLED2_BOTTOM5;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_RIGHT_SIDE1] = Mouse::RZLED2::RZLED2_RIGHT_SIDE1;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_RIGHT_SIDE2] = Mouse::RZLED2::RZLED2_RIGHT_SIDE2;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_RIGHT_SIDE3] = Mouse::RZLED2::RZLED2_RIGHT_SIDE3;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_RIGHT_SIDE4] = Mouse::RZLED2::RZLED2_RIGHT_SIDE4;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_RIGHT_SIDE5] = Mouse::RZLED2::RZLED2_RIGHT_SIDE5;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_RIGHT_SIDE6] = Mouse::RZLED2::RZLED2_RIGHT_SIDE6;
	_sMouseEnumMap[EChromaSDKMouseLed::ML_RIGHT_SIDE7] = Mouse::RZLED2::RZLED2_RIGHT_SIDE7;

	// Load module
	IChromaSDKPlugin::Get();
#endif
}

bool UChromaSDKPluginBPLibrary::IsPlatformWindows()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	return true;
#else
	return false;
#endif
}

int32 UChromaSDKPluginBPLibrary::GetMaxLeds(EChromaSDKDevice1DEnum::Type device)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	switch (device)
	{
	case EChromaSDKDevice1DEnum::DE_ChromaLink:
		return ChromaSDK::ChromaLink::MAX_LEDS;
	case EChromaSDKDevice1DEnum::DE_Headset:
		return ChromaSDK::Headset::MAX_LEDS;
	case EChromaSDKDevice1DEnum::DE_Mousepad:
		return ChromaSDK::Mousepad::MAX_LEDS;
	}
#endif
	return 0;
}

int UChromaSDKPluginBPLibrary::GetMaxRow(EChromaSDKDevice2DEnum::Type device)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	switch (device)
	{
	case EChromaSDKDevice2DEnum::DE_Keyboard:
		return ChromaSDK::Keyboard::MAX_ROW;
	case EChromaSDKDevice2DEnum::DE_KeyboardExtended:
		return ChromaSDK::Keyboard::v2::MAX_ROW;
	case EChromaSDKDevice2DEnum::DE_Keypad:
		return ChromaSDK::Keypad::MAX_ROW;
	case EChromaSDKDevice2DEnum::DE_Mouse:
		return ChromaSDK::Mouse::MAX_ROW;
	}
#endif
	return 0;
}

int UChromaSDKPluginBPLibrary::GetMaxColumn(EChromaSDKDevice2DEnum::Type device)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	switch (device)
	{
	case EChromaSDKDevice2DEnum::DE_Keyboard:
		return ChromaSDK::Keyboard::MAX_COLUMN;
	case EChromaSDKDevice2DEnum::DE_KeyboardExtended:
		return ChromaSDK::Keyboard::v2::MAX_COLUMN;
	case EChromaSDKDevice2DEnum::DE_Keypad:
		return ChromaSDK::Keypad::MAX_COLUMN;
	case EChromaSDKDevice2DEnum::DE_Mouse:
		return ChromaSDK::Mouse::MAX_COLUMN;
	}
#endif
	return 0;
}

FLinearColor UChromaSDKPluginBPLibrary::GetRGB(int32 red, int32 green, int32 blue)
{
	FLinearColor color = FLinearColor(red/255.0f, green/255.0f, blue/255.0f, 1.0f);
	return color;
}

int32 UChromaSDKPluginBPLibrary::GetBGRInt(int32 red, int32 green, int32 blue)
{
	return UtilGetRGB(red, green, blue);
}

int32 UChromaSDKPluginBPLibrary::ToBGR(const FLinearColor& colorParam)
{
	return UtilToBGR(colorParam);
}

FLinearColor UChromaSDKPluginBPLibrary::ToLinearColor(int32 colorParam)
{
	float red = (colorParam & 0xFF) / 255.0f;
	float green = ((colorParam & 0xFF00) >> 8) / 255.0f;
	float blue = ((colorParam & 0xFF0000) >> 16) / 255.0f;
	float alpha = ((colorParam & 0xFF000000) >> 24) / 255.0f;
	return FLinearColor(red, green, blue, alpha);
}

float UChromaSDKPluginBPLibrary::Lerp(float start, float end, float amt)
{
	return (1 - amt)*start + amt * end;
}

int32 UChromaSDKPluginBPLibrary::LerpColorBGR(int from, int to, float t)
{
	int red = floor(Lerp((from & 0xFF), (to & 0xFF), t));
	int green = floor(Lerp((from & 0xFF00) >> 8, (to & 0xFF00) >> 8, t));
	int blue = floor(Lerp((from & 0xFF0000) >> 16, (to & 0xFF0000) >> 16, t));
	int color = red | (green << 8) | (blue << 16);
	return color;
}

FLinearColor UChromaSDKPluginBPLibrary::LerpColor(FLinearColor colorParam1, FLinearColor colorParam2, float t)
{
	int color1 = ToBGR(colorParam1);
	int color2 = ToBGR(colorParam2);
	int color = LerpColorBGR(color1, color2, t);
	return ToLinearColor(color);
}

TArray<FLinearColor> UChromaSDKPluginBPLibrary::CreateColors1D(EChromaSDKDevice1DEnum::Type device)
{
	TArray<FLinearColor> colors = TArray<FLinearColor>();
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int elements = GetMaxLeds(device);
	for (int i = 0; i < elements; ++i)
	{
		FLinearColor color = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f);
		colors.Add(color);
	}
#endif
	return colors;
}

TArray<FChromaSDKColors> UChromaSDKPluginBPLibrary::CreateColors2D(EChromaSDKDevice2DEnum::Type device)
{
	TArray<FChromaSDKColors> result = TArray<FChromaSDKColors>();
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int maxRows = GetMaxRow(device);
	int maxColumns = GetMaxColumn(device);
	for (int i = 0; i < maxRows; ++i)
	{
		FChromaSDKColors row = FChromaSDKColors();
		for (int j = 0; j < maxColumns; ++j)
		{
			FLinearColor color = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f);
			row.Colors.Add(color);
		}
		result.Add(row);
	}
#endif
	return result;
}

// RANDOM

TArray<FLinearColor> UChromaSDKPluginBPLibrary::CreateRandomColors1D(EChromaSDKDevice1DEnum::Type device)
{
	TArray<FLinearColor> colors = TArray<FLinearColor>();
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int elements = GetMaxLeds(device);
	for (int i = 0; i < elements; ++i)
	{
		float red = FMath::FRandRange(0.0f, 1.0f);
		float green = FMath::FRandRange(0.0f, 1.0f);
		float blue = FMath::FRandRange(0.0f, 1.0f);
		float alpha = 1.0f;
		FLinearColor color = FLinearColor(red, green, blue, alpha);
		colors.Add(color);
	}
#endif
	return colors;
}

TArray<FChromaSDKColors> UChromaSDKPluginBPLibrary::CreateRandomColors2D(EChromaSDKDevice2DEnum::Type device)
{
	TArray<FChromaSDKColors> result = TArray<FChromaSDKColors>();
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int maxRows = GetMaxRow(device);
	int maxColumns = GetMaxColumn(device);
	for (int i = 0; i < maxRows; ++i)
	{
		FChromaSDKColors row = FChromaSDKColors();
		for (int j = 0; j < maxColumns; ++j)
		{
			float red = FMath::FRandRange(0.0f, 1.0f);
			float green = FMath::FRandRange(0.0f, 1.0f);
			float blue = FMath::FRandRange(0.0f, 1.0f);
			float alpha = 1.0f;
			FLinearColor color = FLinearColor(red, green, blue, alpha);
			row.Colors.Add(color);
		}
		result.Add(row);
	}
#endif
	return result;
}

// RANDOM BLACK AND WHITE

TArray<FLinearColor> UChromaSDKPluginBPLibrary::CreateRandomColorsBlackAndWhite1D(EChromaSDKDevice1DEnum::Type device)
{
	TArray<FLinearColor> colors = TArray<FLinearColor>();
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int elements = GetMaxLeds(device);
	for (int i = 0; i < elements; ++i)
	{
		float gray = FMath::FRandRange(0.0f, 1.0f);
		float alpha = 1.0f;
		FLinearColor color = FLinearColor(gray, gray, gray, alpha);
		colors.Add(color);
	}
#endif
	return colors;
}

TArray<FChromaSDKColors> UChromaSDKPluginBPLibrary::CreateRandomColorsBlackAndWhite2D(EChromaSDKDevice2DEnum::Type device)
{
	TArray<FChromaSDKColors> result = TArray<FChromaSDKColors>();
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int maxRows = GetMaxRow(device);
	int maxColumns = GetMaxColumn(device);
	for (int i = 0; i < maxRows; ++i)
	{
		FChromaSDKColors row = FChromaSDKColors();
		for (int j = 0; j < maxColumns; ++j)
		{
			float gray = FMath::FRandRange(0.0f, 1.0f);
			float alpha = 1.0f;
			FLinearColor color = FLinearColor(gray, gray, gray, alpha);
			row.Colors.Add(color);
		}
		result.Add(row);
	}
#endif
	return result;
}

void UChromaSDKPluginBPLibrary::SetKeyboardKeyColor(EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam, TArray<FChromaSDKColors>& colors)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int maxRow = ChromaSDK::Keyboard::MAX_ROW;
	int maxColumn = ChromaSDK::Keyboard::MAX_COLUMN;
	if (maxRow != colors.Num() ||
		colors.Num() == 0 ||
		maxColumn != colors[0].Colors.Num())
	{
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::SetKeyboardKeyColor Array size mismatch row: %d==%d column: %d==%d!"),
			maxRow,
			colors.Num(),
			maxColumn,
			colors.Num() > 0 ? colors[0].Colors.Num() : 0);
		return;
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		colors[HIBYTE(rzkey)].Colors[LOBYTE(rzkey)] = colorParam;
	}
#endif
}

FLinearColor UChromaSDKPluginBPLibrary::GetKeyboardKeyColor(EChromaSDKKeyboardKey::Type key, TArray<FChromaSDKColors>& colors)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int maxRow = ChromaSDK::Keyboard::MAX_ROW;
	int maxColumn = ChromaSDK::Keyboard::MAX_COLUMN;
	if (maxRow != colors.Num() ||
		colors.Num() == 0 ||
		maxColumn != colors[0].Colors.Num())
	{
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::GetKeyboardKeyColor Array size mismatch row: %d==%d column: %d==%d!"),
			maxRow,
			colors.Num(),
			maxColumn,
			colors.Num() > 0 ? colors[0].Colors.Num() : 0);
		return FLinearColor(0, 0, 0, 0);
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		return colors[HIBYTE(rzkey)].Colors[LOBYTE(rzkey)];
	}
#endif
	return FLinearColor(0, 0, 0, 0);
}

void UChromaSDKPluginBPLibrary::SetMouseLedColor(EChromaSDKMouseLed::Type led, const FLinearColor& colorParam, TArray<FChromaSDKColors>& colors)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int maxRow = ChromaSDK::Mouse::MAX_ROW;
	int maxColumn = ChromaSDK::Mouse::MAX_COLUMN;
	if (maxRow != colors.Num() ||
		colors.Num() == 0 ||
		maxColumn != colors[0].Colors.Num())
	{
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::SetMouseLedColor Array size mismatch row: %d==%d column: %d==%d!"),
			maxRow,
			colors.Num(),
			maxColumn,
			colors.Num() > 0 ? colors[0].Colors.Num() : 0);
		return;
	}

	ChromaSDK::Mouse::RZLED2 rzled = _sMouseEnumMap[led];
	colors[HIBYTE(rzled)].Colors[LOBYTE(rzled)] = colorParam;
#endif
}

FLinearColor UChromaSDKPluginBPLibrary::GetMouseLedColor(EChromaSDKMouseLed::Type led, TArray<FChromaSDKColors>& colors)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	int maxRow = ChromaSDK::Mouse::MAX_ROW;
	int maxColumn = ChromaSDK::Mouse::MAX_COLUMN;
	if (maxRow != colors.Num() ||
		colors.Num() == 0 ||
		maxColumn != colors[0].Colors.Num())
	{
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::SetMouseLedColor Array size mismatch row: %d==%d column: %d==%d!"),
			maxRow,
			colors.Num(),
			maxColumn,
			colors.Num() > 0 ? colors[0].Colors.Num() : 0);
		return FLinearColor(0, 0, 0, 0);
	}

	ChromaSDK::Mouse::RZLED2 rzled = _sMouseEnumMap[led];
	return colors[HIBYTE(rzled)].Colors[LOBYTE(rzled)];
#endif
	return FLinearColor(0, 0, 0, 0);
}

bool UChromaSDKPluginBPLibrary::IsInitialized()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	return _sInitialized;
#else
	return false;
#endif
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKInit()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!ChromaAnimationAPI::GetIsInitializedAPI())
	{
		return -1;
	}
	if (!_sInitialized)
	{
		// Init the SDK
		long result = ChromaAnimationAPI::Init();
		if (result == RZRESULT_SUCCESS)
		{
			_sInitialized = true;
		}
		return result;
	}
	else
	{
		return -1;
	}
#else
	return -1;
#endif
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKInitSDK(const FChromaSDKAppInfoType& appInfo)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!ChromaAnimationAPI::GetIsInitializedAPI())
	{
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary: API is not initialized!"));
		return -1;
	}
	if (!_sInitialized)
	{
		ChromaSDK::APPINFOTYPE coreAppInfo = {};

		wstring title = TCHAR_TO_WCHAR(*appInfo.Title);
		_tcscpy_s(coreAppInfo.Title, 256, title.c_str());

		wstring desc = TCHAR_TO_WCHAR(*appInfo.Description);
		_tcscpy_s(coreAppInfo.Description, 1024, desc.c_str());

		wstring name = TCHAR_TO_WCHAR(*appInfo.Author_Name);
		_tcscpy_s(coreAppInfo.Author.Name, 256, name.c_str());

		wstring contact = TCHAR_TO_WCHAR(*appInfo.Author_Contact);
		_tcscpy_s(coreAppInfo.Author.Contact, 256, contact.c_str());

		//appInfo.SupportedDevice = 
		//    0x01 | // Keyboards
		//    0x02 | // Mice
		//    0x04 | // Headset
		//    0x08 | // Mousepads
		//    0x10 | // Keypads
		//    0x20   // ChromaLink devices
		//    ;
		coreAppInfo.SupportedDevice = appInfo.SupportedDevice;
		coreAppInfo.Category = appInfo.Category;

		// Init the SDK
		long result = ChromaAnimationAPI::InitSDK(&coreAppInfo);

		if (result == RZRESULT_SUCCESS)
		{
			_sInitialized = true;
		}

		return result;
	}
	else
	{
		return -1;
	}
#else
	return -1;
#endif
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKUnInit()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!ChromaAnimationAPI::GetIsInitializedAPI())
	{
		return -1;
	}
	// Stop all animations
	// UnInit the SDK
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("UChromaSDKPluginBPLibrary:: Uninit"));
	if (_sInitialized)
	{
		RZRESULT result = ChromaAnimationAPI::Uninit();
		_sInitialized = false;
		return result;
	}
	else
	{
		return -1;
	}
#else
	return -1;
#endif
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectNone(EChromaSDKDeviceEnum::Type device)
{
	FChromaSDKEffectResult data = FChromaSDKEffectResult();

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

	if (!IsInitialized())
	{
		return data;
	}

	RZRESULT result = 0;
	RZEFFECTID effectId = RZEFFECTID();
	switch (device)
	{
	case EChromaSDKDeviceEnum::DE_ChromaLink:
		result = ChromaAnimationAPI::CoreCreateChromaLinkEffect(ChromaSDK::ChromaLink::CHROMA_NONE, NULL, &effectId);
		break;
	case EChromaSDKDeviceEnum::DE_Headset:
		result = ChromaAnimationAPI::CoreCreateHeadsetEffect(ChromaSDK::Headset::CHROMA_NONE, NULL, &effectId);
		break;
	case EChromaSDKDeviceEnum::DE_Keyboard:
		result = ChromaAnimationAPI::CoreCreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_NONE, NULL, &effectId);
		break;
	case EChromaSDKDeviceEnum::DE_Keypad:
		result = ChromaAnimationAPI::CoreCreateKeypadEffect(ChromaSDK::Keypad::CHROMA_NONE, NULL, &effectId);
		break;
	case EChromaSDKDeviceEnum::DE_Mouse:
		result = ChromaAnimationAPI::CoreCreateMouseEffect(ChromaSDK::Mouse::CHROMA_NONE, NULL, &effectId);
		break;
	case EChromaSDKDeviceEnum::DE_Mousepad:
		result = ChromaAnimationAPI::CoreCreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_NONE, NULL, &effectId);
		break;
	default:
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectNone Unsupported device used!"));
		break;
	}
	data.EffectId.Data = effectId;
	data.Result = result;

#endif

	return data;
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic(EChromaSDKDeviceEnum::Type device, const FLinearColor& colorParam)
{
	FChromaSDKEffectResult data = FChromaSDKEffectResult();

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

	if (!IsInitialized())
	{
		return data;
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("ChromaSDKPlugin:: Color R=%f G=%f B=%f"), color.R, color.G, color.B);	
	int red = colorParam.R * 255;
	int green = colorParam.G * 255;
	int blue = colorParam.B * 255;

	RZRESULT result = 0;
	RZEFFECTID effectId = RZEFFECTID();
	switch (device)
	{
	case EChromaSDKDeviceEnum::DE_ChromaLink:
	{
		ChromaSDK::ChromaLink::STATIC_EFFECT_TYPE pParam = {};
		pParam.Color = RGB(red, green, blue);
		result = ChromaAnimationAPI::CoreCreateChromaLinkEffect(ChromaSDK::ChromaLink::CHROMA_STATIC, &pParam, &effectId);
	}
	break;
	case EChromaSDKDeviceEnum::DE_Headset:
	{
		ChromaSDK::Headset::STATIC_EFFECT_TYPE pParam = {};
		pParam.Color = RGB(red, green, blue);
		result = ChromaAnimationAPI::CoreCreateHeadsetEffect(ChromaSDK::Headset::CHROMA_STATIC, &pParam, &effectId);
	}
	break;
	case EChromaSDKDeviceEnum::DE_Keyboard:
	{
		ChromaSDK::Keyboard::STATIC_EFFECT_TYPE pParam = {};
		pParam.Color = RGB(red, green, blue);
		result = ChromaAnimationAPI::CoreCreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_STATIC, &pParam, &effectId);
	}
	break;
	case EChromaSDKDeviceEnum::DE_Keypad:
	{
		ChromaSDK::Keypad::STATIC_EFFECT_TYPE pParam = {};
		pParam.Color = RGB(red, green, blue);
		result = ChromaAnimationAPI::CoreCreateKeypadEffect(ChromaSDK::Keypad::CHROMA_STATIC, &pParam, &effectId);
	}
	break;
	case EChromaSDKDeviceEnum::DE_Mouse:
	{
		ChromaSDK::Mouse::STATIC_EFFECT_TYPE pParam = {};
		pParam.Color = RGB(red, green, blue);
		pParam.LEDId = ChromaSDK::Mouse::RZLED_ALL;
		result = ChromaAnimationAPI::CoreCreateMouseEffect(ChromaSDK::Mouse::CHROMA_STATIC, &pParam, &effectId);
	}
	break;
	case EChromaSDKDeviceEnum::DE_Mousepad:
	{
		ChromaSDK::Mousepad::STATIC_EFFECT_TYPE pParam = {};
		pParam.Color = RGB(red, green, blue);
		result = ChromaAnimationAPI::CoreCreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_STATIC, &pParam, &effectId);
	}
	break;
	default:
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectStatic Unsupported device used!"));
		break;
	}
	data.EffectId.Data = effectId;
	data.Result = result;

#endif

	return data;
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom1D(EChromaSDKDevice1DEnum::Type device, const TArray<FLinearColor>& colors)
{
	FChromaSDKEffectResult data = FChromaSDKEffectResult();

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

	if (!IsInitialized())
	{
		return data;
	}

	RZRESULT result = 0;
	RZEFFECTID effectId = RZEFFECTID();
	int maxLeds = 0;
	switch (device)
	{
	case EChromaSDKDevice1DEnum::DE_ChromaLink:
	{
		maxLeds = ChromaSDK::ChromaLink::MAX_LEDS;
		if (maxLeds != colors.Num())
		{
			UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom1D Array size mismatch elements: %d==%d!"),
				maxLeds,
				colors.Num());
			break;
		}
		ChromaSDK::ChromaLink::CUSTOM_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxLeds; i++)
		{
			const FLinearColor& color = colors[i];
			int red = color.R * 255;
			int green = color.G * 255;
			int blue = color.B * 255;
			pParam.Color[i] = RGB(red, green, blue);
		}
		result = ChromaAnimationAPI::CoreCreateChromaLinkEffect(ChromaSDK::ChromaLink::CHROMA_CUSTOM, &pParam, &effectId);
	}
	break;
	case EChromaSDKDevice1DEnum::DE_Headset:
	{
		maxLeds = ChromaSDK::Headset::MAX_LEDS;
		if (maxLeds != colors.Num())
		{
			UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom1D Array size mismatch elements: %d==%d!"),
				maxLeds,
				colors.Num());
			break;
		}
		ChromaSDK::Headset::CUSTOM_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxLeds; i++)
		{
			const FLinearColor& color = colors[i];
			int red = color.R * 255;
			int green = color.G * 255;
			int blue = color.B * 255;
			pParam.Color[i] = RGB(red, green, blue);
		}
		result = ChromaAnimationAPI::CoreCreateHeadsetEffect(ChromaSDK::Headset::CHROMA_CUSTOM, &pParam, &effectId);
	}
	break;
	case EChromaSDKDevice1DEnum::DE_Mousepad:
	{
		maxLeds = ChromaSDK::Mousepad::MAX_LEDS;
		if (maxLeds != colors.Num())
		{
			UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom1D Array size mismatch elements: %d==%d!"),
				maxLeds,
				colors.Num());
			break;
		}
		ChromaSDK::Mousepad::CUSTOM_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxLeds; i++)
		{
			const FLinearColor& color = colors[i];
			int red = color.R * 255;
			int green = color.G * 255;
			int blue = color.B * 255;
			pParam.Color[i] = RGB(red, green, blue);
		}
		result = ChromaAnimationAPI::CoreCreateMousepadEffect(ChromaSDK::Mousepad::CHROMA_CUSTOM, &pParam, &effectId);
	}
	break;
	default:
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom1D Unsupported device used!"));
		break;
	}
	data.EffectId.Data = effectId;
	data.Result = result;

#endif

	return data;
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom2D(EChromaSDKDevice2DEnum::Type device, const TArray<FChromaSDKColors>& colors)
{
	FChromaSDKEffectResult data = FChromaSDKEffectResult();

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

	if (!IsInitialized())
	{
		return data;
	}

	RZRESULT result = 0;
	RZEFFECTID effectId = RZEFFECTID();
	int maxRow = 0;
	int maxColumn = 0;
	switch (device)
	{
	case EChromaSDKDevice2DEnum::DE_Keyboard:
	{
		maxRow = ChromaSDK::Keyboard::MAX_ROW;
		maxColumn = ChromaSDK::Keyboard::MAX_COLUMN;
		if (maxRow != colors.Num() ||
			(colors.Num() > 0 &&
			maxColumn != colors[0].Colors.Num()))
		{
			UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom2D Array size mismatch row: %d==%d column: %d==%d!"),
				maxRow,
				colors.Num(),
				maxColumn,
				colors.Num() > 0 ? colors[0].Colors.Num() : 0);
			break;
		}
		ChromaSDK::Keyboard::CUSTOM_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxRow; i++)
		{
			const FChromaSDKColors& row = colors[i];
			for (int j = 0; j < maxColumn; j++)
			{
				const FLinearColor& color = row.Colors[j];
				int red = color.R * 255;
				int green = color.G * 255;
				int blue = color.B * 255;
				pParam.Color[i][j] = RGB(red, green, blue);
			}
		}
		result = ChromaAnimationAPI::CoreCreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM, &pParam, &effectId);
	}
	break;
	case EChromaSDKDevice2DEnum::DE_Keypad:
	{
		maxRow = ChromaSDK::Keypad::MAX_ROW;
		maxColumn = ChromaSDK::Keypad::MAX_COLUMN;
		if (maxRow != colors.Num() ||
			(colors.Num() > 0 &&
			maxColumn != colors[0].Colors.Num()))
		{
			UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom2D Array size mismatch row: %d==%d column: %d==%d!"),
				maxRow,
				colors.Num(),
				maxColumn,
				colors.Num() > 0 ? colors[0].Colors.Num() : 0);
			break;
		}
		ChromaSDK::Keypad::CUSTOM_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxRow; i++)
		{
			const FChromaSDKColors& row = colors[i];
			for (int j = 0; j < maxColumn; j++)
			{
				const FLinearColor& color = row.Colors[j];
				int red = color.R * 255;
				int green = color.G * 255;
				int blue = color.B * 255;
				pParam.Color[i][j] = RGB(red, green, blue);
			}
		}
		result = ChromaAnimationAPI::CoreCreateKeypadEffect(ChromaSDK::Keypad::CHROMA_CUSTOM, &pParam, &effectId);
	}
	break;
	case EChromaSDKDevice2DEnum::DE_Mouse:
	{
		maxRow = ChromaSDK::Mouse::MAX_ROW;
		maxColumn = ChromaSDK::Mouse::MAX_COLUMN;
		if (maxRow != colors.Num() ||
			(colors.Num() > 0 &&
			maxColumn != colors[0].Colors.Num()))
		{
			UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom2D Array size mismatch row: %d==%d column: %d==%d!"),
				maxRow,
				colors.Num(),
				maxColumn,
				colors.Num() > 0 ? colors[0].Colors.Num() : 0);
			break;
		}
		ChromaSDK::Mouse::CUSTOM_EFFECT_TYPE2 pParam = {};
		for (int i = 0; i < maxRow; i++)
		{
			const FChromaSDKColors& row = colors[i];
			for (int j = 0; j < maxColumn; j++)
			{
				const FLinearColor& color = row.Colors[j];
				int red = color.R * 255;
				int green = color.G * 255;
				int blue = color.B * 255;
				pParam.Color[i][j] = RGB(red, green, blue);
			}
		}
		result = ChromaAnimationAPI::CoreCreateMouseEffect(ChromaSDK::Mouse::CHROMA_CUSTOM2, &pParam, &effectId);
	}
	break;
	default:
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectCustom2D Unsupported device used!"));
		break;
	}
	data.EffectId.Data = effectId;
	data.Result = result;

#endif

	return data;
}

FChromaSDKEffectResult UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectKeyboardCustom2D(const TArray<FChromaSDKColors>& colors)
{
	FChromaSDKEffectResult data = FChromaSDKEffectResult();

#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

	if (!IsInitialized())
	{
		return data;
	}

	RZRESULT result = 0;
	RZEFFECTID effectId = RZEFFECTID();
	int maxRow = ChromaSDK::Keyboard::MAX_ROW;
	int maxColumn = ChromaSDK::Keyboard::MAX_COLUMN;

	if (maxRow != colors.Num() ||
		(colors.Num() > 0 &&
		maxColumn != colors[0].Colors.Num()))
	{
		UE_LOG(LogChromaBlueprintLibrary, Error, TEXT("UChromaSDKPluginBPLibrary::ChromaSDKCreateEffectKeyboardCustom2D Array size mismatch row: %d==%d column: %d==%d!"),
			maxRow,
			colors.Num(),
			maxColumn,
			colors.Num() > 0 ? colors[0].Colors.Num() : 0);
	}
	else
	{
		ChromaSDK::Keyboard::CUSTOM_KEY_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxRow; i++)
		{
			const FChromaSDKColors& row = colors[i];
			for (int j = 0; j < maxColumn; j++)
			{
				const FLinearColor& color = row.Colors[j];
				pParam.Key[i][j] = ToBGR(color);
			}
		}
		result = ChromaAnimationAPI::CoreCreateKeyboardEffect(ChromaSDK::Keyboard::CHROMA_CUSTOM_KEY, &pParam, &effectId);
	}
	
	data.EffectId.Data = effectId;
	data.Result = result;

#endif

	return data;
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKSetEffect(const FChromaSDKGuid& effectId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}
	return ChromaAnimationAPI::SetEffect(effectId);
#else
	return -1;
#endif
}

int32 UChromaSDKPluginBPLibrary::ChromaSDKDeleteEffect(const FChromaSDKGuid& effectId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}
	return ChromaAnimationAPI::DeleteEffect(effectId);
#else
	return -1;
#endif
}

int UChromaSDKPluginBPLibrary::GetAnimation(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	return ChromaAnimationAPI::GetAnimation(TCHAR_TO_WCHAR(*path));
#else
	return -1;
#endif
}

int UChromaSDKPluginBPLibrary::GetAnimationId(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	return ChromaAnimationAPI::GetAnimation(TCHAR_TO_WCHAR(*path));
#else
	return -1;
#endif
}

FString UChromaSDKPluginBPLibrary::GetAnimationName(const int animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return TEXT("");
	}
	FString result = ChromaAnimationAPI::GetAnimationName(animationId);
	return result;
#else
	return TEXT("");
#endif
}

void UChromaSDKPluginBPLibrary::LoadAnimation(const int animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}
	ChromaAnimationAPI::LoadAnimation(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::LoadAnimationName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::LoadAnimationName(TCHAR_TO_WCHAR(*path));
#endif
}

void UChromaSDKPluginBPLibrary::CloseAll()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}
	ChromaAnimationAPI::CloseAll();
#endif
}

void UChromaSDKPluginBPLibrary::CloseAnimation(const int animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}
	ChromaAnimationAPI::CloseAnimation(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::CloseAnimationName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::CloseAnimationName(TCHAR_TO_WCHAR(*path));
#endif
}

void UChromaSDKPluginBPLibrary::UnloadAnimation(const int animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}
	ChromaAnimationAPI::UnloadAnimation(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::UnloadAnimationName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::UnloadAnimationName(TCHAR_TO_WCHAR(*path));
#endif
}

void UChromaSDKPluginBPLibrary::PlayAnimation(const FString& animationName, bool loop)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("PlayAnimation: %s"), *path);
	ChromaAnimationAPI::PlayAnimationName(TCHAR_TO_WCHAR(*path), loop);
#endif
}

void UChromaSDKPluginBPLibrary::PlayAnimationName(const FString& animationName, bool loop)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("PlayAnimationName: %s"), *path);
	ChromaAnimationAPI::PlayAnimationName(TCHAR_TO_WCHAR(*path), loop);
#endif
}

void UChromaSDKPluginBPLibrary::StopAnimation(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::StopAnimationName(TCHAR_TO_WCHAR(*path));
#endif
}

void UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::Type device)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	switch (device)
	{
	case EChromaSDKDeviceEnum::DE_ChromaLink:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_ChromaLink);
		break;
	case EChromaSDKDeviceEnum::DE_Headset:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_Headset);
		break;
	case EChromaSDKDeviceEnum::DE_Keyboard:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Keyboard);
		break;
	case EChromaSDKDeviceEnum::DE_Keypad:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Keypad);
		break;
	case EChromaSDKDeviceEnum::DE_Mouse:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Mouse);
		break;
	case EChromaSDKDeviceEnum::DE_Mousepad:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_Mousepad);
		break;
	}
#endif
}

void UChromaSDKPluginBPLibrary::StopAll()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	StopAnimationType(EChromaSDKDeviceEnum::DE_ChromaLink);
	StopAnimationType(EChromaSDKDeviceEnum::DE_Headset);
	StopAnimationType(EChromaSDKDeviceEnum::DE_Keyboard);
	StopAnimationType(EChromaSDKDeviceEnum::DE_Keypad);
	StopAnimationType(EChromaSDKDeviceEnum::DE_Mouse);
	StopAnimationType(EChromaSDKDeviceEnum::DE_Mousepad);
#endif
}

void UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::Type device)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	StopAnimationType(device);

	FChromaSDKEffectResult result = ChromaSDKCreateEffectNone(device);
	if (result.Result == 0)
	{
		ChromaSDKSetEffect(result.EffectId);
		ChromaSDKDeleteEffect(result.EffectId);
	}
#endif
}

void UChromaSDKPluginBPLibrary::ClearAll()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	ClearAnimationType(EChromaSDKDeviceEnum::DE_ChromaLink);
	ClearAnimationType(EChromaSDKDeviceEnum::DE_Headset);
	ClearAnimationType(EChromaSDKDeviceEnum::DE_Keyboard);
	ClearAnimationType(EChromaSDKDeviceEnum::DE_Keypad);
	ClearAnimationType(EChromaSDKDeviceEnum::DE_Mouse);
	ClearAnimationType(EChromaSDKDeviceEnum::DE_Mousepad);
#endif
}

int UChromaSDKPluginBPLibrary::GetAnimationCount()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

	return ChromaAnimationAPI::GetAnimationCount();
#else
	return -1;
#endif
}

int UChromaSDKPluginBPLibrary::GetAnimationIdByIndex(int index)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

	return ChromaAnimationAPI::GetAnimationId(index);
#else
	return -1;
#endif
}

int UChromaSDKPluginBPLibrary::GetPlayingAnimationCount()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

	return ChromaAnimationAPI::GetPlayingAnimationCount();
#else
	return -1;
#endif
}

int UChromaSDKPluginBPLibrary::GetPlayingAnimationId(int index)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

	return ChromaAnimationAPI::GetPlayingAnimationId(index);
#else
	return -1;
#endif
}

bool UChromaSDKPluginBPLibrary::IsAnimationPlaying(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return false;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("IsAnimationPlaying: %s"), *path);
	return ChromaAnimationAPI::IsPlayingName(TCHAR_TO_WCHAR(*path));
#else
	return false;
#endif
}

bool UChromaSDKPluginBPLibrary::IsAnimationTypePlaying(EChromaSDKDeviceEnum::Type device)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return false;
	}

	switch (device)
	{
	case EChromaSDKDeviceEnum::DE_ChromaLink:
		return ChromaAnimationAPI::IsPlayingType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_ChromaLink);
	case EChromaSDKDeviceEnum::DE_Headset:
		return ChromaAnimationAPI::IsPlayingType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_Headset);
	case EChromaSDKDeviceEnum::DE_Keyboard:
		return ChromaAnimationAPI::IsPlayingType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Keyboard);
	case EChromaSDKDeviceEnum::DE_Keypad:
		return ChromaAnimationAPI::IsPlayingType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Keypad);
	case EChromaSDKDeviceEnum::DE_Mouse:
		return ChromaAnimationAPI::IsPlayingType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Mouse);
	case EChromaSDKDeviceEnum::DE_Mousepad:
		return ChromaAnimationAPI::IsPlayingType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_Mousepad);
	}
#endif
	return false;
}

void UChromaSDKPluginBPLibrary::PlayAnimations(const TArray<FString>& animationNames, bool loop)
{
	for (int i = 0; i < animationNames.Num(); ++i)
	{
		PlayAnimation(animationNames[i], loop);
	}
}

void UChromaSDKPluginBPLibrary::StopAnimations(const TArray<FString>& animationNames)
{
	for (int i = 0; i < animationNames.Num(); ++i)
	{
		StopAnimation(animationNames[i]);
	}
}

void UChromaSDKPluginBPLibrary::PlayAnimationComposite(const FString& animationName, bool loop)
{
	PlayAnimation(animationName + "_ChromaLink", loop);
	PlayAnimation(animationName + "_Headset", loop);
	PlayAnimation(animationName + "_Keyboard", loop);
	PlayAnimation(animationName + "_Keypad", loop);
	PlayAnimation(animationName + "_Mouse", loop);
	PlayAnimation(animationName + "_Mousepad", loop);
}

void UChromaSDKPluginBPLibrary::StopAnimationComposite(const FString& animationName)
{
	StopAnimation(animationName + "_ChromaLink");
	StopAnimation(animationName + "_Headset");
	StopAnimation(animationName + "_Keyboard");
	StopAnimation(animationName + "_Keypad");
	StopAnimation(animationName + "_Mouse");
	StopAnimation(animationName + "_Mousepad");
}

FLinearColor UChromaSDKPluginBPLibrary::GetKeyColor(int animationId, int frameIndex, EChromaSDKKeyboardKey::Type key)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return ToLinearColor(0);
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		int color = ChromaAnimationAPI::GetKeyColor(animationId, frameIndex, rzkey);
		return ToLinearColor(color);
	}
#endif
	return ToLinearColor(0);
}

FLinearColor UChromaSDKPluginBPLibrary::GetKeyColorName(const FString& animationName, const int frameIndex, EChromaSDKKeyboardKey::Type key)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return ToLinearColor(0);
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		int color = ChromaAnimationAPI::GetKeyColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey);
		return ToLinearColor(color);
	}
#endif
	return ToLinearColor(0);
}


void UChromaSDKPluginBPLibrary::SetKeyColor(int animationId, int frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::SetKeyColor(animationId, frameIndex, rzkey, UtilToBGR(colorParam));
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeyColorName(const FString& animationName, const int frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::SetKeyColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey, UtilToBGR(colorParam));
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeyRowColumnColorName(const FString& animationName, const int32 frameIndex, const int32 row, const int32 column, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int rzkey = (row << 8) | column;
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::SetKeyColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey, UtilToBGR(colorParam));
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeyNonZeroColor(int animationId, int frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::SetKeyNonZeroColor(animationId, frameIndex, rzkey, UtilToBGR(colorParam));
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeyNonZeroColorName(const FString& animationName, const int frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::SetKeyNonZeroColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey, UtilToBGR(colorParam));
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeysColor(int animationId, int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int colorArg = UtilToBGR(colorParam);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyColor(animationId, frameIndex, rzkey, colorArg);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeysColorName(const FString& animationName, const int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int colorArg = UtilToBGR(colorParam);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey, colorArg);
		}
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeysColorRGB(int animationId, int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int colorArg = UtilGetRGB(red, green, blue);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyColor(animationId, frameIndex, rzkey, colorArg);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeysColorRGBName(const FString& animationName, const int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int colorArg = UtilGetRGB(red, green, blue);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey, colorArg);
		}
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeysNonZeroColor(int animationId, int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int colorArg = UtilToBGR(colorParam);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyNonZeroColor(animationId, frameIndex, rzkey, colorArg);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorName(const FString& animationName, const int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int colorArg = UtilToBGR(colorParam);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyNonZeroColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey, colorArg);
		}
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeyColorAllFrames(int animationId, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		int frameCount = ChromaAnimationAPI::GetFrameCount(animationId);
		int colorArg = UtilToBGR(colorParam);
		for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
		{
			ChromaAnimationAPI::SetKeyColor(animationId, frameIndex, rzkey, colorArg);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeyColorAllFramesName(const FString& animationName, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*path));
		int colorArg = UtilToBGR(colorParam);
		ChromaAnimationAPI::SetKeyColorAllFramesName(TCHAR_TO_WCHAR(*path), rzkey, colorArg);
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeyNonZeroColorAllFrames(int animationId, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		int frameCount = ChromaAnimationAPI::GetFrameCount(animationId);
		int colorArg = UtilToBGR(colorParam);
		for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
		{
			ChromaAnimationAPI::SetKeyNonZeroColor(animationId, frameIndex, rzkey, colorArg);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeyNonZeroColorAllFramesName(const FString& animationName, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*path));
		int colorArg = UtilToBGR(colorParam);
		for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
		{
			ChromaAnimationAPI::SetKeyNonZeroColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey, colorArg);
		}
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeysColorAllFrames(int animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(animationId);
	int colorArg = UtilToBGR(colorParam);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
			{
				ChromaAnimationAPI::SetKeyColor(animationId, frameIndex, rzkey, colorArg);
			}
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesName(const FString& animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*path));
	int colorArg = UtilToBGR(colorParam);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyColorAllFramesName(TCHAR_TO_WCHAR(*path), rzkey, colorArg);
		}
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesRGB(int animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(animationId);
	int colorArg = UtilGetRGB(red, green, blue);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyColorAllFrames(animationId, rzkey, colorArg);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesRGBName(const FString& animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*path));
	int colorArg = UtilGetRGB(red, green, blue);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::SetKeyColorAllFramesName(TCHAR_TO_WCHAR(*path), rzkey, colorArg);
		}
	}
#endif
}


void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorAllFrames(int animationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(animationId);
	int colorArg = UtilToBGR(colorParam);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
			{
				ChromaAnimationAPI::SetKeyNonZeroColor(animationId, frameIndex, rzkey, colorArg);
			}
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorAllFramesName(const FString& animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*path));
	int colorArg = UtilToBGR(colorParam);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
			{
				ChromaAnimationAPI::SetKeyNonZeroColorName(TCHAR_TO_WCHAR(*path), frameIndex, rzkey, colorArg);
			}
		}
	}
#endif
}


void UChromaSDKPluginBPLibrary::CopyKeyColor(int sourceAnimationId, int targetAnimationId, int frameIndex, EChromaSDKKeyboardKey::Type key)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::CopyKeyColor(sourceAnimationId, targetAnimationId, frameIndex, rzkey);
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, EChromaSDKKeyboardKey::Type key)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::CopyKeyColorName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, rzkey);
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyKeysColor(int sourceAnimationId, int targetAnimationId, int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::CopyKeyColor(sourceAnimationId, targetAnimationId, frameIndex, rzkey);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::CopyKeyColorName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, rzkey);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyKeysColorAllFrames(int sourceAnimationId, int targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(targetAnimationId);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
			{
				ChromaAnimationAPI::CopyKeyColor(sourceAnimationId, targetAnimationId, frameIndex, rzkey);
			}
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*targetPath));
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
			{
				ChromaAnimationAPI::CopyKeyColorName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, rzkey);
			}
		}
	}
#endif
}

// COPY ALL KEYS

void UChromaSDKPluginBPLibrary::CopyAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::CopyAllKeys(sourceAnimationId, targetAnimationId, frameIndex);
#endif
}

void UChromaSDKPluginBPLibrary::CopyAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameIndex)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex);
#endif
}

// NONZERO

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::CopyNonZeroAllKeys(sourceAnimationId, targetAnimationId, frameIndex);
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameIndex)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyNonZeroAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex);
#endif
}

// NONZERO ADD

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::AddNonZeroAllKeys(sourceAnimationId, targetAnimationId, frameIndex);
#endif
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameIndex)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::AddNonZeroAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex);
#endif
}

// NONZERO Subtract

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::SubtractNonZeroAllKeys(sourceAnimationId, targetAnimationId, frameIndex);
#endif
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameIndex)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::SubtractNonZeroAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex);
#endif
}

// NONZERO OFFSET

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 frameIndex, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::CopyNonZeroAllKeysOffset(sourceAnimationId, targetAnimationId, frameIndex, offset);
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameIndex, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyNonZeroAllKeysOffsetName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, offset);
#endif
}

// COPY ALL KEYS ALL FRAMES

void UChromaSDKPluginBPLibrary::CopyAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(sourceAnimationId);
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::CopyAllKeys(sourceAnimationId, targetAnimationId, frameIndex);
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*targetPath));
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::CopyAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex);
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeyColor(int sourceAnimationId, int targetAnimationId, int frameIndex, EChromaSDKKeyboardKey::Type key)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::CopyNonZeroKeyColor(sourceAnimationId, targetAnimationId, frameIndex, rzkey);
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeyColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, EChromaSDKKeyboardKey::Type key)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int rzkey = _sKeyboardEnumMap[key];
	if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
	{
		ChromaAnimationAPI::CopyNonZeroKeyColorName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, rzkey);
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeysColor(int sourceAnimationId, int targetAnimationId, int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::CopyNonZeroKeyColor(sourceAnimationId, targetAnimationId, frameIndex, rzkey);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeysColorName(const FString& sourceAnimationName, const FString& targetAnimationName, const int frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			ChromaAnimationAPI::CopyNonZeroKeyColorName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, rzkey);
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeysColorAllFrames(int sourceAnimationId, int targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(targetAnimationId);
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
			{
				ChromaAnimationAPI::CopyNonZeroKeyColor(sourceAnimationId, targetAnimationId, frameIndex, rzkey);
			}
		}
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroKeysColorAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*targetPath));
	for (int k = 0; k < keys.Num(); ++k)
	{
		EChromaSDKKeyboardKey::Type key = keys[k];
		int rzkey = _sKeyboardEnumMap[key];
		if (rzkey != ChromaSDK::Keyboard::RZKEY::RZKEY_INVALID)
		{
			for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
			{
				ChromaAnimationAPI::CopyNonZeroKeyColorName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, rzkey);
			}
		}
	}
#endif
}

// NONZERO

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(sourceAnimationId);
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::CopyNonZeroAllKeys(sourceAnimationId, targetAnimationId, frameIndex);
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*targetPath));
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::CopyNonZeroAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex);
	}
#endif
}

// NONZERO ADD

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(sourceAnimationId);
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::AddNonZeroAllKeys(sourceAnimationId, targetAnimationId, frameIndex);
	}
#endif
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*targetPath));
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::AddNonZeroAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex);
	}
#endif
}

// NONZERO SUBTRACT

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(sourceAnimationId);
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::SubtractNonZeroAllKeys(sourceAnimationId, targetAnimationId, frameIndex);
	}
#endif
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*targetPath));
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::SubtractNonZeroAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex);
	}
#endif
}

// NONZERO OFFSET

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(sourceAnimationId);
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::CopyNonZeroAllKeysOffset(sourceAnimationId, targetAnimationId, frameIndex, offset);
	}
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*targetPath));
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::CopyNonZeroAllKeysOffsetName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, offset);
	}
#endif
}

// NONZERO OFFSET ADD

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(sourceAnimationId);
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::AddNonZeroAllKeysOffset(sourceAnimationId, targetAnimationId, frameIndex, offset);
	}
#endif
}

void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*sourcePath));
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::AddNonZeroAllKeysOffsetName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, offset);
	}
#endif
}

// NONZERO OFFSET SUBTRACT

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int frameCount = ChromaAnimationAPI::GetFrameCount(sourceAnimationId);
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::SubtractNonZeroAllKeysOffset(sourceAnimationId, targetAnimationId, frameIndex, offset);
	}
#endif
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	int frameCount = ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*targetPath));
	for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex)
	{
		ChromaAnimationAPI::SubtractNonZeroAllKeysOffsetName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameIndex, offset);
	}
#endif
}

// FILL COLOR

void UChromaSDKPluginBPLibrary::FillColor(int animationId, int frameId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillColor(animationId, frameId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillColorName(const FString& animationName, int frameId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::FillColorName(TCHAR_TO_WCHAR(*path), frameId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillColorRGB(int animationId, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillColorRGB(animationId, frameId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::FillColorRGBName(const FString& animationName, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::FillColorRGBName(TCHAR_TO_WCHAR(*path), frameId, red, green, blue);
#endif
}


void UChromaSDKPluginBPLibrary::FillThresholdColorsRGB(int32 animationId, int32 frameId, int32 threshold, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillThresholdColorsRGB(animationId, frameId, threshold, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsRGBName(const FString& animationName, int32 frameId, int32 threshold, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::FillThresholdColorsRGBName(TCHAR_TO_WCHAR(*path), frameId, threshold, red, green, blue);
#endif
}


// NONZERO COLOR

void UChromaSDKPluginBPLibrary::FillNonZeroColor(int animationId, int frameId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillNonZeroColor(animationId, frameId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorName(const FString& animationName, int frameId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillNonZeroColorName: %s"), *path);
	ChromaAnimationAPI::FillNonZeroColorName(TCHAR_TO_WCHAR(*path), frameId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorRGB(int animationId, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillNonZeroColorRGB(animationId, frameId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorRGBName(const FString& animationName, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillNonZeroColorName: %s"), *path);
	ChromaAnimationAPI::FillNonZeroColorRGBName(TCHAR_TO_WCHAR(*path), frameId, red, green, blue);
#endif
}

// ZERO COLOR

void UChromaSDKPluginBPLibrary::FillZeroColor(int animationId, int frameId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillZeroColor(animationId, frameId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillZeroColorName(const FString& animationName, int frameId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillZeroColorName: %s"), *path);
	ChromaAnimationAPI::FillZeroColorName(TCHAR_TO_WCHAR(*path), frameId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillZeroColorRGB(int animationId, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillZeroColorRGB(animationId, frameId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::FillZeroColorRGBName(const FString& animationName, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillZeroColorName: %s"), *path);
	ChromaAnimationAPI::FillZeroColorRGBName(TCHAR_TO_WCHAR(*path), frameId, red, green, blue);
#endif
}


// FILL THRESHOLD COLORS ALL FRAMES

void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFrames(int animationId, int threshold, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillThresholdColorsAllFrames(animationId, threshold, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesName(const FString& animationName, int threshold, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillColorAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillThresholdColorsAllFramesName(TCHAR_TO_WCHAR(*path), threshold, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesRGB(int animationId, int threshold, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillThresholdColorsAllFramesRGB(animationId, threshold, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesRGBName(const FString& animationName, int threshold, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillColorAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillThresholdColorsAllFramesRGBName(TCHAR_TO_WCHAR(*path), threshold, red, green, blue);
#endif
}


// FILL COLOR ALL FRAMES

void UChromaSDKPluginBPLibrary::FillColorAllFrames(int animationId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillColorAllFrames(animationId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillColorAllFramesName(const FString& animationName, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillColorAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillColorAllFramesName(TCHAR_TO_WCHAR(*path), UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillColorAllFramesRGB(int animationId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillColorAllFramesRGB(animationId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::FillColorAllFramesRGBName(const FString& animationName, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillColorAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillColorAllFramesRGBName(TCHAR_TO_WCHAR(*path), red, green, blue);
#endif
}

// NONZERO COLOR

void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFrames(int animationId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillNonZeroColorAllFrames(animationId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesName(const FString& animationName, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillNonZeroColorAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillNonZeroColorAllFramesName(TCHAR_TO_WCHAR(*path), UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesRGB(int animationId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillNonZeroColorAllFramesRGB(animationId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesRGBName(const FString& animationName, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillNonZeroColorAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillNonZeroColorAllFramesRGBName(TCHAR_TO_WCHAR(*path), red, green, blue);
#endif
}

// ZERO COLOR

void UChromaSDKPluginBPLibrary::FillZeroColorAllFrames(int animationId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillZeroColorAllFrames(animationId, UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesName(const FString& animationName, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillNonZeroColorAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillZeroColorAllFramesName(TCHAR_TO_WCHAR(*path), UtilToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesRGB(int animationId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillZeroColorAllFramesRGB(animationId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesRGBName(const FString& animationName, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillNonZeroColorAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillZeroColorAllFramesRGBName(TCHAR_TO_WCHAR(*path), red, green, blue);
#endif
}


// FILL RANDOM COLORS

void UChromaSDKPluginBPLibrary::FillRandomColors(int32 animationId, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillRandomColors(animationId, frameId);
#endif
}

void UChromaSDKPluginBPLibrary::FillRandomColorsName(const FString& animationName, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillRandomColorsName: %s"), *path);
	ChromaAnimationAPI::FillRandomColorsName(TCHAR_TO_WCHAR(*path), frameId);
#endif
}


void UChromaSDKPluginBPLibrary::FillRandomColorsAllFrames(int32 animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillRandomColorsAllFrames(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::FillRandomColorsAllFramesName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillRandomColorsAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillRandomColorsAllFramesName(TCHAR_TO_WCHAR(*path));
#endif
}


// FILL RANDOM BLACK AND WHITE


void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhite(int32 animationId, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillRandomColorsBlackAndWhite(animationId, frameId);
#endif
}

void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteName(const FString& animationName, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillRandomColorsBlackAndWhiteName: %s"), *path);
	ChromaAnimationAPI::FillRandomColorsBlackAndWhiteName(TCHAR_TO_WCHAR(*path), frameId);
#endif
}


void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteAllFrames(int32 animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillRandomColorsBlackAndWhiteAllFrames(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteAllFramesName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("FillRandomColorsBlackAndWhiteAllFramesName: %s"), *path);
	ChromaAnimationAPI::FillRandomColorsBlackAndWhiteAllFramesName(TCHAR_TO_WCHAR(*path));
#endif
}


// OFFSET COLORS

void UChromaSDKPluginBPLibrary::OffsetColors(int animationId, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::OffsetColors(animationId, frameId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::OffsetColorsName(const FString& animationName, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("OffsetColorsName: %s"), *path);
	ChromaAnimationAPI::OffsetColorsName(TCHAR_TO_WCHAR(*path), frameId, red, green, blue);
#endif
}


void UChromaSDKPluginBPLibrary::OffsetColorsAllFrames(int animationId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::OffsetColorsAllFrames(animationId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::OffsetColorsAllFramesName(const FString& animationName, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("OffsetColorsAllFramesName: %s"), *path);
	ChromaAnimationAPI::OffsetColorsAllFramesName(TCHAR_TO_WCHAR(*path), red, green, blue);
#endif
}


void UChromaSDKPluginBPLibrary::OffsetNonZeroColors(int animationId, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::OffsetNonZeroColors(animationId, frameId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsName(const FString& animationName, int frameId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("OffsetNonZeroColorsName: %s"), *path);
	ChromaAnimationAPI::OffsetNonZeroColorsName(TCHAR_TO_WCHAR(*path), frameId, red, green, blue);
#endif
}


void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFrames(int animationId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::OffsetNonZeroColorsAllFrames(animationId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(const FString& animationName, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("OffsetNonZeroColorsAllFramesName: %s"), *path);
	ChromaAnimationAPI::OffsetNonZeroColorsAllFramesName(TCHAR_TO_WCHAR(*path), red, green, blue);
#endif
}


// MULTIPLY INTENSITY

void UChromaSDKPluginBPLibrary::MultiplyIntensity(int animationId, int frameId, float intensity)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::MultiplyIntensity(animationId, frameId, intensity);
#endif
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityName(const FString& animationName, int frameId, float intensity)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("MultiplyIntensityName: %s"), *path);
	ChromaAnimationAPI::MultiplyIntensityName(TCHAR_TO_WCHAR(*path), frameId, intensity);
#endif
}

// MULTIPLY INTENSITY RGB

void UChromaSDKPluginBPLibrary::MultiplyIntensityRGB(int32 animationId, int32 frameId, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::MultiplyIntensityRGB(animationId, frameId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityRGBName(const FString& animationName, int32 frameId, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("MultiplyIntensityName: %s"), *path);
	ChromaAnimationAPI::MultiplyIntensityRGBName(TCHAR_TO_WCHAR(*path), frameId, red, green, blue);
#endif
}


// MULTIPLY INTENSITY COLOR

void UChromaSDKPluginBPLibrary::MultiplyIntensityColor(int animationId, int frameId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int color = ToBGR(colorParam);
	ChromaAnimationAPI::MultiplyIntensityColor(animationId, frameId, color);
#endif
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityColorName(const FString& animationName, int frameId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("MultiplyIntensityName: %s"), *path);
	int color = ToBGR(colorParam);
	ChromaAnimationAPI::MultiplyIntensityColorName(TCHAR_TO_WCHAR(*path), frameId, color);
#endif
}


// MULTIPLY INTENSITY ALL FRAMES

void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFrames(int animationId, float intensity)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::MultiplyIntensityAllFrames(animationId, intensity);
#endif
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(const FString& animationName, float intensity)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("MultiplyIntensityAllFramesName: %s"), *path);
	ChromaAnimationAPI::MultiplyIntensityAllFramesName(TCHAR_TO_WCHAR(*path), intensity);
#endif
}


// MULTIPLY INTENSITY COLOR ALL FRAMES

void UChromaSDKPluginBPLibrary::MultiplyIntensityColorAllFrames(int animationId, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int color = ToBGR(colorParam);
	ChromaAnimationAPI::MultiplyIntensityColorAllFrames(animationId, color);
#endif
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityColorAllFramesName(const FString& animationName, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}
	
	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("MultiplyIntensityAllFramesName: %s"), *path);
	int color = ToBGR(colorParam);
	ChromaAnimationAPI::MultiplyIntensityColorAllFramesName(TCHAR_TO_WCHAR(*path), color);
#endif
}

// RGB

void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesRGB(int animationId, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::MultiplyIntensityAllFramesRGB(animationId, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesRGBName(const FString& animationName, int red, int green, int blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}
	
//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	//UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("MultiplyIntensityAllFramesRGBName: %s"), *path);
	ChromaAnimationAPI::MultiplyIntensityAllFramesRGBName(TCHAR_TO_WCHAR(*path), red, green, blue);
#endif
}


int UChromaSDKPluginBPLibrary::GetFrameCount(const int animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

	return ChromaAnimationAPI::GetFrameCount(animationId);
#else
	return -1;
#endif
}

int UChromaSDKPluginBPLibrary::GetFrameCountName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return 0;
	}
	
//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	return ChromaAnimationAPI::GetFrameCountName(TCHAR_TO_WCHAR(*path));
#else
	return 0;
#endif
}

void UChromaSDKPluginBPLibrary::SetChromaCustomFlagName(const FString& animationName, bool flag)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::SetChromaCustomFlagName(TCHAR_TO_WCHAR(*path), flag);
#endif
}

void UChromaSDKPluginBPLibrary::SetChromaCustomColorAllFramesName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::SetChromaCustomColorAllFramesName(TCHAR_TO_WCHAR(*path));
#endif
}


int32 UChromaSDKPluginBPLibrary::PreviewFrame(int32 animationId, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

	return ChromaAnimationAPI::PreviewFrame(animationId, frameId);
#else
	return -1;
#endif
}

void UChromaSDKPluginBPLibrary::PreviewFrameName(const FString& animationName, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::PreviewFrameName(TCHAR_TO_WCHAR(*path), frameId);
#endif
}


void UChromaSDKPluginBPLibrary::OverrideFrameDurationName(const FString& animationName, float duration)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::OverrideFrameDurationName(TCHAR_TO_WCHAR(*path), duration);
#endif
}

// MAKE FRAMES

void UChromaSDKPluginBPLibrary::MakeBlankFrames(int32 animationId, int32 frameCount, float duration, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::MakeBlankFrames(animationId, frameCount, duration, ToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesName(const FString& animationName, int32 frameCount, float duration, const FLinearColor& colorParam)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::MakeBlankFramesName(TCHAR_TO_WCHAR(*path), frameCount, duration, ToBGR(colorParam));
#endif
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRGB(int32 animationId, int32 frameCount, float duration, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::MakeBlankFramesRGB(animationId, frameCount, duration, red, green, blue);
#endif
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRGBName(const FString& animationName, int32 frameCount, float duration, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::MakeBlankFramesRGBName(TCHAR_TO_WCHAR(*path), frameCount, duration, red, green, blue);
#endif
}

// RANDOM

void UChromaSDKPluginBPLibrary::MakeBlankFramesRandom(int32 animationId, int32 frameCount, float duration)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::MakeBlankFramesRandom(animationId, frameCount, duration);
#endif
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomName(const FString& animationName, int32 frameCount, float duration)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::MakeBlankFramesRandomName(TCHAR_TO_WCHAR(*path), frameCount, duration);
#endif
}

// RANDOM BLACK AND WHITE

void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomBlackAndWhite(int32 animationId, int32 frameCount, float duration)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::MakeBlankFramesRandomBlackAndWhite(animationId, frameCount, duration);
#endif
}

void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomBlackAndWhiteName(const FString& animationName, int32 frameCount, float duration)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::MakeBlankFramesRandomBlackAndWhiteName(TCHAR_TO_WCHAR(*path), frameCount, duration);
#endif
}


// REVERSE ALL FRAMES

void UChromaSDKPluginBPLibrary::ReverseAllFrames(int32 animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::ReverseAllFrames(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::ReverseAllFramesName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::ReverseAllFramesName(TCHAR_TO_WCHAR(*path));
#endif
}


// DUPLICATE FRAMES

void UChromaSDKPluginBPLibrary::DuplicateFrames(int32 animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::DuplicateFrames(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::DuplicateFramesName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::DuplicateFramesName(TCHAR_TO_WCHAR(*path));
#endif
}


// DUPLICATE FIRST FRAME

void UChromaSDKPluginBPLibrary::DuplicateFirstFrame(int32 animationId, int32 frameCount)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::DuplicateFirstFrame(animationId, frameCount);
#endif
}

void UChromaSDKPluginBPLibrary::DuplicateFirstFrameName(const FString& animationName, int32 frameCount)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::DuplicateFirstFrameName(TCHAR_TO_WCHAR(*path), frameCount);
#endif
}


// DUPLICATE MIRROR FRAMES

void UChromaSDKPluginBPLibrary::DuplicateMirrorFrames(int32 animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::DuplicateMirrorFrames(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::DuplicateMirrorFramesName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::DuplicateMirrorFramesName(TCHAR_TO_WCHAR(*path));
#endif
}


// INSERT FRAME

void UChromaSDKPluginBPLibrary::InsertFrame(int32 animationId, int32 sourceFrame, int32 targetFrame)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::InsertFrame(animationId, sourceFrame, targetFrame);
#endif
}

void UChromaSDKPluginBPLibrary::InsertFrameName(const FString& animationName, int32 sourceFrame, int32 targetFrame)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::InsertFrameName(TCHAR_TO_WCHAR(*path), sourceFrame, targetFrame);
#endif
}


// INSERT DELAY

void UChromaSDKPluginBPLibrary::InsertDelay(int32 animationId, int32 frameId, int32 delay)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::InsertDelay(animationId, frameId, delay);
#endif
}

void UChromaSDKPluginBPLibrary::InsertDelayName(const FString& animationName, int32 frameId, int32 delay)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::InsertDelayName(TCHAR_TO_WCHAR(*path), frameId, delay);
#endif
}


// REDUCE FRAMES

void UChromaSDKPluginBPLibrary::ReduceFrames(int32 animationId, int32 n)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::ReduceFrames(animationId, n);
#endif
}

void UChromaSDKPluginBPLibrary::ReduceFramesName(const FString& animationName, int32 n)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::ReduceFramesName(TCHAR_TO_WCHAR(*path), n);
#endif
}


// TRIM FRAME

void UChromaSDKPluginBPLibrary::TrimFrame(int32 animationId, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::TrimFrame(animationId, frameId);
#endif
}

void UChromaSDKPluginBPLibrary::TrimFrameName(const FString& animationName, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::TrimFrameName(TCHAR_TO_WCHAR(*path), frameId);
#endif
}


// TRIM START FRAMES

void UChromaSDKPluginBPLibrary::TrimStartFrames(int32 animationId, int32 numberOfFrames)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::TrimStartFrames(animationId, numberOfFrames);
#endif
}

void UChromaSDKPluginBPLibrary::TrimStartFramesName(const FString& animationName, int32 numberOfFrames)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::TrimStartFramesName(TCHAR_TO_WCHAR(*path), numberOfFrames);
#endif
}


// TRIM END FRAMES

void UChromaSDKPluginBPLibrary::TrimEndFrames(int32 animationId, int32 lastFrameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::TrimEndFrames(animationId, lastFrameId);
#endif
}

void UChromaSDKPluginBPLibrary::TrimEndFramesName(const FString& animationName, int32 lastFrameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::TrimEndFramesName(TCHAR_TO_WCHAR(*path), lastFrameId);
#endif
}


// FADE START FRAMES

void UChromaSDKPluginBPLibrary::FadeStartFrames(int32 animationId, int32 fade)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FadeStartFrames(animationId, fade);
#endif
}

void UChromaSDKPluginBPLibrary::FadeStartFramesName(const FString& animationName, int32 fade)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::FadeStartFramesName(TCHAR_TO_WCHAR(*path), fade);
#endif
}


// FADE END FRAMES

void UChromaSDKPluginBPLibrary::FadeEndFrames(int32 animationId, int32 fade)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FadeEndFrames(animationId, fade);
#endif
}

void UChromaSDKPluginBPLibrary::FadeEndFramesName(const FString& animationName, int32 fade)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::FadeEndFramesName(TCHAR_TO_WCHAR(*path), fade);
#endif
}

EChromaSDKKeyboardKey::Type UChromaSDKPluginBPLibrary::GetKeyboardRazerKey(FKey key)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (_sKeyboardFKeyMap.find(key) != _sKeyboardFKeyMap.end())
	{
		return _sKeyboardFKeyMap[key];
	}
#endif
	return EChromaSDKKeyboardKey::KK_INVALID;
}

int32 UChromaSDKPluginBPLibrary::GetKeyboardRzKey(EChromaSDKKeyboardKey::Type key)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	return _sKeyboardEnumMap[key];
#endif
	return 0;
}

// COPY ANIMATION

void UChromaSDKPluginBPLibrary::CopyAnimation(int32 sourceAnimationId, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyAnimation(sourceAnimationId, TCHAR_TO_WCHAR(*targetPath));
#endif
}

void UChromaSDKPluginBPLibrary::CopyAnimationName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyAnimationName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath));
#endif
}


// APPEND

void UChromaSDKPluginBPLibrary::AppendAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::AppendAllFrames(sourceAnimationId, targetAnimationId);
#endif
}

void UChromaSDKPluginBPLibrary::AppendAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::AppendAllFramesName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath));
#endif
}


// INVERT COLORS

void UChromaSDKPluginBPLibrary::InvertColorsAllFrames(int32 animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::InvertColorsAllFrames(animationId);
#endif
}

void UChromaSDKPluginBPLibrary::InvertColorsAllFramesName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::InvertColorsAllFramesName(TCHAR_TO_WCHAR(*path));
#endif
}


// NONZERO TARGET

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeys(int32 sourceAnimationId, int32 targetAnimationId, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::CopyNonZeroTargetAllKeys(sourceAnimationId, targetAnimationId, frameId);
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyNonZeroTargetAllKeysName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), frameId);
#endif
}

// NONZERO TARGET

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFrames(sourceAnimationId, targetAnimationId);
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath));
#endif
}

// ZERO TARGET

void UChromaSDKPluginBPLibrary::CopyZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::CopyZeroTargetAllKeysAllFrames(sourceAnimationId, targetAnimationId);
#endif
}

void UChromaSDKPluginBPLibrary::CopyZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyZeroTargetAllKeysAllFramesName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath));
#endif
}

// ADD NONZERO TARGET

void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFrames(sourceAnimationId, targetAnimationId);
#endif
}

void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFramesName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath));
#endif
}


// SUBTRACT NONZERO TARGET

void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, int32 targetAnimationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFrames(sourceAnimationId, targetAnimationId);
#endif
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesName(const FString& sourceAnimationName, const FString& targetAnimationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFramesName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath));
#endif
}

// NONZERO TARGET OFFSET

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
#endif
}

void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesOffsetName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), offset);
#endif
}


// ADD NONZERO TARGET OFFSET

void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
#endif
}

void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFramesOffsetName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), offset);
#endif
}


// SUBTRACT NONZERO TARGET OFFSET

void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesOffset(int32 sourceAnimationId, int32 targetAnimationId, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
#endif
}

void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesOffsetName(const FString& sourceAnimationName, const FString& targetAnimationName, int32 offset)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString sourcePath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString sourcePath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (sourceAnimationName.EndsWith(".chroma"))
	{
		sourcePath += sourceAnimationName;
	}
	else
	{
		sourcePath += sourceAnimationName + ".chroma";
	}

//	FString targetPath = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString targetPath = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (targetAnimationName.EndsWith(".chroma"))
	{
		targetPath += targetAnimationName;
	}
	else
	{
		targetPath += targetAnimationName + ".chroma";
	}

	ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFramesOffsetName(TCHAR_TO_WCHAR(*sourcePath), TCHAR_TO_WCHAR(*targetPath), offset);
#endif
}

// LERP

void UChromaSDKPluginBPLibrary::MultiplyColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int color1 = ToBGR(colorParam1);
	int color2 = ToBGR(colorParam2);
	ChromaAnimationAPI::MultiplyColorLerpAllFrames(animationId, color1, color2);
#endif
}

void UChromaSDKPluginBPLibrary::MultiplyColorLerpAllFramesName(const FString& animationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int color1 = ToBGR(colorParam1);
	int color2 = ToBGR(colorParam2);
	ChromaAnimationAPI::MultiplyColorLerpAllFramesName(TCHAR_TO_WCHAR(*path), color1, color2);
#endif
}


// TARGET LERP

void UChromaSDKPluginBPLibrary::MultiplyTargetColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int color1 = ToBGR(colorParam1);
	int color2 = ToBGR(colorParam2);
	ChromaAnimationAPI::MultiplyTargetColorLerpAllFrames(animationId, color1, color2);
#endif
}
void UChromaSDKPluginBPLibrary::MultiplyTargetColorLerpAllFramesName(const FString& animationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int color1 = ToBGR(colorParam1);
	int color2 = ToBGR(colorParam2);
	ChromaAnimationAPI::MultiplyTargetColorLerpAllFramesName(TCHAR_TO_WCHAR(*path), color1, color2);
#endif
}

void UChromaSDKPluginBPLibrary::FillThresholdRGBColorsAllFramesRGB(int32 animationId, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillThresholdRGBColorsAllFramesRGB(animationId, redThreshold, greenThreshold, blueThreshold, red, green, blue);
#endif
}
void UChromaSDKPluginBPLibrary::FillThresholdRGBColorsAllFramesRGBName(const FString& animationName, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, int32 red, int32 green, int32 blue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::FillThresholdRGBColorsAllFramesRGBName(TCHAR_TO_WCHAR(*path), redThreshold, greenThreshold, blueThreshold, red, green, blue);
#endif
}


void UChromaSDKPluginBPLibrary::FillThresholdColorsMinMaxAllFramesRGB(int32 animationId, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::FillThresholdColorsMinMaxAllFramesRGB(animationId, minThreshold, minRed, minGreen, minBlue, maxThreshold, maxRed, maxGreen, maxBlue);
#endif
}

void UChromaSDKPluginBPLibrary::FillThresholdColorsMinMaxAllFramesRGBName(const FString& animationName, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::FillThresholdColorsMinMaxAllFramesRGBName(TCHAR_TO_WCHAR(*path), minThreshold, minRed, minGreen, minBlue, maxThreshold, maxRed, maxGreen, maxBlue);
#endif
}


// NON ZERO

void UChromaSDKPluginBPLibrary::MultiplyNonZeroTargetColorLerpAllFrames(int32 animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	int color1 = ToBGR(colorParam1);
	int color2 = ToBGR(colorParam2);
	ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFrames(animationId, color1, color2);
#endif
}

void UChromaSDKPluginBPLibrary::MultiplyNonZeroTargetColorLerpAllFramesName(const FString& animationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	int color1 = ToBGR(colorParam1);
	int color2 = ToBGR(colorParam2);
	ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFramesName(TCHAR_TO_WCHAR(*path), color1, color2);
#endif
}

void UChromaSDKPluginBPLibrary::UseIdleAnimation(EChromaSDKDeviceEnum::Type device, bool flag)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::UseIdleAnimation((EChromaSDKDeviceEnum::Type)device, flag);
#endif
}

void UChromaSDKPluginBPLibrary::UseIdleAnimations(bool flag)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::UseIdleAnimations(flag);
#endif
}

void UChromaSDKPluginBPLibrary::SetIdleAnimationName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::SetIdleAnimationName(TCHAR_TO_WCHAR(*path));
#endif
}

void UChromaSDKPluginBPLibrary::UsePreloading(int32 animationId, bool flag)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::UsePreloading(animationId, flag);
#endif
}

void UChromaSDKPluginBPLibrary::UsePreloadingName(const FString& animationName, bool flag)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::UsePreloadingName(TCHAR_TO_WCHAR(*path), flag);
#endif
}


int32 UChromaSDKPluginBPLibrary::GetCurrentFrame(int32 animationId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return 0;
	}

	return ChromaAnimationAPI::GetCurrentFrame(animationId);
#else
	return 0;
#endif
}

int32 UChromaSDKPluginBPLibrary::GetCurrentFrameName(const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return 0;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	return ChromaAnimationAPI::GetCurrentFrameName(TCHAR_TO_WCHAR(*path));
#else
	return 0;
#endif
}


void UChromaSDKPluginBPLibrary::SetCurrentFrame(int32 animationId, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	ChromaAnimationAPI::SetCurrentFrame(animationId, frameId);
#endif
}

void UChromaSDKPluginBPLibrary::SetCurrentFrameName(const FString& animationName, int32 frameId)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	ChromaAnimationAPI::SetCurrentFrameName(TCHAR_TO_WCHAR(*path), frameId);
#endif
}

void UChromaSDKPluginBPLibrary::OpenAnimationFromMemory(const TArray<uint8>& data, const FString& animationName)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

//	FString path = FPaths::GameContentDir(); //___HACK_UE4_VERSION_4_17_OR_LESS
	FString path = FPaths::ProjectContentDir(); //___HACK_UE4_VERSION_4_18_OR_GREATER
	if (animationName.EndsWith(".chroma"))
	{
		path += animationName;
	}
	else
	{
		path += animationName + ".chroma";
	}

	if (data.Num() > 0)
	{
		BYTE* buffer = new BYTE[data.Num()];
		const int size = data.Num();
		for (int i = 0; i < size; ++i)
		{
			buffer[i] = data[i];
		}

		ChromaAnimationAPI::OpenAnimationFromMemory(buffer, TCHAR_TO_WCHAR(*path));

		delete[] buffer;
	}
#endif
}


int UChromaSDKPluginBPLibrary::GetFrameBGR(int animationId, int frameIndex, float* duration, int* colors, int length, int* keys, int keysLength)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return -1;
	}

	return ChromaAnimationAPI::GetFrame(animationId, frameIndex, duration, colors, length, keys, keysLength);
#else
	return -1;
#endif
}


RZRESULT UChromaSDKPluginBPLibrary::SetEffectCustom1D_BGR(EChromaSDKDevice1DEnum::Type device, int32* colors)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return 0;
	}

	int maxLeds = GetMaxLeds(device);

	RZRESULT result = 0;
	switch (device)
	{
	case EChromaSDKDevice1DEnum::DE_ChromaLink:
	{
		ChromaLink::CUSTOM_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxLeds; i++)
		{
			pParam.Color[i] = colors[i];
		}
		result = ChromaAnimationAPI::CoreCreateChromaLinkEffect(ChromaLink::CHROMA_CUSTOM, &pParam, nullptr);
	}
	break;
	case EChromaSDKDevice1DEnum::DE_Headset:
	{
		Headset::CUSTOM_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxLeds; i++)
		{
			pParam.Color[i] = colors[i];
		}
		result = ChromaAnimationAPI::CoreCreateHeadsetEffect(Headset::CHROMA_CUSTOM, &pParam, nullptr);
	}
	break;
	case EChromaSDKDevice1DEnum::DE_Mousepad:
	{
		Mousepad::CUSTOM_EFFECT_TYPE pParam = {};
		for (int i = 0; i < maxLeds; i++)
		{
			pParam.Color[i] = colors[i];
		}
		result = ChromaAnimationAPI::CoreCreateMousepadEffect(Mousepad::CHROMA_CUSTOM, &pParam, nullptr);
	}
	break;
	default:
		//LogError("SetEffectCustom1D_BGR Unsupported device used!\r\n");
		return (ULONG)RZRESULT_FAILED;
	}
	return result;
#else
	return 0;
#endif
}

RZRESULT UChromaSDKPluginBPLibrary::SetEffectCustom2D_BGR(EChromaSDKDevice2DEnum::Type device, int32* colors)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return 0;
	}

	int maxRow = GetMaxRow(device);
	int maxColumn = GetMaxColumn(device);

	RZRESULT result = 0;
	switch (device)
	{
	case EChromaSDKDevice2DEnum::DE_Keyboard:
	{
		Keyboard::CUSTOM_EFFECT_TYPE pParam = {};
		int index = 0;
		for (int i = 0; i < maxRow; i++)
		{
			for (int j = 0; j < maxColumn; j++)
			{
				pParam.Color[i][j] = colors[index];
				++index;
			}
		}
		result = ChromaAnimationAPI::CoreCreateKeyboardEffect(Keyboard::CHROMA_CUSTOM, &pParam, nullptr);
	}
	break;
	case EChromaSDKDevice2DEnum::DE_Keypad:
	{
		Keypad::CUSTOM_EFFECT_TYPE pParam = {};
		int index = 0;
		for (int i = 0; i < maxRow; i++)
		{
			for (int j = 0; j < maxColumn; j++)
			{
				pParam.Color[i][j] = colors[index];
				++index;
			}
		}
		result = ChromaAnimationAPI::CoreCreateKeypadEffect(Keypad::CHROMA_CUSTOM, &pParam, nullptr);
	}
	break;
	case EChromaSDKDevice2DEnum::DE_Mouse:
	{
		Mouse::CUSTOM_EFFECT_TYPE2 pParam = {};
		int index = 0;
		for (int i = 0; i < maxRow; i++)
		{
			for (int j = 0; j < maxColumn; j++)
			{
				pParam.Color[i][j] = colors[index];
				++index;
			}
		}
		result = ChromaAnimationAPI::CoreCreateMouseEffect(Mouse::CHROMA_CUSTOM2, &pParam, nullptr);
	}
	break;
	default:
		//LogError("SetEffectCustom2D_BGR Unsupported device used!\r\n");
		return (ULONG)RZRESULT_FAILED;
	}

	return result;
#else
	return 0;
#endif
}

RZRESULT UChromaSDKPluginBPLibrary::SetCustomColorFlag2D_BGR(EChromaSDKDevice2DEnum::Type device, int32* colors)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return 0;
	}

	int maxRow = GetMaxRow(device);
	int maxColumn = GetMaxColumn(device);

	const int customFlag = 0x1 << 24;
	RZRESULT result = 0;
	switch (device)
	{
		case EChromaSDKDevice2DEnum::DE_Keyboard:
		{
			int index = 0;
			for (int i = 0; i < maxRow; i++)
			{
				for (int j = 0; j < maxColumn; j++)
				{
					colors[index] = colors[index] | customFlag;
					++index;
				}
			}
		}
		break;
	default:
		return (ULONG)RZRESULT_FAILED;
	}

	return RZRESULT_SUCCESS;
#else
	return 0;
#endif
}

RZRESULT UChromaSDKPluginBPLibrary::SetEffectKeyboardCustom2D_BGR(EChromaSDKDevice2DEnum::Type device, int32* colors, int32* keys)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return 0;
	}

	RZRESULT result = 0;
	switch (device)
	{
	case EChromaSDKDevice2DEnum::DE_Keyboard:
	{
		Keyboard::CUSTOM_KEY_EFFECT_TYPE pParam = {};
		int maxRow = GetMaxRow(device);
		int maxColumn = GetMaxColumn(device);
		if (colors)
		{
			int index = 0;
			for (int i = 0; i < maxRow; i++)
			{
				for (int j = 0; j < maxColumn; j++)
				{
					pParam.Color[i][j] = colors[index];
					++index;
				}
			}
		}
		if (keys)
		{
			int index = 0;
			for (int i = 0; i < maxRow; i++)
			{
				for (int j = 0; j < maxColumn; j++)
				{
					pParam.Key[i][j] = keys[index];
					++index;
				}
			}
		}
		result = ChromaAnimationAPI::CoreCreateKeyboardEffect(Keyboard::CHROMA_CUSTOM_KEY, &pParam, nullptr);
	}
	break;
	case EChromaSDKDevice2DEnum::DE_KeyboardExtended:
	{
		Keyboard::v2::CUSTOM_EFFECT_TYPE pParam = {};
		if (colors)
		{
			int maxRow = GetMaxRow(device);
			int maxColumn = GetMaxColumn(device);
			int index = 0;
			for (int i = 0; i < maxRow; i++)
			{
				for (int j = 0; j < maxColumn; j++)
				{
					pParam.Color[i][j] = colors[index];
					++index;
				}
			}
		}
		if (keys)
		{
			int maxRow = GetMaxRow(EChromaSDKDevice2DEnum::DE_Keyboard);
			int maxColumn = GetMaxColumn(EChromaSDKDevice2DEnum::DE_Keyboard);
			int index = 0;
			for (int i = 0; i < maxRow; i++)
			{
				for (int j = 0; j < maxColumn; j++)
				{
					pParam.Key[i][j] = keys[index];
					++index;
				}
			}
		}
		result = ChromaAnimationAPI::CoreCreateKeyboardEffect(Keyboard::CHROMA_CUSTOM2, &pParam, nullptr);
	}
	break;
	default:
		return (ULONG)RZRESULT_FAILED;
	}

	return result;
#else
	return 0;
#endif
}

void UChromaSDKPluginBPLibrary::SetStaticColor(EChromaSDKDeviceEnum::Type device, const FLinearColor& color)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	FChromaSDKEffectResult result;
	switch (device)
	{
	case EChromaSDKDeviceEnum::DE_ChromaLink:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_ChromaLink);
		break;
	case EChromaSDKDeviceEnum::DE_Headset:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_Headset);
		break;
	case EChromaSDKDeviceEnum::DE_Keyboard:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Keyboard);
		break;
	case EChromaSDKDeviceEnum::DE_Keypad:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Keypad);
		break;
	case EChromaSDKDeviceEnum::DE_Mouse:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_2D, (int)EChromaSDKDevice2DEnum::DE_Mouse);
		break;
	case EChromaSDKDeviceEnum::DE_Mousepad:
		ChromaAnimationAPI::StopAnimationType((int)EChromaSDKDeviceTypeEnum::DE_1D, (int)EChromaSDKDevice1DEnum::DE_Mousepad);
		break;
	}
	result = ChromaSDKCreateEffectStatic(device, color);
	if (result.Result == 0)
	{
		ChromaSDKSetEffect(result.EffectId);
		ChromaSDKDeleteEffect(result.EffectId);
	}
#endif
}

void UChromaSDKPluginBPLibrary::SetStaticColorAll(const FLinearColor& color)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	SetStaticColor(EChromaSDKDeviceEnum::DE_ChromaLink, color);
	SetStaticColor(EChromaSDKDeviceEnum::DE_Headset, color);
	SetStaticColor(EChromaSDKDeviceEnum::DE_Keyboard, color);
	SetStaticColor(EChromaSDKDeviceEnum::DE_Keypad, color);
	SetStaticColor(EChromaSDKDeviceEnum::DE_Mouse, color);
	SetStaticColor(EChromaSDKDeviceEnum::DE_Mousepad, color);
#endif
}

void UChromaSDKPluginBPLibrary::StreamBroadcast(const FString& streamId, const FString& streamKey)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		ChromaAnimationAPI::CoreStreamBroadcast(TCHAR_TO_ANSI(*streamId), TCHAR_TO_ANSI(*streamKey));
	}
#endif
}

void UChromaSDKPluginBPLibrary::StreamBroadcastEnd()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		ChromaAnimationAPI::CoreStreamBroadcastEnd();
	}
#endif
}

FString UChromaSDKPluginBPLibrary::StreamGetAuthShortcode(const FString& platform, const FString& title)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return FString("");
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		char shortcode[7] = { 0 };
		unsigned char lenShortcode = 0;
		ChromaAnimationAPI::CoreStreamGetAuthShortcode(shortcode, &lenShortcode, TCHAR_TO_WCHAR(*platform), TCHAR_TO_WCHAR(*title));
		if (lenShortcode != 6)
		{
			return FString("");
		}
		else
		{
			return FString(shortcode);
		}
	}
#endif
	return FString("");
}

FString UChromaSDKPluginBPLibrary::StreamGetFocus()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return FString("");
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		char streamFocus[48] = { 0 };
		unsigned char lenStreamFocus = 0;
		ChromaAnimationAPI::CoreStreamGetFocus(streamFocus, &lenStreamFocus);
		if (lenStreamFocus == 0)
		{
			return FString("");
		}
		else
		{
			return FString(streamFocus);
		}
	}
#endif
	return FString("");
}

bool UChromaSDKPluginBPLibrary::StreamSetFocus(const FString& streamFocus)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return false;
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		return ChromaAnimationAPI::CoreStreamSetFocus(TCHAR_TO_ANSI(*streamFocus));
	}
#endif
	return false;
}

FString UChromaSDKPluginBPLibrary::StreamGetId(const FString& shortcode)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return FString("");
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		char streamId[48] = { 0 };
		unsigned char lenStreamId = 0;
		ChromaAnimationAPI::CoreStreamGetId(TCHAR_TO_ANSI(*shortcode), streamId, &lenStreamId);
		if (lenStreamId == 0)
		{
			return FString("");
		}
		else
		{
			return FString(streamId);
		}
	}
#endif
	return FString("");
}

FString UChromaSDKPluginBPLibrary::StreamGetKey(const FString& shortcode)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return FString("");
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		char streamKey[48] = { 0 };
		unsigned char lenStreamKey = 0;
		ChromaAnimationAPI::CoreStreamGetKey(TCHAR_TO_ANSI(*shortcode), streamKey, &lenStreamKey);
		if (lenStreamKey == 0)
		{
			return FString("");
		}
		else
		{
			return FString(streamKey);
		}
	}
#endif
	return FString("");
}

bool UChromaSDKPluginBPLibrary::StreamReleaseShortcode(const FString& shortcode)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return false;
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		return ChromaAnimationAPI::CoreStreamReleaseShortcode(TCHAR_TO_ANSI(*shortcode));
	}
#endif
	return false;
}

bool UChromaSDKPluginBPLibrary::SupportsStreaming()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!ChromaAnimationAPI::GetIsInitializedAPI())
	{
		return false;
	}

	return ChromaAnimationAPI::CoreStreamSupportsStreaming();
#else
	return false;
#endif
}

void UChromaSDKPluginBPLibrary::StreamWatch(const FString& streamId, int32 timestamp)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		ChromaAnimationAPI::CoreStreamWatch(TCHAR_TO_ANSI(*streamId), timestamp);
	}
#endif
}

void UChromaSDKPluginBPLibrary::StreamWatchEnd()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return;
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		ChromaAnimationAPI::CoreStreamWatchEnd();
	}
#endif
}

const EChromaSDKStreamStatusEnum::Type UChromaSDKPluginBPLibrary::StreamGetStatus()
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return EChromaSDKStreamStatusEnum::SERVICE_OFFLINE;
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		return (EChromaSDKStreamStatusEnum::Type)ChromaAnimationAPI::CoreStreamGetStatus();
	}
#endif
	return EChromaSDKStreamStatusEnum::SERVICE_OFFLINE;
}

FString UChromaSDKPluginBPLibrary::StreamGetStatusString(const EChromaSDKStreamStatusEnum::Type status)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	if (!IsInitialized())
	{
		return FString("");
	}

	if (ChromaAnimationAPI::CoreStreamSupportsStreaming())
	{
		switch (status)
		{
		case EChromaSDKStreamStatusEnum::READY:
			return FString("READY");
		case EChromaSDKStreamStatusEnum::AUTHORIZING:
			return FString("AUTHORIZING");
		case EChromaSDKStreamStatusEnum::BROADCASTING:
			return FString("BROADCASTING");
		case EChromaSDKStreamStatusEnum::WATCHING:
			return FString("WATCHING");
		case EChromaSDKStreamStatusEnum::NOT_AUTHORIZED:
			return FString("NOT_AUTHORIZED");
		case EChromaSDKStreamStatusEnum::BROADCAST_DUPLICATE:
			return FString("BROADCAST_DUPLICATE");
		case EChromaSDKStreamStatusEnum::SERVICE_OFFLINE:
			return FString("SERVICE_OFFLINE");
		default:
			return FString("UNKNOWN");
		}
	}
#endif
	return FString("");
}


int UChromaSDKPluginBPLibrary::min(const int a, const int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int UChromaSDKPluginBPLibrary::max(const int a, const int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int UChromaSDKPluginBPLibrary::UtilGetRGB(const int red, const int green, const int blue)
{
	return (red & 0xFF) | ((green & 0xFF) << 8) | ((blue & 0xFF) << 16);
}

int UChromaSDKPluginBPLibrary::UtilToBGR(const FLinearColor& color)
{
	int red = max(0, min(255, color.R * 255));
	int green = max(0, min(255, color.G * 255));
	int blue = max(0, min(255, color.B * 255));
	int customFlag = max(0, min(255, color.A * 255));
	int bgrColor = (red & 0xFF) | ((green & 0xFF) << 8) | ((blue & 0xFF) << 16) | (customFlag << 24);
	return bgrColor;
}

int32 UChromaSDKPluginBPLibrary::IsActive(bool& active)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	BOOL isActive;
	int result = ChromaAnimationAPI::CoreIsActive(isActive);
	active = isActive != FALSE;
	return result;
#else
	return -1;
#endif
}

int32 UChromaSDKPluginBPLibrary::IsConnected(FChromaSDKDeviceInfoType& deviceInfoType)
{
#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)
	DEVICE_INFO_TYPE deviceInfo;
	int32 valDeviceType = (int32)(uint8)(TEnumAsByte<EChromaSDKCoreDeviceTypeEnum::Type>)deviceInfoType.DeviceType;
	deviceInfo.DeviceType = (enum DEVICE_INFO_TYPE::DeviceType)valDeviceType;
	int result = ChromaAnimationAPI::CoreIsConnected(deviceInfo);
	deviceInfoType.Connected = deviceInfo.Connected;

	/*
	UE_LOG(LogChromaBlueprintLibrary, Log, TEXT("UChromaSDKPluginBPLibrary::IsConnected deviceType=%d connected=%d"),
		(int32)deviceInfo.DeviceType,
		deviceInfoType.Connected);
	*/

	return result;
#else
	return -1;
#endif
}

int32 UChromaSDKPluginBPLibrary::SetEventName(const FString& name)
{
	return ChromaAnimationAPI::CoreSetEventName(TCHAR_TO_WCHAR(*name));
}

void UChromaSDKPluginBPLibrary::UseForwardChromaEvents(bool toggle)
{
	ChromaAnimationAPI::UseForwardChromaEvents(toggle);
}


#if PLATFORM_WINDOWS || (defined(PLATFORM_XBOXONE) && PLATFORM_XBOXONE)

#include "Windows/HideWindowsPlatformTypes.h"

#endif
