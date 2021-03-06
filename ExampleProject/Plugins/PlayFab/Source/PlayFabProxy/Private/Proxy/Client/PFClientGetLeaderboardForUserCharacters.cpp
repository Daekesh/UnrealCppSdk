// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetLeaderboardForUserCharacters.h"

UPFClientGetLeaderboardForUserCharacters::UPFClientGetLeaderboardForUserCharacters(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetLeaderboardForUserCharactersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetLeaderboardForUserCharacters* UPFClientGetLeaderboardForUserCharacters::GetLeaderboardForUserCharacters(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InStatisticName, const int32& InMaxResultsCount)
{
	UPFClientGetLeaderboardForUserCharacters* Proxy = NewObject<UPFClientGetLeaderboardForUserCharacters>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.StatisticName = InStatisticName;
	Proxy->Request.MaxResultsCount = InMaxResultsCount;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetLeaderboardForUserCharacters::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetLeaderboardForUserCharacters(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetLeaderboardForUsersCharactersResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetLeaderboardForUserCharacters::OnSuccessCallback(const PlayFab::ClientModels::FGetLeaderboardForUsersCharactersResult& Result)
{
	FBPClientGetLeaderboardForUsersCharactersResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetLeaderboardForUserCharacters::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetLeaderboardForUsersCharactersResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
