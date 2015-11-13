// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientValidateIOSReceipt.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientValidateIOSReceipt : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnSuccess; 

	UPROPERTY(BlueprintAssignable)
	FEmptyOnlineDelegate OnFailure; 
	
	// Validates with the Apple store that the receipt for an iOS in-app purchase is valid and that it matches the purchased catalog item
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|IOS-Specific APIs")
	static UPFClientValidateIOSReceipt* ValidateIOSReceipt(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InReceiptData, const FString& InCurrencyCode, const int32& InPurchasePrice);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FValidateIOSReceiptRequest Request;

	PlayFab::UPlayFabClientAPI::FValidateIOSReceiptDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FValidateIOSReceiptResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};