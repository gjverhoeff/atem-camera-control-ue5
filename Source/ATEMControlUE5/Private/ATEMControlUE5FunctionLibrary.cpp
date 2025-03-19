#include "ATEMControlUE5FunctionLibrary.h"

#include "IWebSocket.h"
#include "ATEMControlUE5Websocket.h"
#include "WebSocketsModule.h"
#include "Kismet/KismetStringLibrary.h"
#include "JsonObjectConverter.h"
#include "Misc/CString.h"
#include "Containers/Array.h"
#include "Math/Vector.h"
#include "Math/Rotator.h"
#include "Misc/WildcardString.h"
#include "Dom/JsonObject.h"
#include "Containers/UnrealString.h"
#include "Json.h"
#include "JsonUtilities.h"

UWebSocket* UATEMControlUE5FunctionLibrary::ATEMControlUE5WebsocketURL(FString ServerUrl)
{
	const TSharedPtr<IWebSocket> ActualSocket = FModuleManager::LoadModuleChecked<FWebSocketsModule>(TEXT("WebSockets")).CreateWebSocket(ServerUrl);
	UWebSocket* const WrapperSocket = NewObject<UWebSocket>();
	WrapperSocket->InitWebSocket(ActualSocket);
	return WrapperSocket;
}

// Implementation of DeserializeJson function
TSharedPtr<FJsonObject> UATEMControlUE5FunctionLibrary::DeserializeJson(const FString& Data)
{
    // Implementation
    TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Data);
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
    {
        return JsonObject;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON: %s"), *Data);
        return nullptr;
    }
}



void UATEMControlUE5FunctionLibrary::BMCamera(const FString& Data,
    float& kelvin, float& iris, int& gainDb, float& saturation, float& contrast, float& pivot, float& hue, int& tint, int& filter, float& LumMix,
    FVector4& gamma, FVector4& gain, FVector4& lift,
    float& shutter)
{
    // Deserialize JSON with error handling
    TSharedPtr<FJsonObject> jsonObject = DeserializeJson(Data);
    if (!jsonObject.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON: %s"), *Data);
        return;
    }

    // Extract Camera Settings with error handling
    if (!jsonObject->TryGetNumberField(TEXT("kelvin"), kelvin))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'kelvin' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("iris"), iris))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'iris' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("shutter"), shutter))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'shutter' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("saturation"), saturation))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'saturation' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("pivot"), pivot))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'pivot' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("contrast"), contrast))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'contrast' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("hue"), hue))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'hue' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("tint"), tint))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'tint' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("filter"), filter))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'filter' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("gaindb"), gainDb))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gaindb' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("lummix"), LumMix))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'lummix' field in JSON payload"));
    }

    // Extract Gamma Settings with error handling
    float gammaRed, gammaGreen, gammaBlue, gammaWhite;
    if (!jsonObject->TryGetNumberField(TEXT("gammaRed"), gammaRed))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gammaRed' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("gammaGreen"), gammaGreen))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gammaGreen' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("gammaBlue"), gammaBlue))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gammaBlue' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("gammaWhite"), gammaWhite))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gammaWhite' field in JSON payload"));
    }
    gamma = FVector4(gammaRed, gammaGreen, gammaBlue, gammaWhite);

    // Extract Gain Settings with error handling
    float gainRed, gainGreen, gainBlue, gainWhite;
    if (!jsonObject->TryGetNumberField(TEXT("gainRed"), gainRed))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gainRed' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("gainGreen"), gainGreen))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gainGreen' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("gainBlue"), gainBlue))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gainBlue' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("gainWhite"), gainWhite))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'gainWhite' field in JSON payload"));
    }
    gain = FVector4(gainRed, gainGreen, gainBlue, gainWhite);

    // Extract Lift Settings with error handling
    float liftRed, liftGreen, liftBlue, liftWhite;
    if (!jsonObject->TryGetNumberField(TEXT("liftRed"), liftRed))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'liftRed' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("liftGreen"), liftGreen))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'liftGreen' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("liftBlue"), liftBlue))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'liftBlue' field in JSON payload"));
    }
    if (!jsonObject->TryGetNumberField(TEXT("liftWhite"), liftWhite))
    {
        UE_LOG(LogTemp, Warning, TEXT("Missing 'liftWhite' field in JSON payload"));
    }
    lift = FVector4(liftRed, liftGreen, liftBlue, liftWhite);

    //// Extract Program and Preview booleans
    //if (!jsonObject->TryGetBoolField(TEXT("program"), program))
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("Missing 'program' field in JSON payload"));
    //}
    //if (!jsonObject->TryGetBoolField(TEXT("preview"), preview))
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("Missing 'preview' field in JSON payload"));
    //}
}