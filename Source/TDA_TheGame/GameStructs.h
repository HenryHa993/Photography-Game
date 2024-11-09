// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "GameStructs.generated.h"


USTRUCT(BlueprintType)
struct FQuest : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FText QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FText LogDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int Tasks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int TasksComplete = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	bool QuestComplete = false;
};