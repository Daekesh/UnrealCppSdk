// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetTitleInternalData.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFAdminGetTitleInternalData : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetTitleDataResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPAdminGetTitleDataResultDelegate OnFailure;
	
	// Retrieves the key-value store of custom title settings which cannot be read by the client
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Admin|Title-Wide Data Management")
	static UPFAdminGetTitleInternalData* GetTitleInternalData(UObject* WorldContextObject, class APlayerController* PlayerController, const TArray<FString>& InKeys);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::AdminModels::FGetTitleDataRequest Request;

	PlayFab::UPlayFabAdminAPI::FGetTitleInternalDataDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::AdminModels::FGetTitleDataResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
