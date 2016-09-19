// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerBanUsers.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerBanUsers : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerBanUsersResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerBanUsersResultDelegate OnFailure;
	
	// Bans users by PlayFab ID with optional IP address, or MAC address for the provided game.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Account Management")
	static UPFServerBanUsers* BanUsers(UObject* WorldContextObject, class APlayerController* PlayerController, const TArray<FBPServerBanRequest>& InBans);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FBanUsersRequest Request;

	PlayFab::UPlayFabServerAPI::FBanUsersDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FBanUsersResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};