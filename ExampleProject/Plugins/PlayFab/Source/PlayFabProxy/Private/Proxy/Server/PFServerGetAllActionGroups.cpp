// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFServerGetAllActionGroups.h"

UPFServerGetAllActionGroups::UPFServerGetAllActionGroups(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetAllActionGroupsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFServerGetAllActionGroups* UPFServerGetAllActionGroups::GetAllActionGroups(UObject* WorldContextObject, class APlayerController* PlayerController )
{
	UPFServerGetAllActionGroups* Proxy = NewObject<UPFServerGetAllActionGroups>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFServerGetAllActionGroups::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

	bool CallResult = false;

	if(ServerAPI.IsValid())
	{	
		CallResult = ServerAPI->GetAllActionGroups(SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPServerGetAllActionGroupsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFServerGetAllActionGroups::OnSuccessCallback(const PlayFab::ServerModels::FGetAllActionGroupsResult& Result)
{
	FBPServerGetAllActionGroupsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFServerGetAllActionGroups::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPServerGetAllActionGroupsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
