// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientUpdateCharacterStatistics.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientUpdateCharacterStatistics : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Updates the values of the specified title-specific statistics for the specific character
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Characters")
	static UPFClientUpdateCharacterStatistics* UpdateCharacterStatistics(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InCharacterId, const int32& InCharacterStatistics);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FUpdateCharacterStatisticsRequest Request;

	PlayFab::UPlayFabClientAPI::FUpdateCharacterStatisticsDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FUpdateCharacterStatisticsResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
