// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "PlayFabProxyPrivatePCH.h"
#include "PlayFab.h"
#include "PFClientGetCharacterLeaderboard.h"

UPFClientGetCharacterLeaderboard::UPFClientGetCharacterLeaderboard(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetCharacterLeaderboardDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
	, ErrorDelegate(PlayFab::FPlayFabErrorDelegate::CreateUObject(this, &ThisClass::OnErrorCallback))
{
}

UPFClientGetCharacterLeaderboard* UPFClientGetCharacterLeaderboard::GetCharacterLeaderboard(UObject* WorldContextObject, class APlayerController* PlayerController , const FString& InCharacterType, const FString& InStatisticName, const int32& InStartPosition, const int32& InMaxResultsCount)
{
	UPFClientGetCharacterLeaderboard* Proxy = NewObject<UPFClientGetCharacterLeaderboard>();
 	//Proxy->PlayerControllerWeakPtr = PlayerController;
	Proxy->Request.CharacterType = InCharacterType;
	Proxy->Request.StatisticName = InStatisticName;
	Proxy->Request.StartPosition = InStartPosition;
	Proxy->Request.MaxResultsCount = InMaxResultsCount;
	

 	//Proxy->WorldContextObject = WorldContextObject;
	return Proxy;
}

void UPFClientGetCharacterLeaderboard::Activate()
{
	// grab the module, so we can get a valid pointer to the client API 
	PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

	bool CallResult = false;

	if(ClientAPI.IsValid())
	{	
		CallResult = ClientAPI->GetCharacterLeaderboard(Request, SuccessDelegate, ErrorDelegate);
	}

	if(CallResult == false)
	{
		FBPClientGetCharacterLeaderboardResult BPResult;
 		OnFailure.Broadcast(BPResult);
	}
}


//////////////////////////////////////////////////////////////////////////
// Delegate handles
void UPFClientGetCharacterLeaderboard::OnSuccessCallback(const PlayFab::ClientModels::FGetCharacterLeaderboardResult& Result)
{
	FBPClientGetCharacterLeaderboardResult BPResult;
 	BPResult.Data = Result;
 	OnSuccess.Broadcast(BPResult);
}

void UPFClientGetCharacterLeaderboard::OnErrorCallback(const PlayFab::FPlayFabError& InError)
{
	FBPClientGetCharacterLeaderboardResult BPResult;
 	OnFailure.Broadcast(BPResult);	
}
