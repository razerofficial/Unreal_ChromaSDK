// Copyright 2017-2024 Razer, Inc. All Rights Reserved.

//! \file RzChromaSDKDefines.h
//! \brief Definitions of global and static variables.

#ifndef _RZSCHROMADKDEFINES_H_
#define _RZSCHROMADKDEFINES_H_

#pragma once

#if PLATFORM_WINDOWS || PLATFORM_XBOXONE

#ifndef GUID_DEFINED
#include "Windows/AllowWindowsPlatformTypes.h" 
#include <Guiddef.h>
#include "Windows/HideWindowsPlatformTypes.h"
#endif

namespace ChromaSDK
{
    // Keyboards
    //! Razer Blackwidow Chroma device.
    // {2EA1BB63-CA28-428D-9F06-196B88330BBB}
    static const GUID BLACKWIDOW_CHROMA = 
    { 0x2ea1bb63, 0xca28, 0x428d, { 0x9f, 0x06, 0x19, 0x6b, 0x88, 0x33, 0x0b, 0xbb } }; 

    //! Razer Blackwidow Chroma Tournament Edition device.
    // {ED1C1B82-BFBE-418F-B49D-D03F05B149DF}
    static const GUID BLACKWIDOW_CHROMA_TE = 
    { 0xed1c1b82, 0xbfbe, 0x418f, { 0xb4, 0x9d, 0xd0, 0x3f, 0x5, 0xb1, 0x49, 0xdf } };

    //! Razer Deathstalker device.
    // {18C5AD9B-4326-4828-92C4-2669A66D2283}
    static const GUID DEATHSTALKER_CHROMA = 
    { 0x18c5ad9b, 0x4326, 0x4828, { 0x92, 0xc4, 0x26, 0x69, 0xa6, 0x6d, 0x22, 0x83 } };

    //! Overwatch Keyboard.
    // {872AB2A9-7959-4478-9FED-15F6186E72E4}
    static const GUID OVERWATCH_KEYBOARD = 
    { 0x872ab2a9, 0x7959, 0x4478, { 0x9f, 0xed, 0x15, 0xf6, 0x18, 0x6e, 0x72, 0xe4 } };

    //! Razer Blackwidow X Chroma device.
    // {5AF60076-ADE9-43D4-B574-52599293B554}
    static const GUID BLACKWIDOW_X_CHROMA = 
    { 0x5af60076, 0xade9, 0x43d4, { 0xb5, 0x74, 0x52, 0x59, 0x92, 0x93, 0xb5, 0x54 } };

    //! Razer Blackwidow X TE Chroma device.
    // {2D84DD51-3290-4AAC-9A89-D8AFDE38B57C}
    static const GUID BLACKWIDOW_X_TE_CHROMA = 
    { 0x2d84dd51, 0x3290, 0x4aac, { 0x9a, 0x89, 0xd8, 0xaf, 0xde, 0x38, 0xb5, 0x7c } };

    //! Razer Ornata Chroma
    // {803378C1-CC48-4970-8539-D828CC1D420A}
    static const GUID ORNATA_CHROMA =
    { 0x803378c1, 0xcc48, 0x4970,{ 0x85, 0x39, 0xd8, 0x28, 0xcc, 0x1d, 0x42, 0xa } };

    //! Razer Blade Stealth.
    // {C83BDFE8-E7FC-40E0-99DB-872E23F19891}
    static const GUID BLADE_STEALTH = 
    { 0xc83bdfe8, 0xe7fc, 0x40e0, { 0x99, 0xdb, 0x87, 0x2e, 0x23, 0xf1, 0x98, 0x91 } };

    //! Razer Blade
    // {F2BEDFAF-A0FE-4651-9D41-B6CE603A3DDD}
    static const GUID BLADE = 
    { 0xf2bedfaf, 0xa0fe, 0x4651, { 0x9d, 0x41, 0xb6, 0xce, 0x60, 0x3a, 0x3d, 0xdd } };

    //! Razer Blade Pro
    // {A73AC338-F0E5-4BF7-91AE-DD1F7E1737A5}
    static const GUID BLADE_PRO =
    { 0xa73ac338, 0xf0e5, 0x4bf7,{ 0x91, 0xae, 0xdd, 0x1f, 0x7e, 0x17, 0x37, 0xa5 } };

    //! Razer Blackwidow Chroma v2
    // {608E743F-B402-44BD-A7A6-7AA9F574ECF4}
    static const GUID BLACKWIDOW_CHROMA2 =
    { 0x608e743f, 0xb402, 0x44bd,{ 0xa7, 0xa6, 0x7a, 0xa9, 0xf5, 0x74, 0xec, 0xf4 } };



    // Mice
    //! Razer Deathadder Chroma device.
    // {AEC50D91-B1F1-452F-8E16-7B73F376FDF3}
    static const GUID DEATHADDER_CHROMA = 
    { 0xaec50d91, 0xb1f1, 0x452f, { 0x8e, 0x16, 0x7b, 0x73, 0xf3, 0x76, 0xfd, 0xf3 } };

    //! Razer Mamba Chroma Tournament Edition device.
    // {7EC00450-E0EE-4289-89D5-0D879C19061A}
    static const GUID MAMBA_CHROMA_TE = 
    { 0x7ec00450, 0xe0ee, 0x4289, { 0x89, 0xd5, 0xd, 0x87, 0x9c, 0x19, 0x6, 0x1a } };

    //! Razer Diamondback device.
    // {FF8A5929-4512-4257-8D59-C647BF9935D0}
    static const GUID DIAMONDBACK_CHROMA = 
    { 0xff8a5929, 0x4512, 0x4257, { 0x8d, 0x59, 0xc6, 0x47, 0xbf, 0x99, 0x35, 0xd0 } };

    //! Razer Mamba device.
    // {D527CBDC-EB0A-483A-9E89-66D50463EC6C}
    static const GUID MAMBA_CHROMA = 
    { 0xd527cbdc, 0xeb0a, 0x483a, { 0x9e, 0x89, 0x66, 0xd5, 0x4, 0x63, 0xec, 0x6c } };

    //! Razer Naga Epic device.
    // {D714C50B-7158-4368-B99C-601ACB985E98}
    static const GUID NAGA_EPIC_CHROMA = 
    { 0xd714c50b, 0x7158, 0x4368, { 0xb9, 0x9c, 0x60, 0x1a, 0xcb, 0x98, 0x5e, 0x98 } };

    //! Razer Naga device.
    // {F1876328-6CA4-46AE-BE04-BE812B414433}
    static const GUID NAGA_CHROMA = 
    { 0xf1876328, 0x6ca4, 0x46ae, { 0xbe, 0x4, 0xbe, 0x81, 0x2b, 0x41, 0x44, 0x33 } };

    //! Razer Orochi Chroma device.
    // {52C15681-4ECE-4DD9-8A52-A1418459EB34}
    static const GUID OROCHI_CHROMA = 
    { 0x52c15681, 0x4ece, 0x4dd9, { 0x8a, 0x52, 0xa1, 0x41, 0x84, 0x59, 0xeb, 0x34 } };

    //! Razer Naga Hex Chroma device.
    // {195D70F5-F285-4CFF-99F2-B8C0E9658DB4}
    static const GUID NAGA_HEX_CHROMA = 
    { 0x195d70f5, 0xf285, 0x4cff, { 0x99, 0xf2, 0xb8, 0xc0, 0xe9, 0x65, 0x8d, 0xb4 } };

    //! Razer DeathAdder Elite Chroma device.
    // {77834867-3237-4A9F-AD77-4A46C4183003}
    static const GUID DEATHADDER_ELITE_CHROMA =
    { 0x77834867, 0x3237, 0x4a9f,{ 0xad, 0x77, 0x4a, 0x46, 0xc4, 0x18, 0x30, 0x3 } };


    // Headsets
    //! Razer Kraken 7.1 Chroma device.
    // {CD1E09A5-D5E6-4A6C-A93B-E6D9BF1D2092}
    static const GUID KRAKEN71_CHROMA = 
    { 0xcd1e09a5, 0xd5e6, 0x4a6c, { 0xa9, 0x3b, 0xe6, 0xd9, 0xbf, 0x1d, 0x20, 0x92 } };

    //! Razer ManO'War device.
    // {DF3164D7-5408-4A0E-8A7F-A7412F26BEBF}
    static const GUID MANOWAR_CHROMA = 
    { 0xdf3164d7, 0x5408, 0x4a0e, { 0x8a, 0x7f, 0xa7, 0x41, 0x2f, 0x26, 0xbe, 0xbf } };

    //! Razer Kraken 7.1 Chroma Refresh headset.
    // {7FB8A36E-9E74-4BB3-8C86-CAC7F7891EBD}
    static const GUID KRAKEN71_REFRESH_CHROMA =
    { 0x7fb8a36e, 0x9e74, 0x4bb3,{ 0x8c, 0x86, 0xca, 0xc7, 0xf7, 0x89, 0x1e, 0xbd } };


    // Mouse mat
    //! Razer Firefly device.
    // {80F95A94-73D2-48CA-AE9A-0986789A9AF2}
    static const GUID FIREFLY_CHROMA = 
    { 0x80f95a94, 0x73d2, 0x48ca, { 0xae, 0x9a, 0x9, 0x86, 0x78, 0x9a, 0x9a, 0xf2 } };


    // Keypads
    //! Razer Tartarus device.
    // {00F0545C-E180-4AD1-8E8A-419061CE505E}
    static const GUID TARTARUS_CHROMA = 
    { 0xf0545c, 0xe180, 0x4ad1, { 0x8e, 0x8a, 0x41, 0x90, 0x61, 0xce, 0x50, 0x5e } };

    //! Razer Orbweaver device.
    // {9D24B0AB-0162-466C-9640-7A924AA4D9FD}
    static const GUID ORBWEAVER_CHROMA = 
    { 0x9d24b0ab, 0x162, 0x466c, { 0x96, 0x40, 0x7a, 0x92, 0x4a, 0xa4, 0xd9, 0xfd } };


    // Chroma Linked devices
    // {35F6F18D-1AE5-436C-A575-AB44A127903A}
    static const GUID LENOVO_Y900 = 
    { 0x35f6f18d, 0x1ae5, 0x436c, { 0xa5, 0x75, 0xab, 0x44, 0xa1, 0x27, 0x90, 0x3a } };

    // {47DB1FA7-6B9B-4EE6-B6F4-4071A3B2053B}
    static const GUID LENOVO_Y27 = 
    { 0x47db1fa7, 0x6b9b, 0x4ee6, { 0xb6, 0xf4, 0x40, 0x71, 0xa3, 0xb2, 0x5, 0x3b } };

    // {0201203B-62F3-4C50-83DD-598BABD208E0}
    static const GUID CORE_CHROMA = 
    { 0x201203b, 0x62f3, 0x4c50, { 0x83, 0xdd, 0x59, 0x8b, 0xab, 0xd2, 0x8, 0xe0 } };

	// {BB2E9C9B-B0D2-461A-BA52-230B5D6C3609}
	static const GUID CHROMABOX =
	{ 0xbb2e9c9b, 0xb0d2, 0x461a,{ 0xba, 0x52, 0x23, 0xb, 0x5d, 0x6c, 0x36, 0x9 } };
}

#endif

#endif
