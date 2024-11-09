// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestLogComponent.h"

// Sets default values for this component's properties
UQuestLogComponent::UQuestLogComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UQuestLogComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UQuestLogComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UQuestLogComponent::AddQuest(FName RowName)
{
	// If already added, prevent addition
	if (CurrentQuests.Contains(RowName))
	{
		UE_LOG(LogTemp, Warning, TEXT("WARNING: Quest already added."));
		return false;
	}

	static const FString ContextString(TEXT("Quest Context"));
	FQuest* NewQuest = QuestDataTable->FindRow<FQuest>(RowName, ContextString, true);
	CurrentQuests.Add(RowName, *(NewQuest));

	OnQuestAssignedDelegate.Broadcast(RowName);

	return true;
}

bool UQuestLogComponent::CompleteQuest(FName RowName)
{
	UE_LOG(LogTemp, Warning, TEXT("DEBUG: Quest completed!"));
	FQuest CompletedQuest = CurrentQuests.FindAndRemoveChecked(RowName);

	CompletedQuests.Add(RowName, CompletedQuest);

	OnQuestCompletedDelegate.Broadcast(RowName);
	return true;
}

bool UQuestLogComponent::ProgressQuest(FName RowName)
{
	UE_LOG(LogTemp, Warning, TEXT("DEBUG: Quest progressed!"));
	FQuest* Quest = CurrentQuests.Find(RowName);

	if (!Quest)
	{
		UE_LOG(LogTemp, Warning, TEXT("WARNING: Quest is not currently ongoing."));
		return false;
	}

	Quest->TasksComplete++;
	bool IsCompleted = (Quest->Tasks <= Quest->TasksComplete);

	if (IsCompleted)
	{
		CompleteQuest(RowName);
	}
	else
	{
		OnQuestProgressedDelegate.Broadcast(RowName);
	}

	return true;
}

bool UQuestLogComponent::CheckQuestComplete(FName RowName)
{
	bool IsComplete = CompletedQuests.Contains(RowName);
	return IsComplete;
}

bool UQuestLogComponent::CheckQuestOngoing(FName RowName)
{
	bool IsOngoing = CurrentQuests.Contains(RowName);
	if (IsOngoing)
	{
		UE_LOG(LogTemp, Warning, TEXT("WARNING: Quest assigned."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("WARNING: Quest is not assigned."));
	}
	return IsOngoing;
}

