// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFAdminSetPublishedRevision.h"

UPFAdminSetPublishedRevision::UPFAdminSetPublishedRevision(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FSetPublishedRevisionDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminSetPublishedRevision* UPFAdminSetPublishedRevision::SetPublishedRevision(UObject* WorldContextObject, class APlayerController* PlayerController , const int32& InVersion, const int32& InRevision)
{
	UPFAdminSetPublishedRevision* Proxy = NewObject<UPFAdminSetPublishedRevision>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Version = InVersion;
	Proxy->Request.Revision = InRevision;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminSetPublishedRevision::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->SetPublishedRevision(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminSetPublishedRevision::OnSuccessCallback(const PlayFab::AdminModels::FSetPublishedRevisionResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFAdminSetPublishedRevision::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}