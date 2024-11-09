// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameStructs.h"
#include "Engine/DataTable.h"
#include "QuestLogComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestProgressedSignature, FName, RowName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestCompletedSignature, FName, RowName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuestAssignedSignature, FName, RowName);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TDA_THEGAME_API UQuestLogComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestLogComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Data tables and maps to track quests
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
	UDataTable* QuestDataTable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
	TMap<FName, FQuest> CurrentQuests;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quests")
	TMap<FName, FQuest> CompletedQuests;

	// Delegates to tie events to quest events
	UPROPERTY(BlueprintAssignable)
	FOnQuestProgressedSignature OnQuestProgressedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnQuestCompletedSignature OnQuestCompletedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnQuestAssignedSignature OnQuestAssignedDelegate;

	// Quest related functions
	UFUNCTION(BlueprintCallable)
	bool AddQuest(FName RowName);

	UFUNCTION(BlueprintCallable)
	bool CompleteQuest(FName RowName);

	UFUNCTION(BlueprintCallable)
	bool ProgressQuest(FName RowName);

	UFUNCTION(BlueprintCallable)
	bool CheckQuestComplete(FName RowName);

	UFUNCTION(BlueprintCallable)
	bool CheckQuestOngoing(FName RowName);

};
