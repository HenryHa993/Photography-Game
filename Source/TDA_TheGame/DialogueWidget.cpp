// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"

void UDialogueWidget::ShowStory(UInkpotStory* Story)
{
	InkStory = Story;
	ReceiveOnShowStory(InkStory);
}
