// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DialogueWidget.generated.h"

class UInkpotStory;

UCLASS(Abstract, Blueprintable)
class TDA_THEGAME_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Set story and run RecieveOnShowStory
	UFUNCTION(BlueprintCallable, Category = "Inkpot")
	void ShowStory(UInkpotStory* Story);

	// Runs blueprint implemented event
	UFUNCTION(BlueprintImplementableEvent, Category = "Inkpot", meta = (DisplayName = "OnShowStory"))
	void ReceiveOnShowStory(UInkpotStory* Story);

private:
	UPROPERTY(VisibleAnywhere, Transient)
	UInkpotStory* InkStory{ nullptr };
};
