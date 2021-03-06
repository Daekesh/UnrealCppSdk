// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminGetUserBans.h"

UPFAdminGetUserBans::UPFAdminGetUserBans(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetUserBansDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminGetUserBans* UPFAdminGetUserBans::GetUserBans(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InPlayFabId)
{
	UPFAdminGetUserBans* Proxy = NewObject<UPFAdminGetUserBans>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.PlayFabId = InPlayFabId;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminGetUserBans::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->GetUserBans(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminGetUserBansResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminGetUserBans::OnSuccessCallback(const PlayFab::AdminModels::FGetUserBansResult& Result)
{
	FBPAdminGetUserBansResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminGetUserBans::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminGetUserBansResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
