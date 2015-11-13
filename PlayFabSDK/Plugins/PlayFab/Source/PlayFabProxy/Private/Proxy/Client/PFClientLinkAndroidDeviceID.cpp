// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PFClientLinkAndroidDeviceID.h"

UPFClientLinkAndroidDeviceID::UPFClientLinkAndroidDeviceID(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FLinkAndroidDeviceIDDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientLinkAndroidDeviceID* UPFClientLinkAndroidDeviceID::LinkAndroidDeviceID(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InAndroidDeviceId, const FString& InOS, const FString& InAndroidDevice)
{
	UPFClientLinkAndroidDeviceID* Proxy = NewObject<UPFClientLinkAndroidDeviceID>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.AndroidDeviceId = InAndroidDeviceId;
	Proxy->Request.OS = InOS;
	Proxy->Request.AndroidDevice = InAndroidDevice;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientLinkAndroidDeviceID::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->LinkAndroidDeviceID(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		OnFailure.Broadcast();
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientLinkAndroidDeviceID::OnSuccessCallback(const PlayFab::ClientModels::FLinkAndroidDeviceIDResult& Result)
{
	OnSuccess.Broadcast();
}

void UPFClientLinkAndroidDeviceID::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	OnFailure.Broadcast();	
}