// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFAdminCreateCloudScriptTask.h"

UPFAdminCreateCloudScriptTask::UPFAdminCreateCloudScriptTask(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabAdminAPI::FCreateCloudScriptTaskDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFAdminCreateCloudScriptTask* UPFAdminCreateCloudScriptTask::CreateCloudScriptTask(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InName, const FString& InDescription, const FString& InSchedule, const bool& InIsActive, const FBPAdminCloudScriptTaskParameter& InParameter)
{
	UPFAdminCreateCloudScriptTask* Proxy = NewObject<UPFAdminCreateCloudScriptTask>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.Name = InName;
	Proxy->Request.Description = InDescription;
	Proxy->Request.Schedule = InSchedule;
	Proxy->Request.IsActive = InIsActive;
	Proxy->Request.Parameter = InParameter.Data;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFAdminCreateCloudScriptTask::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

	bool CallResult = false;

	if(AdminAPI.IsValid())
	{	
		CallResult = AdminAPI->CreateCloudScriptTask(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPAdminCreateTaskResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFAdminCreateCloudScriptTask::OnSuccessCallback(const PlayFab::AdminModels::FCreateTaskResult& Result)
{
	FBPAdminCreateTaskResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFAdminCreateCloudScriptTask::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPAdminCreateTaskResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
