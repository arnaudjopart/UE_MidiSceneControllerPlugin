// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorExplorerUtilityWidget.h"

#include "UObject/UnrealTypePrivate.h"

void UActorExplorerUtilityWidget::ListActorFunctions(AActor* TargetActor)
{
	if (!TargetActor) return;

	UClass* ActorClass = TargetActor->GetClass();
    
	UE_LOG(LogTemp, Log, TEXT("=== Liste des fonctions de %s ==="), *ActorClass->GetName());

	for (TFieldIterator<UFunction> FuncIt(ActorClass, EFieldIteratorFlags::IncludeSuper); FuncIt; ++FuncIt)
	{
		UFunction* Function = *FuncIt;
		uint8 NbParams = Function->NumParms;
		UE_LOG(LogTemp, Log, TEXT(" - %s - %d"), *Function->GetName(), NbParams);

		for (auto It = TFieldIterator<UProperty>(Function); It; ++It)
		{
			auto Property = *It;
			UE_LOG(LogTemp, Log, TEXT(" - %s"), *Property->GetName());
			
			// Call Property->HasAnyPropertyFlags(...) to determine if return value, input/ouput param, etc.
		}
	}
}

void UActorExplorerUtilityWidget::SayHello()
{
	UE_LOG(LogTemp, Log, TEXT("SayHello"));
}
