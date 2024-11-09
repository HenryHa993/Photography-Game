// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "DialogueChoiceWidget.generated.h"

UCLASS(BlueprintType, Blueprintable)
class TDA_THEGAME_API UDialogueChoiceWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Inkpot", meta = (DisplayName = "OnTextUpdate"))
	void ReceiveOnTextUpdate(const FText& InText);

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
};
