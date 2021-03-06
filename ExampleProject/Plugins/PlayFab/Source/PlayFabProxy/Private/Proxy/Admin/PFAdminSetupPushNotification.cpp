// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminSetupPushNotification.h"

UPFAdminSetupPushNotification::UPFAdminSetupPushNotification(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FSetupPushNotificationDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminSetupPushNotification* UPFAdminSetupPushNotification::SetupPushNotification(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InName, const FString& InPlatform, const FString& InKey, const FString& InCredential, const bool& InOverwriteOldARN)
{
	UPFAdminSetupPushNotification* Proxy = NewObject<UPFAdminSetupPushNotification>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Name = InName;
	Proxy->Request.Platform = InPlatform;
	Proxy->Request.Key = InKey;
	Proxy->Request.Credential = InCredential;
	Proxy->Request.OverwriteOldARN = InOverwriteOldARN;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminSetupPushNotification::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->SetupPushNotification(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminSetupPushNotificationResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminSetupPushNotification::OnSuccessCallback(const PlayFab::AdminModels::FSetupPushNotificationResult& Result)
{
	FBPAdminSetupPushNotificationResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminSetupPushNotification::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminSetupPushNotificationResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
