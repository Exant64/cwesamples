// just a simple code snippet to see usage of the function

static int myAccessoryID;

// the accessory ID fetching cannot go in EarlyLoad, since we need our code
// to run once the accessory has already been registered through the JSONs
extern "C" __declspec(dllexport) void CWEAPI_Load(CWE_API* pAPI) {
    myAccessoryID = pAPI->pRegister->pAccessory->GetAccessoryIndex("your_accessory_id_here");
}