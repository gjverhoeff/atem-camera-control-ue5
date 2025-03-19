#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonObjectConverter.h"
#include "Json.h"
#include "ATEMControlUE5FunctionLibrary.generated.h"

class UWebSocket;

UENUM(BlueprintType)
enum EScored
{
	GoalScored,
	NotScored

};

UENUM(BlueprintType)
enum EStatFeed
{
	StatEventFire,
	NoStatEventFire

};

UENUM(BlueprintType)
enum EBallHit
{
	BallHit,
	BallNotHit

};

UCLASS(MinimalAPI)
class UATEMControlUE5FunctionLibrary final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable, Category = "Blackmagic ATEM", Meta = (ToolTip = "Fill in the IP address and port how to reach ATEM Connect Software. Normally ws://localhost:8080 for local usage."))
	static UWebSocket* ATEMControlUE5WebsocketURL(FString ServerUrl);



	UFUNCTION(BlueprintCallable, Category = "Blackmagic ATEM|Camera", meta = (DisplayName = "ATEM Connect Camera Control"))
	static void BMCamera(const FString& Data,
		float& kelvin, float& iris, int& gainDb, float& saturation, float& contrast, float& pivot, float& hue, int& tint, int& filter, float& LumMix,
		FVector4& gamma, FVector4& gain, FVector4& lift,
		float& shutter);

	static TSharedPtr<FJsonObject> DeserializeJson(const FString& Data);
	
};



