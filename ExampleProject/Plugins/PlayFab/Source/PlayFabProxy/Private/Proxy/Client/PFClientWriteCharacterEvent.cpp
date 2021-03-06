// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientWriteCharacterEvent.h"

UPFClientWriteCharacterEvent::UPFClientWriteCharacterEvent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FWriteCharacterEventDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientWriteCharacterEvent* UPFClientWriteCharacterEvent::WriteCharacterEvent(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InCharacterId, const FString& InEventName, const FDateTime& InTimestamp)
{
	UPFClientWriteCharacterEvent* Proxy = NewObject<UPFClientWriteCharacterEvent>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.CharacterId = InCharacterId;
	Proxy->Request.EventName = InEventName;
	
	
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientWriteCharacterEvent::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->WriteCharacterEvent(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientWriteEventResponse BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientWriteCharacterEvent::OnSuccessCallback(const PlayFab::ClientModels::FWriteEventResponse& Result)
{
	FBPClientWriteEventResponse BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientWriteCharacterEvent::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientWriteEventResponse BPResult;
 	OnFailure.Broadcast(BPResult);	
}
