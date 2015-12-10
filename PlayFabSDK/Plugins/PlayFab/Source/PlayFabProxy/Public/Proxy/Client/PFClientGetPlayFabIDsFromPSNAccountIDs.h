// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetPlayFabIDsFromPSNAccountIDs.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientGetPlayFabIDsFromPSNAccountIDs : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientGetPlayFabIDsFromPSNAccountIDsResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientGetPlayFabIDsFromPSNAccountIDsResultDelegate OnFailure;
	
	// Retrieves the unique PlayFab identifiers for the given set of PlayStation Network identifiers.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Account Management")
	static UPFClientGetPlayFabIDsFromPSNAccountIDs* GetPlayFabIDsFromPSNAccountIDs(UObject* WorldContextObject, class APlayerController* PlayerController, const TArray<FString>& InPSNAccountIDs, const int32& InIssuerId);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FGetPlayFabIDsFromPSNAccountIDsRequest Request;

	PlayFab::UPlayFabClientAPI::FGetPlayFabIDsFromPSNAccountIDsDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FGetPlayFabIDsFromPSNAccountIDsResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
