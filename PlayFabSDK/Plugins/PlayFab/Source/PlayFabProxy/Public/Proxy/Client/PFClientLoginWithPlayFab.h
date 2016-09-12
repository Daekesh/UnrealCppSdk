// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLoginWithPlayFab.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFClientLoginWithPlayFab : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPClientLoginResultDelegate OnFailure;
	
	// Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user. Unlike other login API calls, LoginWithEmailAddress does not permit the creation of new accounts via the CreateAccountFlag. Email accounts must be created using the RegisterPlayFabUser API or added to existing accounts using AddUsernamePassword.
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Client|Authentication")
	static UPFClientLoginWithPlayFab* LoginWithPlayFab(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InTitleId, const FString& InUsername, const FString& InPassword, const FBPClientGetPlayerCombinedInfoRequestParams& InInfoRequestParameters);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ClientModels::FLoginWithPlayFabRequest Request;

	PlayFab::UPlayFabClientAPI::FLoginWithPlayFabDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
