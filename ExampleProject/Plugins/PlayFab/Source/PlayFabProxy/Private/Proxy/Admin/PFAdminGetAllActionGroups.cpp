// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetAllActionGroups.h"

UPFAdminGetAllActionGroups::UPFAdminGetAllActionGroups(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetAllActionGroupsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetAllActionGroups* UPFAdminGetAllActionGroups::GetAllActionGroups(UObject* WorldContextObject, class APlayerController* PlayerController )
{
	UPFAdminGetAllActionGroups* Proxy = NewObject<UPFAdminGetAllActionGroups>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetAllActionGroups::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetAllActionGroups(SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetAllActionGroupsResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetAllActionGroups::OnSuccessCallback(const PlayFab::AdminModels::FGetAllActionGroupsResult& Result)
{
	FBPAdminGetAllActionGroupsResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetAllActionGroups::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetAllActionGroupsResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
