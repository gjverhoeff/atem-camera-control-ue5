

#include "ATEMControlUE5.h"
#include "Modules/ModuleManager.h"
#include "WebSocketsModule.h"

#define LOCTEXT_NAMESPACE "FATEMControlUE5Module"

void FATEMControlUE5Module::StartupModule()
{
	FModuleManager::LoadModuleChecked<FWebSocketsModule>("WebSockets");
	
}

void FATEMControlUE5Module::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FATEMControlUE5Module, ATEMControlUE5)
