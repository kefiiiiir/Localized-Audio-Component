/*
 * GameInstance проекта, в котором хранится выбранный язык.
 * Этот класс используется `ULocalizedAudioComponent` для выбора нужной звуковой дорожки.
 */

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LocalizedAudio/LanguageTypes.h"
#include "DefaultGameInstance.generated.h"

/**
 * Простой GameInstance с одним публичным параметром языка.
 * Можно менять из Blueprints (например, при выборе языка в меню).
 */
UCLASS()
class YOURGAME_API UDefaultGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	/** Текущий язык игры (по умолчанию RU). */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ELanguage CurrentLanguage = ELanguage::RU;
};
