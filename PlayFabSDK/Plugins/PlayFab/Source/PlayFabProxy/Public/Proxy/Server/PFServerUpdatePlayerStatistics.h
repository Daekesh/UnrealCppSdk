// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerUpdatePlayerStatistics.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerUpdatePlayerStatistics : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Updates the values of the specified title-specific statistics for the user
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Player Data Management")
	static UPFServerUpdatePlayerStatistics* UpdatePlayerStatistics(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const TArray<FBPServerStatisticUpdate>& InStatistics);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FUpdatePlayerStatisticsRequest Request;

	PlayFab::UPlayFabServerAPI::FUpdatePlayerStatisticsDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FUpdatePlayerStatisticsResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};