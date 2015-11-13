// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetPublisherData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientGetPublisherData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientGetPublisherDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientGetPublisherDataResultDelegate OnFailure;
	
	// Retrieves the key-value store of custom publisher settings
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Shared Group Data")
	static UPFClientGetPublisherData* GetPublisherData(UObject* WorldContextObject, class APlayerController* PlayerController, const TArray<FString>& InKeys);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FGetPublisherDataRequest Request;

	PlayFab::UPlayFabClientAPI::FGetPublisherDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FGetPublisherDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};