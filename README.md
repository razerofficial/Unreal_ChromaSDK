## Table of contents

* [Getting Started With Unreal SDK](#getting-started-with-unreal-sdk)
* [User Privacy](#user-privacy)
* [Dependencies](#dependencies)
* [General](#general)
* [Initialize SDK](#initialize-sdk)
* [Is Active](#is-active)
* [Is Connected](#is-connected)
* [Play Chroma Animation](#play-chroma-animation)
* [Set Event Name](#set-event-name)
* [Use Forward Chroma Events](#use-forward-chroma-events)
* [Microsoft Dynamic Lighting](#microsoft-dynamic-lighting)
* [See Also](#see-also)
* [Overview](#overview)
* [Tutorials](#tutorials)
* [Supported versions](#supported-versions)
* [Chroma Editor Library](#chroma-editor-library)
* [Windows PC](#windows-pc)
* [Windows Cloud](#windows-cloud)
* [Dependencies](#dependencies)
* [Plugin Structure](#plugin-structure)
* [Samples](#samples)
* [Unreal Compatibility](#unreal-compatibility)
* [Full API](#full-api)

# Getting Started With Unreal SDK

This Chroma SDK plugin has been tested with `Unreal` versions 4.21 through 5.3.

## User Privacy

Note: The Chroma SDK requires only the minimum amount of information necessary to operate during initialization, including the title of the application or game, description of the application or game, application or game author, and application or game support contact information. This information is displayed in the Chroma app. The Chroma SDK does not monitor or collect any personal data related to users. 

## Dependencies

To use the Chroma SDK first install the new [Razer Synapse and Chroma App](https://www.razer.com/synapse-new).

![image_1](images/image_1.png)

* If you don't have Chroma hardware, you can see Chroma effects with the [Chroma Emulator](https://github.com/razerofficial/ChromaEmulator)

## General

* The Chroma SDK allows an application or game to set the details in the Chroma Apps list within the `Chroma App`.

* The Chroma Plugin `Unreal SDK for Chroma` is available at [Unreal_ChromaSDK](https://github.com/razerofficial/Unreal_ChromaSDK) on Github.

This document provides a guide to integrating Chroma RGB using the Chroma Unreal SDK. Chroma can be included through premade Chroma Animations or APIs. Here is the list of available methods:

* [Initialize SDK](?#markdown-header-initialize-sdk): Initialize the Chroma SDK to use the library.

* [Is Active](?#markdown-header-is-active): Check if the app/game has Chroma focus.

* [Is Connected](?#markdown-header-is-connected): Check if Chroma hardware is connected.

* [Play Chroma Animation](?#markdown-header-play-chroma-animation): Playback a Chroma Animation asset.

* [Set Event Name](?#markdown-header-set-event-name): Name a game event or game trigger in order to also add Haptics to the Chroma event.

* [Use Forward Chroma Events](?#markdown-header-use-forward-chroma-events): Toggle automatic invocation of SetEventName when invoking PlayAnimation using the animation name.

### Chromatic Level

* The following APIs are demonstrated in the `Chroma_Sample\Content\Levels\Chromatic_Level.umap` sample level and `Chroma_Sample\Content\UI\ChromaticWidget_BP.uasset` widget blueprint.

![image_5](images/image_5.png)

## Initialize SDK

Initialize the Chroma SDK in order to utilize the API. The `InitSDK` method takes an `AppInfo` parameter which defines the application or game details that will appear in the `Chroma App` within the `Chroma Apps` tab. The expected return result should be zero for success which indicates the API is ready for use. If a non-zero result is returned, the Chroma implementation should be disabled until the next time the application or game is launched. Reasons for failure are likely to be the user does not have the `Synapse` or the `Chroma App` installed. After successfully initializing the Chroma SDK, wait approximately 100 ms before playing Chroma Animations.

![image_8](images/image_8.png)

```c++
FChromaSDKAppInfoType appInfo;
appInfo.Title = "Unreal Sample Scene - Chromatic";
appInfo.Description = "A sample application using Razer Chroma SDK";
appInfo.Author_Name = "Razer";
appInfo.Author_Contact = "https://developer.razer.com/chroma";

//appInfo.SupportedDevice = 
//    0x01 | // Keyboards
//    0x02 | // Mice
//    0x04 | // Headset
//    0x08 | // Mousepads
//    0x10 | // Keypads
//    0x20   // ChromaLink devices
//    ;
appInfo.SupportedDevice = (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20);
//    0x01 | // Utility. (To specifiy this is an utility application)
//    0x02   // Game. (To specifiy this is a game);
appInfo.Category = 1;

int result = UChromaSDKPluginBPLibrary::ChromaSDKInitSDK(appInfo);
if (result == 0)
{
    // Init Success! Ready to use the Chroma SDK!
}
else
{
    // Init Failed! Stop using the Chroma SDK until the next game launch!";
}
```

Applications should uninitialize the Chroma SDK with Uninit() for a clean exit. Uninitialization is only needed if the Chroma SDK was successfully initialized.

```c++
int result = UChromaSDKPluginBPLibrary::ChromaSDKUnInit();
if (result == 0)
{
    // Chroma has been uninitialized!
}
else
{
    // Uninitialization was unsuccessful!
}
```

## Is Active

Many applications and games can use the Chroma SDK at the same time, yet only one can have the Chroma focus. The `APP PRIORITY LIST` defines the priority order and the highest on the list receives the Chroma focus when more than one are actively using the Chroma SDK. Users can adjust the priority order by dragging and dropping or toggling the app completely off.

![image_2](images/image_2.png)

 The IsActive() method allows an application or game to check if it has Chroma focus at a time. This allows the title to free up overhead when Chroma is not in use. If a title uses this to check for focus, the state should be periodically checked to turn Chroma back on when focus is returned. When active returns false, the title can stop playing Chroma Animations, disable idle animations, and inactivate dynamic Chroma to free up some overhead. Keep in mind that some apps use Chroma notifications so they will only briefly take Chroma focus and then return it typically over a 5 second period.

Blueprints should define a bool variable to pass by reference.

![image_10](images/image_10.png)

Check the state of the variable when the result is successful.

![image_6](images/image_6.png)

```C++
bool isActive;
int result = UChromaSDKPluginBPLibrary::IsActive(isActive);
if (result == 0)
{
    if (isActive)
    {
        // The game currently has the Chroma focus!
    }
    else
    {
        // The game does not currently have the Chroma focus!"
    }
}
else
{
    // Unable to check for Chroma focus. Unexpected result!
}
```

## Is Connected

To further reduce overhead, a title can check if supported devices are connected before showing Chroma effects. The IsConnected() method can indicate if supported devices are in use to help determine if Chroma should be active. Games often will include a menu settings option to toggle Chroma RGB support, with being on by default as an additional way that users can minimize overhead.

Blueprints should define a FChromaSDKDeviceInfoType variable to pass by reference.

![image_9](images/image_9.png)

Check the state of the variable when the result is successful.

![image_7](images/image_7.png)

```c++
FChromaSDKDeviceInfoType deviceInfoType;
deviceInfoType.DeviceType = EChromaSDKCoreDeviceTypeEnum::DEVICE_ALL;
int result = UChromaSDKPluginBPLibrary::IsConnected(deviceInfoType);
if (result == 0)
{
    if (deviceInfo.Connected > 0)
    {
        // Chroma devices are connected!
    }
    else
    {
        // "No Chroma devices are connected!";
    }
}
else
{
    // "Unable to check for Chroma devices. Unexpected result!";
}
```

## Play Chroma Animation

The Chroma SDK supports playing premade Chroma animations which are placed in the `Content` folder or subfolders within. Chroma animations can be created in the web authoring tools, or dynamically created and modified using the API. Call PlayAnimation() to play Chroma animations with or without looping. Animations have a device category, and playing an animation will stop an existing animation from playing before playing the new animation for the given device category. The animation name is file path of the Chroma animation relative to the `Content` folder.

![image_11](images/image_11.png)

```c++
bool loop = false;
TArray<FString> deviceCategories =
{
    "ChromaLink",
    "Headset",
    "Keyboard",
    "Keypad",
    "Mouse",
    "Mousepad",
};
for (int i = 0; i < deviceCategories.Num(); ++i)
{
    FString animationName = "Animations/Spiral_" + deviceCategories[i] + ".chroma";
    UChromaSDKPluginBPLibrary::PlayAnimationName(animationName, loop);
}
```

## Set Event Name

Chroma events can be named to add supplemental technology to your lighting experience. By naming game events and game triggers, the event name can be used as a lookup to play things like haptics effects. `Jump_2s` could be used when playing a Chroma animation of a jump effect that lasts for 2 seconds. Using "Jump_2s" a corresponding haptic effect with similar duration can be added with the Chroma effect to enhance emersion for the title. No other APIs are required to add haptics effects other than to invoke SetEffectName().

![image_12](images/image_12.png)

```c++
int result = UChromaSDKPluginBPLibrary::SetEventName("Jump_2s");
if (result == 0)
{
    // Chroma event named successfully!"
}
else
{
    // Unable to set event name. Unexpected result!"
}
```

## Use Forward Chroma Events

By default when PlayAnimation is called, the animation name is automatically sent to SetEffectName(). In order to disable the default behaviour set the toggle to false. PlayAnimation() as shown above is called for each device category. It will be more efficent to use SetEventName() once for the Chroma Animation set. Manual mode gives the title explicit control over when SetEventName() is called.

![image_13](images/image_13.png)

```c++

bool toggle = false; // manual mode
UChromaSDKPluginBPLibrary::UseForwardChromaEvents(toggle);
if (toggle)
{
    // When PlayAnimation is used, the name is sent to SetEventName().
}
else
{
    // The PlayAnimation name is not forwarded.
}

```

## Microsoft Dynamic Lighting

Windows 11 launched Microsoft Dynamic Lighting which is built-in to the Windows Settings Personalization on Windows. Microsoft DL became generally available in `Windows 11 22H2`. See the [list of supported devices](https://learn.microsoft.com/en-us/windows-hardware/design/component-guidelines/dynamic-lighting-devices).

![image_3](images/image_3.png)

For HID compatible devices, with `Dynamic Lighting` set to `ON` and `Chroma App` set as the ambient controller, Chroma effects will display on DL compatible hardware. No extra coding is required to add this compatibility. `Chroma App` handles Chroma compatibility with DL and it is completely automatic.

![image_4](images/image_4.png)

<a name="see-also"></a>

## See Also

**Docs:**

* [Chroma Animation Guide](http://chroma.razer.com/ChromaGuide/) - Visual examples of the Chroma Animation API methods

**Plugins:**

* [CChromaEditor](https://github.com/RazerOfficial/CChromaEditor) - C++ library for playing and editing Chroma animations

## Overview

`Chroma_Sample` provides a runtime module for using the `ChromaSDK`. The runtime module provides a blueprint library and C++ methods for playing Chroma animations. See the [Chroma Guide](http://chroma.razer.com/ChromaGuide/) for details on how to make visually interesting Chroma animations using the plugin API.

## Tutorials

### Videos

**Chroma Design Guide**

<a target="_blank" href="https://www.youtube.com/watch?v=-demSB_xLTc"><img src="https://img.youtube.com/vi/-demSB_xLTc/0.jpg"/></a>

**Chroma_Sample Plugin Setup** for your specific version of UE.

<a target="_blank" href="https://www.youtube.com/watch?v=7buO9YCXjtY"><img src="https://img.youtube.com/vi/7buO9YCXjtY/0.jpg"/></a>

**Chroma_Sample Overview**

<a target="_blank" href="https://www.youtube.com/watch?v=-Q6Dn15m1Jg"><img src="https://img.youtube.com/vi/-Q6Dn15m1Jg/0.jpg"/></a>

**Simplify UI Blueprints**

<a target="_blank" href="https://www.youtube.com/watch?v=Rz-mOXvd2a0"><img src="https://img.youtube.com/vi/Rz-mOXvd2a0/0.jpg"/></a>

## Supported versions

This project is checked in under `UE 4.21`. To use a later version of Unreal, open the [Chroma_Sample/Chroma_Sample.uproject](Chroma_Sample/Chroma_Sample.uproject) project file in a text editor and change the `EngineAssociation` to the target version.

```
"EngineAssociation": "4.21",
```

To update the plugin version, open [Chroma_Sample/Plugins/ChromaSDKPlugin/ChromaSDKPlugin.uplugin](Chroma_Sample/Plugins/ChromaSDKPlugin/ChromaSDKPlugin.uplugin) in a text editor and set the target version.

```
"EngineVersion": "4.21.0",
```

## Chroma Editor Library

The [Chroma Editor Library](https://github.com/razerofficial/CChromaEditor) is a helper library for Chroma animation playback and realtime manipulation of Chroma animations.

In the UE Editor, Chroma animations files are placed within the project content folder. Animation paths used in the Chroma API are relative to the content folder.

```
Chroma_Sample\Content
```

![image_14](images/image_14.png)

In a standalone PC or Cloud build, Chroma animation files may need to be copied to within the build content folder.

```
WindowsNoEditor\Chroma_Sample\Content
```

![image_15](images/image_15.png)

The latest versions of the `Chroma Editor Library` can be found in [Releases](https://github.com/razerofficial/CChromaEditor/releases) for `Windows-PC` and `Windows-Cloud`.

The plugin build file [Chroma_Sample\Plugins\ChromaSDKPlugin\Source\ChromaSDKPlugin\ChromaSDKPlugin.Build.cs](Chroma_Sample\Plugins\ChromaSDKPlugin\Source\ChromaSDKPlugin\ChromaSDKPlugin.Build.cs) has a preprocessor definition to check the signature of the `Chroma Editor Library`. This a security feature and Chroma libraries won't be loaded that fail to pass the signature validation when this flag is enabled.

```
PrivateDefinitions.Add("CHECK_CHROMA_LIBRARY_SIGNATURE=1");
PublicDefinitions.Add("CHECK_CHROMA_LIBRARY_SIGNATURE=1");
```

Video: **UE Chroma Animation Sample App - Streaming on Windows PC and Cloud**

<a target="_blank" href="https://www.youtube.com/watch?v=MpdEF6hVu5E"><img src="https://img.youtube.com/vi/MpdEF6hVu5E/0.jpg"/></a>

<a name="windows-pc"></a>

## Windows PC

For `Windows PC` builds the `RzChromaSDK.dll` and `RzChromaStreamPlugin.dll` are not packaged with the build. These libraries are automatically updated and managed by Synapse and the Chroma Connect module. Avoid including these files in your build folder for `Windows PC` builds.

Within the `Unreal Editor` the `Chroma Editor Library` files are placed in `Win32` and `Win64` folders on Windows.

**32-bit libraries**

```
Project Folder\Binaries\Win32\CChromaEditorLibrary.dll
Build Folder\WindowsNoEditor\Chroma_Sample\Binaries\Win32\CChromaEditorLibrary.dll
```

**64-bit libraries**

```
Project Folder\Binaries\Win64\CChromaEditorLibrary64.dll
Build Folder\WindowsNoEditor\Chroma_Sample\Binaries\Win64\CChromaEditorLibrary64.dll
```

<a name="windows-cloud"></a>

## Windows Cloud

`Windows Cloud` builds run on cloud platforms using `Windows` such as `Amazon Luna`, `Microsoft Game Pass`, and `NVidia GeForce Now`. Game instances run in the cloud without direct access to Chroma hardware. Chroma effects stream across the Internet to reach your local machine and connected hardware. No extra code is required to add Cloud support. In the case with `NVidia GeForce Now`, the cloud runs the same Epic Games and Steam builds as the desktop version and support Chroma streaming. Viewers can watch the cloud stream via the [Razer Stream Portal](https://stream.razer.com/).

## Plugin Structure

Plugin Definition: `Plugins/ChromaSDKPlugin/ChromaSDKPlugin.uplugin`

Plugin Source: `Chroma_Sample/Plugins/ChromaSDKPlugin/Source/ChromaSDKPlugin/`

Headers: `Chroma_Sample/Plugins/ChromaSDKPlugin/Source/ChromaSDKPlugin/Public/`

Implementation: `Chroma_Sample/Plugins/ChromaSDKPlugin/Source/ChromaSDKPlugin/Private/`

## Plugin appears in Window->Plugins

![image_16](images/image_16.png)

## Sample Blueprint Init / Uninit Setup

`Event BeginPlay` invokes `InitSDK` passing the `AppInfo` that provides the information that displays within `Synapse->Connect->Apps`. `InitSDK` returns `0` upon success after a 100ms delay the Chroma API is ready to use. If `InitSDK` returns nonzero, avoid further calls to the Chroma API. After success, make a call to `SupportsStreaming` and save the result. If `SupportsStreaming` returns true, the streaming API can be used for broadcasting Chroma.

![image_17](images/image_17.png)

## Samples

The project has a few sample levels.

Samples share the same `Stream Overlay` logic defined in the [Chroma_Sample/Content/UI/StreamingWidget_BP.uasset](Chroma_Sample/Content/UI/StreamingWidget_BP.uasset) Widget Blueprint.

![image_18](images/image_18.png)

Sample UI event construction checks if streaming is supported before showing the button that displays the sample stream overlay.

![image_19](images/image_19.png)

---

**UE Chroma Sample App**

The [Chroma_Sample/Content/Levels/SampleApp_Level.umap](Chroma_Sample/Content/Levels/SampleApp_Level.umap) level shows the sample animations from the [Chroma Animation Guide](https://chroma.razer.com/ChromaGuide/). The level blueprint uses BP functions defined in the [Chroma_Sample/Source/Chroma_Sample/SampleAppChromaBP.h](Chroma_Sample/Source/Chroma_Sample/SampleAppChromaBP.h) header and implemented in the [Chroma_Sample/Source/Chroma_Sample/SampleAppChromaBP.cpp](Chroma_Sample/Source/Chroma_Sample/SampleAppChromaBP.cpp) source.

![image_20](images/image_20.png)

**UE Game Loop Chroma Sample App**

The [Chroma_Sample/Content/Levels/SampleGameLoopLevel.umap](Chroma_Sample/Content/Levels/SampleGameLoopLevel.umap) level shows how to dynamically set color effects directly through the API and while also playing several animations at the same time using various blending operations. This sample shows how to do Chroma effects without using premade Chroma animations. Chroma animations can be used as source color information when doing dynamic blending. The level blueprint uses BP functions defined in the [Chroma_Sample/Source/Chroma_Sample/SampleGameLoopChromaBP.h](Chroma_Sample/Source/Chroma_Sample/SampleGameLoopChromaBP.h) header and implemented in the [Chroma_Sample/Source/Chroma_Sample/SampleGameLoopChromaBP.cpp](Chroma_Sample/Source/Chroma_Sample/SampleGameLoopChromaBP.cpp) source.

![image_21](images/image_21.png)

**UE Sample Game Chroma Design**

The [Chroma_Sample/Content/Levels/SampleGameLevel.umap](Chroma_Sample/Content/Levels/SampleGameLevel.umap) level is a template intended to work with the automated [Chroma Design Converter](https://github.com/razerofficial/ChromaDesignConverter) for quickly porting sample effects from HTML5 to Unity. The level blueprint uses BP functions defined in the [Chroma_Sample/Source/Chroma_Sample/SampleGameChromaBP.h](Chroma_Sample/Source/Chroma_Sample/SampleGameChromaBP.h) header and implemented in the [Chroma_Sample/Source/Chroma_Sample/SampleGameChromaBP.cpp](Chroma_Sample/Source/Chroma_Sample/SampleGameChromaBP.cpp) source. Chroma Design samples are commonly created with 15 sample effects which is why the template has that many buttons to play the sample effects from the ported code. The Chroma Design Converter is not limited to just 15 sample effects and can generate more effect code from the input HTML5 script.

![image_22](images/image_22.png)

<a name="unreal-compatibility"></a>

## Unreal Compatibility

* Note: Enum syntax - Enums are namespaced and types use the `EChromaSDKKeyboardKey::Type` syntax to avoid collisions.

* Note: No const enum types or passing enums by reference in function parameters - Avoid use of const enum types because that seems to crash in UE 4.5.

<a name="full-api"></a>

## Full API

`Chroma_Sample` is a Blueprint API library with methods that expose the [CChromaEditor](https://github.com/razerofficial/CChromaEditor) library.

* Take a look at the code from [SampleAppChromaBP.cpp](Chroma_Sample/Source/Chroma_Sample/SampleAppChromaBP.cpp). These sample effects show how the blueprint library was used to create the `Chroma` effects that correspond to the `Guide`.

* [AddNonZeroAllKeys](#AddNonZeroAllKeys)
* [AddNonZeroAllKeysAllFrames](#AddNonZeroAllKeysAllFrames)
* [AddNonZeroAllKeysAllFramesName](#AddNonZeroAllKeysAllFramesName)
* [AddNonZeroAllKeysAllFramesOffset](#AddNonZeroAllKeysAllFramesOffset)
* [AddNonZeroAllKeysAllFramesOffsetName](#AddNonZeroAllKeysAllFramesOffsetName)
* [AddNonZeroAllKeysName](#AddNonZeroAllKeysName)
* [AddNonZeroTargetAllKeysAllFrames](#AddNonZeroTargetAllKeysAllFrames)
* [AddNonZeroTargetAllKeysAllFramesName](#AddNonZeroTargetAllKeysAllFramesName)
* [AddNonZeroTargetAllKeysAllFramesOffset](#AddNonZeroTargetAllKeysAllFramesOffset)
* [AddNonZeroTargetAllKeysAllFramesOffsetName](#AddNonZeroTargetAllKeysAllFramesOffsetName)
* [AppendAllFrames](#AppendAllFrames)
* [AppendAllFramesName](#AppendAllFramesName)
* [ClearAll](#ClearAll)
* [ClearAnimationType](#ClearAnimationType)
* [CloseAll](#CloseAll)
* [CloseAnimation](#CloseAnimation)
* [CloseAnimationName](#CloseAnimationName)
* [CopyAllKeys](#CopyAllKeys)
* [CopyAllKeysName](#CopyAllKeysName)
* [CopyAnimation](#CopyAnimation)
* [CopyAnimationName](#CopyAnimationName)
* [CopyKeyColor](#CopyKeyColor)
* [CopyKeyColorName](#CopyKeyColorName)
* [CopyKeysColor](#CopyKeysColor)
* [CopyKeysColorAllFrames](#CopyKeysColorAllFrames)
* [CopyKeysColorAllFramesName](#CopyKeysColorAllFramesName)
* [CopyKeysColorName](#CopyKeysColorName)
* [CopyNonZeroAllKeys](#CopyNonZeroAllKeys)
* [CopyNonZeroAllKeysAllFrames](#CopyNonZeroAllKeysAllFrames)
* [CopyNonZeroAllKeysAllFramesName](#CopyNonZeroAllKeysAllFramesName)
* [CopyNonZeroAllKeysAllFramesOffset](#CopyNonZeroAllKeysAllFramesOffset)
* [CopyNonZeroAllKeysAllFramesOffsetName](#CopyNonZeroAllKeysAllFramesOffsetName)
* [CopyNonZeroAllKeysName](#CopyNonZeroAllKeysName)
* [CopyNonZeroAllKeysOffset](#CopyNonZeroAllKeysOffset)
* [CopyNonZeroAllKeysOffsetName](#CopyNonZeroAllKeysOffsetName)
* [CopyNonZeroKeyColor](#CopyNonZeroKeyColor)
* [CopyNonZeroKeyColorName](#CopyNonZeroKeyColorName)
* [CopyNonZeroTargetAllKeys](#CopyNonZeroTargetAllKeys)
* [CopyNonZeroTargetAllKeysAllFrames](#CopyNonZeroTargetAllKeysAllFrames)
* [CopyNonZeroTargetAllKeysAllFramesName](#CopyNonZeroTargetAllKeysAllFramesName)
* [CopyNonZeroTargetAllKeysAllFramesOffset](#CopyNonZeroTargetAllKeysAllFramesOffset)
* [CopyNonZeroTargetAllKeysAllFramesOffsetName](#CopyNonZeroTargetAllKeysAllFramesOffsetName)
* [CopyNonZeroTargetAllKeysName](#CopyNonZeroTargetAllKeysName)
* [CopyZeroTargetAllKeysAllFrames](#CopyZeroTargetAllKeysAllFrames)
* [CopyZeroTargetAllKeysAllFramesName](#CopyZeroTargetAllKeysAllFramesName)
* [DuplicateFirstFrame](#DuplicateFirstFrame)
* [DuplicateFirstFrameName](#DuplicateFirstFrameName)
* [DuplicateFrames](#DuplicateFrames)
* [DuplicateFramesName](#DuplicateFramesName)
* [DuplicateMirrorFrames](#DuplicateMirrorFrames)
* [DuplicateMirrorFramesName](#DuplicateMirrorFramesName)
* [FadeEndFrames](#FadeEndFrames)
* [FadeEndFramesName](#FadeEndFramesName)
* [FadeStartFrames](#FadeStartFrames)
* [FadeStartFramesName](#FadeStartFramesName)
* [FillColor](#FillColor)
* [FillColorAllFrames](#FillColorAllFrames)
* [FillColorAllFramesName](#FillColorAllFramesName)
* [FillColorAllFramesRGB](#FillColorAllFramesRGB)
* [FillColorAllFramesRGBName](#FillColorAllFramesRGBName)
* [FillColorName](#FillColorName)
* [FillColorRGB](#FillColorRGB)
* [FillColorRGBName](#FillColorRGBName)
* [FillNonZeroColor](#FillNonZeroColor)
* [FillNonZeroColorAllFrames](#FillNonZeroColorAllFrames)
* [FillNonZeroColorAllFramesName](#FillNonZeroColorAllFramesName)
* [FillNonZeroColorAllFramesRGB](#FillNonZeroColorAllFramesRGB)
* [FillNonZeroColorAllFramesRGBName](#FillNonZeroColorAllFramesRGBName)
* [FillNonZeroColorName](#FillNonZeroColorName)
* [FillNonZeroColorRGB](#FillNonZeroColorRGB)
* [FillNonZeroColorRGBName](#FillNonZeroColorRGBName)
* [FillRandomColors](#FillRandomColors)
* [FillRandomColorsAllFrames](#FillRandomColorsAllFrames)
* [FillRandomColorsAllFramesName](#FillRandomColorsAllFramesName)
* [FillRandomColorsBlackAndWhite](#FillRandomColorsBlackAndWhite)
* [FillRandomColorsBlackAndWhiteAllFrames](#FillRandomColorsBlackAndWhiteAllFrames)
* [FillRandomColorsBlackAndWhiteAllFramesName](#FillRandomColorsBlackAndWhiteAllFramesName)
* [FillRandomColorsBlackAndWhiteName](#FillRandomColorsBlackAndWhiteName)
* [FillRandomColorsName](#FillRandomColorsName)
* [FillThresholdColorsAllFrames](#FillThresholdColorsAllFrames)
* [FillThresholdColorsAllFramesName](#FillThresholdColorsAllFramesName)
* [FillThresholdColorsAllFramesRGB](#FillThresholdColorsAllFramesRGB)
* [FillThresholdColorsAllFramesRGBName](#FillThresholdColorsAllFramesRGBName)
* [FillThresholdColorsMinMaxAllFramesRGB](#FillThresholdColorsMinMaxAllFramesRGB)
* [FillThresholdColorsMinMaxAllFramesRGBName](#FillThresholdColorsMinMaxAllFramesRGBName)
* [FillThresholdColorsRGB](#FillThresholdColorsRGB)
* [FillThresholdColorsRGBName](#FillThresholdColorsRGBName)
* [FillThresholdRGBColorsAllFramesRGB](#FillThresholdRGBColorsAllFramesRGB)
* [FillThresholdRGBColorsAllFramesRGBName](#FillThresholdRGBColorsAllFramesRGBName)
* [FillZeroColor](#FillZeroColor)
* [FillZeroColorAllFrames](#FillZeroColorAllFrames)
* [FillZeroColorAllFramesName](#FillZeroColorAllFramesName)
* [FillZeroColorAllFramesRGB](#FillZeroColorAllFramesRGB)
* [FillZeroColorAllFramesRGBName](#FillZeroColorAllFramesRGBName)
* [FillZeroColorName](#FillZeroColorName)
* [FillZeroColorRGB](#FillZeroColorRGB)
* [FillZeroColorRGBName](#FillZeroColorRGBName)
* [GetAnimation](#GetAnimation)
* [GetAnimationCount](#GetAnimationCount)
* [GetAnimationId](#GetAnimationId)
* [GetAnimationName](#GetAnimationName)
* [GetCurrentFrame](#GetCurrentFrame)
* [GetCurrentFrameName](#GetCurrentFrameName)
* [GetFrameCount](#GetFrameCount)
* [GetFrameCountName](#GetFrameCountName)
* [GetKeyColor](#GetKeyColor)
* [GetKeyColorName](#GetKeyColorName)
* [GetMaxColumn](#GetMaxColumn)
* [GetMaxLeds](#GetMaxLeds)
* [GetMaxRow](#GetMaxRow)
* [GetPlayingAnimationCount](#GetPlayingAnimationCount)
* [GetPlayingAnimationId](#GetPlayingAnimationId)
* [GetRGB](#GetRGB)
* [InsertDelay](#InsertDelay)
* [InsertDelayName](#InsertDelayName)
* [InsertFrame](#InsertFrame)
* [InsertFrameName](#InsertFrameName)
* [InvertColorsAllFrames](#InvertColorsAllFrames)
* [InvertColorsAllFramesName](#InvertColorsAllFramesName)
* [IsActive](#IsActive)
* [IsConnected](#IsConnected)
* [IsInitialized](#IsInitialized)
* [Lerp](#Lerp)
* [LerpColor](#LerpColor)
* [LoadAnimation](#LoadAnimation)
* [LoadAnimationName](#LoadAnimationName)
* [MakeBlankFrames](#MakeBlankFrames)
* [MakeBlankFramesName](#MakeBlankFramesName)
* [MakeBlankFramesRandom](#MakeBlankFramesRandom)
* [MakeBlankFramesRandomBlackAndWhite](#MakeBlankFramesRandomBlackAndWhite)
* [MakeBlankFramesRandomBlackAndWhiteName](#MakeBlankFramesRandomBlackAndWhiteName)
* [MakeBlankFramesRandomName](#MakeBlankFramesRandomName)
* [MakeBlankFramesRGB](#MakeBlankFramesRGB)
* [MakeBlankFramesRGBName](#MakeBlankFramesRGBName)
* [MultiplyColorLerpAllFrames](#MultiplyColorLerpAllFrames)
* [MultiplyColorLerpAllFramesName](#MultiplyColorLerpAllFramesName)
* [MultiplyIntensity](#MultiplyIntensity)
* [MultiplyIntensityAllFrames](#MultiplyIntensityAllFrames)
* [MultiplyIntensityAllFramesName](#MultiplyIntensityAllFramesName)
* [MultiplyIntensityAllFramesRGB](#MultiplyIntensityAllFramesRGB)
* [MultiplyIntensityAllFramesRGBName](#MultiplyIntensityAllFramesRGBName)
* [MultiplyIntensityColor](#MultiplyIntensityColor)
* [MultiplyIntensityColorAllFrames](#MultiplyIntensityColorAllFrames)
* [MultiplyIntensityColorAllFramesName](#MultiplyIntensityColorAllFramesName)
* [MultiplyIntensityColorName](#MultiplyIntensityColorName)
* [MultiplyIntensityName](#MultiplyIntensityName)
* [MultiplyIntensityRGB](#MultiplyIntensityRGB)
* [MultiplyIntensityRGBName](#MultiplyIntensityRGBName)
* [MultiplyNonZeroTargetColorLerpAllFrames](#MultiplyNonZeroTargetColorLerpAllFrames)
* [MultiplyNonZeroTargetColorLerpAllFramesName](#MultiplyNonZeroTargetColorLerpAllFramesName)
* [MultiplyTargetColorLerpAllFrames](#MultiplyTargetColorLerpAllFrames)
* [MultiplyTargetColorLerpAllFramesName](#MultiplyTargetColorLerpAllFramesName)
* [OffsetColors](#OffsetColors)
* [OffsetColorsAllFrames](#OffsetColorsAllFrames)
* [OffsetColorsAllFramesName](#OffsetColorsAllFramesName)
* [OffsetColorsName](#OffsetColorsName)
* [OffsetNonZeroColors](#OffsetNonZeroColors)
* [OffsetNonZeroColorsAllFrames](#OffsetNonZeroColorsAllFrames)
* [OffsetNonZeroColorsAllFramesName](#OffsetNonZeroColorsAllFramesName)
* [OffsetNonZeroColorsName](#OffsetNonZeroColorsName)
* [OpenAnimationFromMemory](#OpenAnimationFromMemory)
* [OverrideFrameDurationName](#OverrideFrameDurationName)
* [PlayAnimation](#PlayAnimation)
* [PlayAnimationName](#PlayAnimationName)
* [PreviewFrame](#PreviewFrame)
* [PreviewFrameName](#PreviewFrameName)
* [ReduceFrames](#ReduceFrames)
* [ReduceFramesName](#ReduceFramesName)
* [ReverseAllFrames](#ReverseAllFrames)
* [ReverseAllFramesName](#ReverseAllFramesName)
* [SetChromaCustomColorAllFramesName](#SetChromaCustomColorAllFramesName)
* [SetChromaCustomFlagName](#SetChromaCustomFlagName)
* [SetCurrentFrame](#SetCurrentFrame)
* [SetCurrentFrameName](#SetCurrentFrameName)
* [SetEventName](#SetEventName)
* [SetIdleAnimationName](#SetIdleAnimationName)
* [SetKeyColor](#SetKeyColor)
* [SetKeyColorAllFrames](#SetKeyColorAllFrames)
* [SetKeyColorAllFramesName](#SetKeyColorAllFramesName)
* [SetKeyColorName](#SetKeyColorName)
* [SetKeyNonZeroColor](#SetKeyNonZeroColor)
* [SetKeyNonZeroColorName](#SetKeyNonZeroColorName)
* [SetKeyRowColumnColorName](#SetKeyRowColumnColorName)
* [SetKeysColor](#SetKeysColor)
* [SetKeysColorAllFrames](#SetKeysColorAllFrames)
* [SetKeysColorAllFramesName](#SetKeysColorAllFramesName)
* [SetKeysColorAllFramesRGB](#SetKeysColorAllFramesRGB)
* [SetKeysColorAllFramesRGBName](#SetKeysColorAllFramesRGBName)
* [SetKeysColorName](#SetKeysColorName)
* [SetKeysColorRGB](#SetKeysColorRGB)
* [SetKeysColorRGBName](#SetKeysColorRGBName)
* [SetKeysNonZeroColor](#SetKeysNonZeroColor)
* [SetKeysNonZeroColorAllFrames](#SetKeysNonZeroColorAllFrames)
* [SetKeysNonZeroColorAllFramesName](#SetKeysNonZeroColorAllFramesName)
* [SetKeysNonZeroColorName](#SetKeysNonZeroColorName)
* [SetStaticColor](#SetStaticColor)
* [SetStaticColorAll](#SetStaticColorAll)
* [StopAll](#StopAll)
* [StopAnimation](#StopAnimation)
* [StopAnimationType](#StopAnimationType)
* [StreamBroadcast](#StreamBroadcast)
* [StreamBroadcastEnd](#StreamBroadcastEnd)
* [StreamGetAuthShortcode](#StreamGetAuthShortcode)
* [StreamGetFocus](#StreamGetFocus)
* [StreamGetId](#StreamGetId)
* [StreamGetKey](#StreamGetKey)
* [StreamGetStatusString](#StreamGetStatusString)
* [StreamReleaseShortcode](#StreamReleaseShortcode)
* [StreamSetFocus](#StreamSetFocus)
* [StreamWatch](#StreamWatch)
* [StreamWatchEnd](#StreamWatchEnd)
* [SubtractNonZeroAllKeys](#SubtractNonZeroAllKeys)
* [SubtractNonZeroAllKeysAllFrames](#SubtractNonZeroAllKeysAllFrames)
* [SubtractNonZeroAllKeysAllFramesName](#SubtractNonZeroAllKeysAllFramesName)
* [SubtractNonZeroAllKeysAllFramesOffset](#SubtractNonZeroAllKeysAllFramesOffset)
* [SubtractNonZeroAllKeysAllFramesOffsetName](#SubtractNonZeroAllKeysAllFramesOffsetName)
* [SubtractNonZeroAllKeysName](#SubtractNonZeroAllKeysName)
* [SubtractNonZeroTargetAllKeysAllFrames](#SubtractNonZeroTargetAllKeysAllFrames)
* [SubtractNonZeroTargetAllKeysAllFramesName](#SubtractNonZeroTargetAllKeysAllFramesName)
* [SubtractNonZeroTargetAllKeysAllFramesOffset](#SubtractNonZeroTargetAllKeysAllFramesOffset)
* [SubtractNonZeroTargetAllKeysAllFramesOffsetName](#SubtractNonZeroTargetAllKeysAllFramesOffsetName)
* [TrimEndFrames](#TrimEndFrames)
* [TrimEndFramesName](#TrimEndFramesName)
* [TrimFrame](#TrimFrame)
* [TrimFrameName](#TrimFrameName)
* [TrimStartFrames](#TrimStartFrames)
* [TrimStartFramesName](#TrimStartFramesName)
* [UnloadAnimation](#UnloadAnimation)
* [UnloadAnimationName](#UnloadAnimationName)
* [UseForwardChromaEvents](#UseForwardChromaEvents)
* [UseIdleAnimation](#UseIdleAnimation)
* [UseIdleAnimations](#UseIdleAnimations)
* [UsePreloading](#UsePreloading)
* [UsePreloadingName](#UsePreloadingName)

---
<a name="AddNonZeroAllKeys"></a>
**AddNonZeroAllKeys**

Add source color to target where color is not black for frame id, reference 
source and target by id.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroAllKeys(int32 sourceAnimationId, 
	int32 targetAnimationId, int32 frameId);
```

---
<a name="AddNonZeroAllKeysAllFrames"></a>
**AddNonZeroAllKeysAllFrames**

Add source color to target where color is not black for all frames, reference 
source and target by id.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFrames(int32 sourceAnimationId, 
	int32 targetAnimationId);
```

---
<a name="AddNonZeroAllKeysAllFramesName"></a>
**AddNonZeroAllKeysAllFramesName**

Add source color to target where color is not black for all frames, reference 
source and target by name.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesName(const FString& 
	sourceAnimationName, const FString& targetAnimationName);
```

---
<a name="AddNonZeroAllKeysAllFramesOffset"></a>
**AddNonZeroAllKeysAllFramesOffset**

Add source color to target where color is not black for all frames starting 
at offset for the length of the source, reference source and target by 
id.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesOffset(int32 sourceAnimationId, 
	int32 targetAnimationId, int32 offset);
```

---
<a name="AddNonZeroAllKeysAllFramesOffsetName"></a>
**AddNonZeroAllKeysAllFramesOffsetName**

Add source color to target where color is not black for all frames starting 
at offset for the length of the source, reference source and target by 
name.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysAllFramesOffsetName(const 
	FString& sourceAnimationName, const FString& targetAnimationName, int32 
	offset);
```

---
<a name="AddNonZeroAllKeysName"></a>
**AddNonZeroAllKeysName**

Add source color to target where color is not black for frame id, reference 
source and target by name.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroAllKeysName(const FString& sourceAnimationName, 
	const FString& targetAnimationName, int32 frameId);
```

---
<a name="AddNonZeroTargetAllKeysAllFrames"></a>
**AddNonZeroTargetAllKeysAllFrames**

Add source color to target where the target color is not black for all frames, 
reference source and target by id.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFrames(int32 sourceAnimationId, 
	int32 targetAnimationId);
```

---
<a name="AddNonZeroTargetAllKeysAllFramesName"></a>
**AddNonZeroTargetAllKeysAllFramesName**

Add source color to target where the target color is not black for all frames, 
reference source and target by name.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesName(const 
	FString& sourceAnimationName, const FString& targetAnimationName);
```

---
<a name="AddNonZeroTargetAllKeysAllFramesOffset"></a>
**AddNonZeroTargetAllKeysAllFramesOffset**

Add source color to target where the target color is not black for all frames 
starting at offset for the length of the source, reference source and target 
by id.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesOffset(int32 
	sourceAnimationId, int32 targetAnimationId, int32 offset);
```

---
<a name="AddNonZeroTargetAllKeysAllFramesOffsetName"></a>
**AddNonZeroTargetAllKeysAllFramesOffsetName**

Add source color to target where the target color is not black for all frames 
starting at offset for the length of the source, reference source and target 
by name.
```c++
void UChromaSDKPluginBPLibrary::AddNonZeroTargetAllKeysAllFramesOffsetName(const 
	FString& sourceAnimationName, const FString& targetAnimationName, int32 
	offset);
```

---
<a name="AppendAllFrames"></a>
**AppendAllFrames**

Append all source frames to the target animation, reference source and target 
by id.
```c++
void UChromaSDKPluginBPLibrary::AppendAllFrames(int32 sourceAnimationId, 
	int32 targetAnimationId);
```

---
<a name="AppendAllFramesName"></a>
**AppendAllFramesName**

Append all source frames to the target animation, reference source and target 
by name.
```c++
void UChromaSDKPluginBPLibrary::AppendAllFramesName(const FString& sourceAnimationName, 
	const FString& targetAnimationName);
```

---
<a name="ClearAll"></a>
**ClearAll**

`PluginClearAll` will issue a `CLEAR` effect for all devices.
```c++
void UChromaSDKPluginBPLibrary::ClearAll();
```

---
<a name="ClearAnimationType"></a>
**ClearAnimationType**

`PluginClearAnimationType` will issue a `CLEAR` effect for the given device.
```c++
void UChromaSDKPluginBPLibrary::ClearAnimationType(EChromaSDKDeviceEnum::Type 
	device);
```

---
<a name="CloseAll"></a>
**CloseAll**

`PluginCloseAll` closes all open animations so they can be reloaded from 
disk. The set of animations will be stopped if playing.
```c++
void UChromaSDKPluginBPLibrary::CloseAll();
```

---
<a name="CloseAnimation"></a>
**CloseAnimation**

Closes the `Chroma` animation to free up resources referenced by id. Returns 
the animation id upon success. Returns negative one upon failure. This 
might be used while authoring effects if there was a change necessitating 
re-opening the animation. The animation id can no longer be used once closed.
```c++
void UChromaSDKPluginBPLibrary::CloseAnimation(const int32 animationId);
```

---
<a name="CloseAnimationName"></a>
**CloseAnimationName**

Closes the `Chroma` animation referenced by name so that the animation can 
be reloaded from disk.
```c++
void UChromaSDKPluginBPLibrary::CloseAnimationName(const FString& animationName);
```

---
<a name="CopyAllKeys"></a>
**CopyAllKeys**

Copy source animation to target animation for the given frame. Source and 
target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::CopyAllKeys(int32 sourceAnimationId, int32 
	targetAnimationId, int32 frameId);
```

---
<a name="CopyAllKeysName"></a>
**CopyAllKeysName**

Copy source animation to target animation for the given frame. Source and 
target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::CopyAllKeysName(const FString& sourceAnimationName, 
	const FString& targetAnimationName, int32 frameId);
```

---
<a name="CopyAnimation"></a>
**CopyAnimation**

Copy animation to named target animation in memory. If target animation 
exists, close first. Source is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::CopyAnimation(int32 sourceAnimationId, const 
	FString& targetAnimationName);
```

---
<a name="CopyAnimationName"></a>
**CopyAnimationName**

Copy animation to named target animation in memory. If target animation 
exists, close first. Source is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::CopyAnimationName(const FString& sourceAnimationName, 
	const FString& targetAnimationName);
```

---
<a name="CopyKeyColor"></a>
**CopyKeyColor**

Copy animation key color from the source animation to the target animation 
for the given frame. Reference the source and target by id.
```c++
void UChromaSDKPluginBPLibrary::CopyKeyColor(int32 sourceAnimationId, int32 
	targetAnimationId, int32 frameIndex, EChromaSDKKeyboardKey::Type key);
```

---
<a name="CopyKeyColorName"></a>
**CopyKeyColorName**

Copy animation key color from the source animation to the target animation 
for the given frame.
```c++
void UChromaSDKPluginBPLibrary::CopyKeyColorName(const FString& sourceAnimationName, 
	const FString& targetAnimationName, const int32 frameIndex, EChromaSDKKeyboardKey::Type 
	key);
```

---
<a name="CopyKeysColor"></a>
**CopyKeysColor**

Copy animation color for a set of keys from the source animation to the 
target animation for the given frame. Reference the source and target by 
id.
```c++
void UChromaSDKPluginBPLibrary::CopyKeysColor(int32 sourceAnimationId, int32 
	targetAnimationId, int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys);
```

---
<a name="CopyKeysColorAllFrames"></a>
**CopyKeysColorAllFrames**

Copy animation color for a set of keys from the source animation to the 
target animation for all frames. Reference the source and target by id.
```c++
void UChromaSDKPluginBPLibrary::CopyKeysColorAllFrames(int32 sourceAnimationId, 
	int32 targetAnimationId, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys);
```

---
<a name="CopyKeysColorAllFramesName"></a>
**CopyKeysColorAllFramesName**

Copy animation color for a set of keys from the source animation to the 
target animation for all frames. Reference the source and target by name.
```c++
void UChromaSDKPluginBPLibrary::CopyKeysColorAllFramesName(const FString& 
	sourceAnimationName, const FString& targetAnimationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys);
```

---
<a name="CopyKeysColorName"></a>
**CopyKeysColorName**

Copy animation color for a set of keys from the source animation to the 
target animation for the given frame. Reference the source and target by 
name.
```c++
void UChromaSDKPluginBPLibrary::CopyKeysColorName(const FString& sourceAnimationName, 
	const FString& targetAnimationName, const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys);
```

---
<a name="CopyNonZeroAllKeys"></a>
**CopyNonZeroAllKeys**

Copy source animation to target animation for the given frame. Source and 
target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeys(int32 sourceAnimationId, 
	int32 targetAnimationId, int32 frameId);
```

---
<a name="CopyNonZeroAllKeysAllFrames"></a>
**CopyNonZeroAllKeysAllFrames**

Copy nonzero colors from a source animation to a target animation for all 
frames. Reference source and target by id.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFrames(int32 sourceAnimationId, 
	int32 targetAnimationId);
```

---
<a name="CopyNonZeroAllKeysAllFramesName"></a>
**CopyNonZeroAllKeysAllFramesName**

Copy nonzero colors from a source animation to a target animation for all 
frames. Reference source and target by name.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesName(const FString& 
	sourceAnimationName, const FString& targetAnimationName);
```

---
<a name="CopyNonZeroAllKeysAllFramesOffset"></a>
**CopyNonZeroAllKeysAllFramesOffset**

Copy nonzero colors from a source animation to a target animation for all 
frames starting at the offset for the length of the source animation. The 
source and target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesOffset(int32 
	sourceAnimationId, int32 targetAnimationId, int32 offset);
```

---
<a name="CopyNonZeroAllKeysAllFramesOffsetName"></a>
**CopyNonZeroAllKeysAllFramesOffsetName**

Copy nonzero colors from a source animation to a target animation for all 
frames starting at the offset for the length of the source animation. The 
source and target are referenced by name.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysAllFramesOffsetName(const 
	FString& sourceAnimationName, const FString& targetAnimationName, int32 
	offset);
```

---
<a name="CopyNonZeroAllKeysName"></a>
**CopyNonZeroAllKeysName**

Copy nonzero colors from source animation to target animation for the specified 
frame. Source and target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysName(const FString& sourceAnimationName, 
	const FString& targetAnimationName, int32 frameId);
```

---
<a name="CopyNonZeroAllKeysOffset"></a>
**CopyNonZeroAllKeysOffset**

Copy nonzero colors from the source animation to the target animation from 
the source frame to the target offset frame. Source and target are referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysOffset(int32 sourceAnimationId, 
	int32 targetAnimationId, int32 frameId, int32 offset);
```

---
<a name="CopyNonZeroAllKeysOffsetName"></a>
**CopyNonZeroAllKeysOffsetName**

Copy nonzero colors from the source animation to the target animation from 
the source frame to the target offset frame. Source and target are referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroAllKeysOffsetName(const FString& 
	sourceAnimationName, const FString& targetAnimationName, int32 frameId, 
	int32 offset);
```

---
<a name="CopyNonZeroKeyColor"></a>
**CopyNonZeroKeyColor**

Copy animation key color from the source animation to the target animation 
for the given frame where color is not zero.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroKeyColor(int32 sourceAnimationId, 
	int32 targetAnimationId, int32 frameIndex, EChromaSDKKeyboardKey::Type 
	key);
```

---
<a name="CopyNonZeroKeyColorName"></a>
**CopyNonZeroKeyColorName**

Copy animation key color from the source animation to the target animation 
for the given frame where color is not zero.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroKeyColorName(const FString& sourceAnimationName, 
	const FString& targetAnimationName, const int32 frameIndex, EChromaSDKKeyboardKey::Type 
	key);
```

---
<a name="CopyNonZeroTargetAllKeys"></a>
**CopyNonZeroTargetAllKeys**

Copy nonzero colors from the source animation to the target animation where 
the target color is nonzero for the specified frame. Source and target 
are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeys(int32 sourceAnimationId, 
	int32 targetAnimationId, int32 frameId);
```

---
<a name="CopyNonZeroTargetAllKeysAllFrames"></a>
**CopyNonZeroTargetAllKeysAllFrames**

Copy nonzero colors from the source animation to the target animation where 
the target color is nonzero for all frames. Source and target are referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFrames(int32 
	sourceAnimationId, int32 targetAnimationId);
```

---
<a name="CopyNonZeroTargetAllKeysAllFramesName"></a>
**CopyNonZeroTargetAllKeysAllFramesName**

Copy nonzero colors from the source animation to the target animation where 
the target color is nonzero for all frames. Source and target are referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesName(const 
	FString& sourceAnimationName, const FString& targetAnimationName);
```

---
<a name="CopyNonZeroTargetAllKeysAllFramesOffset"></a>
**CopyNonZeroTargetAllKeysAllFramesOffset**

Copy nonzero colors from the source animation to the target animation where 
the target color is nonzero for all frames. Source and target are referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesOffset(int32 
	sourceAnimationId, int32 targetAnimationId, int32 offset);
```

---
<a name="CopyNonZeroTargetAllKeysAllFramesOffsetName"></a>
**CopyNonZeroTargetAllKeysAllFramesOffsetName**

Copy nonzero colors from the source animation to the target animation where 
the target color is nonzero for all frames starting at the target offset 
for the length of the source animation. Source and target animations are 
referenced by name.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysAllFramesOffsetName(const 
	FString& sourceAnimationName, const FString& targetAnimationName, int32 
	offset);
```

---
<a name="CopyNonZeroTargetAllKeysName"></a>
**CopyNonZeroTargetAllKeysName**

Copy nonzero colors from the source animation to the target animation where 
the target color is nonzero for the specified frame. The source and target 
are referenced by name.
```c++
void UChromaSDKPluginBPLibrary::CopyNonZeroTargetAllKeysName(const FString& 
	sourceAnimationName, const FString& targetAnimationName, int32 frameId);
```

---
<a name="CopyZeroTargetAllKeysAllFrames"></a>
**CopyZeroTargetAllKeysAllFrames**

Copy nonzero color from source animation to target animation where target 
is zero for all frames. Source and target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::CopyZeroTargetAllKeysAllFrames(int32 sourceAnimationId, 
	int32 targetAnimationId);
```

---
<a name="CopyZeroTargetAllKeysAllFramesName"></a>
**CopyZeroTargetAllKeysAllFramesName**

Copy nonzero color from source animation to target animation where target 
is zero for all frames. Source and target are referenced by name.
```c++
void UChromaSDKPluginBPLibrary::CopyZeroTargetAllKeysAllFramesName(const 
	FString& sourceAnimationName, const FString& targetAnimationName);
```

---
<a name="DuplicateFirstFrame"></a>
**DuplicateFirstFrame**

Duplicate the first animation frame so that the animation length matches 
the frame count. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::DuplicateFirstFrame(int32 animationId, int32 
	frameCount);
```

---
<a name="DuplicateFirstFrameName"></a>
**DuplicateFirstFrameName**

Duplicate the first animation frame so that the animation length matches 
the frame count. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::DuplicateFirstFrameName(const FString& animationName, 
	int32 frameCount);
```

---
<a name="DuplicateFrames"></a>
**DuplicateFrames**

Duplicate all the frames of the animation to double the animation length. 
Frame 1 becomes frame 1 and 2. Frame 2 becomes frame 3 and 4. And so on. 
The animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::DuplicateFrames(int32 animationId);
```

---
<a name="DuplicateFramesName"></a>
**DuplicateFramesName**

Duplicate all the frames of the animation to double the animation length. 
Frame 1 becomes frame 1 and 2. Frame 2 becomes frame 3 and 4. And so on. 
The animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::DuplicateFramesName(const FString& animationName);
```

---
<a name="DuplicateMirrorFrames"></a>
**DuplicateMirrorFrames**

Duplicate all the animation frames in reverse so that the animation plays 
forwards and backwards. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::DuplicateMirrorFrames(int32 animationId);
```

---
<a name="DuplicateMirrorFramesName"></a>
**DuplicateMirrorFramesName**

Duplicate all the animation frames in reverse so that the animation plays 
forwards and backwards. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::DuplicateMirrorFramesName(const FString& 
	animationName);
```

---
<a name="FadeEndFrames"></a>
**FadeEndFrames**

Fade the animation to black starting at the fade frame index to the end 
of the animation. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FadeEndFrames(int32 animationId, int32 fade);
```

---
<a name="FadeEndFramesName"></a>
**FadeEndFramesName**

Fade the animation to black starting at the fade frame index to the end 
of the animation. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FadeEndFramesName(const FString& animationName, 
	int32 fade);
```

---
<a name="FadeStartFrames"></a>
**FadeStartFrames**

Fade the animation from black to full color starting at 0 to the fade frame 
index. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FadeStartFrames(int32 animationId, int32 
	fade);
```

---
<a name="FadeStartFramesName"></a>
**FadeStartFramesName**

Fade the animation from black to full color starting at 0 to the fade frame 
index. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FadeStartFramesName(const FString& animationName, 
	int32 fade);
```

---
<a name="FillColor"></a>
**FillColor**

Set the RGB value for all colors in the specified frame. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::FillColor(int32 animationId, int32 frameId, 
	const FLinearColor& colorParam);
```

---
<a name="FillColorAllFrames"></a>
**FillColorAllFrames**

Set the RGB value for all colors for all frames. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::FillColorAllFrames(int32 animationId, const 
	FLinearColor& colorParam);
```

---
<a name="FillColorAllFramesName"></a>
**FillColorAllFramesName**

Set the RGB value for all colors for all frames. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::FillColorAllFramesName(const FString& animationName, 
	const FLinearColor& colorParam);
```

---
<a name="FillColorAllFramesRGB"></a>
**FillColorAllFramesRGB**

Set the RGB value for all colors for all frames. Use the range of 0 to 255 
for red, green, and blue parameters. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillColorAllFramesRGB(int32 animationId, 
	int32 red, int32 green, int32 blue);
```

---
<a name="FillColorAllFramesRGBName"></a>
**FillColorAllFramesRGBName**

Set the RGB value for all colors for all frames. Use the range of 0 to 255 
for red, green, and blue parameters. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillColorAllFramesRGBName(const FString& 
	animationName, int32 red, int32 green, int32 blue);
```

---
<a name="FillColorName"></a>
**FillColorName**

Set the RGB value for all colors in the specified frame. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::FillColorName(const FString& animationName, 
	int32 frameId, const FLinearColor& colorParam);
```

---
<a name="FillColorRGB"></a>
**FillColorRGB**

Set the RGB value for all colors in the specified frame. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::FillColorRGB(int32 animationId, int32 frameId, 
	int32 red, int32 green, int32 blue);
```

---
<a name="FillColorRGBName"></a>
**FillColorRGBName**

Set the RGB value for all colors in the specified frame. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::FillColorRGBName(const FString& animationName, 
	int32 frameId, int32 red, int32 green, int32 blue);
```

---
<a name="FillNonZeroColor"></a>
**FillNonZeroColor**

This method will only update colors in the animation that are not already 
set to black. Set the RGB value for a subset of colors in the specified 
frame. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillNonZeroColor(int32 animationId, int32 
	frameId, const FLinearColor& colorParam);
```

---
<a name="FillNonZeroColorAllFrames"></a>
**FillNonZeroColorAllFrames**

This method will only update colors in the animation that are not already 
set to black. Set the RGB value for a subset of colors for all frames. 
Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFrames(int32 animationId, 
	const FLinearColor& colorParam);
```

---
<a name="FillNonZeroColorAllFramesName"></a>
**FillNonZeroColorAllFramesName**

This method will only update colors in the animation that are not already 
set to black. Set the RGB value for a subset of colors for all frames. 
Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesName(const FString& 
	animationName, const FLinearColor& colorParam);
```

---
<a name="FillNonZeroColorAllFramesRGB"></a>
**FillNonZeroColorAllFramesRGB**

This method will only update colors in the animation that are not already 
set to black. Set the RGB value for a subset of colors for all frames. 
Use the range of 0 to 255 for red, green, and blue parameters. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesRGB(int32 animationId, 
	int32 red, int32 green, int32 blue);
```

---
<a name="FillNonZeroColorAllFramesRGBName"></a>
**FillNonZeroColorAllFramesRGBName**

This method will only update colors in the animation that are not already 
set to black. Set the RGB value for a subset of colors for all frames. 
Use the range of 0 to 255 for red, green, and blue parameters. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillNonZeroColorAllFramesRGBName(const FString& 
	animationName, int32 red, int32 green, int32 blue);
```

---
<a name="FillNonZeroColorName"></a>
**FillNonZeroColorName**

This method will only update colors in the animation that are not already 
set to black. Set the RGB value for a subset of colors in the specified 
frame. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillNonZeroColorName(const FString& animationName, 
	int32 frameId, const FLinearColor& colorParam);
```

---
<a name="FillNonZeroColorRGB"></a>
**FillNonZeroColorRGB**

This method will only update colors in the animation that are not already 
set to black. Set the RGB value for a subset of colors in the specified 
frame. Use the range of 0 to 255 for red, green, and blue parameters. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillNonZeroColorRGB(int32 animationId, int32 
	frameId, int32 red, int32 green, int32 blue);
```

---
<a name="FillNonZeroColorRGBName"></a>
**FillNonZeroColorRGBName**

This method will only update colors in the animation that are not already 
set to black. Set the RGB value for a subset of colors in the specified 
frame. Use the range of 0 to 255 for red, green, and blue parameters. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillNonZeroColorRGBName(const FString& animationName, 
	int32 frameId, int32 red, int32 green, int32 blue);
```

---
<a name="FillRandomColors"></a>
**FillRandomColors**

Fill the frame with random RGB values for the given frame. Animation is 
referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillRandomColors(int32 animationId, int32 
	frameId);
```

---
<a name="FillRandomColorsAllFrames"></a>
**FillRandomColorsAllFrames**

Fill the frame with random RGB values for all frames. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::FillRandomColorsAllFrames(int32 animationId);
```

---
<a name="FillRandomColorsAllFramesName"></a>
**FillRandomColorsAllFramesName**

Fill the frame with random RGB values for all frames. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::FillRandomColorsAllFramesName(const FString& 
	animationName);
```

---
<a name="FillRandomColorsBlackAndWhite"></a>
**FillRandomColorsBlackAndWhite**

Fill the frame with random black and white values for the specified frame. 
Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhite(int32 animationId, 
	int32 frameId);
```

---
<a name="FillRandomColorsBlackAndWhiteAllFrames"></a>
**FillRandomColorsBlackAndWhiteAllFrames**

Fill the frame with random black and white values for all frames. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteAllFrames(int32 
	animationId);
```

---
<a name="FillRandomColorsBlackAndWhiteAllFramesName"></a>
**FillRandomColorsBlackAndWhiteAllFramesName**

Fill the frame with random black and white values for all frames. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteAllFramesName(const 
	FString& animationName);
```

---
<a name="FillRandomColorsBlackAndWhiteName"></a>
**FillRandomColorsBlackAndWhiteName**

Fill the frame with random black and white values for the specified frame. 
Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillRandomColorsBlackAndWhiteName(const 
	FString& animationName, int32 frameId);
```

---
<a name="FillRandomColorsName"></a>
**FillRandomColorsName**

Fill the frame with random RGB values for the given frame. Animation is 
referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillRandomColorsName(const FString& animationName, 
	int32 frameId);
```

---
<a name="FillThresholdColorsAllFrames"></a>
**FillThresholdColorsAllFrames**

Fill all frames with RGB color where the animation color is less than the 
RGB threshold. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFrames(int32 animationId, 
	int32 threshold, const FLinearColor& colorParam);
```

---
<a name="FillThresholdColorsAllFramesName"></a>
**FillThresholdColorsAllFramesName**

Fill all frames with RGB color where the animation color is less than the 
RGB threshold. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesName(const FString& 
	animationName, int32 threshold, const FLinearColor& colorParam);
```

---
<a name="FillThresholdColorsAllFramesRGB"></a>
**FillThresholdColorsAllFramesRGB**

Fill all frames with RGB color where the animation color is less than the 
threshold. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesRGB(int32 animationId, 
	int32 threshold, int32 red, int32 green, int32 blue);
```

---
<a name="FillThresholdColorsAllFramesRGBName"></a>
**FillThresholdColorsAllFramesRGBName**

Fill all frames with RGB color where the animation color is less than the 
threshold. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdColorsAllFramesRGBName(const 
	FString& animationName, int32 threshold, int32 red, int32 green, int32 
	blue);
```

---
<a name="FillThresholdColorsMinMaxAllFramesRGB"></a>
**FillThresholdColorsMinMaxAllFramesRGB**

Fill all frames with the min RGB color where the animation color is less 
than the min threshold AND with the max RGB color where the animation is 
more than the max threshold. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdColorsMinMaxAllFramesRGB(int32 
	animationId, int32 minThreshold, int32 minRed, int32 minGreen, int32 minBlue, 
	int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 maxBlue);
```

---
<a name="FillThresholdColorsMinMaxAllFramesRGBName"></a>
**FillThresholdColorsMinMaxAllFramesRGBName**

Fill all frames with the min RGB color where the animation color is less 
than the min threshold AND with the max RGB color where the animation is 
more than the max threshold. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdColorsMinMaxAllFramesRGBName(const 
	FString& animationName, int32 minThreshold, int32 minRed, int32 minGreen, 
	int32 minBlue, int32 maxThreshold, int32 maxRed, int32 maxGreen, int32 
	maxBlue);
```

---
<a name="FillThresholdColorsRGB"></a>
**FillThresholdColorsRGB**

Fill the specified frame with RGB color where the animation color is less 
than the RGB threshold. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdColorsRGB(int32 animationId, 
	int32 frameId, int32 threshold, int32 red, int32 green, int32 blue);
```

---
<a name="FillThresholdColorsRGBName"></a>
**FillThresholdColorsRGBName**

Fill the specified frame with RGB color where the animation color is less 
than the RGB threshold. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdColorsRGBName(const FString& 
	animationName, int32 frameId, int32 threshold, int32 red, int32 green, 
	int32 blue);
```

---
<a name="FillThresholdRGBColorsAllFramesRGB"></a>
**FillThresholdRGBColorsAllFramesRGB**

Fill all frames with RGB color where the animation color is less than the 
RGB threshold. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdRGBColorsAllFramesRGB(int32 
	animationId, int32 redThreshold, int32 greenThreshold, int32 blueThreshold, 
	int32 red, int32 green, int32 blue);
```

---
<a name="FillThresholdRGBColorsAllFramesRGBName"></a>
**FillThresholdRGBColorsAllFramesRGBName**

Fill all frames with RGB color where the animation color is less than the 
RGB threshold. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillThresholdRGBColorsAllFramesRGBName(const 
	FString& animationName, int32 redThreshold, int32 greenThreshold, int32 
	blueThreshold, int32 red, int32 green, int32 blue);
```

---
<a name="FillZeroColor"></a>
**FillZeroColor**

Fill the specified frame with RGB color where the animation color is zero. 
Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillZeroColor(int32 animationId, int32 frameId, 
	const FLinearColor& colorParam);
```

---
<a name="FillZeroColorAllFrames"></a>
**FillZeroColorAllFrames**

Fill all frames with RGB color where the animation color is zero. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillZeroColorAllFrames(int32 animationId, 
	const FLinearColor& colorParam);
```

---
<a name="FillZeroColorAllFramesName"></a>
**FillZeroColorAllFramesName**

Fill all frames with RGB color where the animation color is zero. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesName(const FString& 
	animationName, const FLinearColor& colorParam);
```

---
<a name="FillZeroColorAllFramesRGB"></a>
**FillZeroColorAllFramesRGB**

Fill all frames with RGB color where the animation color is zero. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesRGB(int32 animationId, 
	int32 red, int32 green, int32 blue);
```

---
<a name="FillZeroColorAllFramesRGBName"></a>
**FillZeroColorAllFramesRGBName**

Fill all frames with RGB color where the animation color is zero. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillZeroColorAllFramesRGBName(const FString& 
	animationName, int32 red, int32 green, int32 blue);
```

---
<a name="FillZeroColorName"></a>
**FillZeroColorName**

Fill the specified frame with RGB color where the animation color is zero. 
Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillZeroColorName(const FString& animationName, 
	int32 frameId, const FLinearColor& colorParam);
```

---
<a name="FillZeroColorRGB"></a>
**FillZeroColorRGB**

Fill the specified frame with RGB color where the animation color is zero. 
Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::FillZeroColorRGB(int32 animationId, int32 
	frameId, int32 red, int32 green, int32 blue);
```

---
<a name="FillZeroColorRGBName"></a>
**FillZeroColorRGBName**

Fill the specified frame with RGB color where the animation color is zero. 
Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::FillZeroColorRGBName(const FString& animationName, 
	int32 frameId, int32 red, int32 green, int32 blue);
```

---
<a name="GetAnimation"></a>
**GetAnimation**

Get the animation id for the named animation.
```c++
int32 UChromaSDKPluginBPLibrary::GetAnimation(const FString& animationName);
```

---
<a name="GetAnimationCount"></a>
**GetAnimationCount**

`PluginGetAnimationCount` will return the number of loaded animations.
```c++
int32 UChromaSDKPluginBPLibrary::GetAnimationCount();
```

---
<a name="GetAnimationId"></a>
**GetAnimationId**

`PluginGetAnimationId` will return the `animationId` given the `index` of 
the loaded animation. The `index` is zero-based and less than the number 
returned by `PluginGetAnimationCount`. Use `PluginGetAnimationName` to 
get the name of the animation.
```c++
int32 UChromaSDKPluginBPLibrary::GetAnimationId(const FString& animationName);
```

---
<a name="GetAnimationName"></a>
**GetAnimationName**

`PluginGetAnimationName` takes an `animationId` and returns the name of 
the animation of the `.chroma` animation file. If a name is not available 
then an empty string will be returned.
```c++
FString UChromaSDKPluginBPLibrary::GetAnimationName(const int32 animationId);
```

---
<a name="GetCurrentFrame"></a>
**GetCurrentFrame**

Get the current frame of the animation referenced by id.
```c++
int32 UChromaSDKPluginBPLibrary::GetCurrentFrame(int32 animationId);
```

---
<a name="GetCurrentFrameName"></a>
**GetCurrentFrameName**

Get the current frame of the animation referenced by name.
```c++
int32 UChromaSDKPluginBPLibrary::GetCurrentFrameName(const FString& animationName);
```

---
<a name="GetFrameCount"></a>
**GetFrameCount**

Returns the frame count of a `Chroma` animation upon success. Returns negative 
one upon failure.
```c++
int32 UChromaSDKPluginBPLibrary::GetFrameCount(const int32 animationId);
```

---
<a name="GetFrameCountName"></a>
**GetFrameCountName**

Returns the frame count of a `Chroma` animation upon success. Returns negative 
one upon failure.
```c++
int32 UChromaSDKPluginBPLibrary::GetFrameCountName(const FString& animationName);
```

---
<a name="GetKeyColor"></a>
**GetKeyColor**

Get the color of an animation key for the given frame referenced by id.
```c++
FLinearColor UChromaSDKPluginBPLibrary::GetKeyColor(int32 animationId, int32 
	frameIndex, EChromaSDKKeyboardKey::Type key);
```

---
<a name="GetKeyColorName"></a>
**GetKeyColorName**

Get the color of an animation key for the given frame referenced by name.
```c++
FLinearColor UChromaSDKPluginBPLibrary::GetKeyColorName(const FString& animationName, 
	const int32 frameIndex, EChromaSDKKeyboardKey::Type key);
```

---
<a name="GetMaxColumn"></a>
**GetMaxColumn**

Returns the `MAX COLUMN` given the `EChromaSDKDevice2DEnum` device as an 
integer upon success. Returns negative one upon failure.
```c++
int32 UChromaSDKPluginBPLibrary::GetMaxColumn(EChromaSDKDevice2DEnum::Type 
	device);
```

---
<a name="GetMaxLeds"></a>
**GetMaxLeds**

Returns the MAX LEDS given the `EChromaSDKDevice1DEnum` device as an integer 
upon success. Returns negative one upon failure.
```c++
int32 UChromaSDKPluginBPLibrary::GetMaxLeds(EChromaSDKDevice1DEnum::Type 
	device);
```

---
<a name="GetMaxRow"></a>
**GetMaxRow**

Returns the `MAX ROW` given the `EChromaSDKDevice2DEnum` device as an integer 
upon success. Returns negative one upon failure.
```c++
int32 UChromaSDKPluginBPLibrary::GetMaxRow(EChromaSDKDevice2DEnum::Type 
	device);
```

---
<a name="GetPlayingAnimationCount"></a>
**GetPlayingAnimationCount**

`PluginGetPlayingAnimationCount` will return the number of playing animations.
```c++
int32 UChromaSDKPluginBPLibrary::GetPlayingAnimationCount();
```

---
<a name="GetPlayingAnimationId"></a>
**GetPlayingAnimationId**

`PluginGetPlayingAnimationId` will return the `animationId` given the `index` 
of the playing animation. The `index` is zero-based and less than the number 
returned by `PluginGetPlayingAnimationCount`. Use `PluginGetAnimationName` 
to get the name of the animation.
```c++
int32 UChromaSDKPluginBPLibrary::GetPlayingAnimationId(int32 index);
```

---
<a name="GetRGB"></a>
**GetRGB**

Get the RGB color given red, green, and blue.
```c++
FLinearColor UChromaSDKPluginBPLibrary::GetRGB(int32 red, int32 green, int32 
	blue);
```

---
<a name="InsertDelay"></a>
**InsertDelay**

Insert an animation delay by duplicating the frame by the delay number of 
times. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::InsertDelay(int32 animationId, int32 frameId, 
	int32 delay);
```

---
<a name="InsertDelayName"></a>
**InsertDelayName**

Insert an animation delay by duplicating the frame by the delay number of 
times. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::InsertDelayName(const FString& animationName, 
	int32 frameId, int32 delay);
```

---
<a name="InsertFrame"></a>
**InsertFrame**

Duplicate the source frame index at the target frame index. Animation is 
referenced by id.
```c++
void UChromaSDKPluginBPLibrary::InsertFrame(int32 animationId, int32 sourceFrame, 
	int32 targetFrame);
```

---
<a name="InsertFrameName"></a>
**InsertFrameName**

Duplicate the source frame index at the target frame index. Animation is 
referenced by name.
```c++
void UChromaSDKPluginBPLibrary::InsertFrameName(const FString& animationName, 
	int32 sourceFrame, int32 targetFrame);
```

---
<a name="InvertColorsAllFrames"></a>
**InvertColorsAllFrames**

Invert all the colors for all frames. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::InvertColorsAllFrames(int32 animationId);
```

---
<a name="InvertColorsAllFramesName"></a>
**InvertColorsAllFramesName**

Invert all the colors for all frames. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::InvertColorsAllFramesName(const FString& 
	animationName);
```

---
<a name="IsActive"></a>
**IsActive**

Direct access to low level API.
```c++
int32 UChromaSDKPluginBPLibrary::IsActive(UPARAM(ref) bool& active);
```

---
<a name="IsConnected"></a>
**IsConnected**

Direct access to low level API.
```c++
int32 UChromaSDKPluginBPLibrary::IsConnected(UPARAM(ref) FChromaSDKDeviceInfoType& 
	deviceInfoType);
```

---
<a name="IsInitialized"></a>
**IsInitialized**

Returns true if the plugin has been initialized. Returns false if the plugin 
is uninitialized.
```c++
bool UChromaSDKPluginBPLibrary::IsInitialized();
```

---
<a name="Lerp"></a>
**Lerp**

Do a lerp math operation on a float.
```c++
float UChromaSDKPluginBPLibrary::Lerp(float start, float end, float amt);
```

---
<a name="LerpColor"></a>
**LerpColor**

Lerp from one color to another given t in the range 0.0 to 1.0.
```c++
FLinearColor UChromaSDKPluginBPLibrary::LerpColor(FLinearColor colorParam1, 
	FLinearColor colorParam2, float t);
```

---
<a name="LoadAnimation"></a>
**LoadAnimation**

Loads `Chroma` effects so that the animation can be played immediately. 
Returns the animation id upon success. Returns negative one upon failure.
```c++
void UChromaSDKPluginBPLibrary::LoadAnimation(const int32 animationId);
```

---
<a name="LoadAnimationName"></a>
**LoadAnimationName**

Load the named animation.
```c++
void UChromaSDKPluginBPLibrary::LoadAnimationName(const FString& animationName);
```

---
<a name="MakeBlankFrames"></a>
**MakeBlankFrames**

Make a blank animation for the length of the frame count. Frame duration 
defaults to the duration. The frame color defaults to color. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::MakeBlankFrames(int32 animationId, int32 
	frameCount, float duration, const FLinearColor& colorParam);
```

---
<a name="MakeBlankFramesName"></a>
**MakeBlankFramesName**

Make a blank animation for the length of the frame count. Frame duration 
defaults to the duration. The frame color defaults to color. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::MakeBlankFramesName(const FString& animationName, 
	int32 frameCount, float duration, const FLinearColor& colorParam);
```

---
<a name="MakeBlankFramesRandom"></a>
**MakeBlankFramesRandom**

Make a blank animation for the length of the frame count. Frame duration 
defaults to the duration. The frame color is random. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::MakeBlankFramesRandom(int32 animationId, 
	int32 frameCount, float duration);
```

---
<a name="MakeBlankFramesRandomBlackAndWhite"></a>
**MakeBlankFramesRandomBlackAndWhite**

Make a blank animation for the length of the frame count. Frame duration 
defaults to the duration. The frame color is random black and white. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomBlackAndWhite(int32 
	animationId, int32 frameCount, float duration);
```

---
<a name="MakeBlankFramesRandomBlackAndWhiteName"></a>
**MakeBlankFramesRandomBlackAndWhiteName**

Make a blank animation for the length of the frame count. Frame duration 
defaults to the duration. The frame color is random black and white. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomBlackAndWhiteName(const 
	FString& animationName, int32 frameCount, float duration);
```

---
<a name="MakeBlankFramesRandomName"></a>
**MakeBlankFramesRandomName**

Make a blank animation for the length of the frame count. Frame duration 
defaults to the duration. The frame color is random. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::MakeBlankFramesRandomName(const FString& 
	animationName, int32 frameCount, float duration);
```

---
<a name="MakeBlankFramesRGB"></a>
**MakeBlankFramesRGB**

Make a blank animation for the length of the frame count. Frame duration 
defaults to the duration. The frame color defaults to color. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::MakeBlankFramesRGB(int32 animationId, int32 
	frameCount, float duration, int32 red, int32 green, int32 blue);
```

---
<a name="MakeBlankFramesRGBName"></a>
**MakeBlankFramesRGBName**

Make a blank animation for the length of the frame count. Frame duration 
defaults to the duration. The frame color defaults to color. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::MakeBlankFramesRGBName(const FString& animationName, 
	int32 frameCount, float duration, int32 red, int32 green, int32 blue);
```

---
<a name="MultiplyColorLerpAllFrames"></a>
**MultiplyColorLerpAllFrames**

Multiply the color intensity with the lerp result from color 1 to color 
2 using the frame index divided by the frame count for the `t` parameter. 
Animation is referenced in id.
```c++
void UChromaSDKPluginBPLibrary::MultiplyColorLerpAllFrames(int32 animationId, 
	const FLinearColor& colorParam1, const FLinearColor& colorParam2);
```

---
<a name="MultiplyColorLerpAllFramesName"></a>
**MultiplyColorLerpAllFramesName**

Multiply the color intensity with the lerp result from color 1 to color 
2 using the frame index divided by the frame count for the `t` parameter. 
Animation is referenced in name.
```c++
void UChromaSDKPluginBPLibrary::MultiplyColorLerpAllFramesName(const FString& 
	animationName, const FLinearColor& colorParam1, const FLinearColor& colorParam2);
```

---
<a name="MultiplyIntensity"></a>
**MultiplyIntensity**

Multiply all the colors in the frame by the intensity value. The valid the 
intensity range is from 0.0 to 255.0. RGB components are multiplied equally. 
An intensity of 0.5 would half the color value. Black colors in the frame 
will not be affected by this method.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensity(int32 animationId, int32 
	frameId, float intensity);
```

---
<a name="MultiplyIntensityAllFrames"></a>
**MultiplyIntensityAllFrames**

Multiply all the colors for all frames by the intensity value. The valid 
the intensity range is from 0.0 to 255.0. RGB components are multiplied 
equally. An intensity of 0.5 would half the color value. Black colors in 
the frame will not be affected by this method.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFrames(int32 animationId, 
	float intensity);
```

---
<a name="MultiplyIntensityAllFramesName"></a>
**MultiplyIntensityAllFramesName**

Multiply all the colors for all frames by the intensity value. The valid 
the intensity range is from 0.0 to 255.0. RGB components are multiplied 
equally. An intensity of 0.5 would half the color value. Black colors in 
the frame will not be affected by this method.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesName(const FString& 
	animationName, float intensity);
```

---
<a name="MultiplyIntensityAllFramesRGB"></a>
**MultiplyIntensityAllFramesRGB**

Multiply all frames by the RBG color intensity. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesRGB(int32 animationId, 
	int32 red, int32 green, int32 blue);
```

---
<a name="MultiplyIntensityAllFramesRGBName"></a>
**MultiplyIntensityAllFramesRGBName**

Multiply all frames by the RBG color intensity. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityAllFramesRGBName(const 
	FString& animationName, int32 red, int32 green, int32 blue);
```

---
<a name="MultiplyIntensityColor"></a>
**MultiplyIntensityColor**

Multiply the specific frame by the RBG color intensity. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityColor(int32 animationId, 
	int32 frameId, const FLinearColor& colorParam);
```

---
<a name="MultiplyIntensityColorAllFrames"></a>
**MultiplyIntensityColorAllFrames**

Multiply all frames by the RBG color intensity. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityColorAllFrames(int32 animationId, 
	const FLinearColor& colorParam);
```

---
<a name="MultiplyIntensityColorAllFramesName"></a>
**MultiplyIntensityColorAllFramesName**

Multiply all frames by the RBG color intensity. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityColorAllFramesName(const 
	FString& animationName, const FLinearColor& colorParam);
```

---
<a name="MultiplyIntensityColorName"></a>
**MultiplyIntensityColorName**

Multiply the specific frame by the RBG color intensity. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityColorName(const FString& 
	animationName, int32 frameId, const FLinearColor& colorParam);
```

---
<a name="MultiplyIntensityName"></a>
**MultiplyIntensityName**

Multiply all the colors in the frame by the intensity value. The valid the 
intensity range is from 0.0 to 255.0. RGB components are multiplied equally. 
An intensity of 0.5 would half the color value. Black colors in the frame 
will not be affected by this method.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityName(const FString& animationName, 
	int32 frameId, float intensity);
```

---
<a name="MultiplyIntensityRGB"></a>
**MultiplyIntensityRGB**

Multiply the specific frame by the RBG color intensity. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityRGB(int32 animationId, 
	int32 frameId, int32 red, int32 green, int32 blue);
```

---
<a name="MultiplyIntensityRGBName"></a>
**MultiplyIntensityRGBName**

Multiply the specific frame by the RBG color intensity. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::MultiplyIntensityRGBName(const FString& 
	animationName, int32 frameId, int32 red, int32 green, int32 blue);
```

---
<a name="MultiplyNonZeroTargetColorLerpAllFrames"></a>
**MultiplyNonZeroTargetColorLerpAllFrames**

Multiply all frames by the color lerp result between color 1 and 2 using 
the frame color value as the `t` value. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::MultiplyNonZeroTargetColorLerpAllFrames(int32 
	animationId, const FLinearColor& colorParam1, const FLinearColor& colorParam2);
```

---
<a name="MultiplyNonZeroTargetColorLerpAllFramesName"></a>
**MultiplyNonZeroTargetColorLerpAllFramesName**

Multiply all frames by the color lerp result between color 1 and 2 using 
the frame color value as the `t` value. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::MultiplyNonZeroTargetColorLerpAllFramesName(const 
	FString& animationName, const FLinearColor& colorParam1, const FLinearColor& 
	colorParam2);
```

---
<a name="MultiplyTargetColorLerpAllFrames"></a>
**MultiplyTargetColorLerpAllFrames**

Multiply all frames by the color lerp result between color 1 and 2 using 
the frame color value as the `t` value. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::MultiplyTargetColorLerpAllFrames(int32 animationId, 
	const FLinearColor& colorParam1, const FLinearColor& colorParam2);
```

---
<a name="MultiplyTargetColorLerpAllFramesName"></a>
**MultiplyTargetColorLerpAllFramesName**

Multiply all frames by the color lerp result between color 1 and 2 using 
the frame color value as the `t` value. Animation is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::MultiplyTargetColorLerpAllFramesName(const 
	FString& animationName, const FLinearColor& colorParam1, const FLinearColor& 
	colorParam2);
```

---
<a name="OffsetColors"></a>
**OffsetColors**

Offset all colors in the frame using the RGB offset. Use the range of -255 
to 255 for red, green, and blue parameters. Negative values remove color. 
Positive values add color.
```c++
void UChromaSDKPluginBPLibrary::OffsetColors(int32 animationId, int32 frameId, 
	int32 red, int32 green, int32 blue);
```

---
<a name="OffsetColorsAllFrames"></a>
**OffsetColorsAllFrames**

Offset all colors for all frames using the RGB offset. Use the range of 
-255 to 255 for red, green, and blue parameters. Negative values remove 
color. Positive values add color.
```c++
void UChromaSDKPluginBPLibrary::OffsetColorsAllFrames(int32 animationId, 
	int32 red, int32 green, int32 blue);
```

---
<a name="OffsetColorsAllFramesName"></a>
**OffsetColorsAllFramesName**

Offset all colors for all frames using the RGB offset. Use the range of 
-255 to 255 for red, green, and blue parameters. Negative values remove 
color. Positive values add color.
```c++
void UChromaSDKPluginBPLibrary::OffsetColorsAllFramesName(const FString& 
	animationName, int32 red, int32 green, int32 blue);
```

---
<a name="OffsetColorsName"></a>
**OffsetColorsName**

Offset all colors in the frame using the RGB offset. Use the range of -255 
to 255 for red, green, and blue parameters. Negative values remove color. 
Positive values add color.
```c++
void UChromaSDKPluginBPLibrary::OffsetColorsName(const FString& animationName, 
	int32 frameId, int32 red, int32 green, int32 blue);
```

---
<a name="OffsetNonZeroColors"></a>
**OffsetNonZeroColors**

This method will only update colors in the animation that are not already 
set to black. Offset a subset of colors in the frame using the RGB offset. 
Use the range of -255 to 255 for red, green, and blue parameters. Negative 
values remove color. Positive values add color.
```c++
void UChromaSDKPluginBPLibrary::OffsetNonZeroColors(int32 animationId, int32 
	frameId, int32 red, int32 green, int32 blue);
```

---
<a name="OffsetNonZeroColorsAllFrames"></a>
**OffsetNonZeroColorsAllFrames**

This method will only update colors in the animation that are not already 
set to black. Offset a subset of colors for all frames using the RGB offset. 
Use the range of -255 to 255 for red, green, and blue parameters. Negative 
values remove color. Positive values add color.
```c++
void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFrames(int32 animationId, 
	int32 red, int32 green, int32 blue);
```

---
<a name="OffsetNonZeroColorsAllFramesName"></a>
**OffsetNonZeroColorsAllFramesName**

This method will only update colors in the animation that are not already 
set to black. Offset a subset of colors for all frames using the RGB offset. 
Use the range of -255 to 255 for red, green, and blue parameters. Negative 
values remove color. Positive values add color.
```c++
void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsAllFramesName(const FString& 
	animationName, int32 red, int32 green, int32 blue);
```

---
<a name="OffsetNonZeroColorsName"></a>
**OffsetNonZeroColorsName**

This method will only update colors in the animation that are not already 
set to black. Offset a subset of colors in the frame using the RGB offset. 
Use the range of -255 to 255 for red, green, and blue parameters. Negative 
values remove color. Positive values add color.
```c++
void UChromaSDKPluginBPLibrary::OffsetNonZeroColorsName(const FString& animationName, 
	int32 frameId, int32 red, int32 green, int32 blue);
```

---
<a name="OpenAnimationFromMemory"></a>
**OpenAnimationFromMemory**

Opens a `Chroma` animation data from memory so that it can be played. `Data` 
is a pointer to BYTE array of the loaded animation in memory. `Name` will 
be assigned to the animation when loaded. Returns an animation id >= 0 
upon success. Returns negative one if there was a failure. The animation 
id is used in most of the API methods.
```c++
void UChromaSDKPluginBPLibrary::OpenAnimationFromMemory(const TArray<uint8>& 
	data, const FString& animationName);
```

---
<a name="OverrideFrameDurationName"></a>
**OverrideFrameDurationName**

Override the duration of all frames with the `duration` value. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::OverrideFrameDurationName(const FString& 
	animationName, float duration);
```

---
<a name="PlayAnimation"></a>
**PlayAnimation**

Plays the `Chroma` animation. This will load the animation, if not loaded 
previously. Returns the animation id upon success. Returns negative one 
upon failure.
```c++
void UChromaSDKPluginBPLibrary::PlayAnimation(const FString& animationName, 
	bool loop);
```

---
<a name="PlayAnimationName"></a>
**PlayAnimationName**

`PluginPlayAnimationName` automatically handles initializing the `ChromaSDK`. 
The named `.chroma` animation file will be automatically opened. The animation 
will play with looping `on` or `off`.
```c++
void UChromaSDKPluginBPLibrary::PlayAnimationName(const FString& animationName, 
	bool loop);
```

---
<a name="PreviewFrame"></a>
**PreviewFrame**

Displays the `Chroma` animation frame on `Chroma` hardware given the `frameIndex`. 
Returns the animation id upon success. Returns negative one upon failure.
```c++
int32 UChromaSDKPluginBPLibrary::PreviewFrame(int32 animationId, int32 frameId);
```

---
<a name="PreviewFrameName"></a>
**PreviewFrameName**

Displays the `Chroma` animation frame on `Chroma` hardware given the `frameIndex`. 
Animaton is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::PreviewFrameName(const FString& animationName, 
	int32 frameId);
```

---
<a name="ReduceFrames"></a>
**ReduceFrames**

Reduce the frames of the animation by removing every nth element. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::ReduceFrames(int32 animationId, int32 n);
```

---
<a name="ReduceFramesName"></a>
**ReduceFramesName**

Reduce the frames of the animation by removing every nth element. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::ReduceFramesName(const FString& animationName, 
	int32 n);
```

---
<a name="ReverseAllFrames"></a>
**ReverseAllFrames**

Reverse the animation frame order of the `Chroma` animation. Animation is 
referenced by id.
```c++
void UChromaSDKPluginBPLibrary::ReverseAllFrames(int32 animationId);
```

---
<a name="ReverseAllFramesName"></a>
**ReverseAllFramesName**

Reverse the animation frame order of the `Chroma` animation. Animation is 
referenced by name.
```c++
void UChromaSDKPluginBPLibrary::ReverseAllFramesName(const FString& animationName);
```

---
<a name="SetChromaCustomColorAllFramesName"></a>
**SetChromaCustomColorAllFramesName**

When custom color is set, the custom key mode will be used. The animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SetChromaCustomColorAllFramesName(const 
	FString& animationName);
```

---
<a name="SetChromaCustomFlagName"></a>
**SetChromaCustomFlagName**

Set the Chroma custom key color flag on all frames. `True` changes the layout 
from grid to key. `True` changes the layout from key to grid. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SetChromaCustomFlagName(const FString& animationName, 
	bool flag);
```

---
<a name="SetCurrentFrame"></a>
**SetCurrentFrame**

Set the current frame of the animation referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SetCurrentFrame(int32 animationId, int32 
	frameId);
```

---
<a name="SetCurrentFrameName"></a>
**SetCurrentFrameName**

Set the current frame of the animation referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SetCurrentFrameName(const FString& animationName, 
	int32 frameId);
```

---
<a name="SetEventName"></a>
**SetEventName**

Direct access to low level API.
```c++
int32 UChromaSDKPluginBPLibrary::SetEventName(const FString& name);
```

---
<a name="SetIdleAnimationName"></a>
**SetIdleAnimationName**

When the idle animation is used, the named animation will play when no other 
animations are playing. Reference the animation by name.
```c++
void UChromaSDKPluginBPLibrary::SetIdleAnimationName(const FString& animationName);
```

---
<a name="SetKeyColor"></a>
**SetKeyColor**

Set animation key to a static color for the given frame.
```c++
void UChromaSDKPluginBPLibrary::SetKeyColor(int32 animationId, int32 frameIndex, 
	EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);
```

---
<a name="SetKeyColorAllFrames"></a>
**SetKeyColorAllFrames**

Set the key to the specified key color for all frames. Animation is referenced 
by id.
```c++
void UChromaSDKPluginBPLibrary::SetKeyColorAllFrames(int32 animationId, 
	EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);
```

---
<a name="SetKeyColorAllFramesName"></a>
**SetKeyColorAllFramesName**

Set the key to the specified key color for all frames. Animation is referenced 
by name.
```c++
void UChromaSDKPluginBPLibrary::SetKeyColorAllFramesName(const FString& 
	animationName, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);
```

---
<a name="SetKeyColorName"></a>
**SetKeyColorName**

Set animation key to a static color for the given frame.
```c++
void UChromaSDKPluginBPLibrary::SetKeyColorName(const FString& animationName, 
	const int32 frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& 
	colorParam);
```

---
<a name="SetKeyNonZeroColor"></a>
**SetKeyNonZeroColor**

Set animation key to a static color for the given frame if the existing 
color is not already black.
```c++
void UChromaSDKPluginBPLibrary::SetKeyNonZeroColor(int32 animationId, int32 
	frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& colorParam);
```

---
<a name="SetKeyNonZeroColorName"></a>
**SetKeyNonZeroColorName**

Set animation key to a static color for the given frame if the existing 
color is not already black.
```c++
void UChromaSDKPluginBPLibrary::SetKeyNonZeroColorName(const FString& animationName, 
	const int32 frameIndex, EChromaSDKKeyboardKey::Type key, const FLinearColor& 
	colorParam);
```

---
<a name="SetKeyRowColumnColorName"></a>
**SetKeyRowColumnColorName**

Set animation key by row and column to a static color for the given frame.
```c++
void UChromaSDKPluginBPLibrary::SetKeyRowColumnColorName(const FString& 
	animationName, const int32 frameIndex, const int32 row, const int32 column, 
	const FLinearColor& colorParam);
```

---
<a name="SetKeysColor"></a>
**SetKeysColor**

Set an array of animation keys to a static color for the given frame. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SetKeysColor(int32 animationId, int32 frameIndex, 
	const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& 
	colorParam);
```

---
<a name="SetKeysColorAllFrames"></a>
**SetKeysColorAllFrames**

Set an array of animation keys to a static color for all frames. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SetKeysColorAllFrames(int32 animationId, 
	const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& 
	colorParam);
```

---
<a name="SetKeysColorAllFramesName"></a>
**SetKeysColorAllFramesName**

Set an array of animation keys to a static color for all frames. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesName(const FString& 
	animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys, const FLinearColor& colorParam);
```

---
<a name="SetKeysColorAllFramesRGB"></a>
**SetKeysColorAllFramesRGB**

Set an array of animation keys to a static color for all frames. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesRGB(int32 animationId, 
	const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, int32 red, 
	int32 green, int32 blue);
```

---
<a name="SetKeysColorAllFramesRGBName"></a>
**SetKeysColorAllFramesRGBName**

Set an array of animation keys to a static color for all frames. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SetKeysColorAllFramesRGBName(const FString& 
	animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys, int32 red, int32 green, int32 blue);
```

---
<a name="SetKeysColorName"></a>
**SetKeysColorName**

Set an array of animation keys to a static color for the given frame.
```c++
void UChromaSDKPluginBPLibrary::SetKeysColorName(const FString& animationName, 
	const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys, const FLinearColor& colorParam);
```

---
<a name="SetKeysColorRGB"></a>
**SetKeysColorRGB**

Set an array of animation keys to a static color for the given frame. Animation 
is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SetKeysColorRGB(int32 animationId, int32 
	frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, 
	int32 red, int32 green, int32 blue);
```

---
<a name="SetKeysColorRGBName"></a>
**SetKeysColorRGBName**

Set an array of animation keys to a static color for the given frame. Animation 
is referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SetKeysColorRGBName(const FString& animationName, 
	const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys, int32 red, int32 green, int32 blue);
```

---
<a name="SetKeysNonZeroColor"></a>
**SetKeysNonZeroColor**

Set an array of animation keys to a static color for the given frame if 
the existing color is not already black.
```c++
void UChromaSDKPluginBPLibrary::SetKeysNonZeroColor(int32 animationId, int32 
	frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, 
	const FLinearColor& colorParam);
```

---
<a name="SetKeysNonZeroColorAllFrames"></a>
**SetKeysNonZeroColorAllFrames**

Set an array of animation keys to a static color for the given frame where 
the color is not black. Animation is referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorAllFrames(int32 animationId, 
	const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& keys, const FLinearColor& 
	colorParam);
```

---
<a name="SetKeysNonZeroColorAllFramesName"></a>
**SetKeysNonZeroColorAllFramesName**

Set an array of animation keys to a static color for all frames if the existing 
color is not already black. Reference animation by name.
```c++
void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorAllFramesName(const FString& 
	animationName, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys, const FLinearColor& colorParam);
```

---
<a name="SetKeysNonZeroColorName"></a>
**SetKeysNonZeroColorName**

Set an array of animation keys to a static color for the given frame if 
the existing color is not already black. Reference animation by name.
```c++
void UChromaSDKPluginBPLibrary::SetKeysNonZeroColorName(const FString& animationName, 
	const int32 frameIndex, const TArray<TEnumAsByte<EChromaSDKKeyboardKey::Type>>& 
	keys, const FLinearColor& colorParam);
```

---
<a name="SetStaticColor"></a>
**SetStaticColor**

Sets the target device to the static color.
```c++
void UChromaSDKPluginBPLibrary::SetStaticColor(EChromaSDKDeviceEnum::Type 
	device, const FLinearColor& color);
```

---
<a name="SetStaticColorAll"></a>
**SetStaticColorAll**

Sets all devices to the static color.
```c++
void UChromaSDKPluginBPLibrary::SetStaticColorAll(const FLinearColor& color);
```

---
<a name="StopAll"></a>
**StopAll**

`PluginStopAll` will automatically stop all animations that are playing.
```c++
void UChromaSDKPluginBPLibrary::StopAll();
```

---
<a name="StopAnimation"></a>
**StopAnimation**

Stops animation playback if in progress. Returns the animation id upon success. 
Returns negative one upon failure.
```c++
void UChromaSDKPluginBPLibrary::StopAnimation(const FString& animationName);
```

---
<a name="StopAnimationType"></a>
**StopAnimationType**

`PluginStopAnimationType` automatically handles initializing the `ChromaSDK`. 
If any animation is playing for the `deviceType` and `device` combination, 
it will be stopped.
```c++
void UChromaSDKPluginBPLibrary::StopAnimationType(EChromaSDKDeviceEnum::Type 
	device);
```

---
<a name="StreamBroadcast"></a>
**StreamBroadcast**

Begin broadcasting Chroma RGB data using the stored stream key as the endpoint. 
Intended for Cloud Gaming Platforms, restore the streaming key when the 
game instance is launched to continue streaming. streamId is a null terminated 
string streamKey is a null terminated string StreamGetStatus() should return 
the READY status to use this method.
```c++
void UChromaSDKPluginBPLibrary::StreamBroadcast(const FString& streamId, 
	const FString& streamKey);
```

---
<a name="StreamBroadcastEnd"></a>
**StreamBroadcastEnd**

End broadcasting Chroma RGB data. StreamGetStatus() should return the BROADCASTING 
status to use this method.
```c++
void UChromaSDKPluginBPLibrary::StreamBroadcastEnd();
```

---
<a name="StreamGetAuthShortcode"></a>
**StreamGetAuthShortcode**

shortcode: Pass the address of a preallocated character buffer to get the 
streaming auth code. The buffer should have a minimum length of 6. length: 
Length will return as zero if the streaming auth code could not be obtained. 
If length is greater than zero, it will be the length of the returned streaming 
auth code. Once you have the shortcode, it should be shown to the user 
so they can associate the stream with their Razer ID StreamGetStatus() 
should return the READY status before invoking this method. platform: is 
the null terminated string that identifies the source of the stream: { 
GEFORCE_NOW, LUNA, STADIA, GAME_PASS } title: is the null terminated string 
that identifies the application or game.
```c++
FString UChromaSDKPluginBPLibrary::StreamGetAuthShortcode(const FString& 
	platform, const FString& title);
```

---
<a name="StreamGetFocus"></a>
**StreamGetFocus**

focus: Pass the address of a preallocated character buffer to get the stream 
focus. The buffer should have a length of 48 length: Length will return 
as zero if the stream focus could not be obtained. If length is greater 
than zero, it will be the length of the returned stream focus.
```c++
FString UChromaSDKPluginBPLibrary::StreamGetFocus();
```

---
<a name="StreamGetId"></a>
**StreamGetId**

Intended for Cloud Gaming Platforms, store the stream id to persist in user 
preferences to continue streaming if the game is suspended or closed. shortcode: 
The shortcode is a null terminated string. Use the shortcode that authorized 
the stream to obtain the stream id. streamId should be a preallocated buffer 
to get the stream key. The buffer should have a length of 48. length: Length 
will return zero if the key could not be obtained. If the length is greater 
than zero, it will be the length of the returned streaming id. Retrieve 
the stream id after authorizing the shortcode. The authorization window 
will expire in 5 minutes. Be sure to save the stream key before the window 
expires. StreamGetStatus() should return the READY status to use this method.
```c++
FString UChromaSDKPluginBPLibrary::StreamGetId(const FString& shortcode);
```

---
<a name="StreamGetKey"></a>
**StreamGetKey**

Intended for Cloud Gaming Platforms, store the streaming key to persist 
in user preferences to continue streaming if the game is suspended or closed. 
shortcode: The shortcode is a null terminated string. Use the shortcode 
that authorized the stream to obtain the stream key. If the status is in 
the BROADCASTING or WATCHING state, passing a NULL shortcode will return 
the active streamId. streamKey should be a preallocated buffer to get the 
stream key. The buffer should have a length of 48. length: Length will 
return zero if the key could not be obtained. If the length is greater 
than zero, it will be the length of the returned streaming key. Retrieve 
the stream key after authorizing the shortcode. The authorization window 
will expire in 5 minutes. Be sure to save the stream key before the window 
expires. StreamGetStatus() should return the READY status to use this method.
```c++
FString UChromaSDKPluginBPLibrary::StreamGetKey(const FString& shortcode);
```

---
<a name="StreamGetStatusString"></a>
**StreamGetStatusString**

Convert StreamStatusType to a printable string
```c++
FString UChromaSDKPluginBPLibrary::StreamGetStatusString(const EChromaSDKStreamStatusEnum::Type 
	status);
```

---
<a name="StreamReleaseShortcode"></a>
**StreamReleaseShortcode**

This prevents the stream id and stream key from being obtained through the 
shortcode. This closes the auth window. shortcode is a null terminated 
string. StreamGetStatus() should return the READY status to use this method. 
returns success when shortcode has been released
```c++
bool UChromaSDKPluginBPLibrary::StreamReleaseShortcode(const FString& shortcode);
```

---
<a name="StreamSetFocus"></a>
**StreamSetFocus**

The focus is a null terminated string. Set the focus identifer for the application 
designated to automatically change the streaming state. Returns true on 
success.
```c++
bool UChromaSDKPluginBPLibrary::StreamSetFocus(const FString& streamFocus);
```

---
<a name="StreamWatch"></a>
**StreamWatch**

Begin watching the Chroma RGB data using streamID parameter. streamId is 
a null terminated string. StreamGetStatus() should return the READY status 
to use this method.
```c++
void UChromaSDKPluginBPLibrary::StreamWatch(const FString& streamId, int32 
	timestamp);
```

---
<a name="StreamWatchEnd"></a>
**StreamWatchEnd**

End watching Chroma RGB data stream. StreamGetStatus() should return the 
WATCHING status to use this method.
```c++
void UChromaSDKPluginBPLibrary::StreamWatchEnd();
```

---
<a name="SubtractNonZeroAllKeys"></a>
**SubtractNonZeroAllKeys**

Subtract the source color from the target color for the frame where the 
target color is not black. Source and target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeys(int32 sourceAnimationId, 
	int32 targetAnimationId, int32 frameId);
```

---
<a name="SubtractNonZeroAllKeysAllFrames"></a>
**SubtractNonZeroAllKeysAllFrames**

Subtract the source color from the target color for all frames where the 
target color is not black. Source and target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFrames(int32 sourceAnimationId, 
	int32 targetAnimationId);
```

---
<a name="SubtractNonZeroAllKeysAllFramesName"></a>
**SubtractNonZeroAllKeysAllFramesName**

Subtract the source color from the target color for all frames where the 
target color is not black. Source and target are referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesName(const 
	FString& sourceAnimationName, const FString& targetAnimationName);
```

---
<a name="SubtractNonZeroAllKeysAllFramesOffset"></a>
**SubtractNonZeroAllKeysAllFramesOffset**

Subtract the source color from the target color for all frames where the 
target color is not black starting at offset for the length of the source. 
Source and target are referenced by id.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesOffset(int32 
	sourceAnimationId, int32 targetAnimationId, int32 offset);
```

---
<a name="SubtractNonZeroAllKeysAllFramesOffsetName"></a>
**SubtractNonZeroAllKeysAllFramesOffsetName**

Subtract the source color from the target color for all frames where the 
target color is not black starting at offset for the length of the source. 
Source and target are referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysAllFramesOffsetName(const 
	FString& sourceAnimationName, const FString& targetAnimationName, int32 
	offset);
```

---
<a name="SubtractNonZeroAllKeysName"></a>
**SubtractNonZeroAllKeysName**

Subtract the source color from the target color for the frame where the 
target color is not black. Source and target are referenced by name.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroAllKeysName(const FString& 
	sourceAnimationName, const FString& targetAnimationName, int32 frameId);
```

---
<a name="SubtractNonZeroTargetAllKeysAllFrames"></a>
**SubtractNonZeroTargetAllKeysAllFrames**

Subtract the source color from the target color where the target color is 
not black for all frames. Reference source and target by id.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFrames(int32 
	sourceAnimationId, int32 targetAnimationId);
```

---
<a name="SubtractNonZeroTargetAllKeysAllFramesName"></a>
**SubtractNonZeroTargetAllKeysAllFramesName**

Subtract the source color from the target color where the target color is 
not black for all frames. Reference source and target by name.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesName(const 
	FString& sourceAnimationName, const FString& targetAnimationName);
```

---
<a name="SubtractNonZeroTargetAllKeysAllFramesOffset"></a>
**SubtractNonZeroTargetAllKeysAllFramesOffset**

Subtract the source color from the target color where the target color is 
not black for all frames starting at the target offset for the length of 
the source. Reference source and target by id.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesOffset(int32 
	sourceAnimationId, int32 targetAnimationId, int32 offset);
```

---
<a name="SubtractNonZeroTargetAllKeysAllFramesOffsetName"></a>
**SubtractNonZeroTargetAllKeysAllFramesOffsetName**

Subtract the source color from the target color where the target color is 
not black for all frames starting at the target offset for the length of 
the source. Reference source and target by name.
```c++
void UChromaSDKPluginBPLibrary::SubtractNonZeroTargetAllKeysAllFramesOffsetName(const 
	FString& sourceAnimationName, const FString& targetAnimationName, int32 
	offset);
```

---
<a name="TrimEndFrames"></a>
**TrimEndFrames**

Trim the end of the animation. The length of the animation will be the lastFrameId 
plus one. Reference the animation by id.
```c++
void UChromaSDKPluginBPLibrary::TrimEndFrames(int32 animationId, int32 lastFrameId);
```

---
<a name="TrimEndFramesName"></a>
**TrimEndFramesName**

Trim the end of the animation. The length of the animation will be the lastFrameId 
plus one. Reference the animation by name.
```c++
void UChromaSDKPluginBPLibrary::TrimEndFramesName(const FString& animationName, 
	int32 lastFrameId);
```

---
<a name="TrimFrame"></a>
**TrimFrame**

Remove the frame from the animation. Reference animation by id.
```c++
void UChromaSDKPluginBPLibrary::TrimFrame(int32 animationId, int32 frameId);
```

---
<a name="TrimFrameName"></a>
**TrimFrameName**

Remove the frame from the animation. Reference animation by name.
```c++
void UChromaSDKPluginBPLibrary::TrimFrameName(const FString& animationName, 
	int32 frameId);
```

---
<a name="TrimStartFrames"></a>
**TrimStartFrames**

Trim the start of the animation starting at frame 0 for the number of frames. 
Reference the animation by id.
```c++
void UChromaSDKPluginBPLibrary::TrimStartFrames(int32 animationId, int32 
	numberOfFrames);
```

---
<a name="TrimStartFramesName"></a>
**TrimStartFramesName**

Trim the start of the animation starting at frame 0 for the number of frames. 
Reference the animation by name.
```c++
void UChromaSDKPluginBPLibrary::TrimStartFramesName(const FString& animationName, 
	int32 numberOfFrames);
```

---
<a name="UnloadAnimation"></a>
**UnloadAnimation**

Unloads `Chroma` effects to free up resources. Returns the animation id 
upon success. Returns negative one upon failure. Reference the animation 
by id.
```c++
void UChromaSDKPluginBPLibrary::UnloadAnimation(const int32 animationId);
```

---
<a name="UnloadAnimationName"></a>
**UnloadAnimationName**

Unload the animation effects. Reference the animation by name.
```c++
void UChromaSDKPluginBPLibrary::UnloadAnimationName(const FString& animationName);
```

---
<a name="UseForwardChromaEvents"></a>
**UseForwardChromaEvents**

On by default, `UseForwardChromaEvents` sends the animation name to `CoreSetEventName` 
automatically when `PlayAnimationName` is called.
```c++
void UChromaSDKPluginBPLibrary::UseForwardChromaEvents(bool toggle);
```

---
<a name="UseIdleAnimation"></a>
**UseIdleAnimation**

When the idle animation flag is true, when no other animations are playing, 
the idle animation will be used. The idle animation will not be affected 
by the API calls to PluginIsPlaying, PluginStopAnimationType, PluginGetPlayingAnimationId, 
and PluginGetPlayingAnimationCount. Then the idle animation flag is false, 
the idle animation is disabled. `Device` uses `EChromaSDKDeviceEnum` enums.
```c++
void UChromaSDKPluginBPLibrary::UseIdleAnimation(EChromaSDKDeviceEnum::Type 
	device, bool flag);
```

---
<a name="UseIdleAnimations"></a>
**UseIdleAnimations**

Set idle animation flag for all devices.
```c++
void UChromaSDKPluginBPLibrary::UseIdleAnimations(bool flag);
```

---
<a name="UsePreloading"></a>
**UsePreloading**

Set preloading animation flag, which is set to true by default. Reference 
animation by id.
```c++
void UChromaSDKPluginBPLibrary::UsePreloading(int32 animationId, bool flag);
```

---
<a name="UsePreloadingName"></a>
**UsePreloadingName**

Set preloading animation flag, which is set to true by default. Reference 
animation by name.
```c++
void UChromaSDKPluginBPLibrary::UsePreloadingName(const FString& animationName, 
	bool flag);
```

---
