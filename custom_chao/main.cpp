#include "pch.h"

#include "cwe_api.h"

#include "ModelInfo.h" 

static ModelInfo* MDLExampleChao;

static bool CosmoEvolve(ObjectMaster* tp) {
	if (tp->Data1.Chao->ChaoDataBase_ptr->Alignment > 0.75 && tp->Data1.Chao->ChaoDataBase_ptr->SA2BCharacterBonds[2].a > 75) {
		PrintDebug("Chao evolving");
		return true;
	}
	
	return false;
}

extern "C" {
    __declspec(dllexport) void CWEAPI_EarlyLoad(CWE_API* pAPI) {
        CWE_API_CHAO_DATA CharChao_pData = {
            MDLExampleChao->getmodel(),	//pObject
            {0},				//pSecondEvoList[5]

            "CosmoChao",			//TextureName
            7,				//TextureCount
            0xFF8CB2B3,			//IconColor - hex, 4 bytes (0xAARRGGBB)
            ICON_TYPE_HALO,			//IconType
            NULL,				//pIconData

            CosmoEvolve,			//pEvolveFunc 

            0,				//Flags
            "Cosmo",			//Name
            "cwe_cosmo",			//id
        };

        //add the Chao Type
        pAPI->pRegister->pChao->AddChaoType(&CharChao_pData);
    }

    __declspec(dllexport) void Init(const char* path) {
        std::string pathStr = std::string(path) + "\\";

        MDLExampleChao = new ModelInfo(pathStr + "MDLExampleChao.sa2mdl");
    }

    __declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}