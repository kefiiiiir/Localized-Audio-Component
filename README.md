# LocalizedAudioComponent (RU)

Небольшой набор типов для выбора звуков по текущему языку игры (Unreal Engine).

## Что входит

- `ELanguage` — перечисление поддерживаемых языков.
- `FLocalizedSound` — структура с вариантами одного звука под разные языки (`RU/JP/EN`).
- `ULocalizedAudioComponent` — компонент с `TMap<FName, FLocalizedSound>`, который по ключу возвращает нужный `USoundBase*`.
- `UDefaultGameInstance` — `UGameInstance`, где хранится `CurrentLanguage`.

## Как это работает

1. В `UDefaultGameInstance::CurrentLanguage` хранится выбранный язык.
2. В `ULocalizedAudioComponent::Sounds` вы заводите записи вида:
   - ключ `FName` (например, `"LowEnergyLine3"`)
   - значение `FLocalizedSound` (заполняете ассеты под RU/JP/EN)
3. В рантайме вызываете `GetLocalizedSound(SoundKey)` и получаете `USoundBase*` под текущий язык.

Если мир/инстанс/ключ отсутствуют — функция вернёт `nullptr`. Если ассет под язык не назначен — тоже `nullptr`.

## Подключение в проект

### GameInstance

Убедитесь, что в настройках проекта используется `UDefaultGameInstance`:

- Project Settings → Maps & Modes → **Game Instance Class** = `DefaultGameInstance`

### Заполнение звуков

1. Добавьте `ULocalizedAudioComponent` на нужный Actor.
2. В Details откройте `Sounds` и добавьте элементы:
   - Name (ключ)
   - RU/JP/EN (ассеты `SoundBase`)

## Использование (Blueprint)

- Вызовите у компонента `GetLocalizedSound` с нужным ключом.
- Полученный `SoundBase` передайте в `Play Sound...`/`Audio Component`/любую вашу систему воспроизведения.

## Расширение

- Добавить новые языки: расширьте `ELanguage` и добавьте поля в `FLocalizedSound` + ветку в `Get`.
- Сделать фолбэк-логику умнее: например, если EN не задан — брать RU, и т.д.

