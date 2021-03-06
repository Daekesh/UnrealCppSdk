// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once
#include "OnlineBlueprintCallProxyBase.h"

#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGetFriendLeaderboard.generated.h"

UCLASS()
class PLAYFABPROXY_API UPFServerGetFriendLeaderboard : public UOnlineBlueprintCallProxyBase
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FBPServerGetLeaderboardResultDelegate OnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBPServerGetLeaderboardResultDelegate OnFailure;
	
	// Retrieves a list of ranked friends of the given player for the given statistic, starting from the indicated point in the leaderboard
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), Category = "PlayFab|Server|Player Data Management")
	static UPFServerGetFriendLeaderboard* GetFriendLeaderboard(UObject* WorldContextObject, class APlayerController* PlayerController, const FString& InPlayFabId, const FString& InStatisticName, const int32& InStartPosition, const int32& InMaxResultsCount, const bool& InIncludeSteamFriends, const bool& InIncludeFacebookFriends);

	// UOnlineBlueprintCallProxyBase interface
	virtual void Activate() override;
	// End of UOnlineBlueprintCallProxyBase interface

private:

	PlayFab::ServerModels::FGetFriendLeaderboardRequest Request;

	PlayFab::UPlayFabServerAPI::FGetFriendLeaderboardDelegate	SuccessDelegate;
	PlayFab::FPlayFabErrorDelegate							ErrorDelegate;

	void OnSuccessCallback(const PlayFab::ServerModels::FGetLeaderboardResult& Result);
	void OnErrorCallback(const PlayFab::FPlayFabError& Error);
};
