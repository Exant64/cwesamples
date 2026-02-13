#include "pch.h"

#include "cwe_api.h"

#include "ModelInfo.h" 
#include "AnimationFile.h"

extern "C"
{
    // stores the contents of the .saanim you load
    static AnimationFile* testAnimation;

    //main CWE Load function -- Important stuff like adding your CWE mod goes here
    __declspec(dllexport) void CWEAPI_EarlyLoad(CWE_API* pAPI) {
        // create a MOTION_TABLE entry for your animation
        const MOTION_TABLE motionTableEntry = { testAnimation->getmotion(), 0, 0, 0xFFFFFFFF, -40, 0, 5, 0.12f};

        // replace the motion table entry at index 387 with ours
        *pAPI->pRegister->pMotion->GetChaoMotionTable(387) = motionTableEntry;
    }

    __declspec(dllexport) void Init(const char* path) {
        std::string pathStr = std::string(path) + "\\";

        // replace the saanim file name with yours
        testAnimation = new AnimationFile(pathStr + "my_animation_here.saanim");
    }

    __declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}