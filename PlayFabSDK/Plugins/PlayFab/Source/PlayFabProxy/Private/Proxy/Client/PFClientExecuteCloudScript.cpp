// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientExecuteCloudScript.h"

UPFClientExecuteCloudScript::UPFClientExecuteCloudScript(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientExecuteCloudScript* UPFClientExecuteCloudScript::ExecuteCloudScript(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InFunctionName, const int32& InSpecificRevision, const bool& InGeneratePlayStreamEvent)
{
	UPFClientExecuteCloudScript* Proxy = NewObject<UPFClientExecuteCloudScript>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.FunctionName = InFunctionName;
	
	
	Proxy->Request.SpecificRevision = InSpecificRevision;
	Proxy->Request.GeneratePlayStreamEvent = InGeneratePlayStreamEvent;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientExecuteCloudScript::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->ExecuteCloudScript(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientExecuteCloudScriptResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientExecuteCloudScript::OnSuccessCallback(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result)
{
	FBPClientExecuteCloudScriptResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientExecuteCloudScript::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientExecuteCloudScriptResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
