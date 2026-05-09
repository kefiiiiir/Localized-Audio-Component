#include "LocalizedAudio/LocalizedAudioComponent.h"
#include "DefaultGameInstance.h"
#include "LocalizedAudio/LocalizedSound.h"

USoundBase* ULocalizedAudioComponent::GetLocalizedSound(FName SoundKey)
{
	// Компонент может существовать в контекстах, где мира ещё нет (или уже нет),
	// поэтому сначала аккуратно получаем `UWorld`.
	UWorld* World = GetWorld();
	if (!World) return nullptr;

	// Язык хранится в нашем GameInstance.
	// Если по какой-то причине используется другой GI — корректно вернём nullptr.
	UDefaultGameInstance* GI = World->GetGameInstance<UDefaultGameInstance>();
	if (!GI) return nullptr;

	// Находим запись по ключу (ключи задаются в `Sounds` в редакторе).
	FLocalizedSound* Entry = Sounds.Find(SoundKey);
	if (!Entry) return nullptr;

	// Возвращаем ассет под выбранный язык. Может быть nullptr, если не назначен.
	return Entry->Get(GI->CurrentLanguage);
}
