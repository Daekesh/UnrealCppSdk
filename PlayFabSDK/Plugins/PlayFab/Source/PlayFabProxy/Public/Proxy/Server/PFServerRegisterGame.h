// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerRegisterGame.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerRegisterGame : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerRegisterGameResponseDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerRegisterGameResponseDelegate OnFailure;
	
	// Inform the matchmaker that a new Game Server Instance is added.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Matchmaking APIs")
	static UPFServerRegisterGame* RegisterGame(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InServerHost, const FString& InServerPort, const FString& InBuild, const FString& InGameMode, const FString& InTags);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FRegisterGameRequest Request;

	PlayFab::UPlayFabServerAPI::FRegisterGameDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FRegisterGameResponse& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};