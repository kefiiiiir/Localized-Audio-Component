#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LocalizedSound.h"
#include "LanguageTypes.h"
#include "LocalizedAudioComponent.generated.h"

/**
 * Компонент, который хранит таблицу "ключ → набор локализованных звуков"
 * и умеет возвращать нужный `USoundBase*` в зависимости от текущего языка игры.
 *
 * Идея: в блюпринтах/коде вы оперируете стабильными ключами (FName),
 * а конкретные звуки назначаются в редакторе.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BACKROOMSREPO_API ULocalizedAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	/**
	 * Словарь звуков.
	 * - Key: идентификатор реплики/события (например, "Empty1", "LowEnergyLine3").
	 * - Value: набор ассетов под разные языки.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<FName, FLocalizedSound> Sounds;

	/**
	 * Возвращает звук для заданного ключа с учётом текущего языка игры.
	 * Может вернуть `nullptr`, если мир/инстанс/ключ отсутствуют или ассет не назначен.
	 */
	UFUNCTION(BlueprintCallable)
	USoundBase* GetLocalizedSound(FName SoundKey);
};
