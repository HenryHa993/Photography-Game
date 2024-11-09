// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueChoiceWidget.h"
#include "Inkpot/InkpotChoice.h"

void UDialogueChoiceWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UInkpotChoice* Choice = Cast<UInkpotChoice>(ListItemObject);

	if (!Choice)
	{
		return;
	}

	FText Text = FText::FromString(Choice->GetString());
	ReceiveOnTextUpdate(Text);
}
