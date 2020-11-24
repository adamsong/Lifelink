#include "LifelinkModule.h"

#include "SML/mod/hooking.h"
#include "SML/util/Logging.h"

#include "FGPlayerController.h"

void FLifelinkModule::StartupModule() {
	SUBSCRIBE_METHOD(AFGPlayerController::StartRespawn, [](auto& scope, AFGPlayerController* self) {
		scope.Cancel();
	})
}

IMPLEMENT_GAME_MODULE(FLifelinkModule, Lifelink);