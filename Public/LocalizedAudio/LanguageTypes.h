#pragma once

#include "CoreMinimal.h"
#include "LanguageTypes.generated.h"

/**
 * Перечень поддерживаемых языков для локализации звуков.
 * Используется как "ключ" выбора нужного `USoundBase*` в `FLocalizedSound`.
 */
UENUM(BlueprintType)
enum class ELanguage : uint8
{
	/** Русский */
	RU,
	/** Японский */
	JP,
	/** Английский */
	EN
};