// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "Core/PlayFabBaseModel.h"

namespace PlayFab
{
namespace MatchmakerModels
{

	
	struct PLAYFAB_API FAuthUserRequest : public FPlayFabBaseModel
    {
		
		// Session Ticket provided by the client.
		FString AuthorizationTicket;
	
        FAuthUserRequest() :
			FPlayFabBaseModel(),
			AuthorizationTicket()
			{}
		
		FAuthUserRequest(const FAuthUserRequest& src) :
			FPlayFabBaseModel(),
			AuthorizationTicket(src.AuthorizationTicket)
			{}
			
		FAuthUserRequest(const TSharedPtr<FJsonObject>& obj) : FAuthUserRequest()
        {
            readFromValue(obj);
        }
		
		~FAuthUserRequest();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FAuthUserResponse : public FPlayFabBaseModel
    {
		
		// Boolean indicating if the user has been authorized to use the external match-making service.
		bool Authorized;
		// [optional] PlayFab unique identifier of the account that has been authorized.
		FString PlayFabId;
	
        FAuthUserResponse() :
			FPlayFabBaseModel(),
			Authorized(false),
			PlayFabId()
			{}
		
		FAuthUserResponse(const FAuthUserResponse& src) :
			FPlayFabBaseModel(),
			Authorized(src.Authorized),
			PlayFabId(src.PlayFabId)
			{}
			
		FAuthUserResponse(const TSharedPtr<FJsonObject>& obj) : FAuthUserResponse()
        {
            readFromValue(obj);
        }
		
		~FAuthUserResponse();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FItemInstance : public FPlayFabBaseModel
    {
		
		// [optional] Unique identifier for the inventory item, as defined in the catalog.
		FString ItemId;
		// [optional] Unique item identifier for this specific instance of the item.
		FString ItemInstanceId;
		// [optional] Class name for the inventory item, as defined in the catalog.
		FString ItemClass;
		// [optional] Timestamp for when this instance was purchased.
		OptionalTime PurchaseDate;
		// [optional] Timestamp for when this instance will expire.
		OptionalTime Expiration;
		// [optional] Total number of remaining uses, if this is a consumable item.
		OptionalInt32 RemainingUses;
		// [optional] The number of uses that were added or removed to this item in this call.
		OptionalInt32 UsesIncrementedBy;
		// [optional] Game specific comment associated with this instance when it was added to the user inventory.
		FString Annotation;
		// [optional] Catalog version for the inventory item, when this instance was created.
		FString CatalogVersion;
		// [optional] Unique identifier for the parent inventory item, as defined in the catalog, for object which were added from a bundle or container.
		FString BundleParent;
		// [optional] CatalogItem.DisplayName at the time this item was purchased.
		FString DisplayName;
		// [optional] Currency type for the cost of the catalog item.
		FString UnitCurrency;
		// Cost of the catalog item in the given currency.
		uint32 UnitPrice;
		// [optional] Array of unique items that were awarded when this catalog item was purchased.
		TArray<FString> BundleContents;
		// [optional] A set of custom key-value pairs on the inventory item.
		TMap<FString, FString> CustomData;
	
        FItemInstance() :
			FPlayFabBaseModel(),
			ItemId(),
			ItemInstanceId(),
			ItemClass(),
			PurchaseDate(),
			Expiration(),
			RemainingUses(),
			UsesIncrementedBy(),
			Annotation(),
			CatalogVersion(),
			BundleParent(),
			DisplayName(),
			UnitCurrency(),
			UnitPrice(0),
			BundleContents(),
			CustomData()
			{}
		
		FItemInstance(const FItemInstance& src) :
			FPlayFabBaseModel(),
			ItemId(src.ItemId),
			ItemInstanceId(src.ItemInstanceId),
			ItemClass(src.ItemClass),
			PurchaseDate(src.PurchaseDate),
			Expiration(src.Expiration),
			RemainingUses(src.RemainingUses),
			UsesIncrementedBy(src.UsesIncrementedBy),
			Annotation(src.Annotation),
			CatalogVersion(src.CatalogVersion),
			BundleParent(src.BundleParent),
			DisplayName(src.DisplayName),
			UnitCurrency(src.UnitCurrency),
			UnitPrice(src.UnitPrice),
			BundleContents(src.BundleContents),
			CustomData(src.CustomData)
			{}
			
		FItemInstance(const TSharedPtr<FJsonObject>& obj) : FItemInstance()
        {
            readFromValue(obj);
        }
		
		~FItemInstance();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FPlayerJoinedRequest : public FPlayFabBaseModel
    {
		
		// Unique identifier of the Game Server Instance the user is joining.
		FString LobbyId;
		// PlayFab unique identifier for the user joining.
		FString PlayFabId;
	
        FPlayerJoinedRequest() :
			FPlayFabBaseModel(),
			LobbyId(),
			PlayFabId()
			{}
		
		FPlayerJoinedRequest(const FPlayerJoinedRequest& src) :
			FPlayFabBaseModel(),
			LobbyId(src.LobbyId),
			PlayFabId(src.PlayFabId)
			{}
			
		FPlayerJoinedRequest(const TSharedPtr<FJsonObject>& obj) : FPlayerJoinedRequest()
        {
            readFromValue(obj);
        }
		
		~FPlayerJoinedRequest();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FPlayerJoinedResponse : public FPlayFabBaseModel
    {
		
	
        FPlayerJoinedResponse() :
			FPlayFabBaseModel()
			{}
		
		FPlayerJoinedResponse(const FPlayerJoinedResponse& src) :
			FPlayFabBaseModel()
			{}
			
		FPlayerJoinedResponse(const TSharedPtr<FJsonObject>& obj) : FPlayerJoinedResponse()
        {
            readFromValue(obj);
        }
		
		~FPlayerJoinedResponse();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FPlayerLeftRequest : public FPlayFabBaseModel
    {
		
		// Unique identifier of the Game Server Instance the user is leaving.
		FString LobbyId;
		// PlayFab unique identifier for the user leaving.
		FString PlayFabId;
	
        FPlayerLeftRequest() :
			FPlayFabBaseModel(),
			LobbyId(),
			PlayFabId()
			{}
		
		FPlayerLeftRequest(const FPlayerLeftRequest& src) :
			FPlayFabBaseModel(),
			LobbyId(src.LobbyId),
			PlayFabId(src.PlayFabId)
			{}
			
		FPlayerLeftRequest(const TSharedPtr<FJsonObject>& obj) : FPlayerLeftRequest()
        {
            readFromValue(obj);
        }
		
		~FPlayerLeftRequest();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FPlayerLeftResponse : public FPlayFabBaseModel
    {
		
	
        FPlayerLeftResponse() :
			FPlayFabBaseModel()
			{}
		
		FPlayerLeftResponse(const FPlayerLeftResponse& src) :
			FPlayFabBaseModel()
			{}
			
		FPlayerLeftResponse(const TSharedPtr<FJsonObject>& obj) : FPlayerLeftResponse()
        {
            readFromValue(obj);
        }
		
		~FPlayerLeftResponse();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	enum Region
	{
		RegionUSCentral,
		RegionUSEast,
		RegionEUWest,
		RegionSingapore,
		RegionJapan,
		RegionBrazil,
		RegionAustralia
	};
	
	void writeRegionEnumJSON(Region enumVal, JsonWriter& writer);
	Region readRegionFromValue(const TSharedPtr<FJsonValue>& value);
	
	
	struct PLAYFAB_API FStartGameRequest : public FPlayFabBaseModel
    {
		
		// Unique identifier of the previously uploaded build executable which is to be started.
		FString Build;
		// Region with which to associate the server, for filtering.
		Region pfRegion;
		// Game mode for this Game Server Instance.
		FString GameMode;
		// [optional] Custom command line argument when starting game server process.
		FString CustomCommandLineData;
		// HTTP endpoint URL for receiving game status events, if using an external matchmaker. When the game ends, PlayFab will make a POST request to this URL with the X-SecretKey header set to the value of the game's secret and an application/json body of { "EventName": "game_ended", "GameID": "<gameid>" }.
		FString ExternalMatchmakerEventEndpoint;
	
        FStartGameRequest() :
			FPlayFabBaseModel(),
			Build(),
			pfRegion(),
			GameMode(),
			CustomCommandLineData(),
			ExternalMatchmakerEventEndpoint()
			{}
		
		FStartGameRequest(const FStartGameRequest& src) :
			FPlayFabBaseModel(),
			Build(src.Build),
			pfRegion(src.pfRegion),
			GameMode(src.GameMode),
			CustomCommandLineData(src.CustomCommandLineData),
			ExternalMatchmakerEventEndpoint(src.ExternalMatchmakerEventEndpoint)
			{}
			
		FStartGameRequest(const TSharedPtr<FJsonObject>& obj) : FStartGameRequest()
        {
            readFromValue(obj);
        }
		
		~FStartGameRequest();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FStartGameResponse : public FPlayFabBaseModel
    {
		
		// [optional] Unique identifier for the lobby in the new Game Server Instance.
		FString GameID;
		// [optional] IP address of the new Game Server Instance.
		FString ServerHostname;
		// Port number for communication with the Game Server Instance.
		uint32 ServerPort;
	
        FStartGameResponse() :
			FPlayFabBaseModel(),
			GameID(),
			ServerHostname(),
			ServerPort(0)
			{}
		
		FStartGameResponse(const FStartGameResponse& src) :
			FPlayFabBaseModel(),
			GameID(src.GameID),
			ServerHostname(src.ServerHostname),
			ServerPort(src.ServerPort)
			{}
			
		FStartGameResponse(const TSharedPtr<FJsonObject>& obj) : FStartGameResponse()
        {
            readFromValue(obj);
        }
		
		~FStartGameResponse();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FUserInfoRequest : public FPlayFabBaseModel
    {
		
		// PlayFab unique identifier of the user whose information is being requested.
		FString PlayFabId;
		// Minimum catalog version for which data is requested (filters the results to only contain inventory items which have a catalog version of this or higher).
		int32 MinCatalogVersion;
	
        FUserInfoRequest() :
			FPlayFabBaseModel(),
			PlayFabId(),
			MinCatalogVersion(0)
			{}
		
		FUserInfoRequest(const FUserInfoRequest& src) :
			FPlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			MinCatalogVersion(src.MinCatalogVersion)
			{}
			
		FUserInfoRequest(const TSharedPtr<FJsonObject>& obj) : FUserInfoRequest()
        {
            readFromValue(obj);
        }
		
		~FUserInfoRequest();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FVirtualCurrencyRechargeTime : public FPlayFabBaseModel
    {
		
		// Time remaining (in seconds) before the next recharge increment of the virtual currency.
		int32 SecondsToRecharge;
		// Server timestamp in UTC indicating the next time the virtual currency will be incremented.
		FDateTime RechargeTime;
		// Maximum value to which the regenerating currency will automatically increment. Note that it can exceed this value through use of the AddUserVirtualCurrency API call. However, it will not regenerate automatically until it has fallen below this value.
		int32 RechargeMax;
	
        FVirtualCurrencyRechargeTime() :
			FPlayFabBaseModel(),
			SecondsToRecharge(0),
			RechargeTime(0),
			RechargeMax(0)
			{}
		
		FVirtualCurrencyRechargeTime(const FVirtualCurrencyRechargeTime& src) :
			FPlayFabBaseModel(),
			SecondsToRecharge(src.SecondsToRecharge),
			RechargeTime(src.RechargeTime),
			RechargeMax(src.RechargeMax)
			{}
			
		FVirtualCurrencyRechargeTime(const TSharedPtr<FJsonObject>& obj) : FVirtualCurrencyRechargeTime()
        {
            readFromValue(obj);
        }
		
		~FVirtualCurrencyRechargeTime();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	
	struct PLAYFAB_API FUserInfoResponse : public FPlayFabBaseModel
    {
		
		// [optional] PlayFab unique identifier of the user whose information was requested.
		FString PlayFabId;
		// [optional] PlayFab unique user name.
		FString Username;
		// [optional] Title specific display name, if set.
		FString TitleDisplayName;
		// [optional] Array of inventory items in the user's current inventory.
		TArray<FItemInstance> Inventory;
		// [optional] Array of virtual currency balance(s) belonging to the user.
		TMap<FString, int32> VirtualCurrency;
		// [optional] Array of remaining times and timestamps for virtual currencies.
		TMap<FString, FVirtualCurrencyRechargeTime> VirtualCurrencyRechargeTimes;
		// Boolean indicating whether the user is a developer.
		bool IsDeveloper;
		// [optional] Steam unique identifier, if the user has an associated Steam account.
		FString SteamId;
	
        FUserInfoResponse() :
			FPlayFabBaseModel(),
			PlayFabId(),
			Username(),
			TitleDisplayName(),
			Inventory(),
			VirtualCurrency(),
			VirtualCurrencyRechargeTimes(),
			IsDeveloper(false),
			SteamId()
			{}
		
		FUserInfoResponse(const FUserInfoResponse& src) :
			FPlayFabBaseModel(),
			PlayFabId(src.PlayFabId),
			Username(src.Username),
			TitleDisplayName(src.TitleDisplayName),
			Inventory(src.Inventory),
			VirtualCurrency(src.VirtualCurrency),
			VirtualCurrencyRechargeTimes(src.VirtualCurrencyRechargeTimes),
			IsDeveloper(src.IsDeveloper),
			SteamId(src.SteamId)
			{}
			
		FUserInfoResponse(const TSharedPtr<FJsonObject>& obj) : FUserInfoResponse()
        {
            readFromValue(obj);
        }
		
		~FUserInfoResponse();
		
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };
	

}
}

