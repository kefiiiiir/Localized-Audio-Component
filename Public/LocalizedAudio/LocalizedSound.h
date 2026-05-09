#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundBase.h"
#include "LanguageTypes.h"
#include "LocalizedSound.generated.h"

/**
 * Набор вариантов одного и того же звука для разных языков.
 * Заполняется в редакторе (Blueprint/Details) и по `ELanguage` возвращает нужный ассет.
 *
 * Важно: указатели могут быть `nullptr` — если ассет для языка не задан.
 */
USTRUCT(BlueprintType)
struct FLocalizedSound
{
	GENERATED_BODY()

	/** Русская версия звука */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* RU = nullptr;

	/** Японская версия звука */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* JP = nullptr;

	/** Английская версия звука */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USoundBase* EN = nullptr;

	/**
	 * Возвращает звук под выбранный язык.
	 * Если язык неизвестен/не поддержан — используем RU как безопасный дефолт.
	 */
	USoundBase* Get(ELanguage Lang) const
	{
		switch (Lang)
		{
		case ELanguage::RU: return RU;
		case ELanguage::JP: return JP;
		case ELanguage::EN: return EN;
		default: return RU; // fallback: чтобы всегда был предсказуемый результат
		}
	}
};
