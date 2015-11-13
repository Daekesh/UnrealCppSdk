// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientUpdateUserTitleDisplayName.h"

UPFClientUpdateUserTitleDisplayName::UPFClientUpdateUserTitleDisplayName(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FUpdateUserTitleDisplayNameDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientUpdateUserTitleDisplayName* UPFClientUpdateUserTitleDisplayName::UpdateUserTitleDisplayName(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InDisplayName)
{
	UPFClientUpdateUserTitleDisplayName* Proxy = NewObject<UPFClientUpdateUserTitleDisplayName>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.DisplayName = InDisplayName;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientUpdateUserTitleDisplayName::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->UpdateUserTitleDisplayName(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientUpdateUserTitleDisplayNameResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientUpdateUserTitleDisplayName::OnSuccessCallback(const PlayFab::ClientModels::FUpdateUserTitleDisplayNameResult& Result)
{
	FBPClientUpdateUserTitleDisplayNameResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientUpdateUserTitleDisplayName::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientUpdateUserTitleDisplayNameResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}