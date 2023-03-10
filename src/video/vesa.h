#ifndef VESA_H
#define VESA_H

#include "common/typedef.h"

struct VESAINFO
{
        // Поддерживается всеми версиями VBE
        char            cSignature[4];
        uint16_t        usVersion;
        char far        *fpInfoOEM;
        uint8_t         ucCapabilities[4];
        uint16_t far    *fpModeTable;

        // Поддерживается VBE версии 1.2
        uint16_t        usTotalMemory;

        // Поддерживается VBE версии 2.0
        uint16_t        usRevVersion;
        char far        *fpOEMName;
        char far        *fpOEMProductName;
        char far        *fpOEMRevVersion;
        char            cReserv[222];
        char            cOEMData[256];
}

// Характеристика режима видеоадаптера
struct VESAMODEINFO
{
        uint16_t        usModeAttr;
        uint8_t         ucWinAAttr;
        uint8_t         ucWinBAttr;
        uint16_t        usWinGranularity;
        uint16_t        usWinSize;
        uint16_t        usBegSegA;
        uint16_t        usBegSegB;
        void far        *fpWinFunc;
        uint16_t        usBytesPerScanLine;

        // Поддерживается VBE версии 1.2
        uint16_t        usSizeX;
        uint16_t        usSizeY;
        uint8_t         ucCharSizeX;
        uint8_t         ucCharSizeY;
        uint8_t         ucNumPlanes;
        uint8_t         ucNumPixelBits;
        uint8_t         ucBanksNum;
        uint8_t         ucTypeMemModel;
        uint8_t         ucBankSize;
        uint8_t         ucPageNum;
        uint8_t         ucReserv1;

        uint8_t         ucRedSize;
        uint8_t         ucRedField;
        uint8_t         ucGreenSize;
        uint8_t         ucGreenField;
        uint8_t         ucBlueSize;
        uint8_t         ucBlueField;
        uint8_t         ucResSize;
        uint8_t         ucResField;
        uint8_t         ucDACInfo;

        // Поддерживается VBE версии 2.0
        uint8_t far     *VideoBuff;
        uint8_t far     *ScrOffset;
        uint16_t        usScrSize;
        uint8_t         ucReserv2[206];
}

#endif